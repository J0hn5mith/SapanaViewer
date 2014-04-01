//
//  TopicContainer.m
//  SapanaViewer
//
//  Created by Jan Meier on 04.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#import "TopicContainer.h"


@implementation TopicContainer

+ (TopicContainer * ) initWithControllers:(NSString *)title withTPController:(TopPanelViewController *)tpController withRPController:(RightPanelViewController *)rpController withTController:(TopicViewController *)tController
{
    return [[self alloc] initWithControllers:title withTPController:tpController withRPController:rpController withTController:tController];
}

- (TopicContainer * ) initWithControllers:(NSString *)title withTPController:(TopPanelViewController *)tpController withRPController:(RightPanelViewController *)rpController withTController:(TopicViewController *)tController
{
    if ((self = [super init]))
    {
        _title = title;
        _topController = tpController;
        _rightController = rpController;
        _topicController = tController;
        [self defaultInit];
    }
    
    return self;
}

-(void)defaultInit
{
    _layoutProperties = [TopicLayoutProperties alloc];
    [self.layoutProperties setPrimaryColor: [UIColor blueColor]];
    [self.layoutProperties setSecondaryColor:  [UIColor whiteColor]];
}
@end
