/*
 * SceneNode.h
 *
 *  Created on: Dec 12, 2013
 *      Author: janmeier
 */

#pragma once
#ifndef SCENENODE_H_
#define SCENENODE_H_

// Base class includes

// External includes
#include <memory.h>
#include <unordered_set>
#include <list>
#include <vector>

// Project includes
#include "Util.h"
#include "TypeDefSpv.h"
#include "SceneNodeProperties.h"

// Project internal includes

/**
 * The scene node base class for all nodes.
 */
namespace spvs{

/**
 * TODO: Documentatoin, enable shared from this
 * Mus be used by a scene graph. Adding and removing children does not set the childs 
 * parent pointer.
 */
class SceneNode
{
public:
    
    enum SceneNodeType
    {
        SCENE_NODE = 0,
        ROOT_NODE = 1,
        FRAME_NODE = 2,
        LEAF_NODE = 3,
        MODEL_NODE = 4,
        CAMERA_NODE = 5,
    };
    
    const std::string SceneNodeTypeNames[6]  = { "Scene Node", "Root Node", "Frame Node", "Leaf Node", "Model Node", "Camera Node" };
    
    explicit SceneNode(SceneNode::SceneNodeType type);

    virtual ~SceneNode();


    
    /**
     * Returne the type of the node
     * @return Type of the node.
     * TODO: Rename
     */
    SceneNodeType getSceneNodeType() const {return sceneNodeType_;}
    
    /**
     * Returns the type of the node as string.
     * @return Name type
     */
    std::string getTypeName() const {return SceneNodeTypeNames[getSceneNodeType()];}
    
    
#pragma mark - Child and Parent Management Methodes
    /**
     * Returns the scene node's parent node. If there is no parent node, null_ptr
     * is returned.(parentNode_)
     * @return The nodes parent node (parentNode_)
     */
     std::shared_ptr< SceneNode > getParentNode() const {return parentNode_;}
    
    /**
     * Returns the scene node's parent node. If there is no parent node, null_ptr
     * is returned.(parentNode_)
     * @return The nodes parent node (parentNode_)
     */
    //std::shared_ptr< SceneNode > getParentNode() const {return parentNode_;} TODO: Remove don't know why its here hope i didn't delete anything important 
    
    /**
     * Returns all nodes between this nodes and the root node (Parent, the parent's parent and so on). The root node is the first node of this list and the last node is the parent.
     * @return The nodes parent node (parentNode_)
     */
    virtual std::list< std::shared_ptr< spvs::SceneNode > > getAncestorNodes() const;

    /**
     * Sets the scene nodes parent node. If the node is a root node
     * this method has no effect.
     *
     * @param newParentNode new parent node
     */
    virtual void setParentNode(std::shared_ptr< SceneNode > newParentNode) {parentNode_ = newParentNode;}

    /**
     * Returns a vector (childNodes_) holding references 
     * to the node's child nodes. If the node is a leaf node
     * this vector will allways be empty.
     * @ Note returns not a pointer for not exposing internals
     * @return Vector holding the scene node's child nodes.
     */
    std::unordered_set< std::shared_ptr< SceneNode > > getChildNodes() const;

    /**
     * Adds a new scene node child to this scene node.
     * If the node is a leaf node this method has no 
     * effect.
     * @warning Does not set the child's parent node.
     * @param childNode the new child scene node
     */
    virtual void addChildNode(std::shared_ptr< SceneNode > childNode);

    /**
     * Removes a SceneNode from the set of child nodes.
     * @warning Does not unsetset the child's parent node.
     * @param childNode Scene node that has to be removed
     */
    virtual void removeChild(std::shared_ptr< SceneNode > childNode);
    
#pragma mark - Transformationlist Management Methodes
    /**
     * Returns a list with all transformation matrices on this node. 
     * The multiplication of them, ergo the trans matrix that defines
     * this node relative to its parent is obtained by getTransMatrix().
     */
    virtual std::list< spvu::TransMatrix > getTransformationList() const ;
    
    /**
     * Adds an identety matrix at the end of the transformationlist.
     */
    virtual void addTransformationMatrix();
    
    /**
     * Removes the transformation matrix at the provided position from the
     * transformation list.
     */
    virtual void shiftTransformationMatrix(int oldPosition, int newPosition);
    
    /**
     * Removes the transformation matrix at the provided position from the
     * transformation list.
     */
    virtual void removeTransformationMatrix(int position);
    
    /**
     * Returns the transformation matrix of the scene node. This transition
     * matrix defines the transition in regard to the world (root node)  coordinates.
     * @deprecated use getWorldTransCoordinates
     * @return
     */
    virtual spvu::TransMatrix getTransMatrix() const;
    
    /**
     * Returns the transformation matrix of the scene node. This transition
     * matrix defines the transition in regard to the world (root node)  coordinates.
     * @return
     */
    virtual spvu::TransMatrix getWorldTransMatrix() const;
    
    /**
     * Returns the transformation matrix of the scene node. This transition
     * matrix defines the transition in regard to the parent node
     * @return
     */
    virtual spvu::TransMatrix getNodeTransMatrix() const;
    
    /**
     * Applies a transformation to the scene node.
     * @param tMatrix Transformation that is applied to the node.
     * @param index Index of the transformation on the transformation list to which the transformation is applied to.
     */
    virtual void transform(const spvu::TransMatrix tMatrix, int index);
    
    
 #pragma mark - Properties Methodes
    /**
     * Returns a scene node properties instance. That instance is not an exact coppy it
     * might contain inherited values.
     */
    virtual spvs::SceneNodeProperties getProperties() const { return properties_;}
    
    /**
     * Sets the nodes properteis
     */
    virtual void setProperties(spvs::SceneNodeProperties properties) { properties_ = properties;}
    
    
  #pragma mark - Update and Change Methodes
    /**
     * Informes the node that it slef or one of his parents parents has
     * changed. Informs the children about this change.
     */
    virtual void nodeHasChanged();
    
    /**
     * Returns whether the node has changed or a parent of the node has
     * changed.
     * @return If the node or a parent node of the node has changed.
     */
    bool hasChanged(){return hasChanged_;}
    
    /**
     * returns the ID of the node. The id of the node is its memory
     * adress. 
     * @warning Because the memory adress of the node is used, this method i
     * not suitable for multithreding!
     * @return id of the node
     */
    spvu::SceneNodeID getID() const {return id_;}
    

private:
    
    /**
     * Type of the scene node.
     */
    SceneNodeType sceneNodeType_;
    
    /**
     * parentNode_ holds a reference to a nodes parent node.
     * If the current node is the root node this is a null_ptr.
     * TODO: make wak pointer 
     */
    std::shared_ptr< SceneNode > parentNode_;

    /**
     * childNodes_ is a vector holding the references to the node's child nodes.
     */
    std::unordered_set< std::shared_ptr< SceneNode > > childNodes_;
    
    /**
     * List of transformations that defines the position of the node
     * regerdint its PARENT node. The matrices are processed in the order
     * they are stored.
     */
    std::list< spvu::TransMatrix > transformationList_;
    
    /**
     * Caches the result when multiplying the transformation matrices in 
     * nodeTransformations_. It defines the nodes transformation regarding its
     * direct parent node.
     */
    spvu::TransMatrix nodeTransMatrix_;
    
    /**
     * Transformation matrix that defines nodes transformation in terms of
     * WORLD coordinates.
     */
    spvu::TransMatrix worldTransMatrix_;
    
    /**
     * Pointer to a scene node proerties instance that holds the properties 
     * of the scenen node.
     */
    spvs::SceneNodeProperties  properties_;
    
    /**
     * Flag that idnicats if the node or a parent node has changed.
     */
    bool hasChanged_;
    
    /**
     * ID for the identification inside a scene graph.
     * 0 by default
     */
    spvu::SceneNodeID id_;
    
    /**
     * Updates the transition matrix of the node.
     */
    void updateWorldTransMatrix();
    
    /**
     * Updates nodeTransMatrix_
     */
    void updateNodeTransMatrix() const;
};

}
#endif /* SCENENODE_H_ */
