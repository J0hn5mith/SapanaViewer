//
//  TransformationVisualizationViewController.h
//  SapanaViewer
//
//  Created by Jan Meier on 19.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Super Class
#import "VisualizationViewController.h"

// Project Includes
#import "MatrixViewController.h"
#import "SceneNodeModifierWrapper.h"
#import "MatrixMultiplicationVisualisationViewController.h"

// External Includes
#import <UIKit/UIKit.h>

@interface TransformationVisualizationViewController : VisualizationViewController < MatrixListDataSource >

//#pragma mark - Views and View Controllers
//
//
//@property NSMutableArray * matrixViews; // 0 elemnt = result => all other matrices are shifted by 1;
//@property NSMutableArray * multiplicationSigns;
//
//@property (weak, nonatomic) IBOutlet UIScrollView *scrollView;
//@property (weak, nonatomic) IBOutlet UIView *contentView;
//@property (weak, nonatomic) IBOutlet UIView *centeredView;
//
//@property (weak, nonatomic) IBOutlet UIView *matrixPrototype;
//@property (weak, nonatomic) IBOutlet UILabel *spacePrototype;
//
//
//@property  CGRect matrixFrame;
//@property  CGRect spaceFrame;
//@property  UIFont * spaceLabelFont;
//@property  UIColor * spaceLabelTextColor;
//@property  NSTextAlignment  spaceLabelTextAlignment;

#pragma mark - Data Source
@property (nonatomic) SceneNodeModifierWrapper * nodeModifier;
@property MatrixMultiplicationVisualisationViewController *  matrixMultiplicationVVC;

#pragma mark - Animation Methodes
-(void) selectMatrix:(int)index;
-(void) moveMatrix:(int) fromIndex toIndex:(int) toIndex;
-(void) deleteMatrix:(int)index;
#pragma mark - Content Controll Methodes
-(void) updateMatrices;

@end
