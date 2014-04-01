/*
 * RenderableModel.cpp
 *
 *  Created on: Dec 9, 2013
 *      Author: janmeier
 */

// Class definition include
#include "RenderableModel.h"

// External includes
#include "Util.h"
#include "ModelData.h"

using namespace spvr;

RenderableModel::RenderableModel( std::shared_ptr< const spvs::ModelData > modelData )
    : verticesBufferID_(0)
    , indicesBufferID_(0)
    , modelData_(modelData)
{
  createBuffers();
}

RenderableModel::~RenderableModel()
{
  deleteBuffers();
}

const GLenum RenderableModel::getVerticesType() const
{
    return modelData_->getVerticesType();
}

const GLsizei RenderableModel::getSizeOfVertex() const
{
    return modelData_->getSizeOfVertex();
}

const GLint RenderableModel::getValuesPerPosition() const
{
    return modelData_->getValuesPerPosition();
}

const GLsizeiptr RenderableModel::getPositionOffset() const
{
    return modelData_->getPositionOffset();
}

const GLint RenderableModel::getValuesPerColor() const
{
    return modelData_->getValuesPerColor();
}

const GLsizeiptr RenderableModel::getColorOffset() const
{
    return modelData_->getColorOffset();
}

const GLsizeiptr RenderableModel::getNormalOffset() const
{
    return modelData_->getNormalOffset();
}

const GLint RenderableModel::getValuesPerTexCoord() const
{
    return modelData_->getValuesPerTexCoord();
}

const GLsizeiptr RenderableModel::getTexCoordOffset() const
{
    return modelData_->getTexCoordOffset();
}

const GLenum RenderableModel::getDrawMode() const
{
    return modelData_->getDrawMode();
}

const GLsizei RenderableModel::getNumIndices() const
{
    return modelData_->getNumIndices();
}
const GLenum RenderableModel::getIndicesType() const
{
    return modelData_->getIndicesType();
}

std::vector< spvu::Vertex > RenderableModel::getVertices() const {
    return modelData_->getVertices();
}

#pragma mark - Methods for Buffer Management
void RenderableModel::createBuffers()
{
    // Create vertex buffer
    std::vector< spvu::Vertex > verticesVector = modelData_->getVertices();
    const spvu::Vertex * vertices = verticesVector.data();
    const GLsizeiptr verticesSize = modelData_->getSizeOfVertices();

    glGenBuffers(1, &verticesBufferID_);
    glBindBuffer(GL_ARRAY_BUFFER, verticesBufferID_);
    glBufferData(GL_ARRAY_BUFFER, verticesSize, vertices, GL_STATIC_DRAW );

    // Create indices buffer
    std::vector< spvu::VertexIndex > indicesVector = modelData_->getIndices();
    const spvu::VertexIndex * indices = indicesVector.data();
    const GLsizeiptr indicesSize = modelData_->getSizeOfInidices();

    glGenBuffers(1, &indicesBufferID_);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,indicesBufferID_);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesSize, indices, GL_STATIC_DRAW);

    // Unbind any buffer
    glBindBuffer(GL_ARRAY_BUFFER,0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void RenderableModel::deleteBuffers()
{
  glDeleteBuffers(1, &verticesBufferID_); // TODO Is it faster to delete both buffers at once?
  glDeleteBuffers(1, &indicesBufferID_);
}
