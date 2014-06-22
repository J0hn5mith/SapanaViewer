/*
 * LeafNode.cpp
 *
 *  Created on: Dec 12, 2013
 *      Author: janmeier
 */

#include"LeafNode.h"

using namespace spvs;

LeafNode::LeafNode(SceneNodeType sceneNodeType)
: SceneNode(sceneNodeType)

{
    // TODO: Implement
}

LeafNode::~LeafNode()
{
    // TODO: Implement
}

void LeafNode::addChildNode(SceneNode * childNode)
{
    // TODO: Plot error message
}

void LeafNode::removeChild(spvu::SceneNodeID childPos)
{
    // TODO: Plot error message
}

void LeafNode::nodeHasChanged()
{
    SceneNode::nodeHasChanged();

}
