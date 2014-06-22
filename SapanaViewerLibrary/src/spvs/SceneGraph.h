/*
 * SceneGraph.h
 *
 *  Created on: Dec 12, 2013
 *      Author: janmeier
 */

#pragma once
#ifndef SCENEGRAPH_H_
#define SCENEGRAPH_H_

// Base class includes
#include "IObservable.h"

// External includes
#include <vector>
#include <memory>
#include <unordered_map>


// Project internal includes
#include "SceneNode.h"
#include "CameraNode.h"
#include "ObservableImpl.h"

// Foreward declarations
namespace spvs {
    class SceneNodeModifier;
}

namespace spvs {
    class RootNode;
    class ModelNode;
    class NodeGraber;
    class CameraNode;
    class LightSourceNode;
    class FrameNode;
}

namespace spvs{
/**
 * TODO: Dokumentation, think about restrictions for ode use( Can nodes be inserted more than once? )
 * TODO: The scene graph should only return const pointers to the node to
 * ensure data sonsistency
 */
class SceneGraph : public spvu::IObservable
{
public:
    explicit SceneGraph();

    ~SceneGraph();


    
    
#pragma mark - Node Acessors
    /**
     * Returns the root node of the scene graph.
     * @return Root node of scene graph.
     */
    std::shared_ptr< const RootNode > getRootNode() const {return rootNode_;}
    
    /**
     * Returns a arbitrary node from the scene graph.
     * @param nodeID the id of the requested node.
     * @return pointer to the requested node, null if node id is inexistent. 
     */
    std::shared_ptr< const SceneNode >getNode(spvu::SceneNodeID nodeID) const { return sceneNodes_.at(nodeID); }
    
    /**
     * Returns a modifyier for a node inside the scene graph.
     * @param nodeID ID of the SceneNode
     * @return SceneNodeModifier for the node with id nodeID.
     */
    virtual std::shared_ptr< spvs::SceneNodeModifier > getNodeModifier(spvu::SceneNodeID nodeID);

    
#pragma mark - Acessors for nodes of a certain type
    /**
     * Returns all model nodes of the scene graph
     */
    std::vector< std::shared_ptr< const spvs::ModelNode > >getModelNodes() const;
    
    /**
     * Returns all camera nodes of the scene graph
     */
    std::vector< std::shared_ptr< const spvs::CameraNode > >getCameraNodes() const;
    
    /**
     * Returns all light source nodes of the scene graph
     */
    std::shared_ptr< std::vector< std::shared_ptr< const spvs::LightSourceNode > > >getLightSourceNodes() const;
    
    std::vector< std::shared_ptr< const spvs::FrameNode > > getFrameNodes() const;
    
    
#pragma mark - Node Management
    /**
     * Adds a scene node to the scene graph.
     * @param parentNode pointer to the parent node
     * @param childNode added node
     * @return id of the added node. 
     */
    template < typename T >// TODO: Doku
    int addNode(std::shared_ptr< const spvs::SceneNode > parentNode,  T & node);
    
    /**
     * Adds a scene node to the scene graph.
     * @param parentNode pointer to the parent node
     * @param childNode added node
     * @return id of the added node.
     */
    template < typename T > // TODO: Doku
    int addNode(spvu::SceneNodeID parentNodeID,  T & node);
    
    
    /**
     * Moves the childe node to a new parent node.
     */
    void moveNode( spvu::SceneNodeID childNodeID, spvu::SceneNodeID parentNodeID);
    /**
     * Remove a node from the scene graph. Also removes all the node's child nodes.
     * @param node node that is removed from the scene graph.
     */
    void removeNode(std::shared_ptr< const spvs::SceneNode > node);
    
    /**
     * Remove a node from the scene graph. Also removes all the node's child nodes.
     * @param node node that is removed from the scene graph.
     */
    void removeNode(spvu::SceneNodeID nodeID);
    
    
    /**
     * Returns the camera node that is currently active in the scene.
     * TODO: Use const?
     */
    virtual std::shared_ptr< const CameraNode > getActiveCamerNode() const;
    
    /**
     * Implementation of the IObservable interface
     */
    
    enum NotificationIDs
    {
        NEW_NODE = 0,
        NODE_DELETED = 1,
        ACTIV_CAMERA_CHANGED = 2,
        NODE_MOVED = 3
    };
 
#pragma mark - IObservable Implementation
    /**
     * @ Implementation
     */
    virtual void notifyObservers(std::shared_ptr<const spvu::INotification > notification) const{observableImpl_->notifyObservers(notification);}
    
    /**
     * @ Implementation
     */
    virtual void registerObserver(std::shared_ptr< spvu::IObserver >observer) const {observableImpl_->registerObserver(observer);}
    
    /**
     * @ Implementation
     */
    virtual void unregisterObserver(std::shared_ptr< spvu::IObserver > observer) const{observableImpl_->unregisterObserver(observer);}
  
    
    
private:

    /**
     * Holds the root node of the scene graph.
     */
    std::shared_ptr< RootNode > rootNode_;
    
    /**
     * Camera node that is used to render the scene.
     */
    std::shared_ptr< CameraNode > activeCameraNode_;
    
    /**
     * Pointer to a NodeGraber
     * TODO: Is this necessary or can is just create them on demand
     */
    std::shared_ptr< spvs::NodeGraber > nodeGraber_;
    
    /**
     * Unordered map that stores all scene nodes that are used in the
     * scene graph.
     */
    std::unordered_map< spvu::SceneNodeID, std::shared_ptr< spvs::SceneNode > > sceneNodes_;
    
    /**
     * Implementation for the IObservable interface
     */
    std::shared_ptr< spvu::ObservableImpl > observableImpl_;
    
};
    
template < typename T >
int SceneGraph::addNode(spvu::SceneNodeID parentNodeID,  T & node)
{
    std::shared_ptr< spvs::SceneNode > newNode = std::make_shared< T > (node);
    std::shared_ptr< spvs::SceneNode > parentNode = sceneNodes_.at(parentNodeID);
    
    sceneNodes_.insert({newNode->getID(), newNode} );
    
    parentNode->addChildNode(newNode);
    newNode->setParentNode(parentNode);
    
    notifyObservers(std::make_shared<spvu::NotificationImpl>(NotificationIDs::NEW_NODE, newNode->getID()));
    
    return newNode->getID();
}
  
template < typename T >
int SceneGraph::addNode(std::shared_ptr< const spvs::SceneNode > parentNode,  T & node)
{
    return addNode(parentNode->getID(), node);
}

}
#endif /* SCENEGRAPH_H_ */
