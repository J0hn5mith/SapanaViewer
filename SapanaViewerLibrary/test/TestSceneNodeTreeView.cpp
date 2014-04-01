//
//  TestSceneNodeTreeView.cpp
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 20.01.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Class definition include
#include "TestSceneNodeTreeView.h"

// External includes

// Project includes

using namespace spvt;
                                                                                
//TestSceneNodeTreeView::TestSceneNodeTreeView(std::shared_ptr< const spvs::SceneGraph >sceneGraph)
//: SceneNodeTreeView(sceneGraph)
//, entries_()
//, sceneGraph_(sceneGraph)
//{
//    std::shared_ptr< const spvs::SceneNode > rootNode = sceneGraph->getRootNode();
//    addTreeViewNode(entries_.begin(), rootNode, 0);
//}

                                                                                
//TestSceneNodeTreeView::~TestSceneNodeTreeView()                                      
//{                                                                               
//  // TODO: Implement
//}

// std::vector< spvg::TreeViewNode > TestSceneNodeTreeView::getItems() const
//{
//    std::vector< spvg::TreeViewNode > returnVector;
//    std::list<  std::shared_ptr< spvg::TreeViewNode > >::const_iterator it1 = entries_.begin();
//    for ( it1; it1!=entries_.end(); ++it1)
//    {
//       returnVector.push_back(**it1);
//    }
//    
//    //std::copy( entries_.begin(), entries_.end(), std::back_inserter( returnVector ) );
//    return returnVector; // TODO: Implement
//}

//void TestSceneNodeTreeView::expandItem(int position)
//{
//    std::list< std::shared_ptr< spvg::TreeViewNode > >::iterator it1 = entries_.begin();
//    for(int i = 0; i< position; i++) it1++;
//    
//   std::shared_ptr< spvg::TreeViewNode > targetNode = *it1;
//    
//    targetNode->setExpanded(true);
//    
//    it1++; // points now to one after the parentNodeItem
//    unsigned int nodeID = targetNode->getId();
//    int childNodeItemLevel = targetNode->getLevel()+1;
//    std::shared_ptr< const spvs::SceneNode > sceneNode = sceneGraph_->getNode(nodeID);
//    for (auto node : sceneNode->getChildNodes())
//    {
//        addTreeViewNode(it1, node, childNodeItemLevel);
//    }
//}

//void TestSceneNodeTreeView::collapseItem(int position)
//{
//    std::list<  std::shared_ptr< spvg::TreeViewNode > >::iterator it1 = entries_.begin();
//    for(int i = 0; i< position; i++) it1++;
//    std::shared_ptr< spvg::TreeViewNode > targetNode = *it1;
//    std::shared_ptr<const  spvs::SceneNode > sceneNode = sceneGraph_->getNode(targetNode->getId());
//    
//    int numChildren = sceneNode->getChildNodes().size();
//    it1++;// Points now to the first element that is deleted.
//    std::list< std::shared_ptr< spvg::TreeViewNode > >::iterator it2 = it1;
//    for(int i = 0; i< numChildren ; i++) it2++;
//    entries_.erase(it1, it2);
//    
//    targetNode->setExpanded(false);
//}

//void TestSceneNodeTreeView::switchItem(int itemPosition)
//{
//    std::list<  std::shared_ptr< spvg::TreeViewNode > >::iterator it1 = entries_.begin();
//    
//    for(int i = 0; i< itemPosition; i++) it1++;
//    
//    if (!(*it1)->isExpanded())
//    {
//        expandItem(itemPosition);
//    }
//    else
//    {
//       collapseItem(itemPosition);
//    }
//}

//void TestSceneNodeTreeView::addTreeViewNode(std::list< std::shared_ptr< spvg::TreeViewNode > >::iterator position, std::shared_ptr< const spvs::SceneNode > node, int level)
//{
//    std::shared_ptr< spvg::TreeViewNode > twNode = std::make_shared< spvg::TreeViewNode >(level, node->getID(), getNameOfNode(node));
//    entries_.insert(position, twNode);
//}

//std::string TestSceneNodeTreeView::getNameOfNode(std::shared_ptr< const spvs::SceneNode > node)
//{
//    return sceneNodeNames_[node->getSceneNodeType()];
//}