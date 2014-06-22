//
//  LightSource.cpp
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 04.04.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Class definition include
#include "LightSource.h"

// External includes

// Project includes

using namespace spvs;
                                                                                
LightSource::LightSource()
: ambient_({0.05, 0.05, 0.05, 1.0})
, difuse_({0.5, 0.5, 0.5, 1.0})
, specular_({0.5, 0.5, 0.5, 1.0})
, cutOff_ (360.0)
{                                                                               
  // TODO: Implement                                     
}                                                                               
                                                                                
LightSource::~LightSource()                                      
{                                                                               
  // TODO: Implement
}
