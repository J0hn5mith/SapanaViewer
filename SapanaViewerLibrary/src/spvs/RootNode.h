/*
 * RootNode.h
 *
 *  Created on: Dec 12, 2013
 *      Author: janmeier
 */

#pragma once
#ifndef ROOTNODE_H_
#define ROOTNODE_H_


// Base class includes
#include "SceneNode.h"

// External includes

// Project internal includes

namespace spvs{
class RootNode : public SceneNode
{
public:
    explicit RootNode();

    ~RootNode();

    /**
     * Overrides the parents method. Root nodes don't have
     * a parent and therefore it can't be one.
     * @param sceneNode
     */
    virtual void setParentNode(std::shared_ptr<SceneNode *> sceneNode);

    /**
     * Overrides the parent's method. Root nodes don't have
     * a parent and therefore can't return one.
     * @return
     */
    virtual std::shared_ptr<SceneNode *> getParent();

private:

};
}

#endif /* ROOTNODE_H_ */
