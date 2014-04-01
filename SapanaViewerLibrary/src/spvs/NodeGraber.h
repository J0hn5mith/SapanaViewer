//
//  NodeGraber.h
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 16.01.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#pragma once
#ifndef SapanaViewerLibrary_NodeGraber_H_
#define SapanaViewerLibrary_NodeGraber_H_

// Base class includes

// External includes
#include <memory>
#include <vector>

// Project includes
#include "SceneNode.h"

namespace spvs{
    class ModelNode;
    class RootNode;
    class SceneNode;
    class CameraNode;
}

namespace spvs{
/**
 * Traverses through a scene graph an collects all ModelNode
 * TODO: Member documentation. Make generic
 */
class NodeGraber
{    
public:    
      
    explicit NodeGraber();    
    virtual ~NodeGraber();    
    

    
    /**
     * Template version of grabers.
     * @warning only works for nodes that hav a construcotr that takes a pointer as parameter
     */
    template<typename T>
    std::shared_ptr< std::vector< std::shared_ptr< const T > > > getNodes(std::shared_ptr< const spvs::RootNode > rNode) const;
    
private:
    
    /**
     * Processes a node. If the node has the type of the template type , 
     * the node is added to the results. If the node has children, the
     * children are processed also.
     */
    template<typename T>
    void collectNodes(std::shared_ptr< const spvs::SceneNode > sNode, spvs::SceneNode::SceneNodeType nodeType, std::shared_ptr< std::vector< std::shared_ptr< const T > > > result) const;
};
    
template<typename T>
std::shared_ptr< std::vector< std::shared_ptr< const T > > > NodeGraber::getNodes(std::shared_ptr< const spvs::RootNode > rNode) const
{
    std::shared_ptr< std::vector< std::shared_ptr< const T > > > nodes = std::make_shared< std::vector< std::shared_ptr< const T > > >();
    
    // Find out node type
    // TODO: Ask David what is the best way to get the nodes type
    T tNode(nullptr);
    
    collectNodes(rNode, tNode.getSceneNodeType(), nodes);
    
    return nodes;
}

template<typename T>
void NodeGraber::collectNodes(std::shared_ptr< const spvs::SceneNode > sNode, spvs::SceneNode::SceneNodeType nodeType, std::shared_ptr< std::vector< std::shared_ptr< const T > > > result) const
{
    if (!sNode)
    {
        return;
    }
    
    for (std::shared_ptr< spvs::SceneNode > node : sNode->getChildNodes())
    {
        if (node->getSceneNodeType() == nodeType)
        {
            result->push_back(std::dynamic_pointer_cast< const T >(node));
        }
        else
        {
            collectNodes(node, nodeType, result);
        }
    }
}
}
#endif /* defined(SapanaViewerLibrary_NodeGraber_H_ */
