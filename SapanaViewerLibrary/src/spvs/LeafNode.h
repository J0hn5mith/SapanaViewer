/*
 * LeafNode.h
 *
 *  Created on: Dec 12, 2013
 *      Author: janmeier
 */

#pragma once
#ifndef LEAFNODE_H_
#define LEAFNODE_H_

// Base class includes
#include "SceneNode.h"

// External includes
#include<vector>
#include <memory.h>

// Project internal includes
#include "IObservable.h"
#include "ObservableImpl.h"

namespace spvs{
/**
 * Leaf nodes are the leafs of a scene graph. Because they are the leafs,
 * they don't have any child nodes.
 */
    class LeafNode: public SceneNode, public spvu::IObservable
{
public:
    explicit LeafNode(SceneNodeType sceneNodeType);

    virtual ~LeafNode();

    /**
    * @ Override
    *  Disables the adding of childs
    * @param childNode
    */
    virtual void addChildNode(SceneNode * childNode);

    /**
    * @ Override
    * Disables child removal. 
    */
    virtual void removeChild(spvu::SceneNodeID childPos);

    /**
    * @Override
    * Observers are also informed about change
    */
    virtual void nodeHasChanged();

    /**
    * Implementation of IObservable
    */

    /**
    * @ Implementation
    */
    virtual void notifyObservers(std::shared_ptr<const spvu::INotification > notification) const{observableImpl_->notifyObservers(notification);}

    /**
    * @ Implementation
    */
    virtual void registerObserver(std::shared_ptr< spvu::IObserver >observer) const {observableImpl_->registerObserver(observer);}

    /**
    * @ Implementation
    */
    virtual void unregisterObserver(std::shared_ptr< spvu::IObserver > observer) const{observableImpl_->unregisterObserver(observer);}
  
  
private:
  
  std::shared_ptr< spvu::ObservableImpl > observableImpl_;

};

}

#endif /* LEAFNODE_H_ */
