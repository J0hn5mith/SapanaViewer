//
//  TopicViewController.m
//  SapanaViewer
//
//  Created by Jan Meier on 04.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Project Includes
#import "TopicViewController.h"
#import "Util.h"
#import "Config.h"

@interface TopicViewController ()

@end

@implementation TopicViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
        self.mask = [[UIView alloc] initWithFrame:self.view.frame];
        [self.mask setBackgroundColor:[UIColor colorWithWhite:0.0 alpha:0.78]];
        [self.view addSubview:self.mask];
        [self.mask setHidden:FALSE];
        
        // DEBUG TODO: Don't use singleton
        //self.sapanaViewer = [SapanaViewerWrapper getSharedManager];
    }
    return self;
}

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil eaglContext:(EAGLContext *) context
{
    self =[super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        self.eaglContext = context;
        // DEBUG TODO: Don't use singleton
        self.mask = [[UIView alloc] initWithFrame:self.view.frame];
        [self.mask setBackgroundColor:[UIColor colorWithWhite:0.0 alpha:0.78]];
        [self.view addSubview:self.mask];
        [self.mask setHidden:TRUE];
    }
    return self;
}

#pragma mark - View did load/unload
- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    
    [self loadSceneViewController];
    [self loadConfigurationViewController];
    [self loadInformationViewController];
    [self loadSelectionViewController];
    [self loadVisualizationViewController];
    
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Getter and Setter
-(void)setSapanaViewer:(SapanaViewerWrapper *)sapanaViewer
{
    _sapanaViewer = sapanaViewer;
    
    [self.selectionViewController setSapanaViewer:self.sapanaViewer];
    [self.sceneViewController setSapanaViewer:self.sapanaViewer];
    //TODO: Propagate
}

-(void)setLayoutProperties:(TopicLayoutProperties *)layoutProperties
{
    _layoutProperties = layoutProperties;
    
    [self.view setBackgroundColor: self.layoutProperties.secondaryColor];
    
    // Set Border color of sub views
    float borderWidth = BORDER_WIDTH_TOPIC_SUBVIEW; // TODO
    self.sceneViewController.view.layer.borderColor = self.layoutProperties.primaryColor.CGColor;
    self.sceneViewController.view.layer.borderWidth = borderWidth;
 
    self.configurationViewController.view.layer.borderColor = self.layoutProperties.primaryColor.CGColor;
    self.configurationViewController.view.layer.borderWidth = borderWidth;

    self.informationViewController.view.layer.borderColor = self.layoutProperties.primaryColor.CGColor;
    self.informationViewController.view.layer.borderWidth = borderWidth;

    self.selectionViewController.view.layer.borderColor = self.layoutProperties.primaryColor.CGColor;
    self.selectionViewController.view.layer.borderWidth = borderWidth;
    
    [self.sceneViewController setLayoutProperties:layoutProperties];

}

#pragma mark - Loading and Configuration of Subview
-(void)loadSceneViewController
{    
    self.sceneViewController = [[SceneViewController alloc] initWithNibName:@"SceneViewController" bundle:nil];
    //self.sceneViewController.eaglContext = self.eaglContext;
    _sceneViewController.view.frame = _sceneView.frame;
    [_sceneView removeFromSuperview];
    _sceneView = self.sceneViewController.view;
    [self.view addSubview:self.sceneViewController.view];
    [self addChildViewController:self.sceneViewController];
    [_sceneViewController didMoveToParentViewController:self];
    [self.sceneViewController.view setClipsToBounds:YES];

}

-(void)loadConfigurationViewController
{
    self.configurationViewController = [[ConfigurationViewController alloc] initWithNibName:@"ConfigurationViewController" bundle:nil];
    _configurationViewController.view.frame = _configurationView.frame;
    [_configurationView removeFromSuperview];

    [self.view addSubview:self.configurationViewController.view];
    [self addChildViewController:self.configurationViewController];
    [_configurationViewController didMoveToParentViewController:self];
    
    [self configureConfigurationViewController];
}

-(void)configureConfigurationViewController
{
    [self.configurationViewController.view setClipsToBounds:YES];
}

-(void)loadInformationViewController
{
    self.informationViewController = [[InformationViewController alloc] initWithNibName:@"InformationViewController" bundle:nil];
    _informationViewController.view.frame = _informationView.frame;
    [_informationView removeFromSuperview];
    
    [self.view addSubview:self.informationViewController.view];
    [self addChildViewController:self.informationViewController];
    [_configurationViewController didMoveToParentViewController:self];
    [self.informationViewController.view setClipsToBounds:YES];
}

-(void)configureInformationViewController
{
    [self.informationViewController.view setClipsToBounds:YES];
}


-(void)loadSelectionViewController
{
    self.selectionViewController = [[SelectionViewController alloc] initWithNibName:@"SelectionViewController" bundle:nil];
    _selectionViewController.view.frame = _selectionView.frame;
    [_selectionView removeFromSuperview];
    [self.view addSubview:self.selectionViewController.view];
    [self addChildViewController:self.selectionViewController];
    [_selectionViewController didMoveToParentViewController:self];
    
    [self configureSelectionViewController];
}

-(void)configureSelectionViewController
{
    [self.selectionViewController.view setClipsToBounds:YES];
}

-(void)loadVisualizationViewController
{
    
}

#pragma mark - TopicViewController Methodes
-(void)activateMask:(BOOL) active
{
    if (active) {
        [self.view bringSubviewToFront:self.mask];
        [self.mask setHidden:FALSE];
    }
    else{
        [self.mask setHidden:TRUE];
    }
}
@end
