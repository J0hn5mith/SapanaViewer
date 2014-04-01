//
//  NodeAncestorList.cpp
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 23.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Class definition include
#include "NodeAncestorList.h"

// External includes

// Project includes

using namespace spvg;

NodeAncestorList::NodeAncestorList(std::shared_ptr< const spvs::SceneNode > sceneNode)
: sceneNode_(sceneNode)
, items_(std::vector < ListItemSpv >())
{
    auto ancestors = sceneNode_->getAncestorNodes();
    
    std::for_each (ancestors.begin(), ancestors.end(),
                   [&]( std::shared_ptr < spvs::SceneNode > node)
                   {
                       std::string name = std::string("Node ") + std::to_string(items_.size());
                       items_.push_back(spvg::ListItemSpv(node->getID(), name));
                   }
                   );
}

NodeAncestorList::~NodeAncestorList()
{
    // TODO: Implement
}

void NodeAncestorList::update()
{
    
}

std::vector < ListItemSpv > NodeAncestorList::getListItems()
{
    return items_ ;
}

unsigned int NodeAncestorList::getNumItems()
{
    return ((int)items_.size());
}