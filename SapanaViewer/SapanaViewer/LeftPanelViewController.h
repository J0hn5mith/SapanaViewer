//
//  LeftPanelViewController.h
//  SapanaViewer
//
//  Created by Jan Meier on 03.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Project includes
#import "TopicContainer.h"
#import "TopicContainerCollection.h"

// External includes
#import <UIKit/UIKit.h>

@protocol LeftPanelViewControllerDelegate <NSObject>

@optional


@required
-(void) topicSelected:(TopicContainer * )tContainer;

@end

@interface LeftPanelViewController : UIViewController

// Initialization
- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil eaglContext:(EAGLContext *) context;


// Members
@property EAGLContext * eaglContext;
@property (nonatomic)TopicContainerCollection * topicContainerCollection;
@property (readonly)NSArray * arrayOfTopicContainers;

// Delegates
@property (nonatomic, assign) id< LeftPanelViewControllerDelegate > delegate;

@end
