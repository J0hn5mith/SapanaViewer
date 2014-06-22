//
//  CSTopicViewController.h
//  SapanaViewer
//
//  Created by Jan Meier on 05.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Import Base Class
#import "TopicViewController.h"

// Import Protocolls
#import "ModelSelectorDelegate.h"
#import "CameraSelectorDelegate.h"
@interface CSTopicViewController : TopicViewController < ModelSelectorDelegate
, CameraSelectorDelegate >

@end
