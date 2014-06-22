/*
 * RenderableScene.cpp
 *
 *  Created on: Dec 13, 2013
 *      Author: janmeier
 */



// Class definition
#include"RenderableScene.h"


// External includes
#include <map>


// Project Includes
#include "SceneGraph.h"
#include "ModelNode.h"
#include "FrameNode.h"

// Project Includes: Renderable Nodes
#include "RenderableCameraNode.h"
#include "RenderableModelNode.h"
#include "RenderableLightSourceNode.h"
#include "RenderableSceneNode.h"

// Project Includes: Renderable Data
#include "RenderableModel.h"


using namespace spvr;


#pragma mark - Con- & Destructors
// TODO: Error handling if scene has no models or camera or what else
RenderableScene::RenderableScene(std::shared_ptr< const spvs::SceneGraph > sceneGraph)
: sceneGraph_(sceneGraph)
, renderableModelNodes_()
, renderableLightSourceNodes_()
, renderableFrameNodes_()
, activeCameraNode_(std::make_shared< const RenderableCameraNode >(sceneGraph_->getActiveCamerNode()))
, observerImpl_(std::make_shared< spvu::ObserverImpl>())
, visibleModelNodes_(std::make_shared<std::vector< std::shared_ptr< const RenderableModelNode > >>())
, clearColor_({1.0, 1.0, 1.0, 1.0})
{
	// Create RenderableModelNode for each model node of the Scene
    createRenderableModels();
    createRenderableLightSources();
    createRenderableFrameNodes();
    sceneGraph_->registerObserver(observerImpl_);
}

RenderableScene::~RenderableScene()
{
    
}


#pragma mark - Getter and Setter Methodes
std::shared_ptr< std::vector< std::shared_ptr< const RenderableModelNode > > > RenderableScene::getRenderbaleModelNodes() const
{
    // TODO Implement update mechanism, if the modelnodes change, this is not
    // handled in the RenderableModelNode. Also, the modification of the scene
    // graph (node removel or adding) is not taken into account. 
    return visibleModelNodes_;
}

std::vector< std::shared_ptr< const RenderableLightSourceNode > >  RenderableScene::getRenderbaleLightSourceNodes() const
{
    // TODO: Performance
    std::vector< std::shared_ptr< const RenderableLightSourceNode > > v;
    std::for_each(renderableLightSourceNodes_.begin(), renderableLightSourceNodes_.end(),
                  [&](std::pair < spvu::SceneNodeID, std::shared_ptr< const RenderableLightSourceNode > >pair)
                  {
                      v.push_back(pair.second);
                  });
    
    return v;
}

std::vector< std::shared_ptr< const RenderableSceneNode > >  RenderableScene::getRenderbaleFrameNodes() const
{
    // TODO: Performance
    std::vector< std::shared_ptr< const RenderableSceneNode > > v;
    
    std::for_each(renderableFrameNodes_.begin(), renderableFrameNodes_.end(),
                  [&](std::pair < spvu::SceneNodeID, std::shared_ptr< const RenderableSceneNode > >pair)
                  {
                      v.push_back(pair.second);
                  });
    
    return v;
}

std::shared_ptr< const RenderableCameraNode > RenderableScene::getActiveCameraNode() const
{
    return activeCameraNode_;
}

void RenderableScene::update() const
{
    updateRenderables();
    RenderableScene * unconsThis = const_cast< RenderableScene * >(this);
    if (observerImpl_->hasNotification())
    {
        unconsThis->handleNotifications();
    }
    
    observerImpl_->update();
}


void RenderableScene::createRenderableModels()
{
    auto modelNodes = sceneGraph_->getModelNodes();
    for (std::shared_ptr< const spvs::ModelNode > mNode : modelNodes )
    {
        std::shared_ptr< const RenderableModelNode > rmNode = std::make_shared< RenderableModelNode >(mNode);
        
        renderableModelNodes_.insert({mNode->getID(), rmNode});
    }
    updateVisibleModelNodes();
}

void RenderableScene::createRenderableLightSources()
{
    auto lightSourceNodes = *(sceneGraph_->getLightSourceNodes());
    for (std::shared_ptr< const spvs::LightSourceNode > lightSourceNode : lightSourceNodes )
    {
        std::shared_ptr< const RenderableLightSourceNode > renderableLightSourceNode = std::make_shared< RenderableLightSourceNode >(lightSourceNode);
        
        renderableLightSourceNodes_.insert({lightSourceNode->getID(), renderableLightSourceNode});
    }
   
}

void RenderableScene::createRenderableFrameNodes()
{
    auto frameNodes = sceneGraph_->getFrameNodes();
    
    for (std::shared_ptr< const spvs::FrameNode > frameNode : frameNodes )
    {
        std::shared_ptr< const RenderableSceneNode > renderableSceneNode = std::make_shared< RenderableSceneNode >(frameNode);
        
        renderableFrameNodes_.insert({frameNode->getID(), renderableSceneNode});
    }
    updateVisibleModelNodes();
}

void RenderableScene::updateRenderables() const
{
    activeCameraNode_->update();
    
    for (auto node : *getRenderbaleModelNodes())
    {
        node->update();
    }
    
    for (auto node : getRenderbaleLightSourceNodes())
    {
        node->update();
    }
    
    for (auto node : getRenderbaleFrameNodes())
    {
        node->update();
    }
}

void RenderableScene::handleNotifications()
{
    for(auto notification : *(observerImpl_->getNotifications()))
    {
        // TODO: handle 1) Node insertation/ removal 2) active camera node changed 3) Camera has changed and set of visible nodes changed
        // TODO, DEBUG
        
        if (notification->getID() == spvs::SceneGraph::NEW_NODE)
        {
            spvu::SceneNodeID nodeID = notification->getContent();
            std::shared_ptr< const spvs::ModelNode > mNode = std::dynamic_pointer_cast< const spvs::ModelNode >(sceneGraph_->getNode(nodeID));
            
            std::shared_ptr< const spvr::RenderableModelNode > rmNode = std::make_shared< RenderableModelNode >(mNode);
            
            renderableModelNodes_.insert({nodeID, rmNode});
            
            updateVisibleModelNodes();
        }
        else if (notification->getID() == spvs::SceneGraph::NODE_DELETED)
        {
            if (renderableModelNodes_.erase(notification->getContent()) == 0)
            {
                std::cout << "Node could not be deleted because node is not in list." << std::endl;
            }
            updateVisibleModelNodes();
        }
        else
        {
           std::cout << "RenderableScene::handleNotifications - Unabel to handle notification." << std::endl;
        }
    }
}
    
void RenderableScene::updateVisibleModelNodes()
{
    visibleModelNodes_->clear();
    for (auto & mNode : renderableModelNodes_)
    {
        visibleModelNodes_->push_back(mNode.second);
;
    }
}



