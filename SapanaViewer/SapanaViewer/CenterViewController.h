//
//  CenterViewController.h
//  SapanaViewer
//
//  Created by Jan Meier on 03.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LeftPanelViewController.h"
#import "RightPanelViewController.h"
#import "TopPanelViewController.h"

@protocol CenterViewControllerDelegate <NSObject>

@optional
- (void)movePanelLeft;
- (void)movePanelRight;
- (void)movePanelDown;

@required
- (void)movePanelToOriginalPosition;

@end

@interface CenterViewController : UIViewController <LeftPanelViewControllerDelegate, RightPanelViewControllerDelegate, TopPanelViewControllerDelegate>

// Initialization
- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil eaglContext:(EAGLContext *) context;

// Members
@property (nonatomic, assign) id< CenterViewControllerDelegate > delegate;
@property EAGLContext * eaglContext;
@property (nonatomic) SapanaViewerWrapper * sapanaViewer;

#pragma mark - Topic Container and View
@property (nonatomic, strong) IBOutlet TopicContainer *topicContainer;
@property (nonatomic, strong) IBOutlet TopicViewController *topicViewController;
@property (nonatomic, strong) IBOutlet UIView *topicViewContainer;

#pragma mark - GUI Elements
@property (weak, nonatomic) IBOutlet UINavigationBar *navigationBar;
@property (weak, nonatomic) IBOutlet UILabel *titleLabel;
@property (nonatomic, weak) IBOutlet UIButton *leftButton;
@property (nonatomic, weak) IBOutlet UIButton *rightButton;
@property (nonatomic, weak) IBOutlet UIButton *topButton;

#pragma mark - Container Management
-(void) loadTopicContainer: (TopicContainer *)topicContainer;

@end
