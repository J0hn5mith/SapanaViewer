/*
 * SceneRenderer.h
 *
 *  Created on: Dec 10, 2013
 *      Author: janmeier
 */

#pragma once
#ifndef SCENERENDERER_H_
#define SCENERENDERER_H_

// Base class includes
#include "IRenderer.h"

// External includes
#include <memory>

// Project internal includes
namespace spvr {
    class RenderableScene;
    class SceneRendererContext;
    class ModelRenderer;
    class LightSourceNodeRenderer;
    class SceneNodeRenderer;
}

        
namespace spvr{

/**
 * Renders a RenderableScene.
 */

class SceneRenderer : public IRenderer
{
public:

#pragma mark - Con- & Destructors
    /**
    * @ Note: context has no use so far.
    */
    SceneRenderer(
                  std::shared_ptr< const  RenderableScene > rScene
                  , std::shared_ptr< ModelRenderer > modelRenderer
                  , std::shared_ptr< LightSourceNodeRenderer > lightSourceRenderer
                  , std::shared_ptr< SceneNodeRenderer > frameNodeRenderer
                  , std::shared_ptr< SceneRendererContext > context
                  
               );

    ~SceneRenderer();

#pragma mark - Getter and Setter Methodes
    /**
    * Returns the SceneRendererContext associated that defines the
    * behaviour of the scene renderer.
    **/
    virtual const std::shared_ptr< SceneRendererContext > getSceneRendererContext() const {return sceneRendererContext_;}

    // Implementation of IRenderer


    /**
    * @ Implementation
    */
    virtual void setViewport(GLint x, GLint y, GLint width, GLint height) const;

    /**
    * @ Implementation
    */
    virtual void init() const;
    
    /**
     * @ Implementation
     */
    virtual void render() const;


private:
    
#pragma mark - Private Member Variables
    std::shared_ptr< const RenderableScene > rScene_;
    
    /**
    * Model renderer which is used by this scene renderer to
    * render the models.
    *  * TODO: Clear who is the owner of this object!
    */
    std::shared_ptr< ModelRenderer >  modelRenderer_;

    std::shared_ptr< LightSourceNodeRenderer >  lightSourceRenderer_;
    
    std::shared_ptr< SceneNodeRenderer >  frameNodeRenderer_;
    /**
    * Scene renderer context used by the scene renderer.
    * TODO: Clear who is the owner of this object!
    */
    std::shared_ptr< SceneRendererContext > sceneRendererContext_;
    
    GLuint depthRenderBuffer_;

#pragma mark - Private Methodes
    virtual void setUpOpenGL(std::shared_ptr < const RenderableScene > renderableScene) const;
    
    virtual void setUpDepthBuffer() const;
    /**
    * Sets up to projection matrix that is used to render the scene. 
    */
    void setProjection(std::shared_ptr < const RenderableScene > renderableScene) const;

    /**
    * Sets the position of the virual camera
    */
    void setCameraPosition(std::shared_ptr < const RenderableScene > renderableScene) const;

    /**
    * Clears the depth and color buffer.
    */
    void clearScreen(std::shared_ptr < const RenderableScene > renderableScene) const;
    
    void drawWorldPlane() const;
    /**
    * Renders the modles of the associated RenderableScene. To 
    * render the model the modelRenderer_ is used. 
    */
    void renderModels(std::shared_ptr < const RenderableScene > renderableScene) const;
    
    void renderLightSources(std::shared_ptr < const RenderableScene > renderableScene) const;
    
    void renderFrameNodes(std::shared_ptr < const RenderableScene > renderableScene) const;
};
}


#endif /* SCENERENDERER_H_ */
