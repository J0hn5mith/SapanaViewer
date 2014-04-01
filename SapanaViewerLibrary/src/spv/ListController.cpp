//
//  ListController.cpp
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 01.04.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Class definition include
#include "ListController.h"

// External includes

// Project includes
#include "ListSpv.h"
#include "ListItemSpv.h"
using namespace spv;
                                                                                
ListController::ListController(spvg::ListSpv * list)
: list_(list)
{                                                                               
  // TODO: Implement                                     
}                                                                               
                                                                                
ListController::~ListController()                                      
{                                                                               
  // TODO: Implement
}

std::vector < spvg::ListItemSpv > ListController::getListItems()
{
    return list_->getListItems();
}

spvu::ListSize ListController::getNumItems()
{
    return list_->getNumItems();
}

#pragma mark - Implementation of IController Interface
void ListController::update() const
{
    
}