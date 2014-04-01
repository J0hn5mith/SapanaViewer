//
//  RenderableLeafNode.cpp
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 14.01.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Class definition include
#include "RenderableLeafNode.h"

// External includes
#include <memory>

// Project includes

#include "LeafNode.h"

using namespace spvr;
                                                                                
RenderableLeafNode::RenderableLeafNode(std::shared_ptr< const spvs::LeafNode > lNode)
: leafNode_(lNode)
, transformationMatrix_(lNode->getWorldTransMatrix())
, observerImpl_(std::make_shared< spvu::ObserverImpl >())
{                                                                               
    lNode->registerObserver(observerImpl_); //Observer is registered because i don't know how to register the renderable leaf node it self
}                                                                               
                                                                                
RenderableLeafNode::~RenderableLeafNode()                                      
{                                                                               
  // TODO: Implement
}

std::shared_ptr< const spvu::TransMatrix > RenderableLeafNode::getTransMatrix() const
{
    // TODO: Does this create a new coppy of the data? 
    return std::make_shared< const spvu::TransMatrix > (transformationMatrix_);
}

void RenderableLeafNode::update() const
{
    RenderableLeafNode * unconstThis = const_cast< spvr::RenderableLeafNode * >(this);
    if( observerImpl_ ->hasNotification() )
    {
        unconstThis->handleNotifications(observerImpl_->getNotifications());
    }
    
    observerImpl_->update();
}

void RenderableLeafNode::handleNotifications( std::shared_ptr< std::list< std::shared_ptr<const spvu::INotification > > > notifications)
{
    if (notifications->front()->getID() == 1)
    {
        updateTransMatrix();
    }
}

void RenderableLeafNode::updateTransMatrix()
{
    transformationMatrix_ = leafNode_->getTransMatrix();
}