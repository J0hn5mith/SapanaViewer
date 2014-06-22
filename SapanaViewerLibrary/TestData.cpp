//
//  TestData.cpp
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 16.04.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Class definition include
#include "TestData.h"

// External includes

// Project includes
#include "FrameNode.h"
#include "RootNode.h"
#include "ModelNode.h"
#include "ModelData.h"
#include "LightSource.h"
#include "LightSourceNode.h"
#include "CameraNode.h"
#include "Camera.h"
using namespace spvu;

std::shared_ptr< spv::SceneGraphController > TestData::getTestSceneController()
{
    
    auto scenGraph = std::make_shared< spvs::SceneGraph >();
    // Set up the scene manager
    
    std::shared_ptr< spv::SceneGraphController > sceneGraphController = std::make_shared< spv::SceneGraphController >(scenGraph);
    std::shared_ptr< const spvs::RootNode > rootNode = scenGraph->getRootNode();
    sceneGraphController->setSceneNodeName(rootNode->getID(), "Root Node");
    
    // Add Frames
    spvs::FrameNode testFrameNode;
    spvs::FrameNode testFrameNode2;
    spvs::FrameNode testFrameNode3;
    
    int frameNodeID = scenGraph->addNode(rootNode, testFrameNode);
    sceneGraphController->setSceneNodeName(frameNodeID, "Frame Node");
    
    scenGraph->addNode(frameNodeID, testFrameNode2);
    
    scenGraph->addNode(frameNodeID, testFrameNode3);
    
    sceneGraphController->setSceneNodeName(frameNodeID, "Frame Node");
    sceneGraphController->setSceneNodeName(testFrameNode2.getID(), "Frame Node 2");
    sceneGraphController->setSceneNodeName(testFrameNode3.getID(), "Frame Node 3");
    
    
    // Models
    auto modelData = spvu::TestData::getTestModelData();
    spvs::ModelNode model1(modelData);
    //        auto cowData = spvu::ModelLoader::loadModel("/Users/janmeier/Documents/My_Documents/Studium/Bachelor/Bachelor_Thesis/Code/SapanaViewer/SapanaViewer/SapanaViewer/sphere.obj");
    auto cowData = spvu::TestData::getTestModelData();
    spvs::ModelNode model2(cowData);
    
    sceneGraphController->addSceneNode( model1, frameNodeID, "Model Node 1");
    sceneGraphController->addSceneNode( model2, frameNodeID, "Model Node 2");
    
    auto nodeOneModifier = scenGraph->getNodeModifier(model1.getID());
    nodeOneModifier->translateX(-5);
    nodeOneModifier->translateY(3);
    
    auto nodeTwoModifier = scenGraph->getNodeModifier(model2.getID());
    nodeTwoModifier->translateX(5);
    nodeTwoModifier->translateY(3);
    
    
    // Cameras
    std::shared_ptr< vmml::frustumf > frustum = std::make_shared<vmml::frustumf>();
    frustum->set_perspective(15,1, .1f, 40.0);
    spvs::CameraNode cNode = spvs::CameraNode(std::make_shared< spvs::Camera > (frustum ));
    
    scenGraph->addNode(rootNode, cNode);
    
    // Light
    spvs::LightSourceNode lightSourceNode(std::make_shared< spvs::LightSource>());
    sceneGraphController->addSceneNode( lightSourceNode, frameNodeID, "Light Source");
    
    // Set active camera
    sceneGraphController->selectObserverCameraNode(sceneGraphController->getScene()->getActiveCamerNode());
    auto cameraModifier = sceneGraphController->getObserverCameraModifier();
    cameraModifier->translateZ(-10);
    cameraModifier->translateY(-8);
    //cameraModifier->rotateX(30);
    
    int i = 100;
    i++;
    return sceneGraphController;
}

std::shared_ptr< spvs::ModelData > TestData::getTestModelData()
{

    /*
     *      7---6
     *    3---2 |
     *    |  4|-5
     *    0---1
     */
    
    auto modelData = std::make_shared< spvs::ModelData >(GL_TRIANGLES, GL_FLOAT, GL_UNSIGNED_BYTE);
    //--- Front ---
    spvu::Normal frontNormal = { 0.0f, 0.0f, 1.0f};
    spvu::Color frontColor = {1.0f, 0.0f, 0.0f, 1.f};
    {
        
        Vertex vertex = {
            { -1.f, -1.f, 1.f}                  // Position
            ,frontNormal   // Normal
            ,{ 0.f, 0.f}                        // Texture coordinates
            ,frontColor             // Color
        };
        modelData->addVertex(vertex);
    }
    {
        Vertex vertex = {
            { 1.f, -1.f, 1.f}                  // Position
            ,frontNormal   // Normal
            ,{ 0.f, 0.f}                        // Texture coordinates
            ,frontColor              // Color
        };
        modelData->addVertex(vertex);
    }
    {
        Vertex vertex = {
            {1.f, 1.f, 1.f}                  // Position
            ,frontNormal   // Normal
            ,{ 0.f, 0.f}                        // Texture coordinates
            ,frontColor            // Color
        };
        modelData->addVertex(vertex);
    }
    {
        Vertex vertex = {
            { -1.f, 1.f, 1.f}                  // Position
            ,frontNormal   // Normal
            ,{ 0.f, 0.f}                        // Texture coordinates
            ,frontColor            // Color
        };
        modelData->addVertex(vertex);
    }
    
    
    
    //--- Right ---
    spvu::Normal rightNormal = { 1.0f, 0.0f, 0.0f};
    spvu::Color rightColor = {0.0f, 0.0f, 1.0f, 1.f};
    {
        Vertex vertex = {
            { 1.f, -1.f, 1.f}                  // Position
            ,rightNormal   // Normal
            ,{ 0.f, 0.f}                        // Texture coordinates
            ,rightColor             // Color
        };
        modelData->addVertex(vertex);
    }
    {
        Vertex vertex = {
            { 1.f, -1.f, -1.f}                  // Position
            ,rightNormal   // Normal
            ,{ 0.f, 0.f}                        // Texture coordinates
            ,rightColor              // Color
        };
        modelData->addVertex(vertex);
    }
    {
        Vertex vertex = {
            {1.f, 1.f, -1.f}                  // Position
            ,rightNormal   // Normal
            ,{ 0.f, 0.f}                        // Texture coordinates
            ,rightColor            // Color
        };
        modelData->addVertex(vertex);
    }
    {
        Vertex vertex = {
            { 1.f, 1.f, 1.f}                  // Position
            ,rightNormal   // Normal
            ,{ 0.f, 0.f}                        // Texture coordinates
            ,rightColor            // Color
        };
        modelData->addVertex(vertex);
    }
    
    
    //--- Top ---
    spvu::Normal topNormal = { 0.0f, 1.0f, 0.0f};
    spvu::Color topColor = {0.0f, 1.0f, 0.0f, 1.f};
    {
        Vertex vertex = {
            { -1.f, 1.f, 1.f}                  // Position
            ,topNormal   // Normal
            ,{ 0.f, 0.f}                        // Texture coordinates
            ,topColor             // Color
        };
        modelData->addVertex(vertex);
    }
    {
        Vertex vertex = {
            { 1.f, 1.f, 1.f}                  // Position
            ,topNormal   // Normal
            ,{ 0.f, 0.f}                        // Texture coordinates
            ,topColor              // Color
        };
        modelData->addVertex(vertex);
    }
    {
        Vertex vertex = {
            {1.f, 1.f, -1.f}                  // Position
            ,topNormal   // Normal
            ,{ 0.f, 0.f}                        // Texture coordinates
            ,topColor            // Color
        };
        modelData->addVertex(vertex);
    }
    {
        Vertex vertex = {
            { -1.f, 1.f, -1.f}                  // Position
            ,topNormal   // Normal
            ,{ 0.f, 0.f}                        // Texture coordinates
            ,topColor            // Color
        };
        modelData->addVertex(vertex);
    }
    
    
    //--- Left ---
    spvu::Normal leftNormal = { -1.0f, 0.0f, 0.0f};
    spvu::Color leftColor = {1.f, 1.f, 0.0f, 1.f};
    {
        Vertex vertex = {
            { -1.f, -1.f, -1.f}                  // Position
            ,leftNormal   // Normal
            ,{ 0.f, 0.f}                        // Texture coordinates
            ,leftColor             // Color
        };
        modelData->addVertex(vertex);
    }
    {
        Vertex vertex = {
            { -1.f, -1.f, 1.f}                  // Position
            ,leftNormal   // Normal
            ,{ 0.f, 0.f}                        // Texture coordinates
            ,leftColor              // Color
        };
        modelData->addVertex(vertex);
    }
    {
        Vertex vertex = {
            {-1.f, 1.f, 1.f}                  // Position
            ,leftNormal   // Normal
            ,{ 0.f, 0.f}                        // Texture coordinates
            ,leftColor            // Color
        };
        modelData->addVertex(vertex);
    }
    {
        Vertex vertex = {
            { -1.f, 1.f, -1.f}                  // Position
            ,leftNormal   // Normal
            ,{ 0.f, 0.f}                        // Texture coordinates
            ,leftColor            // Color
        };
        modelData->addVertex(vertex);
    }
    
    
    //--- Bottom ---
    spvu::Normal bottomNormal = { 0.0f, -1.0f, 0.0f};
    spvu::Color bottomColor = {0.0f, 1.f, 1.f, 1.f};
    {
        Vertex vertex = {
            { -1.f, -1.f, -1.f}                  // Position
            ,{ 0, -1, 0}   // Normal
            ,{ 0.f, 0.f}                        // Texture coordinates
            ,bottomColor             // Color
        };
        modelData->addVertex(vertex);
    }
    {
        Vertex vertex = {
            { -1.f, -1.f, 1.f}                  // Position
            ,bottomNormal   // Normal
            ,{ 0.f, 0.f}                        // Texture coordinates
            ,bottomColor              // Color
        };
        modelData->addVertex(vertex);
    }
    {
        Vertex vertex = {
            {1.f, -1.f, 1.f}                  // Position
            ,bottomNormal   // Normal
            ,{ 0.f, 0.f}                        // Texture coordinates
            ,bottomColor            // Color
        };
        modelData->addVertex(vertex);
    }
    {
        Vertex vertex = {
            { 1.f, -1.f, -1.f}                  // Position
            ,bottomNormal   // Normal
            ,{ 0.f, 0.f}                        // Texture coordinates
            ,bottomColor            // Color
        };
        modelData->addVertex(vertex);
    }
    
    
    //--- Back ---
    spvu::Normal backNormal = {0.0, 0.0, -1.0};
    spvu::Color backColor = {1.f, 1.0f, 1.0f, 1.f};
    {
        Vertex vertex = {
            { 1.f, -1.f, -1.f}                  // Position
            ,backNormal   // Normal
            ,{ 0.f, 0.f}                        // Texture coordinates
            ,backColor             // Color
        };
        modelData->addVertex(vertex);
    }
    {
        Vertex vertex = {
            { -1.f, -1.f, -1.f}                  // Position
            ,backNormal   // Normal
            ,{ 0.f, 0.f}                        // Texture coordinates
            ,backColor              // Color
        };
        modelData->addVertex(vertex);
    }
    {
        Vertex vertex = {
            {-1.f, 1.f, -1.f}                  // Position
            ,backNormal   // Normal
            ,{ 0.f, 0.f}                        // Texture coordinates
            ,backColor            // Color
        };
        modelData->addVertex(vertex);
    }
    {
        Vertex vertex = {
            { 1.f, 1.f, -1.f}                  // Position
            ,backNormal   // Normal
            ,{ 0.f, 0.f}                        // Texture coordinates
            ,backColor            // Color
        };
        modelData->addVertex(vertex);
    }
    
    
    
    modelData->addIndex(0);
    modelData->addIndex(1);
    modelData->addIndex(2);
    
    modelData->addIndex(6);
    modelData->addIndex(7);
    modelData->addIndex(4);
    
    modelData->addIndex(2);
    modelData->addIndex(3);
    modelData->addIndex(0);
    
    // Front
    modelData->addIndex(0);
    modelData->addIndex(1);
    modelData->addIndex(2);
    
    modelData->addIndex(2);
    modelData->addIndex(3);
    modelData->addIndex(0);
    
    
    // Right
    modelData->addIndex(4);
    modelData->addIndex(5);
    modelData->addIndex(6);
    
    modelData->addIndex(6);
    modelData->addIndex(7);
    modelData->addIndex(4);
    //
    //
    //    // Top
    modelData->addIndex(8);
    modelData->addIndex(9);
    modelData->addIndex(10);
    
    modelData->addIndex(10);
    modelData->addIndex(11);
    modelData->addIndex(8);
    
    //Left
    modelData->addIndex(12);
    modelData->addIndex(13);
    modelData->addIndex(14);
    
    modelData->addIndex(14);
    modelData->addIndex(15);
    modelData->addIndex(12);
    
    //    //Bottom
    modelData->addIndex(16);
    modelData->addIndex(17);
    modelData->addIndex(18);
    
    modelData->addIndex(18);
    modelData->addIndex(19);
    modelData->addIndex(16);
    //
    //    // Back
    modelData->addIndex(20);
    modelData->addIndex(21);
    modelData->addIndex(22);
    
    modelData->addIndex(22);
    modelData->addIndex(23);
    modelData->addIndex(20);
    
    
    return modelData;
}