/*
 * Util.h
 *
 *  Does not use MoSync functionalities!!!!
 *
 *  Created on: Dec 1, 2013
 *      Author: janmeier
 */

#pragma once
#ifndef UTIL_H_
#define UTIL_H_

// TODO: Remove iOS dependency, Util now also imports the types for a gl version => make type class

// External includes
#include <OpenGLES/ES1/gl.h>
#include "vmmlib/vmmlib.hpp"
#include <list>

// Project includes


/**
 * List of utility methods
 */
namespace spvu{
    
    
    typedef GLubyte VertexIndex;
    /**
    * Defines the position of a vertex.
    */
    struct Position
    {
        GLfloat x;
        GLfloat y;
        GLfloat z;
    };

    /**
    * Defines normal of a vertex.
    */
    struct Normal
    {
        GLfloat nx;
        GLfloat ny;
        GLfloat nz;
    };

    /**
    * Defines texture coordinates of a vertex.
    */
    struct TextureCoordinates
    {
        GLfloat u;
        GLfloat v;
    };

    /**
    * Defines the color of a vertex.
    */
    struct Color
    {
        GLfloat r;
        GLfloat g;
        GLfloat b;
        GLfloat a;
    };

    /**
    * Holds vertex data. The structure is used, because OpenGL can easily
    * handle this data. \n
    * Structs can be used as array because C structs are stored sequentially.
    * Vertex = {x, y, z, nx, ny, nz, u, b, r, g, b, a}
    * http://en.wikipedia.org/wiki/Data_structure_alignment#Typical_alignment_of_C_structs_on_x86
    */
    //
    struct Vertex
    {
        Position position;
        Normal normal;
        TextureCoordinates texCoordinates;
        Color color;
    };


    
    /**
    * Holds indices of vertices for drawing a triangle.
    */
    struct Triangle
    {
        GLubyte first;
        GLubyte secont;
        GLubyte third;
    };

    /**
    * 4D matrix for transformations
    */
    typedef vmml::mat4f TransMatrix;
    
    static std::vector< std::vector< float > > matrix_to_vector(TransMatrix matrix)
    {
        std::vector< std::vector<float>> result;
        for (int i = 0; i < 4; i++)
        {
            result.push_back(std::vector<float>());
            for (int ii = 0; ii < 4; ii++)
            {
                result.at(i).push_back(matrix.at(i, ii));
            }
        }
        return result;
    }
    
    static std::vector< std::vector< std::vector< float > > > matrix_list_to_vector(std::list< spvu::TransMatrix > matrixList )
    {
        std::vector< std::vector< std::vector< float > > > result;
        std::for_each(matrixList.begin(), matrixList.end(),
        [&] (TransMatrix matrix)
                      {
                          result.push_back(spvu::matrix_to_vector(matrix));
                      }
                      );
        return result;
    }
    

}



#endif /* UTIL_H_ */
