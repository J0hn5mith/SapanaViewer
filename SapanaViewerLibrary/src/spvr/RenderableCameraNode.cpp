//
//  RenderableCameraNode.cpp
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 02.01.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Class definition
#include "RenderableCameraNode.h"

// External includes

// Project includes
#include "CameraNode.h"
#include "RenderableCamera.h"


using namespace spvr;

RenderableCameraNode::RenderableCameraNode(std::shared_ptr< const spvs::CameraNode > cNode)
: RenderableLeafNode(cNode)
, cameraNode_(cNode)
, rCamera_(std::make_shared< RenderableCamera >(cameraNode_->getCamera()))
{
    
}

RenderableCameraNode::~RenderableCameraNode()
{
   
}

 std::shared_ptr< const RenderableCamera > RenderableCameraNode::getRenderableCamera() const
{
    return rCamera_;
}

