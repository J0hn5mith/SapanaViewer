/*
 * SceneGraph.cpp
 *
 *  Created on: Dec 12, 2013
 *      Author: janmeier
 */

// Include class definition
#include"SceneGraph.h"

// Project internal includes

#include "RootNode.h"
#include "ModelNode.h"
#include "NodeGraber.h"
#include "CameraNode.h"
#include "SceneNodeModifier.h"

using namespace spvs;

SceneGraph::SceneGraph()
: rootNode_(std::make_shared< spvs::RootNode >())
, nodeGraber_(std::make_shared< NodeGraber >())
, sceneNodes_()
, observableImpl_(std::make_shared< spvu::ObservableImpl >())
{
    //TODO: move this into function
    sceneNodes_.insert({rootNode_->getID(), rootNode_});
}

SceneGraph::~SceneGraph()
{
    // TODO: Implement
}

std::shared_ptr< std::vector< std::shared_ptr< const spvs::ModelNode > > > SceneGraph::getModelNodes() const
{
    return  nodeGraber_->getNodes< spvs::ModelNode >(rootNode_);
}

std::shared_ptr< spvs::SceneNodeModifier > SceneGraph::getNodeModifier(spvu::SceneNodeID nodeID)
{
    auto node = sceneNodes_.at(nodeID);
    return std::make_shared< spvs::SceneNodeModifier >(node);
}

std::shared_ptr< std::vector< std::shared_ptr<  const spvs::CameraNode > > > SceneGraph::getCameraNodes() const
{
    return  nodeGraber_->getNodes< spvs::CameraNode >(rootNode_);
}

void SceneGraph::moveNode( spvu::SceneNodeID childNodeID, spvu::SceneNodeID parentNodeID)
{
    
    std::shared_ptr< spvs::SceneNode > childNode = sceneNodes_.at(childNodeID);
    std::shared_ptr< spvs::SceneNode > parentNode = sceneNodes_.at(parentNodeID);
    std::shared_ptr< spvs::SceneNode > oldParentNode = childNode->getParentNode();
    
    if ( parentNode->getID() == oldParentNode->getID() )
    {
        std::cout << "SceneGraph:: Can't move node because new parent node is the same as the old parent node." << std::endl;
        return;
    }
    
    // DEBUG
    std::cout << "Add node with ID: " << childNode->getID() << " to node with ID: " << parentNode->getID() << ". Previous parent had ID: " << oldParentNode->getID() << std::endl;
    oldParentNode->removeChild(childNode);
    parentNode->addChildNode(childNode);
    childNode->setParentNode(parentNode);
    
    childNode->nodeHasChanged();
    
    notifyObservers(std::make_shared<spvu::NotificationImpl>(NotificationIDs::NODE_MOVED, childNodeID));
}

void SceneGraph::removeNode(std::shared_ptr< const spvs::SceneNode > node)
{
    removeNode(node->getID());
}

void SceneGraph::removeNode(spvu::SceneNodeID nodeID)
{
    if (nodeID == rootNode_->getID())
    {
        // TODO: Handle Exception
        return;
    }
    std::shared_ptr< spvs::SceneNode > removedNode = sceneNodes_.at(nodeID);
    std::shared_ptr< spvs::SceneNode > parentNode = sceneNodes_.at(removedNode->getParentNode()->getID());
    
    for ( auto node : removedNode->getChildNodes() ) //TODO: If children set is changed inside the loop, does that have any influence to the itteration.
    {
        removeNode(node->getID());
    }
    
    parentNode->removeChild(removedNode);
    removedNode->setParentNode(nullptr); // TODO: Should be done by node
    
    notifyObservers(std::make_shared<spvu::NotificationImpl>(NotificationIDs::NODE_DELETED, nodeID));
    
    sceneNodes_.erase(nodeID);
}

std::shared_ptr< const CameraNode > SceneGraph::getActiveCamerNode() const
{
    // TODO: Clean up
    return getCameraNodes()->at(0);
}
