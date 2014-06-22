//
//  CameraList.cpp
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 10.04.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Class definition include
#include "CameraList.h"

// External includes
#include <vector>
#include <memory>

// Project includes
#include "ListItemSpv.h"
#include "CameraNode.h"


using namespace spvg;
                                                                                
CameraList::CameraList(std::shared_ptr< const spvs::SceneGraph > sceneGraph)
: sceneGraph_(sceneGraph)
, items_(std::vector < ListItemSpv >())
{
    std::vector< std::shared_ptr< const spvs::CameraNode > > cameraNodes = sceneGraph_->getCameraNodes();
    
    
    std::for_each (cameraNodes.begin(), cameraNodes.end(),
                   [&](std::shared_ptr< const spvs::CameraNode > node)
                   {
                       std::string name = std::string("Camera Node ") + std::to_string(items_.size());
                       items_.push_back(spvg::ListItemSpv(node->getID(), name));
                   }
                   );
}
                                                                                
CameraList::~CameraList()                                      
{                                                                               
  // TODO: Implement
}

void CameraList::update()
{
    
}

std::vector < ListItemSpv > CameraList::getListItems()
{
    return items_ ;
}

unsigned int CameraList::getNumItems()
{
    return ((int)items_.size());
}
