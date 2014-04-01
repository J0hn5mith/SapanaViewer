/*
 * RootNode.cpp
 *
 *  Created on: Dec 12, 2013
 *      Author: janmeier
 */

#include"RootNode.h"

using namespace spvs;

RootNode::RootNode()
:SceneNode(SceneNodeType::ROOT_NODE)
{

}

RootNode::~RootNode()
{

}

void RootNode::setParentNode(std::shared_ptr<SceneNode *> sceneNode)
{
  // TODO: Plot error message
}

std::shared_ptr<SceneNode *> RootNode::getParent()
{
  // TODO: Plot error message, add null_ptr
  return NULL;
}

