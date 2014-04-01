//
//  RenderableModelNode.cpp
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 29.12.13.
//  Copyright (c) 2013 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Base class includes

// External includes

// Project includes
#include <RenderableModelNode.h>
#include "RenderableModel.h"
#include "ModelNode.h"

using namespace spvr;

RenderableModelNode::RenderableModelNode(std::shared_ptr< const spvs::ModelNode > modelNode)
: modelNode_(modelNode)
, renderableModel_(new RenderableModel(modelNode_->getModelData())) // TODO: Don't use multiple instances of RenderableModel for the same renderable model.
, transformationMatrix_(modelNode_->getTransMatrix())
, observerImpl_(std::make_shared< spvu::ObserverImpl >())
{
    modelNode_->registerObserver(observerImpl_);
}

RenderableModelNode::~RenderableModelNode()
{
    modelNode_->unregisterObserver(observerImpl_);
}

std::shared_ptr< const spvu::TransMatrix > RenderableModelNode::getTransMatrix() const
{
  // TODO: Implement update of trans matrix.
    
    return std::make_shared< const spvu::TransMatrix >(transformationMatrix_);
}

const spvs::SceneNodeProperties RenderableModelNode::getModelNodeProperties() const
{
    return this->modelNode_->getProperties();
}

void RenderableModelNode::update() const
{
    RenderableModelNode * unconstThis = const_cast< RenderableModelNode * >(this);
    if( observerImpl_ ->hasNotification() )
    {
        unconstThis->handleNotifications(observerImpl_->getNotifications());
    }

    observerImpl_->update();
}

void RenderableModelNode::handleNotifications( std::shared_ptr< std::list< std::shared_ptr<const spvu::INotification > > > notifications)
{
    if (notifications->front()->getID() == 1)
    {
        updateTransMatrix();
    }
}

void RenderableModelNode::updateTransMatrix()
{
    transformationMatrix_ = modelNode_->getTransMatrix();
}
