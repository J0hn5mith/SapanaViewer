//
//  TestCameraNode.cpp
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 13.01.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Class definition include
#include "TestCameraNode.h"

// External includes

// Project includes
#include "CameraNode.h"
#include "Camera.h"

using namespace spvt;
                                                                                
TestCameraNode::TestCameraNode()
: spvs::CameraNode( std::make_shared< spvs::Camera > (std::make_shared< vmml::frustumf >() ) )
{                                                                               
  // TODO: Implement
    std::shared_ptr< vmml::frustumf > frustum = std::make_shared<vmml::frustumf>();
   frustum->set_perspective(15,1, 0.1f, 100.0f);
    this->getCamera()->setViewFrustum(frustum);
    
    // Set position
    spvu::TransMatrix transformation;
    vmml::identity(transformation);
    transformation[2][3] = -10;
    this->transform(transformation, 0);
}                                                                               
                                                                                
TestCameraNode::~TestCameraNode()                                      
{                                                                               
  // TODO: Implement
}
