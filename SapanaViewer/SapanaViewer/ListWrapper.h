//
//  ListWrapper.h
//  SapanaViewer
//
//  Created by Jan Meier on 11.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#import <Foundation/Foundation.h>
// Forward declaration
@class ListWrapperImpl;
@class SceneNodeModifierImpl;

@interface ListWrapper : NSObject < UITableViewDataSource >
-(id) initWithList: (ListWrapperImpl *) list;
@end
