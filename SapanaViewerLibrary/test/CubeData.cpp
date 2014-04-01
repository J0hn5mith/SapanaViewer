/*
 * CubeData.cpp
 *
 *  Created on: Dec 1, 2013
 *      Author: janmeier
 */

// Class definition include
#include "CubeData.h"

// External includes
#include <string.h>

// Internal includes

using namespace spvt;
using namespace spvu;
// http://www.songho.ca/opengl/gl_vertexarray.html
CubeData::CubeData()
: ModelData(8,36, GL_TRIANGLES, GL_FLOAT, GL_UNSIGNED_BYTE)
{
  /*
   *      7---6
   *    3---2 |
   *    |  4|-5
   *    0---1
   */
    spvu::Color cubeColor = {0.1f, 0.9f, 0.1f, 1.f};
  {
   Vertex vertex = {
        { 1.f, 1.f, -1.f}                  // Position
        ,{ 1.f/3.f, 1.f/3.f,  -1.f/3.f}   // Normal
        ,{ 0.f, 0.f}                        // Texture coordinates
        ,cubeColor             // Color
      };
      this->addVertex(vertex);
  }
  {
   Vertex vertex = {
        { -1.f, 1.f, -1.f}                  // Position
        ,{ -1.f/3.f, 1.f/3.f,  -1.f/3.f}   // Normal
        ,{ 0.f, 0.f}                        // Texture coordinates
        ,cubeColor              // Color
      };
   this->addVertex(vertex);
  }
  {
   Vertex vertex = {
        {-1.f, -1.f, -1.f}                  // Position
        ,{-1.f/3.f, -1.f/3.f,  -1.f/3.f}   // Normal
        ,{ 0.f, 0.f}                        // Texture coordinates
        ,cubeColor            // Color
      };
   this->addVertex(vertex);
  }
  {
   Vertex vertex = {
        { 1.f, -1.f, -1.f}                  // Position
        ,{1.f/3.f, -1.f/3.f,  1.f/3.f}   // Normal
        ,{ 0.f, 0.f}                        // Texture coordinates
        ,cubeColor            // Color
      };
   this->addVertex(vertex);
  }
  {
   Vertex vertex = {
        { 1.f, -1.f, 1.f}                  // Position
        ,{ 1.f/3.f, -1.f/3.f,  1.f/3.f}   // Normal
        ,{ 0.f, 0.f}                        // Texture coordinates
        ,cubeColor            // Color
      };
  this->addVertex(vertex);
  }
  {
   Vertex vertex = {
        { 1.f, 1.f, 1.f}                  // Position
        ,{ 1.f/3.f, 1.f/3.f,  1.f/3.f}   // Normal
        ,{ 0.f, 0.f}                        // Texture coordinates
        ,cubeColor            // Color
      };
  this->addVertex(vertex);
  }
  {
   Vertex vertex = {
        { -1.f, 1.f, 1.f}                  // Position
        ,{-1.f/3.f, 1.f/3.f, 1.f/3.f}   // Normal
        ,{ 0.f, 0.f}                        // Texture coordinates
        ,cubeColor            // Color
      };
  this->addVertex(vertex);
  }
  {
   Vertex vertex = {
        { -1.f, 1.f, 1.f}                  // Position
        ,{-1.f/3.f, 1.f/3.f,  1.f/3.f}   // Normal
        ,{ 0.f, 0.f}                        // Texture coordinates
        ,cubeColor            // Color
      };
   this->addVertex(vertex);
  }

//    GLubyte indicesTmp[36] = {// Id like to use numIndices_ but compiler complains.
//        // Front
//        0, 1, 2,
//        2,3, 0,
//
    
//        // Right
//        0,3,4,
//        4,5,0,
    
//        // Top
//        0,5,6,
//        6,1,0,
//

//
//        // Left
//        1,6,7,
//        7,2,1,
//
//        // Bottom
//        7,4,3,
//        3,2,7,
//
//        // Back
//        4,7,6,
//        6,5,4
//    };
//
//    for (int i = 0; i < 36; i++)
//    {
//        this->addIndex(indicesTmp[i]);
//    }
//
    
    // Front
    this->addIndex(0);
    this->addIndex(1);
    this->addIndex(2);
    
    this->addIndex(2);
    this->addIndex(3);
    this->addIndex(0);
    
    
// Right
    this->addIndex(0);
    this->addIndex(3);
    this->addIndex(4);

    this->addIndex(4);
    this->addIndex(5);
    this->addIndex(0);
    
    // Top
    this->addIndex(0);
    this->addIndex(5);
    this->addIndex(6);
    
    this->addIndex(6);
    this->addIndex(1);
    this->addIndex(0);
    
    //Left
    this->addIndex(1);
    this->addIndex(6);
    this->addIndex(7);
    
    this->addIndex(7);
    this->addIndex(2);
    this->addIndex(1);
  
    //Bottom
    this->addIndex(7);
    this->addIndex(4);
    this->addIndex(3);
    
    this->addIndex(3);
    this->addIndex(2);
    this->addIndex(7);
    
    // Back
    this->addIndex(4);
    this->addIndex(7);
    this->addIndex(6);
    
    this->addIndex(6);
    this->addIndex(5);
    this->addIndex(4);
    
    
 }

CubeData::~CubeData()
{

}

CoordinateSystem::CoordinateSystem():
ModelData(6,8, GL_LINE_STRIP, GL_FLOAT, GL_UNSIGNED_BYTE)
{
    Vertex vertex = {
            { -10.0f, 0.0f, 0.0f}                  // Position
            ,{0 -0,  0}   // Normal
            ,{ 0.f, 0.f}                        // Texture coordinates
            ,{.1f, 0.8f, 0.8f, 1.f}            // Color
    };
    this->addVertex(vertex);

    vertex = {
            { 10.0f, 0.0f, 0.0f}                  // Position
            ,{0 -0,  0}   // Normal
            ,{ 0.f, 0.f}                        // Texture coordinates
            ,{.1f, 0.8f, 0.8f, 1.f}             // Color
    };
    this->addVertex(vertex);

    vertex = {
            { 0.0f, -10.0f, 0.0f}                  // Position
            ,{0 -0,  0}   // Normal
            ,{ 0.f, 0.f}                        // Texture coordinates
            ,{.1f, 0.8f, 0.8f, 1.f}             // Color
    };
    this->addVertex(vertex);

    vertex = {
            { 0.0f, 10.0f, 0.0f}                  // Position
            ,{0 -0,  0}   // Normal
            ,{ 0.f, 0.f}                        // Texture coordinates
            ,{.1f, 0.8f, 0.8f, 1.f}             // Color
    };
    this->addVertex(vertex);

    vertex = {
            { 0.0f, 0.0f, -10.0f}                  // Position
            ,{0 -0,  0}   // Normal
            ,{ 0.f, 0.f}                        // Texture coordinates
            ,{.1f, 0.8f, 0.8f, 1.f}             // Color
    };
    this->addVertex(vertex);

    vertex = {
            { 0.0f, 0.0f, 10.0f}                  // Position
            ,{0 -0,  0}   // Normal
            ,{ 0.f, 0.f}                        // Texture coordinates
            ,{.1f, 0.8f, 0.8f, 1.f}             // Color
    };
    this->addVertex(vertex);

    this->addIndex(0);
    this->addIndex(1);
    this->addIndex(2);
    this->addIndex(3);
    this->addIndex(4);
    this->addIndex(5);
    this->addIndex(1);
    this->addIndex(5);
}

CoordinateSystem::~CoordinateSystem()
{
        
};

NormalArrow::NormalArrow()
: ModelData(2,2, GL_LINES, GL_FLOAT, GL_UNSIGNED_BYTE)
{
    {
        Vertex vertex = {
            { 0.f, 0.f, 0.f}                  // Position
            ,{0, 0,  0}   // Normal
            ,{ 0.f, 0.f}                        // Texture coordinates
            ,{1.f, 1.0f, 1.0f, 1.f}            // Color
        };
        this->addVertex(vertex);
    }
    {
        Vertex vertex = {
            { 1.f, 1.f, 1.f}                  // Position
            ,{ 0.f,0.f,  0.f}   // Normal
            ,{ 0.f, 0.f}                        // Texture coordinates
            ,{1.f, 1.0f, 1.0f, 1.f}            // Color
        };
        this->addVertex(vertex);
    }
    
    this->addIndex(0);
    this->addIndex(1);
}

NormalArrow::~NormalArrow()
{
    
}


// TODO: Remove
// Old Cube Data
//{
//    Vertex vertex = {
//        { -1.f, -1.f, 1.f}                  // Position
//        ,{- 1.f/3.f, -1.f/3.f,  1.f/3.f}   // Normal
//        ,{ 0.f, 0.f}                        // Texture coordinates
//        ,cubeColor             // Color
//    };
//    this->addVertex(vertex);
//}
//{
//    Vertex vertex = {
//        { 1.f, -1.f, 1.f}                  // Position
//        ,{ 1.f/3.f, -1.f/3.f,  1.f/3.f}   // Normal
//        ,{ 0.f, 0.f}                        // Texture coordinates
//        ,cubeColor              // Color
//    };
//    this->addVertex(vertex);
//}
//{
//    Vertex vertex = {
//        {1.f, 1.f, 1.f}                  // Position
//        ,{1.f/3.f, 1.f/3.f,  1.f/3.f}   // Normal
//        ,{ 0.f, 0.f}                        // Texture coordinates
//        ,cubeColor            // Color
//    };
//    this->addVertex(vertex);
//}
//{
//    Vertex vertex = {
//        { -1.f, 1.f, 1.f}                  // Position
//        ,{-1.f/3.f, 1.f/3.f,  1.f/3.f}   // Normal
//        ,{ 0.f, 0.f}                        // Texture coordinates
//        ,cubeColor            // Color
//    };
//    this->addVertex(vertex);
//}
//{
//    Vertex vertex = {
//        { -1.f, -1.f, -1.f}                  // Position
//        ,{- 1.f/3.f, -1.f/3.f,  -1.f/3.f}   // Normal
//        ,{ 0.f, 0.f}                        // Texture coordinates
//        ,cubeColor            // Color
//    };
//    this->addVertex(vertex);
//}
//{
//    Vertex vertex = {
//        { 1.f, -1.f, -1.f}                  // Position
//        ,{ 1.f/3.f, -1.f/3.f,  -1.f/3.f}   // Normal
//        ,{ 0.f, 0.f}                        // Texture coordinates
//        ,cubeColor            // Color
//    };
//    this->addVertex(vertex);
//}
//{
//    Vertex vertex = {
//        { 1.f, 1.f, -1.f}                  // Position
//        ,{1.f/3.f, 1.f/3.f,  -1.f/3.f}   // Normal
//        ,{ 0.f, 0.f}                        // Texture coordinates
//        ,cubeColor            // Color
//    };
//    this->addVertex(vertex);
//}
//{
//    Vertex vertex = {
//        { -1.f, 1.f, -1.f}                  // Position
//        ,{-1.f/3.f, 1.f/3.f,  -1.f/3.f}   // Normal
//        ,{ 0.f, 0.f}                        // Texture coordinates
//        ,cubeColor            // Color
//    };
//    this->addVertex(vertex);
//}

