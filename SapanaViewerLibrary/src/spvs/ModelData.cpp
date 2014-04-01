/*
 * Data.cpp
 *
 *  Created on: Dec 1, 2013
 *      Author: janmeier
 */


#include "ModelData.h"

using namespace spvs;
// If I don't use pointers to hold the class fields, I don't have to initialize them?
ModelData::ModelData(
    const GLsizeiptr numVertices
    , const GLsizeiptr numIndices
    , const GLenum drawMode
    , const GLenum verticesType
    , const GLenum indicesType
    )
: numVertices_(numVertices)
, numIndices_(numIndices)
, vertices_(std::vector< spvu::Vertex>())
, indices_(std::vector< spvu::VertexIndex >())
, drawMode_(drawMode)
, verticesType_(verticesType)
, indicesType_(indicesType)
{

}

ModelData::~ModelData()
{
    
}

const GLenum ModelData::getDrawMode() const
{
  return drawMode_;
}

const GLsizei ModelData::getSizeOfVertex() const
{
  // TODO: Caching
    return sizeof(spvu::Vertex);
}


