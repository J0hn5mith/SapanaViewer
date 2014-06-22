//
//  LightSourceNodeRenderer.cpp
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 04.04.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Class definition include
#include "LightSourceNodeRenderer.h"

// External includes

// Project includes
#include "RenderableLightSource.h"
#include "RendererUtils.h"

using namespace spvr;
                                                                                
LightSourceNodeRenderer::LightSourceNodeRenderer()                                        
{                                                                               
  // TODO: Implement                                     
}                                                                               
                                                                                
LightSourceNodeRenderer::~LightSourceNodeRenderer()                                      
{                                                                               
  // TODO: Implement
}

void LightSourceNodeRenderer::renderLightSourceNode(std::shared_ptr< const RenderableLightSourceNode > renderableLightSourceNode, unsigned int lightNumber) const
{
    GLenum targetLightSource = GL_LIGHT0;
    
    setPosition(renderableLightSourceNode);
    
    
     std::shared_ptr< const spvr::RenderableLightSource > renderableLightSource = renderableLightSourceNode->getRenderableLightSource();
    renderableLightSource->getAmbient();
    glEnable(targetLightSource);
    
    //const GLfloat light0Ambient[] = {0.05, 0.05, 0.05, 1.0};
    spvu::Color c = renderableLightSource->getAmbient();
    float* colorArray = reinterpret_cast<float*>(&c);
    glLightfv(targetLightSource, GL_AMBIENT, colorArray );
    
    c = renderableLightSource->getDifuse();
    colorArray = reinterpret_cast<float*>(&c);
    glLightfv(targetLightSource, GL_DIFFUSE, colorArray);
    
    c = renderableLightSource->getSpecular();
    colorArray = reinterpret_cast<float*>(&c);
    glLightfv(targetLightSource, GL_SPECULAR, colorArray);
    
    const GLfloat light0Position[] = {1.0, 1.0, 1.0, 0.0};
    
    glLightfv(targetLightSource, GL_POSITION, light0Position);
    // Define a direction vector for the light, this one points right down the Z axis
    const GLfloat light0Direction[] = {0.0, 0.0, 0.0};
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, light0Direction);
    
    spvr::RendererUtils::drawLine({1,1,1}, {0,0,0}, {1,0,1,1});
    
    unsetPosition();
    
}

void LightSourceNodeRenderer::setPosition(std::shared_ptr< const RenderableLightSourceNode > node) const
{
    spvu::TransMatrix    transMatrix =  *node->getTransMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glMultMatrixf(transMatrix);
}

void LightSourceNodeRenderer::unsetPosition() const
{
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}