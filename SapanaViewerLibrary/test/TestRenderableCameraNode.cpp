//
//  TestRenderableCameraNode.cpp
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 02.01.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Class definition include
#include "TestRenderableCameraNode.h"

// External includes

// Project includes
#
using namespace spvt;
                                                                                
TestRenderableCameraNode::TestRenderableCameraNode(std::shared_ptr< spvs::CameraNode > cNode)
: spvr::RenderableCameraNode(cNode)
{
  // Select the projection matrix.
}
                                                                                
TestRenderableCameraNode::~TestRenderableCameraNode()                                      
{
    
}
