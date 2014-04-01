/*
 * RenderableModel.h
 *
 *  Created on: Dec 9, 2013
 *      Author: janmeier
 */

#pragma once
#ifndef RENDERABLEMODEL_H_
#define RENDERABLEMODEL_H_

// Base class include

// External includes
#include <memory>
#include <vector>
#include <OpenGLES/ES1/gl.h>

// Project includes
#include "Util.h"

// Forward Declarations
namespace spvs {
    class ModelData;
}

namespace spvr{

  /**
   * Hold the vertices data that is rendered by a model renderer.
   * Renderable models are drawn by a model renderer. Renderer models
   * makes Modal data renderable. It also takes care of the buffer (OpenGL buffers)
   * allocation and freeing.
   */
class RenderableModel
{
public:
    explicit RenderableModel( std::shared_ptr< const spvs::ModelData > modelData);

    ~RenderableModel();

    /**
     * Returns the ID of vertices buffer.
     * @return ID of the vertices buffer
     */
    const GLuint getVerticesBufferID() const {return verticesBufferID_;}

    /**
     * Returns the ID of the indices buffer.
     * @return ID of the indices buffer
     */
    const GLuint getIndicesBufferID() const { return indicesBufferID_; }

    /**
    * Returns wether the RenderableModel has a texture or not.
    * Fals doesn't mean that there is no texture, it onlu means that 
    * itis not used.
    * @return true if the RenderableModel has a texture that is 
    * used. Else false.
    */
    // TODO: Implement usage of textures
    const bool hasTexture() const {return false;}

    // TODO: Doxygen documentation
    /**
    * Returns the vertice's type that are used to store the
    * renderable models vertices. 
    */
    const GLenum getVerticesType() const;
    /**
    * Returns the size of a single vertex.
    */
    const GLsizei getSizeOfVertex() const;

    const GLint getValuesPerPosition() const;

    const GLsizeiptr getPositionOffset() const;

    const GLint getValuesPerColor() const;

    const GLsizeiptr getColorOffset() const;

    const GLsizeiptr getNormalOffset() const;

    const GLint getValuesPerTexCoord() const;

    const GLsizeiptr getTexCoordOffset() const;

    const GLenum getDrawMode() const;

    const GLsizei getNumIndices() const;

    const GLenum getIndicesType() const;
    
    // TODO: Used for normals, renderer should not have acess to them -> remove and find bette solution
    std::vector< spvu::Vertex > getVertices() const;
    
private:

    /**
     * Pointer to the model data this renderable model.
     * is created of.
     */
    std::shared_ptr< const spvs::ModelData > modelData_;
    
    /**
     * Allocates buffer objects for the vertices and indices buffer.
     * The IDs of these buffers are stored in verticesBufferID_ and
     * indicesBufferID_.
     * \todo Error handling
     */
    void createBuffers();

    /**
     * Deletes the buffers (the buffers associated with the IDs in
     * verticesBufferID_ and indicesBufferID_) that are used for
     * this renderable model.
     * \todo Error handling
     */
    void deleteBuffers();

    /**
     * Updated the renderable object
     * if a change occurs in the related model data (modelData_).
     * \todo Implement. This will be implemented using a observer pattern
     */
    void updateBuffers();

    /**
     * Holds the ID that OpenGL assigned to the vertex buffer which is
     * holding the vertex data for this renderable model.
     */
    GLuint verticesBufferID_;

    /**
     * Holds the ID that OpenGL assigned to the indices buffer which
     * is holding the indices for this model.
     */
    GLuint indicesBufferID_;

 

};

}
#endif /* RENDERABLEMODEL_H_ */
