//
//  TestSceneRenderer.h
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 07.01.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#ifndef SapanaViewerLibrary_TestSceneRenderer_H_
#define SapanaViewerLibrary_TestSceneRenderer_H_

// Base class includes
#include "SceneRenderer.h"
// External includes

// Project includes

namespace spvt{
  class TestSceneRenderer : public spvr::SceneRenderer
  {    
    public:    
          
    explicit TestSceneRenderer(
                               std::shared_ptr< const spvr::RenderableScene > rScene
                               , std::shared_ptr< spvr::ModelRenderer > modelRenderer
                               , std::shared_ptr< spvr::SceneRendererContext > context );
        virtual ~TestSceneRenderer();
    
    private:
                  
  };
}
#endif /* defined(SapanaViewerLibrary_TestSceneRenderer_H_ */
