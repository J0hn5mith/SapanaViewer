//
//  ModelList.cpp
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 12.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Class definition include
#include "ModelList.h"

// External includes
#include <vector>
#include <memory>

// Project includes
#include "ListItemSpv.h"
#include "ModelNode.h"

using namespace spvg;
                                                                                
ModelList::ModelList(std::shared_ptr< const spvs::SceneGraph > sceneGraph)
: sceneGraph_(sceneGraph)
, items_(std::vector < ListItemSpv >())
{                                                                               
    std::vector< std::shared_ptr< const spvs::ModelNode > > modelNodes = sceneGraph_->getModelNodes();
    
    std::for_each (modelNodes.begin(), modelNodes.end(),
                   [&](std::shared_ptr< const spvs::ModelNode > node)
                   {
                       std::string name = std::string("Model Node ") + std::to_string(items_.size());
                       items_.push_back(spvg::ListItemSpv(node->getID(), name));
                   }
                   );
}

ModelList::~ModelList()                                      
{                                                                               
  // TODO: Implement
}

void ModelList::update()
{
    
}

std::vector < ListItemSpv > ModelList::getListItems()
{
    return items_ ;
}

unsigned int ModelList::getNumItems()
{
    return ((int)items_.size());
}