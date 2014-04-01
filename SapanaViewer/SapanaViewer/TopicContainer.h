//
//  TopicContainer.h
//  SapanaViewer
//
//  Created by Jan Meier on 04.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Project includes
#import "TopPanelViewController.h"
#import "RightPanelViewController.h"
#import "TopicViewController.h"

#import "TopicLayoutProperties.h"

// External Includes
#import <Foundation/Foundation.h>

@interface TopicContainer : NSObject
+ (TopicContainer * ) initWithControllers:(NSString *)title withTPController:(TopPanelViewController *)tpController withRPController:(RightPanelViewController *)rpController withTController:(TopicViewController *)tController;

- (TopicContainer * ) initWithControllers:(NSString *)title withTPController:(TopPanelViewController *)tpController withRPController:(RightPanelViewController *)rpController withTController:(TopicViewController *)tController;


# pragma mark - Sub Controller
@property (nonatomic, copy) TopPanelViewController * topController;
@property (nonatomic, copy) RightPanelViewController * rightController;
@property (nonatomic, copy) TopicViewController * topicController;

#pragma mark - Info and Layout
@property (nonatomic, copy) NSString *title;
@property TopicLayoutProperties * layoutProperties;
@end

