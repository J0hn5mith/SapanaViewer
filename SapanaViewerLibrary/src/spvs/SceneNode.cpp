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
{
    vmml::identity(worldTransMatrix_);
    vmml::identity(nodeTransMatrix_);
    
    spvu::TransMatrix identityMatrix;
    vmml::identity(identityMatrix);
    transformationList_.push_back(identityMatrix);
    
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
    return transformationList_;
}

void SceneNode::addTransformationMatrix()
{
    spvu::TransMatrix identityMatrix;
    vmml::identity(identityMatrix);
    transformationList_.push_back(identityMatrix);
    nodeHasChanged();
}

void SceneNode::removeTransformationMatrix(int position)
{
     if ( transformationList_.empty() )
     {
         return;
     }
    auto it = transformationList_.begin();
    std::advance( it, position);
    
    transformationList_.erase(it);
    
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
    
    if ( transformationList_.empty() || transformationList_.size() <= index)
    {
        // TODO: Exception handling
        return;
        
    }
    
    auto it = transformationList_.begin();
    std::advance( it, index);

    const spvu::TransMatrix  previousMatrix = *it;
    spvu::TransMatrix resultMatrix;
    vmml::identity(resultMatrix);
    resultMatrix.multiply(tMatrix, previousMatrix);
    
    (*it) = resultMatrix;
    
    nodeHasChanged();
}

 void SceneNode::shiftTransformationMatrix(int oldPosition, int newPosition)
{
    
    if (oldPosition < 0 || oldPosition >= transformationList_.size())
    {
        // TODO Exception Handling
        return;
    }
    if (newPosition < 0 || newPosition >= transformationList_.size())
    {
        // TODO Exception Handling
        return;
    }
    
    if ( newPosition > oldPosition )
    {
        newPosition++;
    }
    
    auto  itOld = transformationList_.begin();
    std::advance( itOld, oldPosition);
    
    auto itNew = transformationList_.begin();
    std::advance( itNew, newPosition);
    
    transformationList_.splice(itNew, transformationList_, itOld);
    
    nodeHasChanged();
}

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
        for (auto node : childNodes_)
        {
                node->nodeHasChanged();
        }
}

void SceneNode::updateNodeTransMatrix() const
{
        SceneNode * unconstThis = const_cast<SceneNode *>(this);
        vmml::identity(unconstThis->nodeTransMatrix_);
        for (auto tMatrix : transformationList_)
        {
            spvu::TransMatrix tmp = unconstThis->nodeTransMatrix_;
            unconstThis->nodeTransMatrix_.multiply(tMatrix, tmp);
        }
}
