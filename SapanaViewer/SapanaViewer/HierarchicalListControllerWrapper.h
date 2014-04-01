//
//  HierarchicalListControllerWrapper.h
//  SapanaViewer
//
//  Created by Jan Meier on 17.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Project Includes

// External Includes
#import <Foundation/Foundation.h>

// Forward declaration
@class HierarchicalListControllerWrapperImpl;

@interface HierarchicalListControllerWrapper : NSObject  < UITableViewDataSource >
-(id) initWithList: (HierarchicalListControllerWrapperImpl *) list;

-(BOOL) toggleItem:(unsigned long) itemID;
-(BOOL) canMoveToPosition:(unsigned int )oldPosition newPosition:(unsigned int) newPosition;
-(void) refreshItems;
@end
