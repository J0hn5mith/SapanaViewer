//
//  SceneViewController.m
//  SapanaViewer
//
//  Created by Jan Meier on 04.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//


// Class Definition
#import "SceneViewController.h"

// Project Includes

#import "SceneNodeModifierWrapper.h"
#import "Util.h"

// Config
#include "Config.h"

@interface SceneViewController ()
{
   
}
@property CGRect visualizationFrameSmall;
@property CGRect previewFrameSmall;
@property CGRect expandedViewFrame;

@property SceneNodeModifierWrapper * snmWrapper;
@end

@implementation SceneViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self)
    {

    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.loadVisualizationViewController
    [self pareseViews];
    
    [self loadPreviewViewController];
    [self loadVisualizationViewController];
    
    self.view.layer.cornerRadius = CORNER_RADIUS_TOPIC_SUBVIEW;
}

- (void)viewDidUnload
{
    [super viewDidUnload];
    
    if ([EAGLContext currentContext] == self.eaglContext) {
        [EAGLContext setCurrentContext:nil];
    }
    
    self.eaglContext = nil;
}
#pragma mark -
#pragma mark Getter and Setter Methodes
-(void)setSapanaViewer:(SapanaViewerWrapper *)sapanaViewer
{
    _sapanaViewer = sapanaViewer;
    
    //_sapanaViewer = [SapanaViewerWrapper getSharedManager];
    self.snmWrapper = [self.sapanaViewer getObserverCameraModifier];
}

-(void) setEaglContext:(EAGLContext *)eaglContext
{
    _eaglContext = eaglContext;
    GLKView *view = (GLKView *)self.view;
    view.context = self.eaglContext;
    [EAGLContext setCurrentContext:view.context];
}

-(void)setLayoutProperties:(TopicLayoutProperties *)layoutProperties
{
    _layoutProperties = layoutProperties;
    
    [self.view setBackgroundColor: self.layoutProperties.secondaryColor];
    
    // Set Border color of sub views
    self.previewViewController.view.layer.borderColor = self.layoutProperties.primaryColor.CGColor;
    self.previewViewController.view.layer.borderWidth = BORDER_WIDTH_TOPIC_SUBVIEW;
    
    self.visualizationViewController.view.layer.borderColor = self.layoutProperties.primaryColor.CGColor;
    self.visualizationViewController.view.layer.borderWidth = BORDER_WIDTH_TOPIC_SUBVIEW;
    
}

-(void) setVisualizationViewController:(VisualizationViewController *)visualizationViewController
{
    _visualizationViewController = visualizationViewController;
    _visualizationView = self.visualizationViewController.view;
//    _visualizationView.frame = _visualizationFrameSmall;
    [_visualizationView setFrame:_visualizationFrameSmall];
    [self.view addSubview:_visualizationView];
    [self addChildViewController:self.visualizationViewController];
    [_visualizationViewController didMoveToParentViewController:self];
    _visualizationViewController.delegate = self;
}



#pragma mark -
#pragma mark GLKView Stuff

// Is only called if the context of the view already is set;
- (void)glkView:(GLKView *)view drawInRect:(CGRect)rect
{
    if (!self.eaglContext) {
        NSLog(@"Faild to rendere the scene because context was not set");
        return;
    }
    
    view.context = self.eaglContext;
    [EAGLContext setCurrentContext: view.context];
    
    [self.sapanaViewer initOpenGL];
    [self.sapanaViewer drawScene];
}



- (void) pareseViews
{
    _expandedViewFrame = _expandedView.frame;
    [self.expandedView removeFromSuperview];
    self.expandedView = nil;
    
    _previewFrameSmall = _previewView.frame;
    [self.previewView removeFromSuperview];
    self.previewView = nil;
    
    _visualizationFrameSmall = _visualizationView.frame;
    [self.visualizationView removeFromSuperview];
    self.visualizationView = nil;
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void) loadPreviewViewController
{
    self.previewViewController = [[PreviewViewController alloc] initWithNibName:@"PreviewViewController" bundle:nil];
    _previewView = self.previewViewController.view;
    _previewView.frame = _previewFrameSmall;
    [self.view addSubview:self.previewView];
    [self addChildViewController:self.previewViewController];
    [_previewViewController didMoveToParentViewController:self];
    _previewViewController.delegate = self;
}

- (void) loadVisualizationViewController
{
        self.visualizationViewController = [[VisualizationViewController alloc] initWithNibName:@"VisualizationViewController" bundle:nil];
}


#pragma mark -
#pragma mark VisualizationViewControllerDelegate

-(CGRect) expandVisualizationView
{
    [self.view bringSubviewToFront:_visualizationView];
    
     [UIView animateWithDuration:0.5 delay:0.015 options:
     UIViewAnimationOptionBeginFromCurrentState
                     animations:^{
                         _visualizationView.frame = CGRectMake(_expandedViewFrame.origin.x, _expandedViewFrame.origin.y, _expandedViewFrame.size.width, _expandedViewFrame.size.height);
                     }
                     completion:^(BOOL finished) {
                         if (finished) {
                             [self enableGestures:NO];
                         }
                     }];
    
    return _expandedViewFrame;
}

-(CGRect) shrinkVisualizationView
{
    [UIView animateWithDuration:0.5 delay:0.015 options:
     UIViewAnimationOptionBeginFromCurrentState
                     animations:^{
                         _visualizationView.frame = CGRectMake(_visualizationFrameSmall.origin.x, _visualizationFrameSmall.origin.y, _visualizationFrameSmall.size.width, _visualizationFrameSmall.size.height);
                     }
                     completion:^(BOOL finished) {
                         if (finished) {
                             
                             [self enableGestures:YES];
                         }
                     }];
    [self enableGestures:YES];
    return _visualizationFrameSmall;
}


#pragma mark -
#pragma mark PreviewViewControllerDelegate Implementation

-(CGRect) expandPreviewView
{
    [self.view bringSubviewToFront:_previewView];
    [UIView animateWithDuration:0.5 delay:0.015 options:
     UIViewAnimationOptionBeginFromCurrentState
                     animations:^{
                         _previewView.frame = CGRectMake(_expandedViewFrame.origin.x, _expandedViewFrame.origin.y, _expandedViewFrame.size.width, _expandedViewFrame.size.height);
                     }
                     completion:^(BOOL finished) {
                         if (finished) {
                             
                             [self enableGestures:NO];
                         }
                     }];
    
    return _expandedViewFrame;
}

-(CGRect) shrinkPreviewView
{
    [UIView animateWithDuration:0.5 delay:0.015 options:
     UIViewAnimationOptionBeginFromCurrentState
                     animations:^{
                         _previewView.frame = CGRectMake(_previewFrameSmall.origin.x, _previewFrameSmall.origin.y, _previewFrameSmall.size.width, _previewFrameSmall.size.height);
                     }
                     completion:^(BOOL finished) {
                         if (finished) {
                             [self enableGestures:YES];
                             
                         }
                     }];
    return _previewFrameSmall;
}

#pragma mark - Hiding Visualization and Preview View

-(void) hidePreviewView:(BOOL)hide
{
    [self.previewViewController.view setHidden:hide];
}

-(void) hideVisualizationView:(BOOL)hide
{
    [self.visualizationViewController.view setHidden:hide];
}

#pragma mark - Gesture Recognizer Methodes


-(IBAction) pinchGestureRecognizer: (UIPinchGestureRecognizer * ) recognizer
{
    [self.snmWrapper translateZ:recognizer.velocity];
}

-(IBAction) oneFingerPanGestureRecognizer: (UIPanGestureRecognizer * ) recognizer
{
    CGPoint velocity = [recognizer velocityInView:self.view];
    CGFloat xVel = -velocity.y ;
    CGFloat yVel = -velocity.x;
    
    CGFloat xAngle = [Util smoothenVelocity:xVel] * NAVIGATOIN_SPEED_REDUCTION_FACTOR;
    CGFloat yAngle = [Util smoothenVelocity:yVel] * NAVIGATOIN_SPEED_REDUCTION_FACTOR;

    [self.snmWrapper rotateX:xAngle];
    [self.snmWrapper rotateY:yAngle];
}

-(IBAction) twoFingerPanGestureRecognizer: (UIPanGestureRecognizer * ) recognizer
{
    CGPoint velocity = [recognizer velocityInView:self.view];
    CGFloat xVel = -velocity.x ;
    CGFloat yVel = -velocity.y;
    
    CGFloat xDistance = [Util smoothenVelocity:xVel] * NAVIGATOIN_SPEED_REDUCTION_FACTOR;
    CGFloat yDistance = [Util smoothenVelocity:yVel] * NAVIGATOIN_SPEED_REDUCTION_FACTOR;
    
    [self.snmWrapper translateX:xDistance];
    [self.snmWrapper translateY:yDistance];
}

#pragma mark - Util Methodes
-(void) enableGestures:(BOOL)active
{
    self.pinchGestureRecognizer.enabled = active;
    self.oneFingerPanGestureRecognizer.enabled = active;
    self.twoFingerPanGestureRecognizer.enabled = active;
}

@end
