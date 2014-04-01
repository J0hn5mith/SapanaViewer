//
//  TestSceneRenderer.cpp
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 07.01.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Class definition include
#include "TestSceneRenderer.h"

// External includes

// Project includes

using namespace spvt;
                                                                                
TestSceneRenderer::TestSceneRenderer(
                                     std::shared_ptr< const spvr::RenderableScene > rScene
                                     , std::shared_ptr< spvr::ModelRenderer > modelRenderer
                                     , std::shared_ptr< spvr::SceneRendererContext > context
                             )
:spvr::SceneRenderer(rScene, modelRenderer, context)
{
	// TODOd: Implement
}



TestSceneRenderer::~TestSceneRenderer()                                      
{                                                                               
  // TODO: Implement
}

