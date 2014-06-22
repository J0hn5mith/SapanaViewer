//
//  RenderableLightSourceNode.cpp
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 04.04.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Class definition include
#include "RenderableLightSourceNode.h"

// External includes

// Project includes

using namespace spvr;
                                                                                
RenderableLightSourceNode::RenderableLightSourceNode(std::shared_ptr< const spvs::LightSourceNode > lightSourceNode)
: RenderableLeafNode(lightSourceNode)
, lightSourceNode_ (lightSourceNode)
, renderableLightSource_(std::make_shared< spvr::RenderableLightSource >(lightSourceNode->getLightSource()))
{                                                                               
  // TODO: Implement                                     
}                                                                               
                                                                                
RenderableLightSourceNode::~RenderableLightSourceNode()                                      
{                                                                               
  // TODO: Implement
}
