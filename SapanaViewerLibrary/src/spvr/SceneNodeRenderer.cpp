//
//  SceneNodeRenderer.cpp
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 10.04.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Class definition include
#include "SceneNodeRenderer.h"

// External includes

// Project includes
#include "RendererUtils.h"

using namespace spvr;

SceneNodeRenderer::SceneNodeRenderer()
: parentLineColor_({0.0, 1.0, 1.0, 1.0})
, originLineColor_({0.0, 1.0, 1.0, 1.0})
{
}
                                                                                
SceneNodeRenderer::~SceneNodeRenderer()                                      
{                                                                               
  // TODO: Implement
}


#pragma mark Render Utlity Methodes
void SceneNodeRenderer::renderSceneNode(std::shared_ptr< const spvr::RenderableSceneNode > node)
{
    this->drawLineToOrigin(node);
}


#pragma mark Render Utlity Methodes
void SceneNodeRenderer::setPosition(std::shared_ptr< const RenderableSceneNode > node) const
{
    spvu::TransMatrix    transMatrix =  node->getWorldTransMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glMultMatrixf(transMatrix);
}

void SceneNodeRenderer::unsetPosition() const
{
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}

void SceneNodeRenderer::drawLineToParent(std::shared_ptr< const RenderableSceneNode > node) const
{
    
    auto worldTrans = node->getWorldTransMatrix();
    auto nodeTrans = node->getNodeTransMatrix();
    
    spvu::Position startPosition = {};
    startPosition.x = worldTrans[0][3];
    startPosition.y = worldTrans[1][3];
    startPosition.z = worldTrans[2][3];
    
    spvu::Position endPosition;
    endPosition.x =  startPosition.x - nodeTrans[0][3];
    endPosition.y =  startPosition.y - nodeTrans[1][3];
    endPosition.z =  startPosition.z - nodeTrans[2][3];
    
    spvr::RendererUtils::drawLine(startPosition, endPosition, parentLineColor_);
}

void SceneNodeRenderer::drawLineToOrigin(std::shared_ptr< const RenderableSceneNode > node) const
{

    
    auto transformation = node->getWorldTransMatrix();
    
    spvu::Position endPosition;
    endPosition.x = transformation[0][3];
    endPosition.y = transformation[1][3];
    endPosition.z = transformation[2][3];
    
    spvr::RendererUtils::drawLine({0, 0, 0}, endPosition, this->originLineColor_);
}