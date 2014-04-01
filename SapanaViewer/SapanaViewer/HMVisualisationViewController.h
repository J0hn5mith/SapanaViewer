//
//  HMVisualisationViewController.h
//  SapanaViewer
//
//  Created by Jan Meier on 23.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Super Class
#import "VisualizationViewController.h"

// Project Includes
#import <UIKit/UIKit.h>
#import "SceneNodeModifierWrapper.h"
#import "MatrixMultiplicationVisualisationViewController.h"

// External Includes
#import <UIKit/UIKit.h>

@interface HMVisualisationViewController : VisualizationViewController

#pragma mark - Data Source
@property (nonatomic) SceneNodeModifierWrapper * nodeModifier;
@property MatrixMultiplicationVisualisationViewController*  matrixMultiplicationVVC;
@end
