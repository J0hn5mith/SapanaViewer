//
//  HierarchicalListControllerWrapper.m
//  SapanaViewer
//
//  Created by Jan Meier on 17.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Class Definition
#import "HierarchicalListControllerWrapper.h"

// Project Includes
#import "HierarchicalListControllerWrapperImpl.h"
#import "HierarchicalListItemWrapper.h"
#import "Config.h"

// External Includes
#include "ListItemSpv.h"
#include "HierarchicalListItem.h"

@implementation HierarchicalListControllerWrapper
{
    HierarchicalListControllerWrapperImpl * impl;
}

-(id) initWithList: (HierarchicalListControllerWrapperImpl *) list
{
    self = [super init];
    if (self)
    {
        impl = list;
    }
    return self;
}

#pragma mark - List Item Management
-(BOOL) toggleItem:(unsigned long) itemID
{
    BOOL retValue = impl.listController->toggleListItem(itemID);
    impl.listController->refreshItems();
    return retValue;
}

-(BOOL) canMoveToPosition:(unsigned int )oldPosition newPosition:(unsigned int) newPosition
{
    return impl.listController->canMoveToPosition(oldPosition, newPosition);
}

-(void) refreshItems
{
    impl.listController->refreshItems();
}
#pragma mark - UITableViewDataSource

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:
(NSInteger)section{
    return impl.listController->getNumItems();
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:
(NSIndexPath *)indexPath
{
    auto item = impl.listController->getItemAtPosition(indexPath.row);
 // TODO Clean
    
    // Custom Cells
    HierarchicalListItemWrapper * cell = [[HierarchicalListItemWrapper alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"Cell" level_:item.getLevel() expanded_:item.isExpanded() nodeID_:item.getID()];
    
    cell.valueLabel.text = [NSString stringWithCString:item.getLabel().c_str()
                                             encoding:[NSString defaultCStringEncoding]];
    cell.tag = item.getID();
    
    // DBUG
    cell.showsReorderControl = true;
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
