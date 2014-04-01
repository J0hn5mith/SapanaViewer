//
//  SceneGraphController.h
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 13.01.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#pragma once
#ifndef SapanaViewerLibrary_SceneGraphController_H_
#define SapanaViewerLibrary_SceneGraphController_H_

// Base Class and Interface Includes
#include "IController.h"

// External includes

// Project includes
#include "TypeDefSpv.h"
#include "SceneNodeController.h"
#include "CameraNode.h"
#include "SceneGraph.h"

namespace spv
{
/**
 * A interface for the usage of Scenes for external program parts.
 * No other class than a SceneNode manager should edit Scene instances
 */
class SceneGraphController : public spv::IController
{
public:
      
    explicit SceneGraphController(std::shared_ptr< spvs::SceneGraph > scene);
    virtual ~SceneGraphController();
    
    
    /**
     * Returns the managed scene.
     */
    std::shared_ptr< spvs::SceneGraph > getScene(){return scene_;}

    
#pragma mark - Scene Node Management
    /**
     * Sets the Scene node that is currently active and modifyable.
     */
    virtual void selectSceneNode(spvu::SceneNodeID sceneNodeId);
    
    /**
     * Adds a scene node to the scene
     * TODO: Fix, error when using this methode, add the node by acessing the scene graph via the getter and set the node name manualy.
     */
     template < typename T >
    void addSceneNode(T & newSceneNode, spvu::SceneNodeID parentSceneNodeID, std::string name);
    
    /**
     * Changes the parent node of a node. If one of the nodeID doesn't exist, nothing
     * happens.
     */
    virtual void moveNode(spvu::SceneNodeID childID, spvu::SceneNodeID parentID);
    
    
#pragma mark - Scene Node Selecting
    /**
     * Sets the Scene node that is currently active and modifyable.
     */
    virtual void selectSceneNode(std::shared_ptr< const spvs::SceneNode > pointer);
    
    /*
     * Returns a SceneNode modifier for the acive scene node. If no node is selected, nullpointer is returned.
     */
    virtual const std::shared_ptr< spv::SceneNodeController > getSelectedSceneNodeController();
    
    /**
     * Sets the camera node that currently is active and can be modi-
     * fyied.
     */
    virtual void selectObserverCameraNode(std::shared_ptr< const spvs::CameraNode > );
    
    /*
     * Returns a SceneNode modifier for the acive camera node. Returns null if the active camera node was not set before.
     */
    virtual const std::shared_ptr< spv::SceneNodeController > getObserverCameraModifier();
    
#pragma mark - Scene Node Naming
    virtual void setSceneNodeName(spvu::SceneNodeID nodeID, std::string nodeName);
    
    virtual std::string getNameForNode(unsigned long nodeID);

#pragma mark - Implementation of IController Interface
    /**
     * Updates the scene manager and all the updateable members (for example 
     * the SceneNodeModifier).
     */
    virtual void update() const;

private:
    std::shared_ptr< spvs::SceneGraph > scene_;

    std::shared_ptr< const spvs::SceneNode > selectedNode_;
    std::shared_ptr< spv::SceneNodeController > selectedNodeController_;

    std::shared_ptr< const spvs::SceneNode > observerCameraNode_;
    std::shared_ptr< spv::SceneNodeController > observerCameraNodeController_;

    std::map< spvu::SceneNodeID, std::string > sceneNodeNames_;
        
  };
    
template < typename T >
void SceneGraphController::addSceneNode( T & newSceneNode, spvu::SceneNodeID parentSceneNodeID, std::string name)
{
    scene_->addNode(parentSceneNodeID, newSceneNode);
    setSceneNodeName(newSceneNode.getID(), name);
}
    
}
#endif /* defined(SapanaViewerLibrary_SceneGraphController_H_ */
