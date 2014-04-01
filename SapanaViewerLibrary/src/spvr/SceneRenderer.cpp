/*
 * SceneRenderer.cpp
 *
 *  Created on: Dec 13, 2013
 *      Author: janmeier
 */

// Class definition
#include"SceneRenderer.h"

// External includes
#include <math.h>
#include <vector>

// Project includes
#include "Util.h"
#include "RenderableScene.h"
#include "SceneRendererContext.h"
#include "RenderableCameraNode.h"
#include "RenderableCamera.h"
#include "ModelRenderer.h"

// Debug includes

using namespace spvr;

SceneRenderer::SceneRenderer(
                             std::shared_ptr< const  RenderableScene > rScene
                             , std::shared_ptr< ModelRenderer > modelRenderer
                             , std::shared_ptr< SceneRendererContext > context
    )
: rScene_(rScene)
, modelRenderer_(modelRenderer)
, sceneRendererContext_(context)
{
	// TODOd: Implement
}

SceneRenderer::~SceneRenderer()
{
	// TODO: Implement
}


void SceneRenderer::init() const
{
  setUpOpenGL(rScene_);
}

void SceneRenderer::setViewport(GLint x, GLint y, GLint width, GLint height) const
{
    glViewport( x, y, width, height);
}

void SceneRenderer::render() const
{
    clearScreen(rScene_);
    setCameraPosition(rScene_);
    setProjection(rScene_);
    renderModels(rScene_);
    glFinish();
}

void SceneRenderer::setUpOpenGL(std::shared_ptr < const RenderableScene > renderableScene) const
{

    // TODO: Check if this is right because it was copied.
    // TODO: Use scene context for this setup.
    // Enable texture mapping.
    glEnable(GL_TEXTURE_2D);

    // Enable smooth shading.
    glShadeModel(GL_SMOOTH);

    // Set the depth value used when clearing the depth buffer.
    glClearDepthf(1.0f);

    // Enable depth testing.
    glEnable(GL_DEPTH_TEST);

    // Set the type of depth test.
    glDepthFunc(GL_LEQUAL);

    // Use the best perspective correction method.
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    
}

// TODO: Orthogonal projection
void SceneRenderer::setProjection(std::shared_ptr < const RenderableScene > renderableScene) const
{  
  std::shared_ptr< const spvr::RenderableCameraNode > cNode = renderableScene->getActiveCameraNode();
    std::shared_ptr< const vmml::frustumf > frustum = cNode->getRenderableCamera()->getViewFrustum(); // TODO: Ugly code, it would be nicer, if set projection would take a RenderableCamera as parameter since all needed data is inside this class
  const vmml::mat4f proMatrix = frustum->compute_matrix();
  
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glMultMatrixf(proMatrix.array);
}

void SceneRenderer::setCameraPosition(std::shared_ptr < const RenderableScene > renderableScene) const
{
    std::shared_ptr< const spvu::TransMatrix > transMatrix = renderableScene->getActiveCameraNode()->getTransMatrix();
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glMultMatrixf(transMatrix->array);
}


void SceneRenderer::clearScreen(std::shared_ptr < const RenderableScene > renderableScene) const
{
  // TODO: Was copied from example, check if everything is right
    
    std::vector<float> color = renderableScene->getClearColor();
    float red = color.at(0);
    float green = color.at(1);
    float blue = color.at(2);
    float alpha = color.at(3);
    
    glClearColor (red, green, blue, alpha);

    // Clear the screen and the depth buffer.
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

}

void SceneRenderer::renderModels(std::shared_ptr < const RenderableScene > renderableScene) const
{
    std::shared_ptr< std::vector< std::shared_ptr< const RenderableModelNode > > > rModelInstances = renderableScene->getRenderbaleModelNodes();
    modelRenderer_->renderModels(rModelInstances);
}
