//
//  HierarchicalListController.cpp
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 28.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Class definition include
#include "HierarchicalListController.h"
#include "HierarchicalList.h"
// External includes

// Project includes

using namespace spv;
                                                                                
HierarchicalListController::HierarchicalListController(spvg::HierarchicalList * hierarchicalList)
: hierarchicalList_(hierarchicalList)
{                                                                               
  // TODO: Implement                                     
}                                                                               
                                                                                
HierarchicalListController::~HierarchicalListController()                                      
{
}


void HierarchicalListController::expandListItem(spvu::ListItemID listItemID)
{
    hierarchicalList_->expandListItem(listItemID);
}

void HierarchicalListController::collapseListItem(spvu::ListItemID listItemID)
{
    
}

bool HierarchicalListController::toggleListItem(spvu::ListItemID listItemID)
{
    return  hierarchicalList_->toggleListItem(listItemID);
}

bool HierarchicalListController::canMoveToPosition(spvu::ListPosition oldPosition, spvu::ListPosition newPosition)
{
    return hierarchicalList_->canMoveToPosition(oldPosition,newPosition);
}

std::vector < spvg::HierarchicalListItem > HierarchicalListController::getListItems()
{
    return hierarchicalList_->getListItems();
}

spvg::HierarchicalListItem HierarchicalListController::getItemAtPosition(spvu::ListPosition position)
{
    return hierarchicalList_->getListItems().at(position);// TODO: Change
}

spvu::ListSize HierarchicalListController::getNumItems()
{
    return hierarchicalList_->getNumItems();
}

void HierarchicalListController::refreshItems()
{
    hierarchicalList_->update();
}

#pragma mark - Implementation of IController Interface

void HierarchicalListController::update() const
{
    hierarchicalList_->update();
}

std::vector< std::shared_ptr< const spv::IController > > HierarchicalListController::getChildController() const
{
    return std::vector< std::shared_ptr< const spv::IController > >();
}