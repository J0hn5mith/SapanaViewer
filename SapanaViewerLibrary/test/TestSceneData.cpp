/*
 * TestSceneData.cpp
 *
 *  Created on: Dec 12, 2013
 *      Author: janmeier
 */
// Class definition include
#include"TestSceneData.h"

// Project include
#include "FrameNode.h"
#include "RootNode.h"

// Test include
#include "CubeData.h"
#include "TestCameraNode.h"


using namespace spvt;

TestSceneData::TestSceneData()
: sceneGraph_( std::make_shared< spvs::SceneGraph >() )
{
    std::shared_ptr< const spvs::RootNode > testRootNode = sceneGraph_->getRootNode();
    spvs::FrameNode testFrameNode;
    //spvs::ModelNode coordLines1(std::make_shared< const spvt::CoordinateSystem >( ));
    //spvs::ModelNode coordLines2(std::make_shared< const spvt::CoordinateSystem >( ));
    spvs::ModelNode model1(std::make_shared< const spvt::CubeData >( ));
    spvs::ModelNode model2(std::make_shared< const spvt::CubeData >( ));
    spvs::CameraNode cNode = spvt::TestCameraNode();
    
    int frameNodeID = sceneGraph_->addNode(testRootNode, testFrameNode);
    sceneGraph_->addNode(testRootNode, cNode);
    //sceneGraph_->addNode(testRootNode, coordLines1);
    sceneGraph_->addNode(testRootNode, model1);

    spvs::FrameNode testFrameNode2;
    spvs::FrameNode testFrameNode3;
    sceneGraph_->addNode(frameNodeID, model2);
    sceneGraph_->addNode(frameNodeID, testFrameNode2);
    sceneGraph_->addNode(frameNodeID, testFrameNode3);
    //sceneGraph_->addNode(frameNodeID, coordLines2);
}

TestSceneData::~TestSceneData()
{
 // TODO: Fill
}

//std::shared_ptr< const spvs::CameraNode > TestSceneData::getActiveCamerNode() const
//{
////    // DEBUG
////   auto cameraNodes = sceneGraph_->getCameraNodes();
////    std::cout << "getActiveCamerNode() - Number of found camera nodes: " << cameraNodes->size() << std::endl;
////    return sceneGraph_->getCameraNodes()->at(0);
//}
