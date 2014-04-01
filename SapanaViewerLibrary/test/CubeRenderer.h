/*
 * CubeRenderer.h
 *
 *  Created on: Nov 29, 2013
 *      Author: janmeier
 */

#ifndef CUBERENDERER_H_
#define CUBERENDERER_H_

// Project imports
#include "IRenderer.h"
#include "CubeData.h"
#include "RenderableModel.h"
#include "ModelRenderer.h"


// DEPREATED
#include "Modeldata.h" // TODO: This won't be need after model renderer is used.

namespace spvr{

class CubeRenderer: public IRenderer
{
public:
        explicit CubeRenderer();

        virtual ~CubeRenderer();

        void init(int width, int height, const spvs::ModelData * data);

        void renderData();

private:


        /**
         * Create the vertex and indices buffer.
         * They must not be initialized before calling this method.
         * @param data Holds data for filling the buffers.
         */
        void createBuffers(const spvs::ModelData * data);

        /**
         * Deletes the index and vertices buffer that were created by createBuffers()
         */
        void deleteBuffers();

        /**
         * Updates the vertex and indices buffer.
         * @param data
         */
        void updateBuffers(const spvs::ModelData * data);

        // ID of the buffer that holds the cube's vertices.
//        GLuint verticesBuffer_;
//
//        // ID of the indices buffer.
//        GLuint indicesBuffer_;
        RenderableModel * renderableModel_;

        ModelRenderer * modelRenderer_;

};

}
#endif /* CUBERENDERER_H_ */
