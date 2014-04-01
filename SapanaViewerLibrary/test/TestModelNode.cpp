//
//  TestModelNode.cpp
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 29.12.13.
//  Copyright (c) 2013 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Class definition include
#include "TestModelNode.h"

// External includes

// Project includes
#include "CubeData.h"
#include "TestNotificationImpl.h"


#define PI 3.14159265

using namespace spvt;

TestModelNode::TestModelNode()
: spvs::ModelNode(std::make_shared<const spvt::CubeData>( ))
{

}

TestModelNode::~TestModelNode()
{
}

