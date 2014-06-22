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
#include "LightSourceNodeRenderer.h"
#include "SceneNodeRenderer.h"
#include "RendererUtils.h"

// Debug includes

using namespace spvr;


#pragma mark - Con- & Destructors
SceneRenderer::SceneRenderer(
                             std::shared_ptr< const  RenderableScene > rScene
                             , std::shared_ptr< ModelRenderer > modelRenderer
                             , std::shared_ptr< LightSourceNodeRenderer > lightSourceRenderer
                             , std::shared_ptr< SceneNodeRenderer > frameNodeRenderer
                             , std::shared_ptr< SceneRendererContext > context
    )
: rScene_(rScene)
, modelRenderer_(modelRenderer)
, sceneRendererContext_(context)
, lightSourceRenderer_(lightSourceRenderer)
, frameNodeRenderer_(frameNodeRenderer)
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
    //TEST
    setUpOpenGL(nullptr);
    
    clearScreen(rScene_);
    setCameraPosition(rScene_);
    setProjection(rScene_);
    drawWorldPlane();
    renderModels(rScene_);
    renderFrameNodes(rScene_);
    renderLightSources(rScene_);
    glFinish();
}


#pragma mark - Private Methodes
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
    this->setUpDepthBuffer();
    glEnable(GL_DEPTH_TEST);

    // Set the type of depth test.
    glDepthFunc(GL_LEQUAL);

    // Use the best perspective correction method.
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    
    // Use lighting TODO: RMOVE
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    
    // Antialiasing
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
    
    // Blending
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable( GL_BLEND );
}

void SceneRenderer::setUpDepthBuffer() const
{

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
    auto cameraTransformation = transMatrix->array;
  glMultMatrixf(cameraTransformation);
}


void SceneRenderer::clearScreen(std::shared_ptr < const RenderableScene > renderableScene) const
{
  // TODO: Was copied from example, check if everything is right
    
    auto color = renderableScene->getClearColor();
    glClearColor(color.r, color.g, color.b, color.a);

    // Clear the screen and the depth buffer.
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

}

void SceneRenderer::drawWorldPlane() const
{
    
    spvr::RendererUtils::drawMashPlane(10, 1, {0.5, 0.5, 0.5, 1.0}, true);
    
    spvr::RendererUtils::drawCoordinateSystem(10, true);
    spvr::RendererUtils::drawPlane({-10.0, 0.0, -10.0}, {10.0, 0.0, 10.0}, {0.8, 0.6, 0.1, .7});
}

void SceneRenderer::renderModels(std::shared_ptr < const RenderableScene > renderableScene) const
{
    std::shared_ptr< std::vector< std::shared_ptr< const RenderableModelNode > > > rModelInstances = renderableScene->getRenderbaleModelNodes();
    modelRenderer_->renderModels(rModelInstances);
}

void SceneRenderer::renderLightSources(std::shared_ptr < const RenderableScene > renderableScene) const
{
    auto lightSources = rScene_->getRenderbaleLightSourceNodes();
    int i = 0;
    std::for_each(lightSources.begin(), lightSources.end(),
    [&] ( std::shared_ptr< const RenderableLightSourceNode > node)
    {
        lightSourceRenderer_->renderLightSourceNode(node, i++);
    });
}

void SceneRenderer::renderFrameNodes(std::shared_ptr < const RenderableScene > renderableScene) const
{
    auto frameNodes = rScene_->getRenderbaleFrameNodes();

    std::for_each(frameNodes.begin(), frameNodes.end(),
                  [&] ( std::shared_ptr< const RenderableSceneNode > node)
                  {
                      frameNodeRenderer_->renderSceneNode(node);
                  });
}