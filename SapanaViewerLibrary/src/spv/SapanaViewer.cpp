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

// Project Includes
#include "TypeDefSpv.h"
#include "ModelLoader.h"

// Project Includes: Controllers
#include "SceneGraphController.h"
#include "SceneRendererController.h"

// Project Includes: Scene Graph
#include "SceneGraph.h"
#include "LightSourceNode.h"
#include "SceneNode.h"
#include "FrameNode.h"
#include "RootNode.h"
#include "ModelNode.h"
#include "Camera.h"
#include "CameraNode.h"

// Project Includes: Renderer
#include "SceneRenderer.h"
#include "SceneRendererContext.h"
#include "ModelRenderer.h"
#include "LightSourceNodeRenderer.h"
#include "SceneNodeRenderer.h"
#include "RenderableScene.h"

// Project Includes: Lists
#include "ListSpv.h"
#include "ModelList.h"
#include "CameraList.h"
#include "HierarchicalModelList.h"
#include "SceneNodeTreeView.h" //TODO: Remove because it's deptrecated


// Dummy Data
#include "TestData.h"

namespace spv
{
namespace detail
{

/**
 * @brief Private implementation for the spv::SapanaViewer class.
 */
class SapanaViewer: public ISapanaViewer{
public:
    
    SapanaViewer()
    {

        // Sceme
        sceneGraphController_ = spvu::TestData::getTestSceneController();
        subControllers_.push_back(sceneGraphController_);
        std::shared_ptr< spvr::RenderableScene >  testRScene_(std::make_shared< spvr::RenderableScene >(sceneGraphController_->getScene()));
        
        
        // List controllers
        modelListControler_ = std::make_shared< spv::ListController >(new spvg::ListSpv (new spvg::ModelList(sceneGraphController_->getScene()) ));
        hModelNodeListController_ = std::make_shared< HierarchicalListController >(new spvg::HierarchicalList (new spvg::HierarchicalModelList(sceneGraphController_->getScene())));
        subControllers_.push_back(hModelNodeListController_);
        cameraListController_ = std::make_shared< spv::ListController >(new spvg::ListSpv (new spvg::CameraList(sceneGraphController_->getScene()) ));

        
        // Observer Camera
        std::shared_ptr< spv::SceneNodeController > cameraNodeModifier_(sceneGraphController_->getObserverCameraModifier());
        observerCameraModifier_ = cameraNodeModifier_;

        
         // Renderer
        int screenWidth = 728*2;
        int screenHeight = 728*2;
        std::shared_ptr< spvr::SceneRendererContext > srContext_(std::make_shared< spvr::SceneRendererContext >(0, 0, screenWidth,screenHeight));
        std::shared_ptr< spvr::SceneNodeRenderer > sceneNodeRenderer = std::make_shared< spvr::SceneNodeRenderer >();
        std::shared_ptr< spvr::ModelRenderer >  mRenderer_(std::make_shared< spvr::ModelRenderer >(sceneNodeRenderer));
        std::shared_ptr< spvr::LightSourceNodeRenderer >  lRenderer(std::make_shared< spvr::LightSourceNodeRenderer >());
        std::shared_ptr< spvr::SceneNodeRenderer >  fRenderer(std::make_shared< spvr::SceneNodeRenderer >());
        
        
        // Render Controller
        std::shared_ptr< spvr::SceneRenderer > sRenderer_(std::make_shared< spvr::SceneRenderer > (testRScene_,  mRenderer_, lRenderer, fRenderer,  srContext_));
        sceneRenderController_ = std::make_shared< spv::SceneRendererController >(testRScene_, sRenderer_);
        subControllers_.push_back(sceneRenderController_);
        
        
        // Scene Node Controller
        std::shared_ptr< spv::SceneNodeController > snController_(sceneGraphController_->getSelectedSceneNodeController());
        
        
        // Configurations
        sRenderer_->init();
        sceneRenderController_->update();
    }
    
    virtual void initOpenGL()
    {
        sceneRenderController_->initOpenGL();
    }
    
    virtual void update()
    {
        std::for_each(subControllers_.begin(), subControllers_.end(),
                      [&](std::shared_ptr< IController > subController)
                      {
                          subController->update();
                      }
                      );
    }
    
    virtual void drawScene()
    {
        sceneRenderController_->renderScene();
    }
    
    /**
     * @warning Access to raw pointer of smart pointer.
     * @todo change
     */
    virtual spv::SceneNodeController * getObserverCameraModifier()
    {
        // WARNING TODO - ugly code
        return observerCameraModifier_.get();
    }
    
    /**
     * @warning Access to raw pointer of smart pointer.
     */
    void selectSceneNode(spvu::SceneNodeID sceneNodeId)
    {
        sceneGraphController_->selectSceneNode(sceneNodeId);
    }
    
    /**
     * @warning Access to raw pointer of smart pointer.
     * @todo change
     */
    spv::SceneNodeController * getSelectedNodeModifier()
    {
        return sceneGraphController_->getSelectedSceneNodeController().get();
    }
    
    /**
     * @warning Access to raw pointer of smart pointer.
     * @todo change
     */
    virtual spv::ListController * getFlatModelList()
    {
       // WARNING TODO - ugly code
        return modelListControler_.get();
    }
    
    /**
     * @warning Access to raw pointer of smart pointer.
     * @todo change
     */
    virtual spv::HierarchicalListController * getHierarchicalModelListController()
    {
        return hModelNodeListController_.get();
    }
    
    /**
     * @warning Access to raw pointer of smart pointer.
     * @todo change
     */
    virtual spv::ListController * getFlatCameraList()
    {
        return cameraListController_.get();
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
    std::shared_ptr< spv::SceneRendererController > sceneRenderController_;
    
#pragma mark List Controllers
    std::shared_ptr< spv::ListController > modelListControler_;
    std::shared_ptr< spv::ListController > cameraListController_;
    
    std::shared_ptr< spv::HierarchicalListController > hModelNodeListController_;//hierarchicalModelNodeList_;
    
    std::shared_ptr< spv::SceneNodeController > observerCameraModifier_;
    
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


