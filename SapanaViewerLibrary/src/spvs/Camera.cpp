//
//  Camera.cpp
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 13.01.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Class definition include
#include "Camera.h"

// External includes

// Project includes


using namespace spvs;
                                                                                
Camera::Camera()
: viewFrustum_(std::make_shared< vmml::frustumf >())
{                                                                               
    
}
Camera::Camera(std::shared_ptr< vmml::frustumf > frustum)
: viewFrustum_(frustum)
{

}
                                                                                
Camera::~Camera()                                      
{                                                                               
  
}
