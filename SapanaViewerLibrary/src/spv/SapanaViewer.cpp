//
//  SapanaViewer.cpp
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 03.01.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Class definition include
#include "SapanaViewer.h"


// External includes
#include <memory.h>

// Project includes
#include "TypeDefSpv.h"

#include "SceneGraph.h"
#include "SceneGraphController.h"
#include "SceneRenderer.h"
#include "SceneRendererController.h"
#include "SceneNodeTreeView.h"
#include "ListSpv.h"
#include "ModelList.h"
#include "HierarchicalModelList.h"


// Test includes
#include "ModelRenderer.h"
#include "TestSceneRendererContext.h"
#include "TestRenderableScene.h"
#include "TestSceneManager.h"
#include "TestSceneNodeTreeView.h"
#include "CubeData.h"

#include "SceneNode.h"
#include "FrameNode.h"
#include "RootNode.h"
#include "ModelNode.h"
#include "TestCameraNode.h"

namespace spv
{
namespace detail
{
class SapanaViewer: public ISapanaViewer{
public:
    
    SapanaViewer()
    {
        
        sceneGraphController_ = createTestSceneGraphController();

        
        // DEBUG
        std::shared_ptr< spvr::SceneRendererContext > srContext_(std::make_shared< spvt::TestSceneRendererContext >());
        
        std::shared_ptr< spvr::ModelRenderer >  mRenderer_(std::make_shared< spvr::ModelRenderer >());
        
        std::shared_ptr< spvt::TestRenderableScene >  testRScene_(std::make_shared< spvt::TestRenderableScene >(sceneGraphController_->getScene()));
        
        std::shared_ptr< spvr::SceneRenderer > sRenderer_(std::make_shared< spvr::SceneRenderer > (testRScene_,  mRenderer_, srContext_));
        sRenderer_->init();
        
        std::shared_ptr< spv::SceneRendererController > testSRManager_(std::make_shared< spv::SceneRendererController >(testRScene_, sRenderer_));

        std::shared_ptr< spv::SceneNodeController > snController_(sceneGraphController_->getSelectedSceneNodeController());

        std::shared_ptr< spvg::SceneNodeTreeView > treeView_( std::make_shared< spvg::SceneNodeTreeView >(sceneGraphController_->getScene()));
       
       // Final
        
        sceneRendererManager_ = testSRManager_;
        sceneNodeTreeList_ = treeView_;
        ;
        modelListControler_ = std::make_shared< spv::ListController >(new spvg::ListSpv (new spvg::ModelList(sceneGraphController_->getScene()) ));
        
        hModelNodeListController_ = std::make_shared< HierarchicalListController >(new spvg::HierarchicalList (new spvg::HierarchicalModelList(sceneGraphController_->getScene())));
        //subControllers_.push_back(hModelNodeListController_);
    // End Final
        
        std::shared_ptr< spv::SceneNodeController > cameraNodeModifier_(sceneGraphController_->getObserverCameraModifier());
        observerCameraModifier_ = cameraNodeModifier_;

        
        // DEBUG
        sceneRendererManager_->update();
    }
    
    
    virtual void initOpenGL()
    {
        sceneRendererManager_->initOpenGL();
    }
    
    virtual void update()
    {
        std::for_each(subControllers_.begin(), subControllers_.end(),
                      [&](std::shared_ptr< IController > subController)
                      {
                          subController->update();
                      }
                      );
        
        // TODO Remove
        sceneRendererManager_->update();
        sceneGraphController_->update();
        hModelNodeListController_->update();
    }
    
    virtual void drawScene()
    {
        sceneRendererManager_->renderScene();
    }
    
    virtual spv::SceneNodeController * getObserverCameraModifier()
    {
        // WARNING TODO - ugly code
        return observerCameraModifier_.get();
    }
    
    void selectSceneNode(spvu::SceneNodeID sceneNodeId)
    {
        sceneGraphController_->selectSceneNode(sceneNodeId);
    }
    
    spv::SceneNodeController * getSelectedNodeModifier()
    {
        // WARNING TODO - ugly code
        return sceneGraphController_->getSelectedSceneNodeController().get();
    }
    
    virtual spv::ListController * getFlatModelList()
    {
       // WARNING TODO - ugly code
        return modelListControler_.get();
    }
    
    virtual spv::HierarchicalListController * getHierarchicalModelListController()
    {
        return hModelNodeListController_.get();
    }
    
    virtual spv::ListController * getFlatCameraList()
    {
        return nullptr;
    }
    
    void moveNode(spvu::SceneNodeID childID, spvu::SceneNodeID parentID)
    {
        sceneGraphController_->moveNode(childID, parentID);
    }
    
    virtual std::string getNameForNode(unsigned long nodeID)
    {
        return sceneGraphController_->getNameForNode(nodeID);
    }
    
private:
    
    std::vector< std::shared_ptr< IController > > subControllers_;
    
    std::shared_ptr< spv::SceneGraphController > sceneGraphController_;
    std::shared_ptr< spv::SceneRendererController > sceneRendererManager_;
    std::shared_ptr< spv::ListController > modelListControler_;
    std::shared_ptr< spv::HierarchicalListController > hModelNodeListController_;//hierarchicalModelNodeList_;
    
    std::shared_ptr< spvg::SceneNodeTreeView > sceneNodeTreeList_;
    std::shared_ptr< spv::SceneNodeController > observerCameraModifier_;
    
    
#pragma mark - DEBUG Methodes
    std::shared_ptr< spv::SceneGraphController > createTestSceneGraphController()
    {
        
        auto scenGraph = std::make_shared< spvs::SceneGraph >();
    
        
        // Set up the scene manager
        
         std::shared_ptr< spv::SceneGraphController > sceneGraphController = std::make_shared< spv::SceneGraphController >(scenGraph);
        
        // Build Scene Graph
  
        
        
        // Create model data
        auto modelData = std::make_shared< const spvt::CubeData >( );
        spvs::ModelNode model1(modelData);
        spvs::ModelNode model2(std::make_shared< const spvt::CubeData >( ));
        
 
        //sceneGraph_->addNode(testRootNode, coordLines1);
        
        // Get ID of root node
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
        
        // Add cameras
        spvs::CameraNode cNode = spvt::TestCameraNode();
        scenGraph->addNode(rootNode, cNode);
        // Add models
        
        sceneGraphController->addSceneNode( model2, frameNodeID, "Model Node 2");
        sceneGraphController->addSceneNode( model1, frameNodeID, "Model Node 1");
        //sceneGraphController->getScene()->addNode(frameNodeID, model2);
        // scenGraph->addNode(testRootNode, model1);
        // scenGraph->addNode(testRootNode, model2);
        
        //sceneGraph_->addNode(frameNodeID, coordLines2);
        
        sceneGraphController->selectObserverCameraNode(sceneGraphController->getScene()->getActiveCamerNode());
        
        return sceneGraphController;
    }
    
};

}
    
SapanaViewer::SapanaViewer()
{
    impl_ = new detail::SapanaViewer();
}

SapanaViewer::~SapanaViewer()
{
  // delete impl_;
}
    
} // End spv


