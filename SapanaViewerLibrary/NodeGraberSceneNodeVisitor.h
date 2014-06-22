//
//  ModelGraberSceneNodeVisitor.h
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 07.04.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#ifndef SapanaViewerLibrary_ModelGraberSceneNodeVisitor_H_
#define SapanaViewerLibrary_ModelGraberSceneNodeVisitor_H_

// Base class includes
#include "ISceneNodeVisitor.h"

// External includes
#include <vector>

// Project includes
#include "SceneNode.h"

namespace spvs
{
template< typename T >
class NodeGraberSceneNodeVisitor : public ISceneNodeVisitor
{
public:    
      
    explicit NodeGraberSceneNodeVisitor(){
        T tNode(nullptr);
        type_ = tNode.getSceneNodeType();
    }
    
    virtual ~NodeGraberSceneNodeVisitor(){}
    
    void visit(std::shared_ptr< SceneNode > sceneNode)
    {
        if( sceneNode->getSceneNodeType() == type_)
        {
            matchingNodes_.push_back(std::dynamic_pointer_cast< const T >(sceneNode));
        }
        
        
        auto childNodes = sceneNode->getChildNodes();
        
        std::for_each(childNodes.begin(), childNodes.end(),
                      [&](std::shared_ptr<
                          SceneNode > node)
                      {
                          node->accept(*this);
                      });
        
    }
    
    //std::vector< std::shared_ptr< spvs::SceneNode > > getModelNodes();
    std::vector< std::shared_ptr< T > > getMatchingNodes() const{return matchingNodes_;}
    
private:
    SceneNode::SceneNodeType type_;
    std::vector< std::shared_ptr< T > > matchingNodes_;
    
};

}
#endif /* defined(SapanaViewerLibrary_ModelGraberSceneNodeVisitor_H_ */
