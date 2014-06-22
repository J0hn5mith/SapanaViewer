//
//  SapanaViewer.h
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 03.01.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#pragma once
#ifndef SapanaViewerLibrary_SapanaViewer_H_
#define SapanaViewerLibrary_SapanaViewer_H_

// Base class includes


// External includes


// Project includes
//#include "HierarchicalList.h"
#include "ListController.h"
#include "SceneNodeController.h"
#include "HierarchicalListController.h"

namespace spv{
    
namespace detail
{
    /**
     * @brief Interface for the private implementation of the spv::SapanaViewer class.
     */
    class ISapanaViewer{
    public:
        
        virtual void initOpenGL() = 0;
        virtual void update() = 0;
        virtual void drawScene() = 0;
        virtual spv::SceneNodeController * getObserverCameraModifier() =0;
        virtual void selectSceneNode(spvu::SceneNodeID sceneNodeId) = 0;
        virtual spv::SceneNodeController * getSelectedNodeModifier() = 0;
        virtual spv::ListController * getFlatModelList() = 0;
        virtual spv::HierarchicalListController * getHierarchicalModelListController() = 0;
        virtual spv::ListController * getFlatCameraList() = 0;
        virtual void moveNode(spvu::SceneNodeID childID, spvu::SceneNodeID parentID) = 0;
        
        virtual std::string getNameForNode(unsigned long nodeID) = 0;
    };
    
}
    
/**
 * \brief Main access class of the Sapana Viewer library.
 
 * The sapana viewer class is the main class of the sapana viewer library. The
 * update methodes must be called regularly or at least before accessing any 
 * data or calling a rendering methode.\r
 * Is implemented using the PIMPLE idiom.
 */
class SapanaViewer
{    
public:

#pragma mark - Constructor and Destructors
    
    /**
     * Creates a new instance of the Sapana Viewer.
     */
    explicit SapanaViewer();
    
    /**
     * Deletes an instance of the Sapana Viewer.
     */
    virtual ~SapanaViewer();

    
    
/** @name Rendering
 *  Methodes that are related to the rendering of the scene.
 *  @{
 */
#pragma mark - Rendering Related Methodes
    
    /**
     * Initialisees the OpenGL components of the Sapana Viewer Library
     */
    void initOpenGL() {impl_->initOpenGL();}
    
    /**
     * Draws the currently active scene.
     */
    void drawScene(){impl_->drawScene();}
    
/** @} */ // end of rendering */
    
    

/** @name State Manipulation
 *  Methodes that are related to the internal state of the sapana viewer. They are used
 * for things lie seleting scene nodes, cameras or invoking the update process.
 *  @{
 */
#pragma mark - State Manipulation
    
    /**
     * Updates the internals of the Sapana Viewer Library. Must be called before 
     * rendering anything or accessing any data.
     */
    void update() {impl_->update();}
    
    /**
     * Returns a scene node modifier for the observer camera node. The observer camera is used to render the scene.
     * @return Controller for the observer camera.
     */
    spv::SceneNodeController * getObserverCameraModifier() {return impl_->getObserverCameraModifier();}
    
    /**
     * Select a scene node of the active scene graph. The SceneNodeController for the selected node
     * can be obtained by the getSelectedNodeModifier() methode.
     * @param sceneNodeId ID of the newly selected node.
     */
    void selectSceneNode(spvu::SceneNodeID sceneNodeId) {impl_->selectSceneNode(sceneNodeId);}
    
    /**
     * Reutrns a modifier for the currently selected node. A node can be selected by the selectSceneNode()
     * method.
     * @return Controller for the selected secnen node.
     */
    spv::SceneNodeController * getSelectedNodeModifier() {return impl_->getSelectedNodeModifier();}
    
    /**
     * Sets a new parent for a node in the scene graph.
     */
    void moveNode(spvu::SceneNodeID childID, spvu::SceneNodeID parentID) {impl_->moveNode(childID, parentID);}
    
/** @} */ // end of internal state */
    
    
    
/** @name GUI Abstraction Accessors
 *  Methodes that are used to get controllers for the GUIAbstractions that aggregate data about the scene.
 *  @{
 */
#pragma mark - State Manipulation
    
    /**
     * Returns a flat list of allt models in the scene.
     */
    spv::ListController * getFlatModelList() {return impl_->getFlatModelList();}
    
    /**
     * Returns a hierarchical list of all models in the scene. Also contains frame entries.
     */
    spv::HierarchicalListController * getHierarchicalModelListController(){return impl_->getHierarchicalModelListController();}
    
    /**
     * Returns a flat list of all cameras in the scene. 
     */
    spv::ListController * getFlatCameraList(){ return impl_->getFlatCameraList();}
    
/** @} */ // end of GUI Abstraction Accessors */
    
    
    
    /**
     * Returns the name for the node with the provided id
     */
    std::string getNameForNode(unsigned long nodeID) {return impl_->getNameForNode(nodeID);}

private:
    
    /**
     * Pointer to the private implementation. \see PIMPLE Idiom
     */
    detail::ISapanaViewer * impl_;
              
};
}
#endif /* defined(SapanaViewerLibrary_SapanaViewer_H_ */
