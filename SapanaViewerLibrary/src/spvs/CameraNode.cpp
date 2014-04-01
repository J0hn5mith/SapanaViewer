//
//  CameraNode.cpp
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 13.01.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Class definition include
#include "CameraNode.h"

// External includes

// Project includes
#include "Camera.h"
using namespace spvs;

CameraNode::CameraNode(std::shared_ptr< Camera > camera)
: LeafNode(SceneNodeType::CAMERA_NODE)
, camera_(camera)
{
    
}
                                                                                
CameraNode::~CameraNode()                                      
{                                                                               

}
