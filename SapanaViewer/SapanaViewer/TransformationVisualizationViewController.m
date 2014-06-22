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
//        self.matrixViews = [[NSMutableArray alloc]init];
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.

    
    // Do any additional setup after loading the view from its nib.
    self.matrixMultiplicationVVC = [[MatrixMultiplicationVisualisationViewController alloc] init];
    [self addChildViewController:self.matrixMultiplicationVVC];
    [self.view addSubview:self.matrixMultiplicationVVC.view];
    [self.matrixMultiplicationVVC.view setFrame:self.view.frame];
    [self.matrixMultiplicationVVC setDataSource:self];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Getter and Setter Methodes

-(void)setNodeModifier:(SceneNodeModifierWrapper *)nodeModifier
{
    _nodeModifier = nodeModifier;
    [self updateMatrices];
}

-(void)setLayoutProperties:(TopicLayoutProperties *)layoutProperties
{
    [self.matrixMultiplicationVVC setHighLightColor:layoutProperties.secondaryColor];
}

#pragma mark - Content Controll Methodes
-(void) updateMatrices
{
     [self.matrixMultiplicationVVC refreshMatrices];
    
}


#pragma mark - Animation Methodes
-(void) selectMatrix:(int)index
{
    int numMatrices = [[self.nodeModifier getTransformationMatrixList] count]; //+1 because a matrix has been deleted
    
    [self.matrixMultiplicationVVC selectMatrix: (numMatrices - index)];
}
-(void) moveMatrix:(int) fromIndex toIndex:(int) toIndex
{
    [self.matrixMultiplicationVVC moveMatrix:fromIndex+1 toIndex:toIndex+1];
}

-(void) deleteMatrix:(int)index
{
    int numMatrices = [[self.nodeModifier getTransformationMatrixList] count] + 1; //+1 because a matrix has been deleted
    [self.matrixMultiplicationVVC deleteMatrix:(numMatrices -index)];
}


#pragma mark - MatrixListDataSource Implementatoin
- ( NSArray * ) getMatrices
{
    NSMutableArray * transformations = [self.nodeModifier getTransformationMatrixList];
    
    NSMutableArray* reverseTransformations = [[NSMutableArray alloc] init];
    NSEnumerator*   reverseEnumerator = [transformations reverseObjectEnumerator];
    
    TransMatrix * nodeTransformation = [self.nodeModifier getNodeTransformationMatrix];
    [nodeTransformation setLabel:@"Resulting Transformation"];
    [reverseTransformations addObject:nodeTransformation];
    
    for (id object in reverseEnumerator)
    {
        [reverseTransformations addObject:object];
    }
    
    return reverseTransformations;
}










#pragma mark - UIScrollViewDelegate Implementation

//- (UIView *)viewForZoomingInScrollView:(UIScrollView *)scrollView
//{
//    return self.contentView;
//}

//// Update the scrolled view (self.contentViewController.view) to be centered. Coppied from http://stackoverflow.com/questions/1316451/center-content-of-uiscrollview-when-smaller
//- (void)scrollViewDidZoom:(UIScrollView *)scrollView
//{
//    [self centerScrollViewContent:scrollView];
//}
//
//-(void) centerScrollViewContent:(UIScrollView *)scrollView
//{
//    UIView *subView = [scrollView.subviews objectAtIndex:0];
//    
//    CGFloat offsetX = (scrollView.bounds.size.width > scrollView.contentSize.width)?
//    (scrollView.bounds.size.width - scrollView.contentSize.width) * 0.5 : 0.0;
//    
//    
//    CGFloat offsetY = (scrollView.bounds.size.height > scrollView.contentSize.height)?
//    (scrollView.bounds.size.height - scrollView.contentSize.height) * 0.5 : 0.0;
//    
//    subView.center = CGPointMake(scrollView.contentSize.width * 0.5 + offsetX,
//                                 scrollView.contentSize.height * 0.5 + offsetY);
//}



#pragma mark - Animation Methodes
//// http://stackoverflow.com/questions/4033147/how-to-do-a-curve-arc-animation-with-caanimation
//-(void) moveMatrix:(int) fromIndex toIndex:(int) toIndex
//{
//    int duratoin = 2;
//    int controllPointOffset = 200;
//    
//    // Add one becaus matrix at 0 is result
//    fromIndex += 1;
//    toIndex += 1;
//    UIView * fromView = [self.matrixViews objectAtIndex:fromIndex];
//    UIView * toView = [self.matrixViews objectAtIndex:toIndex];
//    
//    // Move Matrix
//    CAKeyframeAnimation *leafAnimation = [CAKeyframeAnimation animationWithKeyPath:@"position"];
//    leafAnimation.duration = duratoin;
//    
//    // Animation's path
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
//     [path addCurveToPoint:toView.center controlPoint1:c1 controlPoint2:c2];
//    leafAnimation.path = path.CGPath;
//    leafAnimation.delegate = self;
//    [fromView.layer addAnimation:leafAnimation forKey:@""];
//    [NSTimer scheduledTimerWithTimeInterval:duratoin target:self selector:@selector(updateMatrices) userInfo:NULL repeats:NO];
//    
////    // Move intermediate matrices
//    int incrementValue = 1;
//    if ( fromIndex < toIndex ) // Shift them left
//    {
//         incrementValue = (-1);
//    }
////
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
//    
//}

#pragma mark - Util Methodes for Creating the Matrices
//-(MatrixViewController *) addMatrix:(TransMatrix *)matrix xOffset:(int)xOffset
//{
//    MatrixViewController * resultMatrix = [[MatrixViewController alloc] init];
//    [self.matrixViews addObject:resultMatrix.view];
//    [self.centeredView addSubview:resultMatrix.view];
//    [resultMatrix updateWithMatrix:matrix];
//    
//    // Set up frame
//    CGRect frame = self.matrixFrame;
//    frame.origin.x += xOffset;
//    [resultMatrix.view setFrame:frame];
//    
//    return resultMatrix;
//}
//
//
//-( UILabel *) addSpaceWithLabel:(NSString * )label xOffset:(int)xOffset
//{
//    UILabel * spaceWithLabel = [[UILabel alloc] init];
//    [self.centeredView addSubview:spaceWithLabel];
//    
//    [spaceWithLabel setText:label];
//    [spaceWithLabel setTextColor:self.spaceLabelTextColor];
//    [spaceWithLabel setBackgroundColor:[UIColor clearColor]];
//    [spaceWithLabel setFont:self.spaceLabelFont];
//    [spaceWithLabel setTextAlignment: self.spaceLabelTextAlignment];
//    
//    // Adjust frame
//    CGRect frame = self.spaceFrame;
//    frame.origin.x += xOffset;
//    [spaceWithLabel setFrame:frame];
//    
//    return spaceWithLabel;
//}


@end
