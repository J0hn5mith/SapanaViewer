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
 * @brief Controller to handle the manipulation of a scene graph.
 */
class SceneGraphController : public spv::IController
{
public:
    
    /**
     * @brief Creates a new SceneGraphController for a scene.
     * @param scene Scene the controller is created for.
     */
    explicit SceneGraphController(std::shared_ptr< spvs::SceneGraph > scene);
    
    /**
     * @brief Deletes an instance of the SceneGraphClass.
     */
    virtual ~SceneGraphController();
    
/** @name Getter and Setter
 *  @{
 */
    /**
     * @brief Returns the controlled scene.
     * @return Scene that is controlled by the controller
     */
    std::shared_ptr< spvs::SceneGraph > getScene(){return scene_;}

/** @} */ // end of getter and Setter */
 
    
    
/** @name Scene Node Management
 *  @brief Methodes for adding, removing and shifting scene nodes
 *  @{
 */
#pragma mark - Scene Node Management
    
    /**
     * @brief Adds a scene node to the scene
     * @param newSceneNode Node that is added
     * @param parentSceneNodeID Node id of the parent node
     * @param name Name of the added scene node
     */
     template < typename T >
    void addSceneNode(T & newSceneNode, spvu::SceneNodeID parentSceneNodeID, std::string name);
    
    
    /**
     * @brief Moves a node to a new parent node.
     *
     * If the node doesn't exist nothing happeg happens.
     * @param childID ID of the node that should be moved
     * @param parentID ID of the parent node
     */
    virtual void moveNode(spvu::SceneNodeID childID, spvu::SceneNodeID parentID);
    
/** @} */ // end of rendering */

    
    
/** @name Scene Node Selecting
 *  @brief Methodes for selcting scene nodes.
 *
 * Selecting scene nodes allows the library user to not to pass around the controller for the selected scene nodes. Hence, it is sufficient to passing around the scene graph controller.
 *  @{
 */
#pragma mark - Scene Node Selecting
    
    /**
     * @brief Selects a scene node by ID.
     *
     * The modifier for the selected scene node can be acessed by the getSelectedSceneNodeController() methode.
     * @param sceneNodeId ID of the selected node
     */
    virtual void selectSceneNode(spvu::SceneNodeID sceneNodeID);
   
    /**
     * @brief Select scene node by const reference.
     * 
     * Uses the version with the id for the actual acess.
     * @param pointer Reference to the node that should be selected.
     **/
    virtual void selectSceneNode(std::shared_ptr< const spvs::SceneNode > pointer);
    
    
    /*
     * @brief Returns the a SceneNodeModifier for the currently selected node. 
     *
     * Returns a SceneNode modifier for the acive scene node. If no node is selected, nullpointer is returned.
     * @return Controller for the selected node
     */
    virtual const std::shared_ptr< spv::SceneNodeController > getSelectedSceneNodeController();
    
    
    /**
     * @brief Select the observer camera node
     *
     * The observer camera is used to render the scene. The modifier for this node returned by the getObserverCameraModifier() method.
     * @param cameraNode Reference to the new observer camera.
     */
    virtual void selectObserverCameraNode(std::shared_ptr< const spvs::CameraNode > cameraNode);
    
    /*
     * @brief Returns a SceneNodeController for the currently selected observer camera.
     *
     * Returns null if the active camera node was not set before.
     */
    virtual const std::shared_ptr< spv::SceneNodeController > getObserverCameraModifier();
    
/** @} */ // end of Scene Node Selecting */
    

    
/** @name Naming Of Scene Nodes
 *  @brief Naming functionality fornaming the various scene nodes.
 *  @{
 */
#pragma mark - Scene Node Naming
    
    /**
     * @brief (Re-) sets the name for a scene node.
     *
     * If the node doesn't exist nothing happens.
     * @param nodeID ID of the renamed node.
     * @param nodeName new name of the node
     */
    virtual void setSceneNodeName(spvu::SceneNodeID nodeID, std::string nodeName);
    
    virtual std::string getNameForNode(unsigned long nodeID);

/** @} */ // end of Naming Of Scene Nodes */
    
    
    
/** @name  IController Interface Implementation
 *  @brief Implementation of the IController interface
 
 *  @{ */

#pragma mark - Implementation of IController Interface
    
    /**
     * \brief Implementation of spv::IController::update()
     */
    virtual void update() const;
    
    
    /**
     * \brief Implementation of spv::IController::getChildController()
     */
    virtual std::vector< std::shared_ptr< const spv::IController > >getChildController() const;
    
/** @} */ // end of Implementation of IController Interface */
    
    
    
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
