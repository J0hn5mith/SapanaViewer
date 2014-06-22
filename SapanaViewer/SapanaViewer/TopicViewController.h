//
//  TopicViewController.h
//  SapanaViewer
//
//  Created by Jan Meier on 04.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Project Includes
#import "SceneViewController.h"
#import "VisualizationViewController.h"
#import "ConfigurationViewController.h"
#import "InformationViewController.h"
#import "SelectionViewController.h"
#import "ModelSelectionViewController.h"
#import "TopicLayoutProperties.h"

// External Includes
#import <UIKit/UIKit.h>


@interface TopicViewController : UIViewController

#pragma - Init
- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil eaglContext:(EAGLContext *) context;

// Members
@property EAGLContext * eaglContext;
@property (nonatomic) SapanaViewerWrapper * sapanaViewer;
@property (nonatomic) TopicLayoutProperties * layoutProperties;


#pragma mark - View Controllers and Viees
@property (nonatomic, strong) IBOutlet UIView * sceneView;
@property (nonatomic, strong) IBOutlet UIView * configurationView;
@property (weak, nonatomic) IBOutlet UIView *informationView;
@property (weak, nonatomic) IBOutlet UIView *selectionView;

@property (nonatomic, strong) SceneViewController * sceneViewController;
@property (nonatomic, strong) VisualizationViewController * visualizationViewController;
@property (nonatomic, strong) ConfigurationViewController * configurationViewController;
@property (nonatomic, strong) InformationViewController * informationViewController;

@property (nonatomic, strong) SelectionViewController * selectionViewController;

#pragma mark
#pragma mark - Loading and Configuration of Subview Controllers
-(void)configureSelectionViewController;
-(void)configureConfigurationViewController;
-(void)configureInformationViewController;
-(void)configureVisualizationViewController;
#pragma mark - Masking
@property UIView * mask;
-(void)activateMask:(BOOL) active;

@end
