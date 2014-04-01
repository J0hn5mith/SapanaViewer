//
//  SceneViewController.h
//  SapanaViewer
//
//  Created by Jan Meier on 04.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Project indlucde
#import "PreviewViewController.h"
#import "VisualizationViewController.h"
#import "SapanaViewerWrapper.h"
#import "TopicLayoutProperties.h"

// External includes
#import <UIKit/UIKit.h>
#include <GLKit/GLKit.h>

@interface SceneViewController : GLKViewController <VisualizationViewControllerDelegate,
PreviewViewControllerDelegate>


@property (nonatomic) SapanaViewerWrapper * sapanaViewer;
@property (nonatomic) TopicLayoutProperties * layoutProperties;

#pragma mark - OpenGL
@property (strong, nonatomic) EAGLContext * eaglContext;

#pragma mark - Subviews and Subcontroller
@property (nonatomic, strong) PreviewViewController * previewViewController;
@property (nonatomic, strong) VisualizationViewController * visualizationViewController;
@property (nonatomic, strong) IBOutlet UIView * previewView;
@property (nonatomic, strong) IBOutlet UIView * visualizationView;
@property (nonatomic, strong) IBOutlet UIView * expandedView;

#pragma mark - Gesture Recognizers Objects
@property (strong, nonatomic) IBOutlet UIPinchGestureRecognizer *pinchGestureRecognizer;
@property (strong, nonatomic) IBOutlet UIPanGestureRecognizer *oneFingerPanGestureRecognizer;
@property (strong, nonatomic) IBOutlet UIPanGestureRecognizer *twoFingerPanGestureRecognizer;


#pragma mark - Hiding Visualization and Preview View

-(void) hidePreviewView:(BOOL)hide;
-(void) hideVisualizationView:(BOOL)hide;

#pragma mark - Gesture Recognizer Methodes
-(IBAction) pinchGestureRecognizer: (UIPinchGestureRecognizer * ) recognizer;
-(IBAction) oneFingerPanGestureRecognizer: (UIPanGestureRecognizer * ) recognizer;

-(IBAction) twoFingerPanGestureRecognizer: (UIPanGestureRecognizer * ) recognizer;

@end
