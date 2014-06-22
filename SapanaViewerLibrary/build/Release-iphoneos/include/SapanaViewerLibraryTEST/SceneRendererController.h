//
//  SceneRendererManager.h
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 08.01.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#pragma once
#ifndef SapanaViewerLibrary_SceneRendererManager_H_
#define SapanaViewerLibrary_SceneRendererManager_H_

// Base class includes
#include "IController.h"
// External includes
#include <memory>

// Project includes

// Forward declaration

namespace spvr {
    class RenderableScene;
    class SceneRenderer;
}

namespace spv{
/**
* Is responsible to invoke the rendering of a scene and manages
* the data, that is rendered.
*/
    class SceneRendererController : public spv::IController
{    
    public:    
    
        explicit SceneRendererController(
                                      std::shared_ptr< spvr::RenderableScene > renderableScene,
                                      std::shared_ptr< spvr::SceneRenderer > sceneRenderer
                                      );
    
        virtual ~SceneRendererController();
    
    void initOpenGL();
    
    
    /**
     * Renders the RenderableScene that is assigned to the SceneRendererManager.
     *
     */
    void renderScene() const;
    
    /**
     * TODO: Doku
     */
    void setViewport(int x, int y, int width, int height);
    

#pragma mark - Implementation IController Interface
    /**
     * Updates the Renderable scene that is currently rendered.
     */
    virtual void update() const;
    
    virtual std::vector< std::shared_ptr< const spv::IController > > getChildController() const;

private:
    
    /**
     * Pointer to the scene that is rendered when invoking the renderScene()
     * method
     */
    std::shared_ptr< spvr::RenderableScene > renderableScene_;
    
    /**
     * Pointer to SceneRenderer that is used to render the scene.
     */
    std::shared_ptr< spvr::SceneRenderer > sceneRenderer_;
    
  };
}
#endif /* defined(SapanaViewerLibrary_SceneRendererManager_H_ */
