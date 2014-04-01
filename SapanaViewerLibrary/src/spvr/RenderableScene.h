/*
 * RenderableScene.h
 *
 *  Created on: Dec 10, 2013
 *      Author: janmeier
 */

#pragma once
#ifndef RENDERABLESCENE_H_
#define RENDERABLESCENE_H_



// Base class includes
#include "IObserver.h"

// External includes
#include <vector>
#include <map>
#include <memory>

// Project  includes
#include "ObserverImpl.h"
#include "TypeDefSpv.h"

namespace spvs {
    class SceneGraph;
}

namespace spvr {
    class RenderableModel;
    class ModelNode;
    class RenderableCameraNode;
    class RenderableModelNode;
}

namespace spvr{
/**
 * - Renderable representaton of SceneGraph
 * - If SceneData of the RenderableScene is alterd
 *   the RenderableScene is updated automatically
 */
class RenderableScene : public spvu::IObserver
{
public:

    explicit RenderableScene(std::shared_ptr< const spvs::SceneGraph > sceneGraph);

    ~RenderableScene();

    /**
     * Returns all RenderableModelNodes that are used in this scene
     */
    virtual std::shared_ptr< std::vector< std::shared_ptr< const RenderableModelNode > > >  getRenderbaleModelNodes() const;

    /**
    * Returns a renderable scene's camera node, that is currently used to
    * render the scene.
    */
    virtual std::shared_ptr< const RenderableCameraNode > getActiveCameraNode() const;

    /**
    * Returns a vector holding the clear color for the scene
    * TODO: Would a pointer be the better choice? 
    * @return Clear color for the scene as a vector
    */
    virtual std::vector<float> getClearColor() const = 0; // TODO: Implementd in test class
    
    /**
     * Observer implementation
     */
    
    /**
     * @ Implementation
     */
    virtual void notify(std::shared_ptr< const spvu::INotification > notification ) const{ observerImpl_->notify(notification);}
    
    /**
     * @ Implementation
     * Updates the Renderable scene and all associated renderables
     * (RenderableCameraNodes, RenderableModelNodes etc.)
     * A update checks if the model date for the renderable has changed
     * and if true, adjust the renderable's data.
     */
    virtual void update() const;
  
private:

    /**
     * A complete list of all model nodes in the scene graph model.
    */
    std::map< spvu::SceneNodeID, std::shared_ptr< const RenderableModelNode > > renderableModelNodes_;
    
    /**
     * List of currently visible model nodes. This is a subset of renderableModelNodes_.
     */
    std::shared_ptr< std::vector< std::shared_ptr< const RenderableModelNode > > > visibleModelNodes_;

    /**
    * Holds a reference to the SceneData this RenderableScene
    * was created of.
    */
    std::shared_ptr< const spvs::SceneGraph > sceneGraph_;
    
    /**
     * Holds a renderable version of the currently active CameraNode.
     */
    std::shared_ptr < const spvr::RenderableCameraNode > activeCameraNode_;
    
    /**
     * Pointer to the implementation of the observer interface.
     */
    std::shared_ptr< spvu::ObserverImpl > observerImpl_;

    /**
    * Feteches the ModelNodes from the Scene and creates
    * RenderabelModelNodes based on them. The RenderbaleModelnodes
    * are stored in renderableModelNodes_;
    */
    void createRenderableModels();
    
    /**
     * Update (recomputes) the Renderables (renderable camera nodes, model nodes etc.)
     */
    void updateRenderables() const;
    
    /**
     * Handles the ntification in the notifications list
     */
    void handleNotifications();
    
    /**
     * Refills the list of visible modelnodes
     */
    void updateVisibleModelNodes();
};
}

#endif /* RENDERABLESCENE_H_ */
