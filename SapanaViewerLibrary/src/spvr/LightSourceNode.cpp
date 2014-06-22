//
//  LightSourceNode.cpp
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 04.04.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Class definition include
#include "LightSourceNode.h"

// External includes

// Project includes

using namespace spvs;
                                                                                
LightSourceNode::LightSourceNode(std::shared_ptr<const spvs::LightSource> lightSource)
: LeafNode(SceneNodeType::LIGHT_SOURCE_NODE)
, lightSource_(lightSource)
{                                                                               
  // TODO: Implement                                     
}                                                                               
                                                                                
LightSourceNode::~LightSourceNode()                                      
{                                                                               
  // TODO: Implement
}
