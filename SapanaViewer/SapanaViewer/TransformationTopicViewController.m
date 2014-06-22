//
//  TransformationTopicViewController.m
//  SapanaViewer
//
//  Created by Jan Meier on 05.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Class Definition
#import "TransformationTopicViewController.h"

// Project Includes
#include "TransformationInformationViewController.h"
#include "TransformationConfigurationViewController.h"
#include "TransformationVisualizationViewController.h"

@interface TransformationTopicViewController () <ModelSelectionViewControllerDelegate , TransformationConfigurationViewControllerDelegate >

// Casted version of VisualizationViewController
@property (nonatomic) TransformationVisualizationViewController * transformationVisualisationViewController;

@end

@implementation TransformationTopicViewController

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

}

#pragma mark - Setter and Getter
-(void) setVisualizationViewController:(VisualizationViewController *)visualizationViewController
{
    // TODO: Typechecking
    [super setVisualizationViewController:visualizationViewController];
    _transformationVisualisationViewController = (TransformationVisualizationViewController * ) self.visualizationViewController;
}

#pragma mark -
#pragma mark Overrides
-(void)loadSelectionViewController
{
    ModelSelectionViewController * msvController = [[ModelSelectionViewController alloc] initWithNibName:@"ModelSelectionViewController" bundle:nil];
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
    [self.selectionViewController.view setClipsToBounds:YES];
    
    [((TransformationConfigurationViewController *) self.configurationViewController) setDelegate:self];
}

-(void)loadConfigurationViewController
{
    // Set up View and Contrller
    self.configurationViewController = [[TransformationConfigurationViewController alloc] initWithNibName:@"TransformationConfigurationViewController" bundle:nil];
    self.configurationViewController.view.frame = self.configurationView.frame;
    [self.configurationView removeFromSuperview];
    
    // Add View and Controller
    [self.view addSubview:self.configurationViewController.view];
    [self addChildViewController:self.configurationViewController];
    [self.configurationViewController didMoveToParentViewController:self];
    
    [self configureConfigurationViewController];
}

-(void)configureConfigurationViewController
{
    [super configureConfigurationViewController];
    
}

-(void)loadInformationViewController
{
    // Set up view
    self.informationViewController = [[TransformationInformationViewController alloc] initWithNibName:@"TransformationInformationViewController" bundle:nil];
    self.informationViewController.view.frame = self.informationView.frame;
    [self.informationView removeFromSuperview];
    
    // Add View and Controller
    [self.view addSubview:self.informationViewController.view];
    [self addChildViewController:self.informationViewController];
    [self.configurationViewController didMoveToParentViewController:self];
    
    // Configure InformationView Controller
    [((TransformationInformationViewController*)self.informationViewController)hideMatrix:true];
     [((TransformationInformationViewController*)self.informationViewController)showNoMatrixSelected:false];
}

-(void)loadVisualizationViewController
{
    self.transformationVisualisationViewController = [[TransformationVisualizationViewController alloc] initWithNibName:@"VisualizationViewController" bundle:nil];
    self.visualizationViewController = self.transformationVisualisationViewController;
    
    self.sceneViewController.visualizationViewController  = self.transformationVisualisationViewController;
    
    [self configureVisualizationViewController];
}

-(void)configureVisualizationViewController
{
    [super configureVisualizationViewController];
}

#pragma mark -
#pragma mark ModelSelectionViewControllerDelegate Protocol
- (void) modelSelected:(int) modelId
{
    if (modelId != -1)
    {
        [self.sapanaViewer selectModelNode: modelId];
        
        SceneNodeModifierWrapper * sceneNodeModifier = [self.sapanaViewer getSelectedNodeModifier];
        
        // Change Configuration View Controller
        TransformationConfigurationViewController * tcvController = ((TransformationConfigurationViewController *)self.configurationViewController);
        tcvController.sceneNodeModifier = sceneNodeModifier;
        
        // Change Information View Controller
        [((TransformationInformationViewController*)self.informationViewController)hideMatrix:true];
        
        // Change The Visualization View Controller
        // TODO: Remove this. Because this methodes is called from the model selector, and the visualization view hasen't been changed then, the needed methode is not available
        
        TransformationVisualizationViewController * tmp = ((TransformationVisualizationViewController*)self.sceneViewController.visualizationViewController);
        if([tmp isKindOfClass:[TransformationVisualizationViewController class]])
        {
            [tmp setNodeModifier:sceneNodeModifier];
        }
        
        
        [self.sceneViewController hideVisualizationView:false];
        [self.transformationVisualisationViewController setNodeModifier:sceneNodeModifier];
        [((TransformationInformationViewController*)self.informationViewController)showNoMatrixSelected:true];
    }
    else
    {
        [((TransformationConfigurationViewController *)self.configurationViewController) setNoModelSelected:true];
        
        //[((TransformationInformationViewController*)self.informationViewController) showNoNodeSelected:true];
        
        [self.sceneViewController hideVisualizationView:true];
    }
    
    
}

#pragma mark -
#pragma mark TransformationConfigurationViewControllerDelegate Protocol
-(void) transformationSelected:(NSInteger) transformationPosition;
{
    if (transformationPosition >= 0)
    {
        [((TransformationInformationViewController*)self.informationViewController)hideMatrix:false];
        TransMatrix * activeTransformationMatrix = [[self.sapanaViewer getSelectedNodeModifier] getActiveTransformationMatrix];
        TransformationInformationViewController *matrixInformationVC =((TransformationInformationViewController*)self.informationViewController);
        [matrixInformationVC.matrixVC updateWithMatrix:activeTransformationMatrix];
            [((TransformationInformationViewController*)self.informationViewController)showNoMatrixSelected:false];
        [self.transformationVisualisationViewController selectMatrix:transformationPosition];
    }
    else
    {
       [((TransformationInformationViewController*)self.informationViewController)hideMatrix:true];
            [((TransformationInformationViewController*)self.informationViewController)showNoMatrixSelected:true];
    }
    
}

-(void) transformationDeleted:(NSInteger)position
{
    [self.transformationVisualisationViewController deleteMatrix:position];
}

-(void) transformationModified
{
   // Update information view
    TransMatrix * activeTransformationMatrix = [[self.sapanaViewer getSelectedNodeModifier] getActiveTransformationMatrix];
    
    TransformationInformationViewController *matrixInformationVC =((TransformationInformationViewController*)self.informationViewController);
    [matrixInformationVC.matrixVC updateWithMatrixWithHighlight:activeTransformationMatrix];
    
    // Update visualization view
    // TODO Clean up
    [self.transformationVisualisationViewController updateMatrices];

}


-(void) transformationMoved:(NSInteger)fromPosition toPosition:(NSInteger ) toPosition
{
    // Update visualization view
    // TODO Clean up
    TransformationVisualizationViewController * tmp = ((TransformationVisualizationViewController*)self.sceneViewController.visualizationViewController);
    if([tmp isKindOfClass:[TransformationVisualizationViewController class]])
    {
        
        [tmp.matrixMultiplicationVVC moveMatrix:fromPosition toIndex:toPosition];
    }
}

-(void) transformationListModified:(BOOL) matrixAdded
{
    
    // Update visualization view
    // TODO Clean up
    TransformationVisualizationViewController * tmp = ((TransformationVisualizationViewController*)self.sceneViewController.visualizationViewController);
    if([tmp isKindOfClass:[TransformationVisualizationViewController class]])
    {
        [tmp updateMatrices];
    }
    
    if (matrixAdded)
    {
        // TODO handle adding
    }
    else
    {
       // TODO handle deletion
    }
}

@end
