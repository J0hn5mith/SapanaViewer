//
//  TestRenderableScene.cpp
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 20.12.13.
//  Copyright (c) 2013 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Project includes
#include "TestRenderableScene.h"
#include "TestSceneData.h" 
#include "TestRenderableModelNode.h"
#include "TestRenderableCameraNode.h"
#include "RenderableModelNode.h"

// Test includes
#include <iostream>
#include <memory>
#include "TestCameraNode.h"

using namespace spvt;

TestRenderableScene::TestRenderableScene(std::shared_ptr< spvs::SceneGraph > sceneData)
: spvr::RenderableScene(sceneData)
, testColor_()
{
    testColor_.resize(4);
    testColor_.clear();
    testColor_.push_back(1.0); // Set color to redish
    testColor_.push_back(1.0);
    testColor_.push_back(1.0);
    testColor_.push_back(1);
}

TestRenderableScene::~TestRenderableScene()
{
}
//
//
//std::shared_ptr<const spvr::RenderableCameraNode> TestRenderableScene::getActiveCameraNode() const
//{
//    return testActiveCameraNode_;
//}

std::vector<float> TestRenderableScene::getClearColor() const
{
    return testColor_;
}
