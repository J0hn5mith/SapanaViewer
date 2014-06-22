/*
 * ModelRenderer.cpp
 *
 *  Created on: Dec 10, 2013
 *      Author: janmeier
 */

// Class definition
#include "ModelRenderer.h"

// External Includes
#include <OpenGLES/ES1/gl.h> // TODO: Remove iOS dependency
#include <vector>
#include <iterator>
#include <memory>

// Project includes
#include "RenderableModelNode.h"
#include "SceneNodeRenderer.h"
#include "RenderableModel.h"
#include "RendererUtils.h"


using namespace spvr;
ModelRenderer::ModelRenderer( std::shared_ptr< spvr::SceneNodeRenderer > sceneNodeRenderer )
: sceneNodeRenderer_(sceneNodeRenderer)
{
    
}

ModelRenderer::~ModelRenderer()
{

}

void ModelRenderer::renderModel(std::shared_ptr< const RenderableModelNode > modelNode) const
{
    drawModelNode(modelNode);
}

void ModelRenderer::renderModels(std::shared_ptr< std::vector< std::shared_ptr< const RenderableModelNode > > > models) const
{
    for (auto node : *models)
    {
        renderModel(node);
    }
}

// Reference: http://www.songho.ca/opengl/gl_vbo.html
void ModelRenderer::bindBuffers( std::shared_ptr< const RenderableModel > rModel) const
{
    const GLuint verticesBuffer = rModel->getVerticesBufferID();
    glBindBuffer(GL_ARRAY_BUFFER, verticesBuffer);

    // Bind Pointers
    const GLenum vertexType = rModel->getVerticesType();
    const GLsizei vertexStride = rModel->getSizeOfVertex();

    
    // Set vertices pointer
    const GLint valuesPerPosition = rModel->getValuesPerPosition();
    const GLsizeiptr vertexDataOffset = rModel->getPositionOffset();
    const GLubyte * vertexPointer = (GLubyte*)((char*)nullptr + vertexDataOffset);

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(valuesPerPosition, vertexType, vertexStride, vertexPointer);


    // Set color pointer
    const GLint valuesPerColor = rModel->getValuesPerColor();
    const GLsizeiptr colorDataOffset = rModel->getColorOffset();
    const GLubyte * colorPointer = (GLubyte * )((char *)nullptr + colorDataOffset);
    glEnableClientState(GL_COLOR_ARRAY);
    glColorPointer(valuesPerColor, vertexType, vertexStride, colorPointer);


    // Set normal pointer
    const GLsizeiptr normalOffset = rModel->getNormalOffset();
    const GLubyte * normalPointer = ((GLubyte * ) ((char *)nullptr + normalOffset));

    glEnableClientState(GL_NORMAL_ARRAY);
    glNormalPointer(vertexType, vertexStride, normalPointer);
    

    // Set texture pointer
    if (rModel->hasTexture())
    {
        const GLint valuesPerTexCoord = rModel->getValuesPerTexCoord();
        const GLsizeiptr texCoordOffset = rModel->getTexCoordOffset();
        const GLvoid * texCoordPointer = ((GLubyte * ) ((char *)nullptr + texCoordOffset));

        glTexCoordPointer(valuesPerTexCoord, vertexType, vertexStride, texCoordPointer);
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    }

    
    // Bind the index buffer
    const GLuint indicesBuffer_ = rModel->getIndicesBufferID();
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indicesBuffer_);
}

void ModelRenderer::unbindBuffers( std::shared_ptr< const RenderableModel > rModel) const
{
  glDisableClientState(GL_VERTEX_ARRAY);
  glDisableClientState(GL_NORMAL_ARRAY);
  glDisableClientState(GL_COLOR_ARRAY);
  if( rModel->hasTexture() )
  {
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
  }
  glBindBuffer(GL_ARRAY_BUFFER,0);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void ModelRenderer::drawModelNode(std::shared_ptr< const RenderableModelNode > modelNode) const
{
    setPosition(modelNode);
    std::shared_ptr< const RenderableModel > model = modelNode->getRenderableModel();
    
    std::shared_ptr< const RenderableModel > rModel = modelNode->getRenderableModel();

    if (modelNode->getModelNodeProperties().getWireFrameMode())
    {
        drawModel(modelNode->getRenderableModel(), true);
    }
    else
    {
        drawModel(modelNode->getRenderableModel(), false);
    }
    
    drawModelNodeSupport(modelNode);
    unsetPosition();
    
    sceneNodeRenderer_->drawLineToParent(modelNode);
    // Connectoin to world origin
    
    
}

void ModelRenderer::drawModel( std::shared_ptr< const RenderableModel > model) const
{
    drawModel(model, false);
}

void ModelRenderer::drawModel( std::shared_ptr< const RenderableModel > model, bool useWireframe) const
{

    bindBuffers(model);
    
    GLenum drawMode = 0;
    if (useWireframe)
    {
        drawMode = GL_LINE_STRIP;
    }
    else
    {
        drawMode = model->getDrawMode();
    }
    
    const GLsizei numIndices = model->getNumIndices();
    const GLenum indicesType = model->getIndicesType();
    
    const GLubyte * indicePointer = ((GLubyte *)(NULL));
    glEnable(GL_DEPTH_TEST);
    glDrawElements(drawMode, numIndices, indicesType, indicePointer);
    
    unbindBuffers(model);
}

void ModelRenderer::setPosition(std::shared_ptr< const RenderableModelNode > modelNode) const
{
    spvu::TransMatrix    transMatrix =  *modelNode->getTransMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glMultMatrixf(transMatrix);
}

void ModelRenderer::unsetPosition() const
{
   glMatrixMode(GL_MODELVIEW);
  glPopMatrix();
}

#pragma mark - Methodes Related to the Suport constructs

void ModelRenderer::drawModelNodeSupport(std::shared_ptr< const RenderableModelNode > modelNode) const
{
    // Coordinates system
    if (modelNode->getModelNodeProperties().getShowCoordinateSystem())
    {
        //drawModel(coordinateSystem_);
       spvr::RendererUtils::drawCoordinateSystem(5.0, false);
        
    }
    
    // Normals
    if (modelNode->getModelNodeProperties().getShowNormals())
    {
        auto vertices = modelNode->getRenderableModel()->getVertices();
        std::for_each(vertices.begin(), vertices.end(),
                      [&](spvu::Vertex vertex)
                      {
                          spvu::Color color;
                          // TODO Define color in config
                          color.r = .5f;
                          color.
                          g = .5f;
                          color.b = 0.f;
                          color.a = 1.0f;
                          spvu::Position endPosition;
                          endPosition.x = vertex.position.x + vertex.normal.nx;
                          endPosition.y = vertex.position.y +vertex.normal.ny;
                          endPosition.z = vertex.position.z +vertex.normal.nz;
                          spvr::RendererUtils::drawLine(vertex.position, endPosition, color);
                      }
                      );
    }
}

void ModelRenderer::drawLineToParentNode(std::shared_ptr< const RenderableModelNode > modelNode) const
{
    spvu::Color color;
    // TODO Define color in config
    color.r = 0.0f;
    color.g = 1.0f;
    color.b = 1.f;
    color.a = 1.0f;
    
    spvu::Position startPoint;
    startPoint.x = 0;
    startPoint.y = 0;
    startPoint.z = 0;
    
    auto transformation = modelNode->getNodeTransMatrix();
    
    spvu::Position endPosition;
    endPosition.x = transformation[0][3];
    endPosition.y = transformation[1][3];
    endPosition.z = transformation[2][3];
    spvr::RendererUtils::drawLine(startPoint, endPosition, color);
}






