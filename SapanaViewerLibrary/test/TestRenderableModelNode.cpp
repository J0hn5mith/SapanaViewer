//
//  TestRenderableModelNode.cpp
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 29.12.13.
//  Copyright (c) 2013 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Class definition include
#include "TestRenderableModelNode.h"

// External includes

// Project includes
#include "TestModelNode.h"

using namespace spvt;

TestRenderableModelNode::TestRenderableModelNode()
: RenderableModelNode(std::make_shared< const TestModelNode >())
{
    
}

TestRenderableModelNode::~TestRenderableModelNode()
{
    
}

