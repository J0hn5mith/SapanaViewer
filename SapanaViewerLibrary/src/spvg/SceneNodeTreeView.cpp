//
//  SceneNodeTreeView.cpp
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 20.01.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Class definition include
#include "SceneNodeTreeView.h"

// External includes

// Project includes
#include "SceneGraph.h"
#include "RootNode.h"

using namespace spvg;
                                                                                
SceneNodeTreeView::SceneNodeTreeView(std::shared_ptr< const spvs::SceneGraph> sceneGraph)
: sceneGraph_(sceneGraph)
, entries_()
, outputCache_()
, hasChanged_(true)
, observerImpl_(std::make_shared< spvu::ObserverImpl>())
{                                                                               
    addTreeViewItem(entries_.begin(), sceneGraph->getRootNode(), 0);
    sceneGraph_->registerObserver(observerImpl_);
}

SceneNodeTreeView::~SceneNodeTreeView()
{
    
}

std::vector< spvg::TreeViewNode > SceneNodeTreeView::getItems() const
{
    if (hasChanged_)
    {
        SceneNodeTreeView * ucThis = const_cast< SceneNodeTreeView *>(this);
        ucThis->buildOutputCache();
    }
    
    return outputCache_;
}

void SceneNodeTreeView::expandItem(int itemPosition)
{
    std::list< std::shared_ptr< spvg::TreeViewNode > >::iterator item = randomAccess(itemPosition);
    expandItem(item);
    hasChanged_ = true;
}

void SceneNodeTreeView::collapseItem(int itemPosition)
{
    std::list<  std::shared_ptr< spvg::TreeViewNode > >::iterator it1 = randomAccess(itemPosition);
    collapseItem(it1);
    hasChanged_ = true;
}

void SceneNodeTreeView::update() const
{
    SceneNodeTreeView * unconstThis = const_cast<SceneNodeTreeView *>(this);
    if (observerImpl_->hasNotification())
    {
        unconstThis->handleNotifications();
        observerImpl_->update();
    }
}

void SceneNodeTreeView::addTreeViewItem(std::list< std::shared_ptr< spvg::TreeViewNode > >::iterator position, std::shared_ptr< const spvs::SceneNode > node, int level)
{
    std::shared_ptr< spvg::TreeViewNode > twNode = std::make_shared< spvg::TreeViewNode >(level, node->getID(), node->getTypeName());
    entries_.insert(position, twNode);
    hasChanged_ = true;
}


void SceneNodeTreeView::addTreeViewItemChild(std::list< std::shared_ptr< spvg::TreeViewNode > >::iterator parent, std::shared_ptr< const spvs::SceneNode > node)
{
    int level = (*parent)->getLevel() + 1;
    parent++;
    addTreeViewItem(parent, node, level);
}

void SceneNodeTreeView::removeTreeViewItem(std::list< std::shared_ptr< spvg::TreeViewNode > >::iterator item)
{
    // remove children if expanded
    if ((*item)->isExpanded())
    {
        std::shared_ptr<const  spvs::SceneNode > sceneNode = sceneGraph_->getNode((*item)->getId());
        
        int numChildren = sceneNode->getChildNodes().size();
        std::list< std::shared_ptr< spvg::TreeViewNode > >::iterator deletePoint = item;
        std::cout << numChildren << std::endl;
        for(int i = 0; i < numChildren; i++)
        {
            deletePoint = item;
            deletePoint++;
            removeTreeViewItem(deletePoint);
        }
        
    }
    
    // remove item
    entries_.erase(item);
}

void SceneNodeTreeView::expandItem(std::list<  std::shared_ptr< spvg::TreeViewNode > >::iterator item)
{
    (*item)->setExpanded(true);
    
    std::list< std::shared_ptr< spvg::TreeViewNode > >::iterator insertPoint = item;
    insertPoint++;
    
    spvu::SceneNodeID nodeID = (*item)->getId();
    std::shared_ptr< const spvs::SceneNode > sceneNode = sceneGraph_->getNode(nodeID);
    int childNodeItemLevel = (*item)->getLevel()+1;
    
    for (auto node : sceneNode->getChildNodes())
    {
        addTreeViewItem( insertPoint, node, childNodeItemLevel);
    }
    
    hasChanged_ = true;
}

void SceneNodeTreeView::collapseItem(std::list<  std::shared_ptr< spvg::TreeViewNode > >::iterator item)
{
    (*item)->setExpanded(false);
    std::shared_ptr<const  spvs::SceneNode > sceneNode = sceneGraph_->getNode((*item)->getId());
    
    int numChildren = sceneNode->getChildNodes().size();
    std::list< std::shared_ptr< spvg::TreeViewNode > >::iterator deletePoint = item;
    deletePoint++;
    std::list< std::shared_ptr< spvg::TreeViewNode > >::iterator endDPoint = deletePoint;
    std::cout << numChildren << std::endl;
    for(int i = 0; i < numChildren; i++) endDPoint++;
    entries_.erase(deletePoint, endDPoint);
    
     hasChanged_ = true;
}

void SceneNodeTreeView::toggleItem(int itemPosition)
{
    std::list<  std::shared_ptr< spvg::TreeViewNode > >::iterator item = randomAccess(itemPosition);
    !(*item)->isExpanded() ? expandItem(item) : collapseItem(item);
}

std::list<  std::shared_ptr< spvg::TreeViewNode > >::iterator SceneNodeTreeView::randomAccess(int itemPosition)
{
    if(itemPosition < 0)
    {
        return entries_.begin(); // TODO: Error message
    }
    else if (itemPosition > entries_.size())
    {
        return entries_.end();
    }
    
    std::list<  std::shared_ptr< spvg::TreeViewNode > >::iterator it1 = entries_.begin();
    for ( int i=0; i < itemPosition; i++) it1++;
    
    return it1;
}

std::list<  std::shared_ptr< spvg::TreeViewNode > >::iterator SceneNodeTreeView::findItem(spvu::SceneNodeID ID)
{
    auto result = std::find_if(entries_.begin(), entries_.end(),
              [&](std::shared_ptr< spvg::TreeViewNode > item)
              {
                  if (item->getId() == ID)
                  {
                      return true;
                  }
                  
                  return false;
                  
              });
    return result;
}

void SceneNodeTreeView::buildOutputCache()
{
    outputCache_.clear();
    std::for_each(entries_.begin(), entries_.end(), //TODO
        [&](std::shared_ptr< spvg::TreeViewNode > item)
        {
          outputCache_.push_back(*item);
        }
        );
    hasChanged_ = false;
}

void SceneNodeTreeView::handleNotifications()
{
    for(auto notification : *(observerImpl_->getNotifications()))
    {
        if (notification->getID() == spvs::SceneGraph::NEW_NODE)
        {
            spvu::SceneNodeID newNodeID = notification->getContent();
            std::shared_ptr< const spvs::SceneNode > newNode = sceneGraph_->getNode(newNodeID);
            std::list<  std::shared_ptr< spvg::TreeViewNode > >::iterator parentItem = findItem(newNode->getParentNode()->getID());
            if (parentItem != entries_.end())
            {
                addTreeViewItemChild(parentItem, newNode);
            }
            
        }
        else if (notification->getID() == spvs::SceneGraph::NODE_DELETED)
        {

           auto dNode = findItem(notification->getContent());
            if (dNode != entries_.end())
            {
                // removeTreeViewItem(dNode);
                // Child don't have to be deleted, because there is a message for them as well
                entries_.erase(dNode);
                hasChanged_ = true;
                
            }
            else
            {
                    std::cout << "SceneNodeTreeView::handleNotifications - could not find entry to delete" << std::endl;
            }
        }
        else
        {
            std::cout << "SceneNodeTreeView::handleNotifications - Unabel to handle notification." << std::endl;
        }
        buildOutputCache();
    }
}