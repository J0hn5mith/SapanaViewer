/*
 * SceneNode.cpp
 *
 *  Created on: Dec 12, 2013
 *      Author: janmeier
 */

// Class definition include
#include"SceneNode.h"


// External includes
#include <algorithm>
// Project includes

using namespace spvs;

SceneNode::SceneNode(SceneNodeType type)
: sceneNodeType_(type)
, parentNode_()
, childNodes_()
, transformationList_()
, nodeTransMatrix_()
, worldTransMatrix_()
, properties_(spvs::SceneNodeProperties())
, hasChanged_(false)
, id_()
, observableImpl_(std::make_shared< spvu::ObservableImpl >())
{
    vmml::identity(worldTransMatrix_);
    vmml::identity(nodeTransMatrix_);
    
    spvu::TransMatrix identityMatrix;
    vmml::identity(identityMatrix);
    
    id_ = reinterpret_cast< unsigned long >( this );
}

SceneNode::~SceneNode()
{
        
}

# pragma mark - Children and parent setters
std::unordered_set< std::shared_ptr< SceneNode > > SceneNode::getChildNodes() const
{
    return childNodes_;
}

std::list< std::shared_ptr< spvs::SceneNode > > SceneNode::getAncestorNodes() const
{
    if (parentNode_ == nullptr) {
        return std::list < std::shared_ptr< spvs::SceneNode > >();
        if (this->getSceneNodeType() != ROOT_NODE)
        {
            std::cout << "Non root node is treated as such" << std::endl;
        }
        else
        {
             std::cout << "Root node was reached." << std::endl;
        }
    }
    else
    {
        auto ancesotrs = parentNode_->getAncestorNodes();
        ancesotrs.push_back(parentNode_);
        return (ancesotrs);
        
        if (this->getSceneNodeType() == ROOT_NODE)
        {
             std::cout << "Root node was nod detected" << std::endl;
        }
        else
        {
            std::cout << "Node was added" << std::endl;
        }
    }
}

void SceneNode::addChildNode(std::shared_ptr< SceneNode > childNode)
{
    childNodes_.insert(childNode);
}

void SceneNode::removeChild(std::shared_ptr< SceneNode > childNode)
{
        childNodes_.erase(childNode);
}

# pragma mark - Transformation List
std::list< spvu::TransMatrix > SceneNode::getTransformationList() const
{
    return transformationList_.getTransformationList();
}

void SceneNode::addTransformationMatrix()
{
    transformationList_.addTransformationMatrix();
    nodeHasChanged();
}

void SceneNode::removeTransformationMatrix(int position)
{
    transformationList_.removeTransformationMatrix((spvu::ListPosition) position);
    
    nodeHasChanged();
    // TODO: Remove at right position
}


# pragma mark -

//@deprecated
spvu::TransMatrix SceneNode::getTransMatrix() const
{
    return getWorldTransMatrix();
}

spvu::TransMatrix SceneNode::getWorldTransMatrix() const
{
    SceneNode * mThis = const_cast<SceneNode *>(this);

    //TODO: Only do that if needed.
    mThis->updateNodeTransMatrix();

    if (mThis->hasChanged())
    {
        mThis->updateWorldTransMatrix();
    }

    return worldTransMatrix_;
}


// TODO: const
spvu::TransMatrix SceneNode::getNodeTransMatrix() const
{
    this->updateNodeTransMatrix();
    return nodeTransMatrix_;
}

void SceneNode::transform(const spvu::TransMatrix tMatrix, int index)
{
    transformationList_.transformMatrix(tMatrix, index);
    nodeHasChanged();
}

 void SceneNode::shiftTransformationMatrix(int oldPosition, int newPosition)
{
    transformationList_.moveTransformationMatrix(oldPosition, newPosition);
    nodeHasChanged();
}

#pragma mark - Visitor Pattern
void SceneNode::accept(spvs::ISceneNodeVisitor &visitor)
{
    visitor.visit(shared_from_this());
}

#pragma mark - Private Methodes
void SceneNode::updateWorldTransMatrix()
{
        if (!hasChanged()) {
                return;
        }
    spvu::TransMatrix pMatrix;
        if (parentNode_)
        {
               pMatrix = parentNode_->getTransMatrix();
        }
        else
        {
                vmml::identity(pMatrix);
        }
        worldTransMatrix_.multiply(nodeTransMatrix_,pMatrix);
        
        hasChanged_ = false;
}

void SceneNode::nodeHasChanged()
{
        hasChanged_ = true;
        notifyObservers(std::make_shared<spvu::NotificationImpl>(1));// TODO: use enum for notification types
        for (auto node : childNodes_)
        {
                node->nodeHasChanged();
        }
}

void SceneNode::updateNodeTransMatrix() const
{
    SceneNode * unconstThis = const_cast<SceneNode *>(this);
    unconstThis->nodeTransMatrix_ = transformationList_.getResultingTransMatrix();
}