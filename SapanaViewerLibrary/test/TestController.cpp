//
//  TestController.cpp
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 20.12.13.
//  Copyright (c) 2013 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Base class includes
#include "TestController.h"

// External includes
#include <iostream>
#include <memory.h>
// TODO: Remove iOS dependent code
#include <OpenGLES/ES1/gl.h>

// Project includes
#include "SceneRenderer.h"
#include "SceneRendererContext.h"
#include "RenderableScene.h"
#include "ModelRenderer.h"
#include "SceneRendererController.h"
#include "SceneNodeModifier.h"
#include "SceneGraph.h"
#include "RootNode.h"
#include "SceneGraphController.h"

// Test includes
#include "TestSceneData.h"
#include "TestSceneRendererContext.h"
#include "TestRenderableScene.h"
#include "TestSceneRenderer.h"
#include "TestSceneNodeTreeView.h"
#include "CubeData.h"

// Debug includes

namespace spvt
{
namespace detail
{
class TestController
{
public:
//    TestController()
//    : srContext_(std::make_shared< spvt::TestSceneRendererContext >())
//    , mRenderer_(std::make_shared< spvr::ModelRenderer >())
//    , testScene_(std::make_shared< spvt::TestSceneData >())
//    , testRScene_(std::make_shared< spvt::TestRenderableScene >(testScene_->getSceneGraph()))
//    , sRenderer_(std::make_shared< spvt::TestSceneRenderer > (testRScene_,  mRenderer_, srContext_))
//    , testSRManager_(std::make_shared< spvr::SceneRendererManager >(testRScene_, sRenderer_))
//    , testSceneGraphController_(std::make_shared< spvt::TestSceneGraphController >(testScene_->getSceneGraph()))
//    , snModifier_(testSceneGraphController_->getActiveSceneNodeModifier())
//    , cameraNodeModifier_(testSceneGraphController_->getActiveCameraNodeModifier())
//    , treeView_( std::make_shared< spvg::SceneNodeTreeView >(testScene_->getSceneGraph()))
//    {
//         // unallowed access
//    }

    virtual void update(int timeDelta)
    {
        testSRManager_->update();
        treeView_->update();
    }

    virtual void draw()
    {
        testSRManager_->renderScene();
    }
    
    void setViewport(int x, int y, int width, int height)
    {
        testSRManager_->setViewport(x, y, width, height);
    }

    void setYRotation(float yRotation)
    {
        //testScene_->getTestModelNode()->setYRotation(yRotation);
    }
    
    void selectSceneNode(unsigned int nodeID)
    {
        snModifier_ = testScene_->getSceneGraph()->getNodeModifier(nodeID);
    }
    
    void rotateX(float xRotation)
    {
        snModifier_->rotateX(xRotation);
    }

    void rotateY(float yRotation)
    {
        snModifier_->rotateY(yRotation);
    }

    void rotateZ(float zRotation)
    {
        snModifier_->rotateZ(zRotation);
    }
    
    void shiftX(float deltaX)
    {
        snModifier_->translateX(deltaX);
    }
    
    void shiftY(float deltaY)
    {
        snModifier_->translateY(deltaY);
    }

    void shiftZ(float deltaZ)
    {
        snModifier_->translateZ(deltaZ);
    }
    
    void rotateCameraX(float xRotation)
    {
        cameraNodeModifier_->rotateX(xRotation);
    }
    
    void rotateCameraY(float yRotation)
    {
        cameraNodeModifier_->rotateY(yRotation);
    }
    
    void rotateCameraZ(float zRotation)
    {
        cameraNodeModifier_->rotateZ(zRotation);
    }
    
    void shiftCameraX(float deltaX)
    {
        cameraNodeModifier_->translateX(deltaX);
    }
    
    void shiftCameraY(float deltaY)
    {
        cameraNodeModifier_->translateY(deltaY);
    }
    
    void shiftCameraZ(float deltaZ)
    {
        cameraNodeModifier_->translateZ(deltaZ);
    }
    
    std::vector< spvg::TreeViewNode > getTreeView()
    {
        return treeView_->getItems();
    }
    
    void switchItem(int itemPosition)
    {
        treeView_->toggleItem(itemPosition);
    }
    
    void expandItem(int itemPosition)
    {
        treeView_->expandItem(itemPosition);
    }
    
    void collapseItem(int itemPosition)
    {
        treeView_->collapseItem(itemPosition);
    }
    
    void deleteNode(unsigned int nodeID)
    {
        testScene_->getSceneGraph()->removeNode(nodeID);
    }
    
    void addNode()
    {
        spvs::ModelNode model(std::make_shared< const spvt::CubeData >( ));
        
        auto sceneGraph = testScene_->getSceneGraph();
    
        sceneGraph->addNode(sceneGraph->getRootNode(), model);
    }
    
private:

    std::shared_ptr< spvr::SceneRendererContext > srContext_;
    std::shared_ptr< spvr::ModelRenderer >  mRenderer_;
    std::shared_ptr< spvt::TestSceneData > testScene_;
    std::shared_ptr< TestRenderableScene >  testRScene_;
    std::shared_ptr< spvr::SceneRenderer > sRenderer_;
    std::shared_ptr< spv::SceneRendererController > testSRManager_;
    std::shared_ptr< spv::SceneGraphController > testSceneGraphController_;
    std::shared_ptr< spvs::SceneNodeModifier > snModifier_;
    std::shared_ptr< spvs::SceneNodeModifier > cameraNodeModifier_;
    std::shared_ptr< spvg::SceneNodeTreeView > treeView_;
};
} // end namespace detail

TestController::TestController()
{
    // TODO: Implement
    impl_ = new spvt::detail::TestController();
}

TestController::~TestController()
{
    // TODO: Implement
}

  void TestController::update(int timeDelta)
  {
    impl_->update(timeDelta);
  }
  
  void TestController::draw()
  {
    impl_->draw();
  }

void TestController::setYRotation(float yRotation)
{
  impl_->setYRotation(yRotation);
}

void TestController::rotateX(float xRotation)
{
  impl_->rotateX(xRotation);
}

void TestController::selectSceneNode(unsigned int nodeID)
{
    impl_->selectSceneNode(nodeID);
}
    
void TestController::rotateY(float yRotation)
{
  impl_->rotateY(yRotation);
}

void TestController::rotateZ(float zRotation)
{
  impl_->rotateZ(zRotation);
}

void TestController::shiftX(float deltaX)
{
    impl_->shiftX(deltaX);
}

void TestController::shiftY(float deltaY)
{
    impl_->shiftY(deltaY);
}
    
void TestController::shiftZ(float deltaZ)
{
  impl_->shiftZ(deltaZ);
}
    
void TestController::rotateCameraX(float xRotation)
{
    impl_->rotateCameraX(xRotation);
}
    
void TestController::rotateCameraY(float yRotation)
{
    impl_->rotateCameraY(yRotation);
}

void TestController::rotateCameraZ(float zRotation)
{
    impl_->rotateCameraZ(zRotation);
}
    
void TestController::shiftCameraX(float deltaX)
{
    impl_->shiftCameraX(deltaX);
}

void TestController::shiftCameraY(float deltaY)
{
    impl_->shiftCameraY(deltaY);
}

void TestController::shiftCameraZ(float deltaZ)
{
    impl_->shiftCameraZ(deltaZ);
}
    
std::vector< spvg::TreeViewNode > TestController::getTreeView()
{
    return impl_->getTreeView();
}
    
void TestController::expandItem(int itemPosition)
{
    impl_->expandItem(itemPosition);
}


void TestController::collapseItem(int itemPosition)
{
    impl_->collapseItem(itemPosition);
}
    
void TestController::switchItem(int itemPosition)
{
    impl_->switchItem(itemPosition);
}
    
void TestController::setViewport(int x, int y, int width, int height)
{
    impl_->setViewport(x, y, width, height);
}
    
void TestController::deleteNode(unsigned int nodeID)
{
    impl_->deleteNode(nodeID);
}

void TestController::addNode()
{
    impl_->addNode();
}

} // End Namespace spvt


