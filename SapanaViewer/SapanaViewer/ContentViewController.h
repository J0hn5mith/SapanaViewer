//
//  ContentViewController.h
//  SapanaViewer
//
//  Created by Jan Meier on 03.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CenterViewController.h"

@interface ContentViewController : UIViewController

#pragma mark - Members
@property EAGLContext * eaglContext;
@property SapanaViewerWrapper * sapanaViewer;
@property TopicContainerCollection * topicContainerCollection;
@end
