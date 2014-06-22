//
//  RenderableLightSource.cpp
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 04.04.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Class definition include
#include "RenderableLightSource.h"

// External includes

// Project includes

using namespace spvr;
                                                                                
RenderableLightSource::RenderableLightSource(std::shared_ptr< const spvs::LightSource > lightSource)
: lightSource_ (lightSource)
{                                                                               
  // TODO: Implement                                     
}                                                                               
                                                                                
RenderableLightSource::~RenderableLightSource()                                      
{                                                                               
  // TODO: Implement
}

#pragma mark - IRenderableData Impl
void RenderableLightSource::update() const
{
    
}