/*
 * CubeRenderer.cpp
 *
 *  Created on: Nov 29, 2013
 *      Author: janmeier
 */


#include "CubeRenderer.h"
#include <GLES/gl.h>

//DEBUG
#include <mavsprintf.h>

using namespace spvr;

CubeRenderer::CubeRenderer()
//: verticesBuffer_(NULL)
//, indicesBuffer_(NULL)
: renderableModel_(NULL)
, modelRenderer_(NULL)
{
  modelRenderer_ = new ModelRenderer();
}

CubeRenderer::~CubeRenderer()
{
  deleteBuffers();
  delete renderableModel_;
  delete modelRenderer_;
}

void CubeRenderer::init(int width, int height, const spvs::ModelData * data)
{

//  // Protect against divide by zero.
//  if (0 == height)
//  {
//          height = 1;
//  }
//
//  // Set view port.
//  glViewport(0, 0, (GLint)width, (GLint)height);
//
//  // Select the projection matrix.
//  glMatrixMode(GL_PROJECTION);
//
//  // Reset the projection matrix.
//  glLoadIdentity();
//
//  // Set the perspective (updates the projection
//  // matrix to use the perspective we define).
//  GLfloat ratio = (GLfloat)width / (GLfloat)height;
//
//  // gluPerspective
//  GLfloat fovy = 45.0f;
//  GLfloat aspect = ratio;
//  GLfloat zNear = 0.1f;
//  GLfloat zFar = 100.0f;
//
//  const float M_PI_LOCAL = 3.14159;
//
//  GLfloat ymax = zNear * tan(fovy * M_PI_LOCAL / 360.0);
//  GLfloat ymin = -ymax;
//  GLfloat xmin = ymin * aspect;
//  GLfloat xmax = ymax * aspect;
//
//  glFrustumf(xmin, xmax, ymin, ymax, zNear, zFar);

//  // Enable texture mapping.
//   glEnable(GL_TEXTURE_2D);
//
//  // Enable smooth shading.
//  glShadeModel(GL_SMOOTH);
//
//  // Set the depth value used when clearing the depth buffer.
//  glClearDepthf(1.0f);
//
//  // Enable depth testing.
//  glEnable(GL_DEPTH_TEST);
//
//  // Set the type of depth test.
//  glDepthFunc(GL_LEQUAL);
//
//  // Use the best perspective correction method.
//  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

  createBuffers(data);

}

void CubeRenderer::renderData()//const ModelData * cubeData)
{

       // Set the background color to be used when clearing the screen.
//       glClearColor(0.3f, .3f, 0.3f, 1.0f);
//
//       // Clear the screen and the depth buffer.
//       glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//       // Use the model matrix.
//       glMatrixMode(GL_MODELVIEW);
//
//       // Reset the model matrix.
//       glLoadIdentity();
//
//       // Move into the screen 5 units.
//       glTranslatef(0.0f, 0.0f, -5.0f);


      // modelRenderer_->renderModel(renderableModel_);
       glFinish();
}


void CubeRenderer::createBuffers(const spvs::ModelData * data)
{
  renderableModel_ = new RenderableModel(data);
}

void CubeRenderer::deleteBuffers()
{
    delete renderableModel_;
}


