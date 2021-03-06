//
//  MatrixMultiplicationVisualisationViewController.h
//  SapanaViewer
//
//  Created by Jan Meier on 23.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Project Includes
#import "MatrixViewController.h"

// External Includes
#import <UIKit/UIKit.h>

@protocol MatrixListDataSource

@required
- ( NSArray * ) getMatrices;
@end

@interface MatrixMultiplicationVisualisationViewController : UIViewController < UIScrollViewDelegate >

#pragma mark - Matrices
@property (nonatomic, assign) id< MatrixListDataSource > dataSource;

#pragma mark - Matrices
@property NSMutableArray * matrixViews; // 0 elemnt = result => all other matrices are shifted by 1;


#pragma mark - Views
@property (strong, nonatomic) IBOutlet UIScrollView *scrollView;
@property (weak, nonatomic) IBOutlet UIView *contentView;
@property (weak, nonatomic) IBOutlet UIView *centeredView;


#pragma mark - View Prototypes
@property (weak, nonatomic) IBOutlet UILabel *spaceLabelPrototype;
@property (weak, nonatomic) IBOutlet UIView *matrixPrototype;
@property (weak, nonatomic) IBOutlet UILabel *matrixLabelPrototype;


#pragma mark - View Prototype Parameters
@property  CGRect matrixFrame;

@property  CGRect spaceFrame;
@property  UIFont * spaceLabelFont;
@property  UIColor * spaceLabelTextColor;
@property  NSTextAlignment  spaceLabelTextAlignment;

@property  CGRect matrixLabelFrame;
@property  UIFont * matrixLabelFont;
@property  UIColor * matrixLabelTextColor;
@property  NSTextAlignment  matrixLabelTextAlignment;

#pragma mark - Configuration Parameter
@property UIColor * highLightColor;
@property NSInteger selectedMatrix;

#pragma mark - Animations
-(void) selectMatrix:(int)index;
-(void) moveMatrix:(int) fromIndex toIndex:(int) toIndex;
-(void) deleteMatrix:(int)index;

#pragma mark - Content Controll Methodes
-(void) refreshMatrices;
-(void) refreshMatrices:( NSArray *) newMatrices;

@end
