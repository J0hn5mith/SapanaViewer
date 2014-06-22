//
//  RenderableSceneNode.cpp
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 10.04.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Class definition include
#include "RenderableSceneNode.h"

// External includes

// Project includes
#include "SceneNode.h"
#include "SceneNodeProperties.h"

using namespace spvr;

#pragma mark - Constructors and Destructors
RenderableSceneNode::RenderableSceneNode(std::shared_ptr< const  spvs::SceneNode > sceneNode)
: sceneNode_(sceneNode)
, worldTransMatrix_(sceneNode_->getWorldTransMatrix())
, nodeTransMatrix_(sceneNode_->getNodeTransMatrix())
, sceneNodeProperties_(sceneNode_->getProperties())
, observerImpl_(std::make_shared< spvu::ObserverImpl >())
{                                                                               
    sceneNode->registerObserver(observerImpl_);
}                                                                               
                                                                                
RenderableSceneNode::~RenderableSceneNode()                                      
{                                                                               
  // TODO: Implement
}


#pragma mark - Getter and Setter Methodes
const spvu::TransMatrix RenderableSceneNode::getWorldTransMatrix() const
{
    // TODO: Implement update of trans matrix.
    
    return worldTransMatrix_;
}

const spvu::TransMatrix  RenderableSceneNode::getNodeTransMatrix() const
{
    return nodeTransMatrix_;
}

const spvs::SceneNodeProperties RenderableSceneNode::getModelNodeProperties() const
{
    return this->sceneNode_->getProperties();
}


#pragma mark - Implementation IObserver Interface
void RenderableSceneNode::notify(std::shared_ptr< const spvu::INotification > notification ) const
{
    observerImpl_->notify(notification);
}

void RenderableSceneNode::update() const
{
    RenderableSceneNode * unconstThis = const_cast< RenderableSceneNode * >(this);
    if( observerImpl_ ->hasNotification() )
    {
        unconstThis->handleNotifications(observerImpl_->getNotifications());
    }
    
    observerImpl_->update();
}


#pragma mark - Private Methodes
void RenderableSceneNode::handleNotifications( std::shared_ptr< std::list< std::shared_ptr<const spvu::INotification > > > notifications)
{
    if (notifications->front()->getID() == 1)
    {
        updateTransMatrix();
    }
}

void RenderableSceneNode::updateTransMatrix()
{
    worldTransMatrix_ = sceneNode_->getWorldTransMatrix();
    nodeTransMatrix_ = sceneNode_->getNodeTransMatrix();
}

void RenderableSceneNode::updateProperties()
{
    sceneNodeProperties_ = sceneNode_->getProperties();
}
