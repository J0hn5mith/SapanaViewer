//
//  TransformationVisualizationViewController.m
//  SapanaViewer
//
//  Created by Jan Meier on 19.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#import "TransformationVisualizationViewController.h"

@interface TransformationVisualizationViewController ()

@end

@implementation TransformationVisualizationViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self)
    {
        self.matrixViews = [[NSMutableArray alloc]init];
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    
    // Set up Scroll view
    [self.scrollView setScrollEnabled:YES];
    [self.scrollView setFrame:self.view.frame];
    [self.scrollView setContentSize:self.contentView.frame.size];
    self.scrollView.delegate = self;
    [self.scrollView setFrame:self.view.frame];
    
    // Parse prototypes from xib
    self.matrixFrame = self.matrixPrototype.frame;
    self.spaceFrame = self.spacePrototype.frame;
    self.spaceLabelFont = self.spacePrototype.font;
    self.spaceLabelTextColor = self.spacePrototype.textColor;
    self.spaceLabelTextAlignment = self.spacePrototype.textAlignment;
    
    [self.matrixPrototype removeFromSuperview];
    [self.spacePrototype removeFromSuperview];
    
    // Set scale that first matrix fits
    [self.scrollView setZoomScale:0.9];
}

#pragma mark - Getter and Setter Methodes
-(void) setNodeModifier:(SceneNodeModifierWrapper *)nodeModifier
{
    _nodeModifier = nodeModifier;
    [self updateMatrices];
    [self centerScrollViewContent:self.scrollView];
     [self.scrollView setZoomScale:0.7];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - UIScrollViewDelegate Implementation

- (UIView *)viewForZoomingInScrollView:(UIScrollView *)scrollView
{
    return self.contentView;
}

// Update the scrolled view (self.contentViewController.view) to be centered. Coppied from http://stackoverflow.com/questions/1316451/center-content-of-uiscrollview-when-smaller
- (void)scrollViewDidZoom:(UIScrollView *)scrollView
{
    [self centerScrollViewContent:scrollView];
}

-(void) centerScrollViewContent:(UIScrollView *)scrollView
{
    UIView *subView = [scrollView.subviews objectAtIndex:0];
    
    CGFloat offsetX = (scrollView.bounds.size.width > scrollView.contentSize.width)?
    (scrollView.bounds.size.width - scrollView.contentSize.width) * 0.5 : 0.0;
    
    
    CGFloat offsetY = (scrollView.bounds.size.height > scrollView.contentSize.height)?
    (scrollView.bounds.size.height - scrollView.contentSize.height) * 0.5 : 0.0;
    
    subView.center = CGPointMake(scrollView.contentSize.width * 0.5 + offsetX,
                                 scrollView.contentSize.height * 0.5 + offsetY);
}

#pragma mark - Content Controll Methodes
-(void) updateMatrices
{
    if (self.nodeModifier)
    {
        // Delete the previous matrixViews
        self.matrixViews = [[NSMutableArray alloc]init];
        
        NSInteger matrixWidth = self.matrixFrame.size.width; // TODO: Get this value from different place
        NSInteger matrixOffset = self.spaceFrame.size.width;
        NSInteger matrixWidthWithOffset = matrixWidth + matrixOffset;
        
        // Remove all matrices from center view
        [[self.centeredView subviews] makeObjectsPerformSelector:@selector(removeFromSuperview)];

        // Add result matrix
        [self addMatrix:[self.nodeModifier getWorldTransformationMatrix] xOffset:0];
 
        // Add = sign
        [self addSpaceWithLabel:@"=" xOffset:0];
        
        NSMutableArray * matrices = [self.nodeModifier getTransformationMatrixList];
        int matrixCounter = 1;
        const int numMatrices = [matrices count];
        for (TransMatrix * matrix in matrices)
        {
            int offset = (matrixWidthWithOffset * (matrixCounter));
            [self addMatrix:matrix xOffset:offset ];
            
            if (matrixCounter != numMatrices)
            {
                // Don't need to add matrix width because ofsset is added to origin and the spaces origin already is positioned after a matrix
                [self addSpaceWithLabel:@"x" xOffset:offset];
            }

      
             matrixCounter++;
        }
        
        
        CGRect newCVSize = self.contentView.frame;
        newCVSize.size.width = ((numMatrices +1) * matrixWidthWithOffset)*self.scrollView.zoomScale;
        [self.contentView setFrame:newCVSize];
        [self.scrollView setContentSize:newCVSize.size];
        
    }
 
}

#pragma mark - Animation Methodes
// http://stackoverflow.com/questions/4033147/how-to-do-a-curve-arc-animation-with-caanimation
-(void) moveMatrix:(int) fromIndex toIndex:(int) toIndex
{
    int duratoin = 2;
    int controllPointOffset = 200;
    
    // Add one becaus matrix at 0 is result
    fromIndex += 1;
    toIndex += 1;
    UIView * fromView = [self.matrixViews objectAtIndex:fromIndex];
    UIView * toView = [self.matrixViews objectAtIndex:toIndex];
    
    // Move Matrix
    CAKeyframeAnimation *leafAnimation = [CAKeyframeAnimation animationWithKeyPath:@"position"];
    leafAnimation.duration = duratoin;
    
    // Animation's path
    UIBezierPath *path = [UIBezierPath bezierPath];
    
    // Move the "cursor" to the start
    [path moveToPoint:fromView.center];
    
    // Calculate the control points

    CGPoint c1 = CGPointMake(fromView.center.x, fromView.center.y - controllPointOffset);
    
    CGPoint c2 = CGPointMake(toView.center.x, toView.center.y - controllPointOffset);
    
     [path addCurveToPoint:toView.center controlPoint1:c1 controlPoint2:c2];
    leafAnimation.path = path.CGPath;
    leafAnimation.delegate = self;
    [fromView.layer addAnimation:leafAnimation forKey:@""];
    [NSTimer scheduledTimerWithTimeInterval:duratoin target:self selector:@selector(updateMatrices) userInfo:NULL repeats:NO];
    
//    // Move intermediate matrices
    int incrementValue = 1;
    if ( fromIndex < toIndex ) // Shift them left
    {
         incrementValue = (-1);
    }
//
    for (int i = toIndex; i != fromIndex; i += incrementValue)
    {
        UIView * fromView = [self.matrixViews objectAtIndex:i];
        UIView * toView = [self.matrixViews objectAtIndex:(i+ incrementValue)];
        
        [UIView animateWithDuration:2 delay:0.015 options:
         UIViewAnimationOptionBeginFromCurrentState
                         animations:^{
                             fromView.frame = toView.frame;
                         }
                         completion:^(BOOL finished) {
                             if (finished) {
                                 
                             }
                         }];
    }
    
}

#pragma mark - Util Methodes for Creating the Matrices
-(MatrixViewController *) addMatrix:(TransMatrix *)matrix xOffset:(int)xOffset
{
    MatrixViewController * resultMatrix = [[MatrixViewController alloc] init];
    [self.matrixViews addObject:resultMatrix.view];
    [self.centeredView addSubview:resultMatrix.view];
    [resultMatrix updateWithMatrix:matrix];
    
    // Set up frame
    CGRect frame = self.matrixFrame;
    frame.origin.x += xOffset;
    [resultMatrix.view setFrame:frame];
    
    return resultMatrix;
}


-( UILabel *) addSpaceWithLabel:(NSString * )label xOffset:(int)xOffset
{
    UILabel * spaceWithLabel = [[UILabel alloc] init];
    [self.centeredView addSubview:spaceWithLabel];
    
    [spaceWithLabel setText:label];
    [spaceWithLabel setTextColor:self.spaceLabelTextColor];
    [spaceWithLabel setBackgroundColor:[UIColor clearColor]];
    [spaceWithLabel setFont:self.spaceLabelFont];
    [spaceWithLabel setTextAlignment: self.spaceLabelTextAlignment];
    
    // Adjust frame
    CGRect frame = self.spaceFrame;
    frame.origin.x += xOffset;
    [spaceWithLabel setFrame:frame];
    
    return spaceWithLabel;
}


@end
