//
//  HierarchicalModelList.cpp
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 17.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Class definition include
#include "HierarchicalModelList.h"

// External includes
#include <list>
// Project includes
#include "RootNode.h"
using namespace spvg;
                                                                                
HierarchicalModelList::HierarchicalModelList(std::shared_ptr< const spvs::SceneGraph> sceneGraph)
: sceneGraph_(sceneGraph)
, expandedNodeIDs_()
, items_()
, observerImpl_(std::make_shared< spvu::ObserverImpl>())
, itemsHaveChanged_(false)
{
    sceneGraph_->registerObserver(observerImpl_);
    
    createItemList();
}                                                                               
                                                                                
HierarchicalModelList::~HierarchicalModelList()                                      
{                                                                               
    sceneGraph_->unregisterObserver(observerImpl_);
}

#pragma mark - Public Methodes
std::vector < HierarchicalListItem > HierarchicalModelList::getListItems()
{
    return items_ ;
}

unsigned int HierarchicalModelList::getNumItems()
{
    return ((int)items_.size());
}

void HierarchicalModelList::expandListItem(spvu::ListItemID listItemID)
{
    expandedNodeIDs_.insert(listItemID);
    itemsHaveChanged_ = true;
}

void HierarchicalModelList::collapseListItem(spvu::ListItemID listItemID)
{
    expandedNodeIDs_.erase(listItemID);
    itemsHaveChanged_ = true;
}

bool HierarchicalModelList::toggleListItem(spvu::SceneNodeID sceneNodeID)
{
    
    //    auto toggledListItem = nodesInList_.find(sceneNodeID);
    //    if ( toggledListItem  == nodesInList_.end() )
    //    {
    //        std::cout << "Item can't be toggled because it's not in list. " << std::endl;
    //        return true; // TODO: Exception handling
    //    }
    //
    //    bool isExpanded = ((*toggledListItem).second).isExpanded();
    
    bool isExpanded  = expandedNodeIDs_.find(sceneNodeID) != expandedNodeIDs_.end();
    isExpanded ? collapseListItem(sceneNodeID) :  expandListItem(sceneNodeID) ;
    return !isExpanded;
}
/**
 * 1) Target node has to be expanded
 * 2) Target node is not Child node
 * 3) New parent node is no leaf node
 */
bool HierarchicalModelList::canMoveToPosition(spvu::ListPosition oldPosition, spvu::ListPosition newPosition)
{
    
    if (newPosition == 0)
    {
        return false; // Not possible because there is no parent
    }
    
    auto movedListItem = items_.at(oldPosition);
    auto newParentListItem = items_.at(newPosition);
    
    if (!newParentListItem.isExpanded()) {
        return false; // Can't be moved to non expanded item
    }
    spvu::SceneNodeID movedNodeID = movedListItem.getID();
    spvu::SceneNodeID newParentNodeID = newParentListItem.getID();
    
    auto newParentNode = sceneGraph_->getNode(newParentNodeID);
    
    if (newParentNode->getSceneNodeType() == spvs::SceneNode::MODEL_NODE)
    {
        return false;
    }
    
    auto newParentNodeAncestors = newParentNode->getAncestorNodes();
    bool canMove = true;
    
    
    std::for_each(newParentNodeAncestors.begin(), newParentNodeAncestors.end(),
                  [&](std::shared_ptr< spvs::SceneNode > secneNode)
                  {
                      canMove = secneNode->getID() != movedNodeID;
                  });
    
    if (!canMove)
    {
        return false; // Item can't be own child
    }
    
    return true;
}




#pragma mark - GUIAbstraction implementation
void HierarchicalModelList::update() const
{
    HierarchicalModelList * unconstThis = const_cast<HierarchicalModelList *>(this);
    
    if (observerImpl_->hasNotification())
    {
        unconstThis->handleNotifications();
        unconstThis->observerImpl_->update();
    }
    
    if (itemsHaveChanged_)
    {
        unconstThis->createItemList();
        unconstThis->itemsHaveChanged_ = false;
    }
}

void HierarchicalModelList::createItemList()
{
    items_ = std::vector < HierarchicalListItem >();
    insertItem(sceneGraph_->getRootNode()->getID(), 0);
}

void HierarchicalModelList::insertItem(spvu::SceneNodeID nodeID, unsigned int level)
{
    
    auto sceneNode = sceneGraph_->getNode(nodeID);
    auto isExpanded = expandedNodeIDs_.find(nodeID) != expandedNodeIDs_.end();
    
    auto nodeType = sceneNode->getSceneNodeType();
    bool isExpandable = (nodeType == spvs::SceneNode::ROOT_NODE || nodeType == spvs::SceneNode::FRAME_NODE );
    
    items_.push_back(HierarchicalListItem(sceneNode->getID(), "Label", isExpanded, isExpandable, level));
    
    if (isExpanded)
    {
        auto nodeChildren = sceneNode->getChildNodes();
        std::for_each(nodeChildren.begin(), nodeChildren.end(),
                      [&](std::shared_ptr< spvs::SceneNode > node)
                      {
                          insertItem(node->getID(), level +1);
                      });
    }
}




void HierarchicalModelList::handleNotifications()
{
    for(auto notification : *(observerImpl_->getNotifications()))
    {
        if (notification->getID() == spvs::SceneGraph::NEW_NODE)
        {
            //            spvu::SceneNodeID newNodeID = notification->getContent();
            //            std::shared_ptr< const spvs::SceneNode > newNode = sceneGraph_->getNode(newNodeID);
            //            std::list<  std::shared_ptr< spvg::TreeViewNode > >::iterator parentItem = findItem(newNode->getParentNode()->getID());
            //            if (parentItem != entries_.end())
            //            {
            //                addTreeViewItemChild(parentItem, newNode);
            //            }
            
        }
        else if (notification->getID() == spvs::SceneGraph::NODE_DELETED)
        {
            //
            //            auto dNode = findItem(notification->getContent());
            //            if (dNode != entries_.end())
            //            {
            //                // removeTreeViewItem(dNode);
            //                // Child don't have to be deleted, because there is a message for them as well
            //                entries_.erase(dNode);
            //                hasChanged_ = true;
            //
            //            }
            //            else
            //            {
            //                std::cout << "SceneNodeTreeView::handleNotifications - could not find entry to delete" << std::endl;
            //            }
        }
        else if (notification->getID() == spvs::SceneGraph::NODE_MOVED)
        {
            itemsHaveChanged_ = true;
            std::cout << "Hierarchical list handles moved node" << std::endl;
            
        }
        else
        {
            std::cout << "SceneNodeTreeView::handleNotifications - Unabel to handle notification." << std::endl;
        }
    }
}














// OLD STUFF

//void HierarchicalModelList::addNode(spvu::SceneNodeID nodeID)
//{
//    if (!(nodesInList_.find(nodeID) == nodesInList_.end()))
//    {
//        std::cout << "Item can't be added to HML because it's already in list. " << std::endl;
//        return;
//    }
//
//    auto node = sceneGraph_->getNode(nodeID);
//
//    // Get parent
//    auto parentNode = node->getParentNode();
//
//    unsigned int level = 0;
//    if (parentNode != nullptr)
//    {
//        // Parent has no parent => Parent node is not in list or not its root node
//        auto parentListItem = (*nodesInList_.find(parentNode->getID())).second;
//        level = parentListItem.getLevel() + 1;
//    }
//
//    std::string label = "";
//    auto nodeType = node->getSceneNodeType();
//    if ( nodeType == spvs::SceneNode::FRAME_NODE)
//    {
//        label += "FN ";
//    }
//    else if ( nodeType == spvs::SceneNode::MODEL_NODE)
//    {
//        label += "MN ";
//    }
//    else if ( nodeType == spvs::SceneNode::CAMERA_NODE)
//    {
//        label += "CM ";
//    }
//    else if ( nodeType == spvs::SceneNode::ROOT_NODE)
//    {
//        label += "RN ";
//    }
//    else
//    {
//        label += "UN ";
//    }
//
//    label += std::to_string(node->getID());
//    HierarchicalListItem newListItem = HierarchicalListItem(node->getID(), label, level);
//
//    nodesInList_.insert( std::pair< spvu::SceneNodeID, HierarchicalListItem >(nodeID, newListItem));
//
//    itemsHaveChanged_ = true;
//}


//#pragma mark - Private Item Management
////void HierarchicalModelList::updateItems()
////{
////    items_.clear();
////    std::shared_ptr< const spvs::SceneNode >  rootNode = sceneGraph_->getRootNode();
////    insertItem(rootNode->getID());
////    itemsHaveChanged_ = false;
////}
//
//void HierarchicalModelList::insertItem(spvu::SceneNodeID nodeID)
//{
//
//    auto nodeItem = (*nodesInList_.find(nodeID)).second;
//    items_.push_back(nodeItem);
//    
//    if (nodeItem.isExpanded())
//    {
//        auto nodeChildren = sceneGraph_->getNode(nodeID)->getChildNodes();
//        std::for_each(nodeChildren.begin(), nodeChildren.end(),
//                      [&](std::shared_ptr< spvs::SceneNode > node)
//                      {
//                          insertItem(node->getID());
//                      });
//    }
//}
//
//
//void HierarchicalModelList::rebuildList()
//{
//    auto oldNodeList = nodesInList_;
//    nodesInList_ = std::map < spvu::SceneNodeID, HierarchicalListItem >();
//    
//    readdNode(sceneGraph_->getRootNode()->getID(), oldNodeList);
//}
//
//void HierarchicalModelList::readdNode(spvu::SceneNodeID nodeID, std::map < spvu::SceneNodeID, HierarchicalListItem > & oldNodes)
//{
//        auto node = sceneGraph_->getNode(nodeID);
//        auto oldListItem = (*oldNodes.find(nodeID)).second;
//    
//    if (node->getSceneNodeType() != spvs::SceneNode::ROOT_NODE)
//    {
//        auto parentListItem = (*nodesInList_.find(node->getParentNode()->getID())).second;
//        oldListItem.setLevel(parentListItem.getLevel()+1);
//    }
//    
//    nodesInList_.insert(std::pair< spvu::SceneNodeID, HierarchicalListItem >(oldListItem.getID(), oldListItem));
//    
//    if (oldListItem.isExpanded())
//    {
//        std::for_each(node->getChildNodes().begin(), node->getChildNodes().end(),
//                      [&](std::shared_ptr< spvs::SceneNode > node)
//                      {
//                          insertItem(node->getID());
//                      });
//    }
//
//}
//
//void HierarchicalModelList::updateNodeLevel(spvu::SceneNodeID nodeID)
//{
//    auto updatedNode = sceneGraph_->getNode(nodeID);
//    auto updatedListItemIt = nodesInList_.find(nodeID);
//    auto newParentListItemIt = (nodesInList_.find(updatedNode->getParentNode()->getID()));
//    
//    auto newListItem = updatedListItemIt->second;
//    newListItem.setLevel(newParentListItemIt->second.getLevel()+1);
//    updatedListItemIt->second = newListItem;
//    
//    if (! newListItem.isExpanded())
//    {
//        return;
//    }
//    
//    auto nodeChildren = updatedNode->getChildNodes();
//    std::for_each(nodeChildren.begin(), nodeChildren.end(),
//                  [&](std::shared_ptr< spvs::SceneNode > node)
//                  {
//                      updateNodeLevel(node->getID());
//                  });
//}




#pragma mark - Node List Management

//void HierarchicalModelList::removeNode(spvu::SceneNodeID nodeID)
//{
//    if (nodesInList_.find(nodeID) == nodesInList_.end())
//    {
//       std::cout << "Node can't be removed from HML because it's not in list. " << std::endl;
//        return;
//    }
//    auto listItem = (*nodesInList_.find(nodeID)).second;
//    if ( listItem.isExpanded() )
//    {
//        collapseNode(nodeID);
//    }
//
//    nodesInList_.erase(nodeID);
//    itemsHaveChanged_ = true;
//}

//void HierarchicalModelList::expandNode(spvu::SceneNodeID nodeID)
//{
//    expandedNodeIDs_.insert(nodeID);
//    if ((nodesInList_.find(nodeID) == nodesInList_.end()))
//    {
//               std::cout << "Item can't be expanded to HML because it's already in list. " << std::endl;
//        return;
//    }
//    auto listItem = (*nodesInList_.find(nodeID)).second;
//
//    if (listItem.isExpanded())
//    {
//        // TODO: Exception handling
//        return;
//    }
//
//    auto nodeChildren = sceneGraph_->getNode(nodeID)->getChildNodes();
//
//    std::for_each(nodeChildren.begin(), nodeChildren.end(),
//                  [&](std::shared_ptr< spvs::SceneNode > node)
//                  {
//                      addNode(node->getID());
//                  });
//
//    listItem.setExpanded(true);
//
//    nodesInList_.erase(nodeID);
//    nodesInList_.insert(std::pair< spvu::SceneNodeID, HierarchicalListItem >(nodeID, listItem));
//
//    itemsHaveChanged_ = true;
//}

//void HierarchicalModelList::collapseNode(spvu::SceneNodeID nodeID)
//{
//    expandedNodeIDs_.erase(nodeID);
//    if ((nodesInList_.find(nodeID) == nodesInList_.end()))
//    {
//        std::cout << "Item can't be collapsed to HML because it's not in list. " << std::endl;
//        return;
//    }
//
//    auto listItem = (*nodesInList_.find(nodeID)).second;
//    if ( listItem.isExpanded() )
//    {
//        auto nodeChildren = sceneGraph_->getNode(nodeID)->getChildNodes();
//
//        std::for_each(nodeChildren.begin(), nodeChildren.end(),
//                      [&](std::shared_ptr< spvs::SceneNode > node)
//                      {
//                          removeNode(node->getID());
//                      });
//    }
//
//    listItem.setExpanded(false);
//
//    nodesInList_.erase(nodeID);
//    nodesInList_.insert(std::pair< spvu::SceneNodeID, HierarchicalListItem >(nodeID, listItem));
//    itemsHaveChanged_ = true;
//}
