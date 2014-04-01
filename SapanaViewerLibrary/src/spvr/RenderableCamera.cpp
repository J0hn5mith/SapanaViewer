//
//  RenderableCamera.cpp
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 14.01.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Class definition include
#include "RenderableCamera.h"

// External includes

// Project includes

using namespace spvr;
                                                                                
RenderableCamera::RenderableCamera(std::shared_ptr< spvs::Camera > camera)
: camera_(camera)
, frustum_(*camera->getViewFrustum())
{                                                                               
  // TODO: Implement                                     
}                                                                               
                                                                                
RenderableCamera::~RenderableCamera()                                      
{                                                                               
  // TODO: Implement
}

std::shared_ptr< const vmml::frustumf > RenderableCamera::getViewFrustum() const
{
    return std::make_shared<vmml::frustumf>(frustum_); // TODO: Does this really makea copy? Same problem as in RenderableLeafNode when returning the TransMatrix.
}