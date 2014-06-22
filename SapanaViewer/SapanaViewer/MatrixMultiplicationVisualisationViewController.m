    //
//  MatrixMultiplicationVisualisationViewController.m
//  SapanaViewer
//
//  Created by Jan Meier on 23.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Class Definition
#import "MatrixMultiplicationVisualisationViewController.h"


@interface MatrixMultiplicationVisualisationViewController ()

@end

@implementation MatrixMultiplicationVisualisationViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
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
    
    self.spaceFrame = self.spaceLabelPrototype.frame;
    self.spaceLabelFont = self.spaceLabelPrototype.font;
    self.spaceLabelTextColor = self.spaceLabelPrototype.textColor;
    self.spaceLabelTextAlignment = self.spaceLabelPrototype.textAlignment;
    
    self.matrixLabelFrame = self.matrixLabelPrototype.frame;
    self.matrixLabelFont = self.matrixLabelPrototype.font;
    self.matrixLabelTextColor = self.matrixLabelPrototype.textColor;
    self.matrixLabelTextAlignment = self.matrixLabelPrototype.textAlignment;
    
    
    [self.matrixPrototype removeFromSuperview];
    [self.spaceLabelPrototype removeFromSuperview];
    
    // Set scale that first matrix fits
    [self.scrollView setZoomScale:0.9];
    
    self.selectedMatrix = -1;
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

- (void)scrollViewDidZoom:(UIScrollView *)scrollView
{
    [self centerScrollViewContent:scrollView];
}

#pragma mark - Content Controll Methodes
-(void) refreshMatrices
{
    [self refreshMatrices:[self.dataSource getMatrices]];
}

-(void) refreshMatrices:( NSArray *) newMatrices
{
    MatrixViewController * matrixPrototype = [[MatrixViewController alloc] init];
    
    if (newMatrices && [newMatrices count] > 0)
    {
        // Delete the previous matrixViews
        self.matrixViews = [[NSMutableArray alloc]init];
        
        NSInteger matrixWidth = matrixPrototype.view.frame.size.width;
        NSInteger matrixOffset = self.spaceFrame.size.width;
        NSInteger matrixWidthWithOffset = matrixWidth + matrixOffset;
        
        // Remove all matrices from center view
        [[self.centeredView subviews] makeObjectsPerformSelector:@selector(removeFromSuperview)];
        
        int matrixCounter = 0;
        const int numMatrices = [newMatrices count];
        
        for (TransMatrix * matrix in newMatrices)
        {
            int offset = (matrixWidthWithOffset * (matrixCounter));
            

            
            MatrixViewController * matrixViewController = [self addMatrix:matrix xOffset:offset ];
            
            if (matrixCounter == self.selectedMatrix)
            {
                [matrixViewController setHighLightColor:self.highLightColor];
                [matrixViewController setIsHighlighted:YES];
            }
            
            [self addMatrixLabel:matrix.label xCenter:(offset +(matrixWidth*0.5))];
            
            
            if (matrixCounter == 0)
            {
                
                // Add = sign
                [self addSpaceWithLabel:@"=" xOffset:0 matrixBounds:matrixPrototype.view.bounds];
            }
            else if (matrixCounter == (numMatrices -1))
            {
                // Last item has no sign
            }
            else
            {

                [self addSpaceWithLabel:@"x" xOffset:offset matrixBounds:matrixPrototype.view.bounds];
                
            }
            
            matrixCounter++;
        }
        
        CGRect newCVSize = self.contentView.frame;
        newCVSize.size.width = ((numMatrices +1) * matrixWidthWithOffset)*self.scrollView.zoomScale;
        [self.contentView setFrame:newCVSize];
        [self.scrollView setContentSize:newCVSize.size];
    }
}

-(void) selectMatrix:(int)index
{
    self.selectedMatrix = index;
    [self refreshMatrices];
}

#pragma mark - Animations
// http://stackoverflow.com/questions/4033147/how-to-do-a-curve-arc-animation-with-caanimation
-(void) moveMatrix:(int) fromIndex toIndex:(int) toIndex
{
    int duratoin = 2;
    int controllPointOffset = 200;
    
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
    [NSTimer scheduledTimerWithTimeInterval:duratoin target:self selector:@selector(refreshMatrices) userInfo:NULL repeats:NO];
    
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

-(void) deleteMatrix:(int)index
{
    int duratoin = 2;
    
    // Add one becaus matrix at 0 is result

    UIView * fromView = [self.matrixViews objectAtIndex:index];

    
    // Move Matrix
    CAKeyframeAnimation *leafAnimation = [CAKeyframeAnimation animationWithKeyPath:@"position"];
    leafAnimation.duration = duratoin;
    
    [UIView animateWithDuration:duratoin
                     animations:^{fromView.alpha = 0.0;}
                     completion:^(BOOL finished) {
                         if (finished) {
                             [self refreshMatrices];
                         }
                     }];
    
    // Animation's path
//    UIBezierPath *path = [UIBezierPath bezierPath];
//    
//    // Move the "cursor" to the start
//    [path moveToPoint:fromView.center];
//    
//    // Calculate the control points
//    
//    CGPoint c1 = CGPointMake(fromView.center.x, fromView.center.y - controllPointOffset);
//    
//    CGPoint c2 = CGPointMake(toView.center.x, toView.center.y - controllPointOffset);
//    
//    [path addCurveToPoint:toView.center controlPoint1:c1 controlPoint2:c2];
//    leafAnimation.path = path.CGPath;
//    leafAnimation.delegate = self;
//    [fromView.layer addAnimation:leafAnimation forKey:@""];
//    [NSTimer scheduledTimerWithTimeInterval:duratoin target:self selector:@selector(refreshMatrices) userInfo:NULL repeats:NO];
//    
//    //    // Move intermediate matrices
//    int incrementValue = 1;
//    if ( fromIndex < toIndex ) // Shift them left
//    {
//        incrementValue = (-1);
//    }
//    //
//    for (int i = toIndex; i != fromIndex; i += incrementValue)
//    {
//        UIView * fromView = [self.matrixViews objectAtIndex:i];
//        UIView * toView = [self.matrixViews objectAtIndex:(i+ incrementValue)];
//        
//        [UIView animateWithDuration:2 delay:0.015 options:
//         UIViewAnimationOptionBeginFromCurrentState
//                         animations:^{
//                             fromView.frame = toView.frame;
//                         }
//                         completion:^(BOOL finished) {
//                             if (finished) {
//                                 
//                             }
//                         }];
//    }
}

#pragma mark - Util Methodes for Creating the Matrices
-(MatrixViewController *) addMatrix:(TransMatrix *)matrix xOffset:(int)xOffset
{
    MatrixViewController * resultMatrix = [[MatrixViewController alloc] init];
    [self.matrixViews addObject:resultMatrix.view];
    [self.centeredView addSubview:resultMatrix.view];
    [resultMatrix updateWithMatrix:matrix];
    
    // Set up frame
    CGRect frame = resultMatrix.view.frame;
    frame.origin.x += xOffset;
    frame.origin.y = self.matrixFrame.origin.y;
    [resultMatrix.view setFrame:frame];
    
    return resultMatrix;
}


-( UILabel *) addSpaceWithLabel:(NSString * )label xOffset:(int)xOffset matrixBounds:(CGRect)matrixBounds
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
    frame.origin.y = self.matrixFrame.origin.y;
    frame.origin.x += xOffset;
    frame.size.width = matrixBounds.size.width*0.65;
    frame.size.height = matrixBounds.size.height;
    [spaceWithLabel setFrame:frame];
    
    return spaceWithLabel;
}

-( UILabel *) addMatrixLabel:(NSString * )label xCenter:(int)xOffset
{
    UILabel * matrixLabel = [[UILabel alloc] init];
    [self.centeredView addSubview:matrixLabel];
    
    [matrixLabel setText:label];
    [matrixLabel setTextColor:self.matrixLabelTextColor];
    [matrixLabel setBackgroundColor:[UIColor clearColor]];
    [matrixLabel setFont:self.matrixLabelFont];
    [matrixLabel setTextAlignment: self.matrixLabelTextAlignment];
    
    // Adjust frame
    [matrixLabel setFrame:self.matrixLabelFrame];
    
    CGPoint center = self.matrixLabelFrame.origin;
    center.x = xOffset;
    [matrixLabel setCenter:center];
    
    return matrixLabel;
}

#pragma mark UIScrollViewDelegate Implementation Utils
// Update the scrolled view (self.contentViewController.view) to be centered. Coppied from http://stackoverflow.com/questions/1316451/center-content-of-uiscrollview-when-smaller
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

@end
