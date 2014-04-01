//
//  SceneGraphController.cpp
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 13.01.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Class definition include
#include "SceneGraphController.h"

// External includes

// Project includes
#include "SceneNodeModifier.h"

using namespace spv;
                                                                                
SceneGraphController::SceneGraphController(std::shared_ptr< spvs::SceneGraph > scene)
: scene_(scene)
, sceneNodeNames_(std::map< spvu::SceneNodeID, std::string >())
{                                                                               
  // TODO: Implement                                     
}                                                                               
                                                                                
SceneGraphController::~SceneGraphController()                                      
{                                                                               
  // TODO: Implement
}

#pragma mark - Scene Node Management
void SceneGraphController::selectSceneNode(std::shared_ptr< const spvs::SceneNode > node)
{
    if (!node) {
        //TODO: Handle exception
    }
    
    selectedNode_ = node;
    
    selectedNodeController_ = std::make_shared<  spv::SceneNodeController >(scene_->getNodeModifier(selectedNode_->getID()));
}

// addSceneNode is implemented in the header file

void SceneGraphController::moveNode(spvu::SceneNodeID childID, spvu::SceneNodeID parentID)
{
    scene_->moveNode(childID, parentID);
}


 #pragma mark - Scene Node Selecting
const std::shared_ptr< spv::SceneNodeController >SceneGraphController::getSelectedSceneNodeController()
{
    return selectedNodeController_;
}

void SceneGraphController::selectSceneNode(spvu::SceneNodeID sceneNodeId)
{
    this->selectSceneNode(scene_->getNode(sceneNodeId));
}

#pragma mark - Implementation of IController Interface
void SceneGraphController::update() const
{
    // TODO: Do some updating
    if (selectedNodeController_ != nullptr )
    {
        selectedNodeController_->update();
    }
}


void SceneGraphController::selectObserverCameraNode(  std::shared_ptr< const spvs::CameraNode > cNode)
{
    std::shared_ptr< const spvs::SceneNode > newObserverCamera = scene_->getNode(cNode->getID());
    if (!newObserverCamera) {
        //TODO: Handle exception
    }
    
    // TODO: Check if it is a camera node
    observerCameraNode_ = newObserverCamera;
    auto cameraModifier = scene_->getNodeModifier(observerCameraNode_->getID());
    observerCameraNodeController_ = std::make_shared<  spv::SceneNodeController >(cameraModifier);
}

const std::shared_ptr<  spv::SceneNodeController > SceneGraphController::getObserverCameraModifier()
{
    return observerCameraNodeController_;
}


#pragma mark - Scene Node Naming
void SceneGraphController::setSceneNodeName(spvu::SceneNodeID nodeID, std::string nodeName)
{
    sceneNodeNames_.insert(std::pair< spvu::SceneNodeID, std::string >{nodeID, nodeName});
}

std::string SceneGraphController::getNameForNode(unsigned long nodeID)
{
    auto nameEntry = sceneNodeNames_.find(nodeID);
    
    if (nameEntry != sceneNodeNames_.end())
    {
        return (*nameEntry).second;
    }
    else
    {
        return "Unnamed Node";
    }
}




