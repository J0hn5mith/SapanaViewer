////
////  TestSceneNodeManager.cpp
////  SapanaViewerLibrary
////
////  Created by Jan Meier on 13.01.14.
////  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
////
//
//// Class definition include
//#include "TestSceneManager.h"
//
//// External includes
//#include <memory>
//
//// Project includes
//#include "RootNode.h"
//#include "SceneGraph.h"
//
//using namespace spvt;
//                                                                                
//TestSceneManager::TestSceneManager(std::shared_ptr< spvs::SceneGraph > scene)
//: SceneManager(scene)
//, testActiveSceneNode_(scene->getRootNode()->getChildNodes().begin()->get()) // TODO: Change
//{
//    
//
//    auto test = scene->getCameraNodes()->at(0);
//    testActiveCameraNodeModifier_ = scene->getNodeModifier(test->getID());
//   
//    testActiveCameraNode_ = test;
//}
//                                                                                
//TestSceneManager::~TestSceneManager()
//{                                                                               
//  // TODO: Implement
//}
//
//void TestSceneManager::setActiveSceneNode(std::shared_ptr< spvs::SceneNode > node)
//{
//    // TODO: Highlight the node and unhighlight the previous node
//    testActiveSceneNode_  = node;
//}
//
//const std::shared_ptr< spv::SceneNodeModifier > TestSceneManager::getActiveSceneNodeModifier()
//{
//    return nullptr;//std::make_shared< spv::SceneNodeModifier >( testActiveSceneNode_ );
//}
//
//void TestSceneManager::setActiveCamera( std::shared_ptr< spvs::CameraNode > cNode)
//{
//    // TODO: Set node in scene
//    testActiveCameraNode_ = cNode;
//}
//
//const std::shared_ptr< spv::SceneNodeModifier > TestSceneManager::getActiveCameraNodeModifier()
//{
//    return testActiveCameraNodeModifier_;
//}
//
//
//
