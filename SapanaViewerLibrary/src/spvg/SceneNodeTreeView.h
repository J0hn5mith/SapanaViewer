//
//  SceneNodeTreeView.h
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 20.01.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#pragma once
#ifndef SapanaViewerLibrary_SceneNodeTreeView_H_
#define SapanaViewerLibrary_SceneNodeTreeView_H_

// Base class includes
#include <ITreeView.h>
#include <IObserver.h>

// External includes
#include <list>
#include <vector> 
#include <memory>

// Project includes
#include "TreeViewNode.h"
#include "ObserverImpl.h"

// Forewared declaration
namespace spvs {
    class SceneGraph;
    class SceneNode;
};

namespace spvg{
    
/**
 * @Implementation
 * @warning uses pseudo random access for lists which is quite slow.
 */
class SceneNodeTreeView : public ITreeView
{
public:
    
    
    explicit SceneNodeTreeView( std::shared_ptr< const  spvs::SceneGraph> sceneGraph);
    
    virtual ~SceneNodeTreeView();    
  
    
    /**
     * Returns a list with the tree view's items.
     * @return List with the tree view's items.
     */
    virtual std::vector< TreeViewNode > getItems() const;
 
    
    /**
     * @Implementation
     */
    virtual void toggleItem(int itemPosition);
    
    /**
     * @Implementation
     */
    virtual void expandItem(int itemPosition);
    
    /**
     * @Implementation
     */
    virtual void collapseItem(int itemPosition);
    
    /**
     * Implementation of the observer interface
     */
    
    /**
     * @ Implementation
     */
    virtual void notify(std::shared_ptr< const spvu::INotification > notification ) const{ observerImpl_->notify(notification);}
    
    /**
     * @ Implementation
     */
    virtual void update() const;
    
    
private:
    
    /**
     * Pointer to the tree (in this case a scene graph)
     * represented by this tree view.
     */
    std::shared_ptr< const spvs::SceneGraph > sceneGraph_;
    
    /**
     * List soring the entries of the tree view
     */
    std::list< std::shared_ptr< spvg::TreeViewNode >  > entries_;
    
    /**
     * Signals if the SceneNodeTreeView has changed since last calling fillOutputCache
     */
    bool hasChanged_;
    
    /**
     * Cache for the output of getItems()
     */
    std::vector< spvg::TreeViewNode > outputCache_;
    
    /**
     * Implementation of the observer interface.
     */
    std::shared_ptr< spvu::ObserverImpl> observerImpl_;
    
    /**
     * Adds a tree view node to the tree view.
     */
    void addTreeViewItem(std::list< std::shared_ptr< spvg::TreeViewNode > >::iterator position, std::shared_ptr< const spvs::SceneNode > node, int level);
    
    /**
     * Adds a tree view item child directly after its parent
     */
    void addTreeViewItemChild(std::list< std::shared_ptr< spvg::TreeViewNode > >::iterator parent, std::shared_ptr< const spvs::SceneNode > node);
    
    /**
     * Remove tree view item
     */
    void removeTreeViewItem(std::list< std::shared_ptr< spvg::TreeViewNode > >::iterator item);
    
    /**
     * Returns a iterator that points to the TreeView item at position itemPosition
     * @param itemPosition Position of the item.
     * @return Iterator pointing to the item at position at itemPosition
     */
    std::list<  std::shared_ptr< spvg::TreeViewNode > >::iterator randomAccess(int itemPosition);
    
    std::list<  std::shared_ptr< spvg::TreeViewNode > >::iterator findItem(spvu::SceneNodeID ID);
    
    /**
     * Collapses a item using in iterator as position.
     */
    void expandItem(std::list<  std::shared_ptr< spvg::TreeViewNode > >::iterator item);
    
    /**
     * Collapses a item using in iterator as position.
     */
    void collapseItem(std::list<  std::shared_ptr< spvg::TreeViewNode > >::iterator item);
    
    
    /**
     * Fills or refills the getItemCache. Sets hasChanged_ to false.
     */
    void buildOutputCache();
    
    /**
     * Handles the notificaiton from the observee.
     */
    void handleNotifications();

    
};
}
#endif /* defined(SapanaViewerLibrary_SceneNodeTreeView_H_ */
