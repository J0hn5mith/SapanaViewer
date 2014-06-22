//
//  SceneRendererManager.cpp
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 08.01.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Class definition
#include "SceneRendererController.h"

// External includes

// Project includes
#include "RenderableScene.h"
#include "SceneRenderer.h"


// DEBUG Includes
#include <iostream>

using namespace spv;
                                                                                
SceneRendererController::SceneRendererController(std::shared_ptr< spvr::RenderableScene > renderableScene,
                                           std::shared_ptr< spvr::SceneRenderer > sceneRenderer)
: renderableScene_(renderableScene)
, sceneRenderer_(sceneRenderer)
{                                                                               
  // TODO: Implement                                     
}                                                                               
                                                                                
SceneRendererController::~SceneRendererController()
{                                                                               
  // TODO: Implement
}

void SceneRendererController::initOpenGL()
{
    sceneRenderer_->init();
}

void SceneRendererController::update() const
{
  renderableScene_->update();

}

std::vector< std::shared_ptr< const spv::IController > > SceneRendererController::getChildController() const
{
    return std::vector< std::shared_ptr< const spv::IController > >();
}

void SceneRendererController::renderScene() const
{
    // DEBUG
    if (sceneRenderer_ == nullptr)
    {
        std::cout << "Scene Renderer is null!!" << std::endl;
    }
    else
    {
        sceneRenderer_->render();
    }
    
}

void SceneRendererController::setViewport(int x, int y, int width, int height)
{
    sceneRenderer_->setViewport(x, y, width, height);
}