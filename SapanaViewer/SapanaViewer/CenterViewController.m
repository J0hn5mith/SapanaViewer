//
//  CenterViewController.m
//  SapanaViewer
//
//  Created by Jan Meier on 03.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#import "CenterViewController.h"
#include "ModelingTopicViewController.h"

// Debug
#include "TransformationTopicViewController.h"

@interface CenterViewController ()

@end

@implementation CenterViewController
{
    // DEBUG - Move it to MainViewController
    NSTimer * spUpdateTimer;
}

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        self.topicContainer = NULL; // TODO Set initial topicContainer
    }
    return self;
}

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil eaglContext:(EAGLContext *) context
{
    self =[self initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        self.eaglContext = context;
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    
    [self initTopicView:NULL];
}

#pragma mark - Getter and Setter
-(void)setTopicViewController:(TopicViewController *)topicViewController
{
    bool isFirstView = self.topicViewController == NULL;
    if (!isFirstView)
    {
        [self.topicViewController.view setHidden:YES ];
        [self.topicViewController.view removeFromSuperview];
        [self.topicViewController removeFromParentViewController];
        
        CGRect newFrame = topicViewController.view.frame;
        newFrame.origin.y = newFrame.size.height;
        self.topicViewController.view.frame = newFrame;
    }
    
    _topicViewController = topicViewController;
    
    if (!isFirstView)
    {
        CGRect newFrame = topicViewController.view.frame;
        newFrame.origin.y = newFrame.size.height;
        self.topicViewController.view.frame = newFrame;
    }
    
    
    [self.topicViewContainer addSubview:topicViewController.view ];
    [self addChildViewController:topicViewController];
    [topicViewController didMoveToParentViewController:self];
    [self.topicViewController activateMask:NO];
    [self.topicViewController.view setHidden:NO];
    
        [self.topicViewController.sceneViewController setEaglContext:self.eaglContext];
    
    [self.topicViewController setSapanaViewer:self.sapanaViewer];

    [UIView animateWithDuration:1.5 delay:0 options:UIViewAnimationOptionBeginFromCurrentState animations:^{
        self.topicViewController.view.frame = self.topicViewContainer.bounds;
    }
                     completion:^(BOOL finished) {
                         if (finished) {
                             
                         }
                     }];
    

}

// TODO: Refactor
-(void )initTopicView:(TopicContainer *) topicContainer
{
    

}

#pragma mark -
#pragma mark View Did Load/Unload

- (void)viewDidUnload
{
    [super viewDidUnload];
}

#pragma mark -
#pragma mark View Will/Did Appear

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
}

- (void)viewDidAppear:(BOOL)animated
{
	[super viewDidAppear:animated];
}


#pragma mark -
#pragma mark View Will/Did Disappear

- (void)viewWillDisappear:(BOOL)animated
{
	[super viewWillDisappear:animated];
}

- (void)viewDidDisappear:(BOOL)animated
{
	[super viewDidDisappear:animated];
}


#pragma mark -
#pragma mark Button Actions

-(IBAction)btnMovePanelRight:(id)sender {
	UIButton *button = sender;
	switch (button.tag) {
		case 0: {
			[_delegate movePanelToOriginalPosition];
			break;
		}
			
		case 1: {
			[_delegate movePanelRight];
			break;
		}
			
		default:
			break;
	}
}

-(IBAction)btnMovePanelLeft:(id)sender {
	UIButton *button = sender;
	switch (button.tag) {
		case 0: {
			[_delegate movePanelToOriginalPosition];
			break;
		}
			
		case 1: {
			[_delegate movePanelLeft];
			break;
		}
            
		default:
			break;
	}
}


-(IBAction)btnMovePanelDown:(id)sender {
	UIButton *button = sender;
	switch (button.tag) {
		case 0: {
			[_delegate movePanelToOriginalPosition];
			break;
		}
			
		case 1: {
			[_delegate movePanelDown];
			break;
		}
			
		default:
			break;
	}
}

#pragma mark -
#pragma mark Delegate Actions
-(void) topicSelected:(TopicContainer *)tContainer
{
    [self loadTopicContainer:tContainer];
    [_delegate movePanelToOriginalPosition];
}

#pragma mark - Container Management
-(void) loadTopicContainer: (TopicContainer *)topicContainer
{
    
    if (topicContainer == self.topicContainer)
    {
        // Container is already loaded
        return;
    }
    _topicContainer = topicContainer;
    
    _titleLabel.text = topicContainer.title;
    [self.navigationBar setBarTintColor:topicContainer.layoutProperties.primaryColor];
    //self
    
    [self setTopicViewController:topicContainer.topicController];
    
    [self.topicViewController setLayoutProperties:self.topicContainer.layoutProperties ];
}


- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}



@end
