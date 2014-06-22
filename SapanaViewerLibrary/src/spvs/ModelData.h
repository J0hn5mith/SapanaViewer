/*
 * Data.h
 *
 *  Does not use MoSync functionalities!!!!
 *  Created on: Nov 28, 2013
 *      Author: janmeier
 */

#pragma once
#ifndef DATA_H_
#define DATA_H_

// My includes
#include "Util.h"

// OpenGL includes

namespace spvs
{

  /**
   * Data that can easily be rendered by OpenGL ES 1.1.
   * Stores meta information about the Vertex struct.
   * TODO: Maybe this class should be called GLData, because
   * it aims be used in combination with OpenGL.
   */
  class ModelData
  {
  public:
    explicit ModelData(
          const GLenum drawMode
        , const GLenum verticesType
        , const GLenum indicesType
        );
    virtual ~ModelData();

#pragma mark - Vertices
    /**
    * Adds a vertex to the modes data.
    * @param vertex Vertex that is added to the model data
    */
    void addVertex(spvu::Vertex vertex) {this->vertices_.push_back(vertex);}

    /**
    * Retruns a vector holding the vertex data.
    * @return Pointer to the vertex data
    */
    std::vector< spvu::Vertex > getVertices() const {return vertices_;}

    /**
    * Returns the total number of vertices this data object has.
    * @return
    */
    const GLsizei getNumVertices() const {return vertices_.size();} //TODO: remove version without using vecotrs{return numVertices_;}
      
    /**
    * Returns the size of the vertices_ array in bytes.
    * @return Size of vertices_ array.
    */
    const GLsizeiptr getSizeOfVertices() const {return ((GLsizeiptr) sizeof(spvu::Vertex))*vertices_.size();}
  
      
#pragma mark - Vertices
    /**
    * Adds a vertex to the modes data.
    * @param index Index that is added to the model data
    */
    void addIndex(spvu::VertexIndex index) {this->indices_.push_back(index);}


    /**
    * Returns a pointer to the indices data.
    * @return Pointer to the indices data.
    */
    std::vector< spvu::VertexIndex > getIndices() const {return indices_;}

    /**
     * Returns the total number of this data object has.
     * @return
     */
      const GLsizei getNumIndices() const {return indices_.size();} //TODO: remove version without using vecotrs{return numIndices_;}


    /**
     * Returns size of indices_ in bytes.
     * @return Size of indices_ in bytes.
     */
    const GLsizeiptr getSizeOfInidices() const { return ((GLsizeiptr) sizeof(spvu::VertexIndex)*indices_.size());}

      
#pragma mark - Information that is used for Rendering

    /**
     * Returns the type which is used for storing the vertices.
     * @return Type that is used for storing the vertices.
     */
    const GLenum getVerticesType() const {return verticesType_;}

    /**
     * Returns the size (in bytes) of the type used to define the
     * vertices. (GLfloat)
     * @return
     */
    const GLsizei getSizeOfVerticesType() const {return sizeof(GLfloat);}

    /**
     * Returns the type of the indices array.
     * @return Type of the indices array.
     */
    const GLenum getIndicesType() const {return indicesType_;}

    /**
     * Returns the draw mode the vertices that are hold by this data
     * is supposed to be drawn with.
     * @see glDrawElements(), glDrawArray()
     * @return
     */
    const GLenum getDrawMode() const;

    /**
     * Returns the size of a vertex in bytes. This can be used for the stride parameter.
     * @return Size in bytes of one single vertex
     */
    const GLsizei getSizeOfVertex() const;

    /**
     * Returns the offset from the beginning of a vertex to its
     * position component in bytes.
     * @return Offset/ stride for the vertices.
     */
    const GLsizei getPositionOffset() const{ return 0;} // Zero because is first element.

    /**
     * Returns the number of primitive values that are used to define
     * the position component of a vertex. The primitive type can be requested
     * using getVerticesType().
     * @return Number of values per position.
     */
    const GLint getValuesPerPosition() const {return ((GLint)this->getSizeOfPosition()/this->getSizeOfVerticesType());}

    /**
     * Returns the size in bytes the vertice's position component has.
     * Shortcut for getNumValuesPerPosition() * sizeof(getVerticesType())
     * @return The position component in bytes
     */
    const GLsizei getSizeOfPosition() const {return ((GLsizei)sizeof(spvu::Position));}


    /**
     * Returns the offset (in bytes) from the vertex beginning to its
     * color component.
     * @return Offset (in bytes) from the vertex beginning to its color component
     */
    const GLsizeiptr getColorOffset() const {return 8*this->getSizeOfVerticesType();} // TODO: Make propper

    /**
     * Return the number of values that are used to define the vertice's
     * color component. The primitive type that is used for these values
     * can be obtained using getVerticesType().
     * @return
     */
    const GLint getValuesPerColor() const {return this->getSizeOfColor()/this->getSizeOfVerticesType();}

    /**
     * Returns the size (in bytes) of a vertices color component.
     * Shortcut for getNumValuesPerColor() * sizeof(getVerticesType())
     * @return Size of a vertices color component
     */
    const GLsizei getSizeOfColor() const{return ((GLsizei) sizeof(spvu::Color));}

    /**
     * Returns the offset (in bytes) from the beginning of a vertex
     * to the normal component of this vertex.
     * @return Offset (in bytes) from the beginning of the vertex to the normal component.
     */
    const GLsizeiptr getNormalOffset() const{ return ((GLsizeiptr)this->getSizeOfPosition());}

    /**
     * Returns the number of values that are used to define a
     * vertice's normal component.
     * The type of these values is accessible by getVerticesType();
     * @return Number of values that are used to define the color component of a vertex.
     */
    const GLint getValuesPerNormal() const {return sizeof(spvu::Normal)/this->getSizeOfVerticesType();}

    /**
     * Returns the size (in bytes) of a vertices normal component.
     * @return  Size (in bytes) of a vertices normal component.
     */
    const GLsizei getSizeOfNormal() const { return sizeof(spvu::Normal);}

    /**
     * Returns the offset (in bytes) from the beginning of a vertex to
     * its texture coordinate component.
     * @return Offset (in bytes) from the beginning of the vertex to its
     * texture coordinate component.
     */
    const GLsizeiptr getTexCoordOffset() const { return ((GLsizeiptr) getSizeOfPosition() + getSizeOfNormal());}

    /**
     * Returns the size (in bytes) of the vertice's texture coordinate
     * component.
     * @return Size (in bytes) of a vertice's texture coordinate component
     */
    const GLsizei getSizeOfTexCoord() const {return sizeof(spvu::TextureCoordinates);}

    /**
     * Returns the number of values that are used to define
     * a vertice's textures coordinate component.
     * @return Number of values that are used to define the vertices texture component.
     */
    const GLint getValuesPerTexCoord() const { return sizeof(spvu::TextureCoordinates)/getSizeOfVerticesType();}


private:

    /**
     * TODO: Use vector, make sure no one has reference to underlying array
     */
    std::vector< spvu::Vertex > vertices_;
    
      std::vector< spvu::VertexIndex> indices_;
    //GLubyte * indices_;

    /**
     * The mode that will be used by glDrawElements
     */
    const GLenum drawMode_;

    /**
     * The data type used by vertices.
     */
    const GLenum verticesType_;

    /**
     * The data type used by vertices.
     */
    const GLenum indicesType_;

  };
}


#endif /* DATA_H_ */
