//
//  TopicControllerCollection.m
//  SapanaViewer
//
//  Created by Jan Meier on 11.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#import "TopicContainer.h"
#import "TopicContainerCollection.h"
#import "ModelingTopicViewController.h"
#import "TransformationTopicViewController.h"
#import "CSTopicViewController.h"
#import "HMTopicViewController.h"
#import "SapanaViewerWrapper.h"
#import "Util.h"

@implementation TopicContainerCollection

-(id)init
{
    if (self = [super init])
    {

    }
    return self;
}

-(id) initWithSpanaViewerWrapper:(id) wrapper eaglContext:(EAGLContext * ) context
{
    self = [self init];
    if(self)
    {
        
        TopicContainer * modelling = [TopicContainer initWithControllers: @"Modelling" withTPController:NULL withRPController:NULL withTController:[[ModelingTopicViewController alloc] initWithNibName:@"TopicViewController" bundle:nil ]];
        
        [modelling.layoutProperties setPrimaryColor: [Util colorFromIntRGB:82  green:168 blue:252 alpha:255]];

        [modelling.layoutProperties setSecondaryColor:[Util colorFromIntRGB:218  green:246 blue:254 alpha:100]];
        
        TopicContainer * transformation = [TopicContainer initWithControllers: @"Transformation" withTPController:NULL withRPController:NULL withTController:[[TransformationTopicViewController alloc] initWithNibName:@"TopicViewController" bundle:nil]];
        
        [transformation.layoutProperties setPrimaryColor: [Util colorFromIntRGB:82  green:168 blue:252 alpha:255]];
        
        [transformation.layoutProperties setSecondaryColor:[Util colorFromIntRGB:218  green:246 blue:254 alpha:255]];
        
        TopicContainer * coordinateSystems = [TopicContainer initWithControllers: @"Coordinate Systems" withTPController:NULL withRPController:NULL withTController:[[CSTopicViewController alloc] initWithNibName:@"TopicViewController" bundle:nil]];
        
        [coordinateSystems.layoutProperties setPrimaryColor: [Util colorFromIntRGB:82  green:168 blue:252 alpha:255]];
        
        [coordinateSystems.layoutProperties setSecondaryColor:[Util colorFromIntRGB:218  green:246 blue:254 alpha:255]];
        
        TopicContainer * hierarchicalModelling = [TopicContainer initWithControllers: @"Hierachical Modelling" withTPController:NULL withRPController:NULL withTController:[[HMTopicViewController alloc] initWithNibName:@"TopicViewController" bundle:nil]];
        
        [hierarchicalModelling.layoutProperties setPrimaryColor: [Util colorFromIntRGB:82  green:168 blue:252 alpha:255]];
        
        [hierarchicalModelling.layoutProperties setSecondaryColor:[Util colorFromIntRGB:218  green:246 blue:254 alpha:255]];
        
        
        _topicContainers = @[
                             modelling
                             , transformation
                             , coordinateSystems
                             , hierarchicalModelling
                             
                             ];
    }
    return self;
}

-(UIColor * ) getColorForCategotry:(int) index;
{
    return [Util colorFromIntRGB:82  green:168 blue:252 alpha:255];
}

-(UIColor * ) getColorForItemInCategotry:(int) index;
{
    return [Util colorFromIntRGB:218  green:246 blue:254 alpha:255];
}
@end
