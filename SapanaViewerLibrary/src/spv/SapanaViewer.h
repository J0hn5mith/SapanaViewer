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
#include "HierarchicalList.h"
#include "ListController.h"
#include "SceneNodeController.h"
#include "HierarchicalListController.h"

namespace spv{
    
namespace detail
{
    // This addition to the PIMPL pattern allows to use inline method definitions in the actual SapanaViewer  class.
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
 * Main class of the Sapana Viewer.
 */
class SapanaViewer
{    
public:    
      
    explicit SapanaViewer();
    virtual ~SapanaViewer();
    
    /**
     *
     */
    
    void initOpenGL() {impl_->initOpenGL();}
    
    /**
     * Updates everything that currently needs to be updated.
     */
    void update() {impl_->update();}
    
    /**
     * Draws the scene
     */
    void drawScene(){impl_->drawScene();}
    
    
    /**
     * Returns a scene node modifier for the observer camera node
     */
    spv::SceneNodeController * getObserverCameraModifier() {return impl_->getObserverCameraModifier();}
    
    /**
     * Select a scene node. The modifier for this node can be obtained by
     * getSelectedNodeModifier()
     */
    
    void selectSceneNode(spvu::SceneNodeID sceneNodeId) {impl_->selectSceneNode(sceneNodeId);}
    
    /**
     * Reutrns a modifier for the currently selected node.
     */
    spv::SceneNodeController * getSelectedNodeModifier() {return impl_->getSelectedNodeModifier();}
    
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
    
    void moveNode(spvu::SceneNodeID childID, spvu::SceneNodeID parentID) {impl_->moveNode(childID, parentID);}
    
    /**
     * Returns the name for the node with the provided id
     */
    std::string getNameForNode(unsigned long nodeID) {return impl_->getNameForNode(nodeID);}

private:
    detail::ISapanaViewer * impl_;
              
};
}
#endif /* defined(SapanaViewerLibrary_SapanaViewer_H_ */
