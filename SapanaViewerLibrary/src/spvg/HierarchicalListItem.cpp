//
//  HierarichcalListItem.cpp
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 17.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Class definition include
#include "HierarchicalListItem.h"

// External includes

// Project includes

using namespace spvg;
                                                                                
HierarchicalListItem::HierarchicalListItem(spvu::ListItemID itemID, std::string label, bool expanded, bool expandable, unsigned int level)
: ListItemSpv (itemID, label)
, isExpanded_(expanded)
, isExpandedable_(expandable)
, level_(level)
{                                                                               
  // TODO: Implement                                     
}                                                                               
                                                                                
HierarchicalListItem::~HierarchicalListItem()
{                                                                               
  // TODO: Implement
}
