//
//  ListWrapper.m
//  SapanaViewer
//
//  Created by Jan Meier on 11.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Class Definition
#import "ListWrapper.h"

// Project Includes
#import "ListWrapperImpl.h"
#import "Config.h"

// External Includes
#include "ListItemSpv.h"

@implementation ListWrapper
{
     ListWrapperImpl * impl;
};


-(id) initWithList: (ListWrapperImpl *) list
{
    self = [super init];
    if (self)
    {
        impl = list;
    }
    return self;
}

#pragma mark - UITableViewDataSource

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:
(NSInteger)section
{
    return impl.list->getNumItems();
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:
(NSIndexPath *)indexPath
{
    auto item = impl.list->getListItems().at(indexPath.row);
    
    UITableViewCell * cell = [[UITableViewCell alloc] init];
    cell.textLabel.text = [NSString stringWithCString:item.getLabel().c_str()
                                             encoding:[NSString defaultCStringEncoding]];
    cell.tag = item.getID();
    
    // DBUG
    cell.showsReorderControl = true;
    
    cell = [self formatCellText:cell];
    return cell;
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return 1;
}

-(UITableViewCell*) formatCellText:(UITableViewCell*) cell
{
    cell.textLabel.font = TABLE_FONT;
    return cell;
}

@end
