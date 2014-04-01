//
//  HMTopicViewController.m
//  SapanaViewer
//
//  Created by Jan Meier on 05.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Class Definition
#import "HMTopicViewController.h"

// Project Includes
#import "HModelSelectionViewController.h"
#import "TransformationConfigurationViewController.h"
#import "HMInformationViewController.h"
#import "HMVisualisationViewController.h"

@interface HMTopicViewController () < HModelSelectionViewControllerDelegate ,TransformationConfigurationViewControllerDelegate >
@property HMVisualisationViewController * hmVisualisationViewController;
@end

@implementation HMTopicViewController

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
    
    [((HMInformationViewController*)self.informationViewController)showNoNodeSelected:true];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];

}

#pragma mark - HModelSelectionViewControllerDelegate Implementation
- (void) modelSelected:(int) modelId
{
   if (modelId != -1)
    {
        [self.sapanaViewer selectModelNode: modelId];
        
        SceneNodeModifierWrapper * sceneNodeModifier = [self.sapanaViewer getSelectedNodeModifier];
        
        TransformationConfigurationViewController * tcvController = ((TransformationConfigurationViewController *)self.configurationViewController);
        
        tcvController.sceneNodeModifier = sceneNodeModifier;
        
        
        // Information View
        [((HMInformationViewController*)self.informationViewController) setSceneNodeModifier:sceneNodeModifier];
        
        
        [self.sceneViewController hideVisualizationView:false];
        
        [self.hmVisualisationViewController setNodeModifier:sceneNodeModifier];
    }
    else
    {
        
        [((TransformationConfigurationViewController *)self.configurationViewController) setNoModelSelected:true];
        
        [((HMInformationViewController*)self.informationViewController) showNoNodeSelected:true];
        
        [self.sceneViewController hideVisualizationView:true];
    }

}

-(void)loadVisualizationViewController
{
    self.hmVisualisationViewController = [[HMVisualisationViewController alloc] initWithNibName:@"VisualizationViewController" bundle:nil];
    
    self.sceneViewController.visualizationViewController  = self.hmVisualisationViewController;
}

#pragma mark -
#pragma mark Overrides
-(void)loadSelectionViewController
{
    HModelSelectionViewController * msvController = [[HModelSelectionViewController alloc] initWithNibName:@"HModelSelectionViewController" bundle:nil];
    self.selectionViewController = msvController;
    
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
    self.configurationViewController = [[TransformationConfigurationViewController alloc] initWithNibName:@"TransformationConfigurationViewController" bundle:nil];
    self.configurationViewController.view.frame = self.configurationView.frame;
    [self.configurationView removeFromSuperview];
    [self.view addSubview:self.configurationViewController.view];
    [self addChildViewController:self.configurationViewController];
    [self.configurationViewController didMoveToParentViewController:self];
     [self configureConfigurationViewController];
}

-(void)configureConfigurationViewController
{
    [super configureConfigurationViewController];
    
    ((TransformationConfigurationViewController *) self.configurationViewController).delegate = self;
}

-(void)loadInformationViewController
{
    self.informationViewController = [[HMInformationViewController alloc] initWithNibName:@"HMInformationViewController" bundle:nil];
    self.informationViewController.view.frame = self.informationView.frame;
    [self.informationView removeFromSuperview];
    [self.view addSubview:self.informationViewController.view];
    [self addChildViewController:self.informationViewController];
    [self.configurationViewController didMoveToParentViewController:self];
    
    [self configureInformationViewController];
}

-(void) configureInformationViewController
{
    [super configureInformationViewController];
}

#pragma mark -
#pragma mark TransformationConfigurationViewControllerDelegate Protocol
-(void) transformationSelected:(BOOL) matrixSelected
{
    [self.hmVisualisationViewController setNodeModifier:[self.sapanaViewer getSelectedNodeModifier]];
}

-(void) transformationModified
{
    [self.hmVisualisationViewController setNodeModifier:[self.sapanaViewer getSelectedNodeModifier]];
    
}


-(void) transformationMoved:(NSInteger)fromPosition toPosition:(NSInteger ) toPosition
{
[self.hmVisualisationViewController setNodeModifier:[self.sapanaViewer getSelectedNodeModifier]];
}

-(void) transformationListModified:(BOOL) matrixAdded
{
[self.hmVisualisationViewController setNodeModifier:[self.sapanaViewer getSelectedNodeModifier]];
}


@end
