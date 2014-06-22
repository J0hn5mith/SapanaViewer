//
//  CSTopicViewController.m
//  SapanaViewer
//
//  Created by Jan Meier on 05.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#import "CSTopicViewController.h"
#import "ModelCameraSelectionViewController.h"
#import "CSInformationViewController.h"
#import "CSConfigurationViewController.h"

@interface CSTopicViewController ()

@property ModelCameraSelectionViewController * modelCameraSelectionViewController;

@end

@implementation CSTopicViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    [self.sceneViewController hidePreviewView:true ];
    [self.sceneViewController hideVisualizationView:true];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark -
#pragma mark Overrides
-(void)loadSelectionViewController
{
    self.modelCameraSelectionViewController = [[ModelCameraSelectionViewController alloc] initWithNibName:@"ModelCameraSelectionViewController" bundle:nil];
    self.selectionViewController = self.modelCameraSelectionViewController;
    
    
    self.selectionViewController.view.frame = self.selectionView.frame;
   // msvController.delegate = self;
    [self.selectionView removeFromSuperview];
    [self.view addSubview:self.selectionViewController.view];
    [self addChildViewController:self.selectionViewController];
    [self.selectionViewController didMoveToParentViewController:self];
    
    [self configureSelectionViewController];
}

-(void)configureSelectionViewController
{
    [super configureSelectionViewController];
    
    self.modelCameraSelectionViewController.modelSelectorDelegate = self;
    self.modelCameraSelectionViewController.cameraSelectorDelegate = self;
}


-(void)loadConfigurationViewController
{
    self.configurationViewController = [[CSConfigurationViewController alloc] initWithNibName:@"CSConfigurationViewController" bundle:nil];
    self.configurationViewController.view.frame = self.configurationView.frame;
    [self.configurationView removeFromSuperview];
    [self.view addSubview:self.configurationViewController.view];
    [self addChildViewController:self.configurationViewController];
    [self.configurationViewController didMoveToParentViewController:self];
}


-(void)loadInformationViewController
{
    self.informationViewController = [[CSInformationViewController alloc] initWithNibName:@"CSInformationViewController" bundle:nil];
    self.informationViewController.view.frame = self.informationView.frame;
    [self.informationView removeFromSuperview];
    [self.view addSubview:self.informationViewController.view];
    [self addChildViewController:self.informationViewController];
    [self.configurationViewController didMoveToParentViewController:self];
}

#pragma mark - ModelSelectorDelegate & CameraSelectorDelegate Implementation
-(void) modelSelected:(int)modelID
{
    
}

-(void) cameraSelected:(int)cameraID
{
    
}

@end
