//
//  NodeTransformationsList.cpp
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 13.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Class definition include
#include "NodeTransformationsList.h"

// External includes
#include <vector>
#include <memory>

// Project includes
#include "ListItemSpv.h"
#include "SceneNode.h"

using namespace spvg;

NodeTransformationsList::NodeTransformationsList(std::shared_ptr< const spvs::SceneNode > sceneNode)
: sceneNode_(sceneNode)
, items_(std::vector < ListItemSpv >())
{
    std::list< spvu::TransMatrix > transformations = sceneNode_->getTransformationList();
    
    std::for_each (transformations.begin(), transformations.end(),
                   [&]( spvu::TransMatrix node)
                   {
                       std::string name = std::string("Transformation ") + std::to_string(items_.size() + 1);
                       items_.push_back(spvg::ListItemSpv(1, name));
                   }
                   );
}

NodeTransformationsList::~NodeTransformationsList()
{
    // TODO: Implement
}

void NodeTransformationsList::update()
{
    
}

std::vector < ListItemSpv > NodeTransformationsList::getListItems()
{
    return items_ ;
}

unsigned int NodeTransformationsList::getNumItems()
{
    return ((int)items_.size());
}
