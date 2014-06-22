//
//  VisualizationViewController.h
//  SapanaViewer
//
//  Created by Jan Meier on 04.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// External Includes
#import <UIKit/UIKit.h>

// Project Includes
#import "TopicLayoutProperties.h"

@protocol VisualizationViewControllerDelegate <NSObject>

@optional

@required
-(CGRect) expandVisualizationView;
-(CGRect) shrinkVisualizationView;
@end


@interface VisualizationViewController : UIViewController

#pragma mark - Properties
@property (nonatomic) TopicLayoutProperties * layoutProperties;


#pragma mark - Delegates
@property (nonatomic, assign) id<VisualizationViewControllerDelegate > delegate;


#pragma mark - Gesture Handling
@property (nonatomic, strong) IBOutlet UITapGestureRecognizer *singleTapRecognizer;
@property bool expanded;
- (IBAction)singleTap:(UITapGestureRecognizer *)recognizer;

@end
