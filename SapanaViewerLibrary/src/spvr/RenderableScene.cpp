/*
 * RenderableScene.cpp
 *
 *  Created on: Dec 13, 2013
 *      Author: janmeier
 */

#include"RenderableScene.h"

// Class definition

// External includes
#include <map>

// Project includes
#include "SceneGraph.h"
#include "RenderableModel.h"
#include "RenderableCameraNode.h"
#include "RenderableModelNode.h"
#include "ModelNode.h"

using namespace spvr;
// TODO: Error handling if scene has no models or camera or what else
RenderableScene::RenderableScene(std::shared_ptr< const spvs::SceneGraph > sceneGraph)
: sceneGraph_(sceneGraph)
, renderableModelNodes_()
, activeCameraNode_(std::make_shared< const RenderableCameraNode >(sceneGraph_->getActiveCamerNode()))
, observerImpl_(std::make_shared< spvu::ObserverImpl>())
, visibleModelNodes_(std::make_shared<std::vector< std::shared_ptr< const RenderableModelNode > >>())
{
	// Create RenderableModelNode for each model node of the Scene
    createRenderableModels();
    sceneGraph_->registerObserver(observerImpl_);
}

RenderableScene::~RenderableScene()
{
    
}

std::shared_ptr< std::vector< std::shared_ptr< const RenderableModelNode > > > RenderableScene::getRenderbaleModelNodes() const
{
    // TODO Implement update mechanism, if the modelnodes change, this is not
    // handled in the RenderableModelNode. Also, the modification of the scene
    // graph (node removel or adding) is not taken into account. 
    return visibleModelNodes_;
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
    auto modelNodes = *(sceneGraph_->getModelNodes());
    for (std::shared_ptr< const spvs::ModelNode > mNode : modelNodes )
    {
        std::shared_ptr< const RenderableModelNode > rmNode = std::make_shared< RenderableModelNode >(mNode);
        
        renderableModelNodes_.insert({mNode->getID(), rmNode});
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



