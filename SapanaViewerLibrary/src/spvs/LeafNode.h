/*
 * LeafNode.h
 *
 *  Created on: Dec 12, 2013
 *      Author: janmeier
 */

#pragma once
#ifndef LEAFNODE_H_
#define LEAFNODE_H_

// Base class includes
#include "SceneNode.h"

// External includes
#include<vector>
#include <memory.h>

// Project internal includes


namespace spvs{
/**
 * Leaf nodes are the leafs of a scene graph. Because they are the leafs,
 * they don't have any child nodes.
 */
    class LeafNode: public SceneNode
{
public:
    explicit LeafNode(SceneNodeType sceneNodeType);

    virtual ~LeafNode();

    
#pragma mark - Overrides of SceneNode Methodes
    /**
    * @ Override
    *  Disables the adding of childs
    * @param childNode
    */
    virtual void addChildNode(SceneNode * childNode);

    /**
    * @ Override
    * Disables child removal. 
    */
    virtual void removeChild(spvu::SceneNodeID childPos);

    /**
    * @Override
    * Observers are also informed about change
    */
    virtual void nodeHasChanged();
  
  
private:

};

}

#endif /* LEAFNODE_H_ */
