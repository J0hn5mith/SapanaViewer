//
//  ModelingTopicViewController.m
//  SapanaViewer
//
//  Created by Jan Meier on 05.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Project includes
#import "ModelingTopicViewController.h"
#import "ModelConfigurationViewController.h"
#import "ModelInformationViewController.h"

@interface ModelingTopicViewController () <ModelSelectionViewControllerDelegate>
// Casted pointer to the selection view
@property (nonatomic, retain) ModelSelectionViewController * modelSelectionViewController;

@property (nonatomic, retain) ModelInformationViewController * modelingInformationViewController;

@end

@implementation ModelingTopicViewController

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
    // Do any additional setup after loading the view from its nib.
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
    ModelSelectionViewController * msvController = [[ModelSelectionViewController alloc] initWithNibName:@"ModelSelectionViewController" bundle:nil];
    
    self.selectionViewController = msvController;
    self.modelSelectionViewController = msvController;
    
    self.selectionViewController.view.frame = self.selectionView.frame;
    msvController.delegate = self;
    [self.selectionView removeFromSuperview];
    [self.view addSubview:self.selectionViewController.view];
    [self addChildViewController:self.selectionViewController];
    [self.selectionViewController didMoveToParentViewController:self];
    
    [self configureSelectionViewController];
}

-(void)configureSelectionViewController
{
    [super configureSelectionViewController];
}


-(void)loadConfigurationViewController
{
    self.configurationViewController = [[ModelConfigurationViewController alloc] initWithNibName:@"ModelConfigurationViewController" bundle:nil];
    self.configurationViewController.view.frame = self.configurationView.frame;
    [self.configurationView removeFromSuperview];
    [self.view addSubview:self.configurationViewController.view];
    [self addChildViewController:self.configurationViewController];
    [self.configurationViewController didMoveToParentViewController:self];
}

-(void)loadInformationViewController
{
     _modelingInformationViewController = [[ModelInformationViewController alloc] initWithNibName:@"ModelInformationViewController" bundle:nil];
    self.informationViewController = self.modelingInformationViewController;
    
    self.informationViewController.view.frame = self.informationView.frame;
    [self.informationView removeFromSuperview];
    [self.view addSubview:self.informationViewController.view];
    [self addChildViewController:self.informationViewController];
    [self.configurationViewController didMoveToParentViewController:self];
    
    [self configureInformationViewController];
}
     
-(void)configureInformationViewController
{
    [super configureInformationViewController];
}


#pragma mark -
#pragma mark ModelSelectionViewControllerDelegate Protocol
- (void) modelSelected:(int) modelId
{
    [self.sapanaViewer selectModelNode: modelId];
    
    SceneNodeModifierWrapper * tmp = [self.sapanaViewer getSelectedNodeModifier];
    ModelConfigurationViewController * mcvController = ((ModelConfigurationViewController *)self.configurationViewController);
    
    [self.modelingInformationViewController setModelInformation:[tmp getModelNodeInformation]];

    mcvController.sceneNodeModifier = tmp;
}

@end
