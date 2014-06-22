/*
 * FrameNode.h
 *
 *  Created on: Dec 12, 2013
 *      Author: janmeier
 */

#pragma once
#ifndef FRAMENODE_H_
#define FRAMENODE_H_

// External includes

// Base class includes
#include "SceneNode.h"

// Project internal includes

namespace spvs{
class FrameNode : public SceneNode
{
/**
 * A scene graph node that is th parent of other nodes.
 */
public:
    
    /**
     * Constructs a new frame node object.
     */
    explicit FrameNode();
    
    explicit FrameNode(void * dummyPtr);
    
    /**
     * Destroys the frame node object.
     */
    virtual ~FrameNode();

private:

};
}



#endif /* FRAMENODE_H_ */
