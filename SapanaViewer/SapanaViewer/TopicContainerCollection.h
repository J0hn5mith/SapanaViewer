//
//  TopicControllerCollection.h
//  SapanaViewer
//
//  Created by Jan Meier on 11.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#import <Foundation/Foundation.h>


// Project Include


#import <OpenGLES/EAGL.h>

// Foreward Declaratoins
@class SapanaViewerWrapper;

@interface TopicContainerCollection : NSObject

#pragma mark - Members
@property (readonly)NSArray * topicContainers;

#pragma mark - Initialisatoin
-(id) initWithSpanaViewerWrapper:(SapanaViewerWrapper *) wrapper eaglContext:(EAGLContext * ) context;

-(UIColor * ) getColorForCategotry:(int) index;
-(UIColor * ) getColorForItemInCategotry:(int) index;
@end
