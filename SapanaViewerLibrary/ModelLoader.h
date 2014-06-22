//
//  ModelLoader.h
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 13.04.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#ifndef SapanaViewerLibrary_ModelLoader_H_
#define SapanaViewerLibrary_ModelLoader_H_

// Base class includes

// External includes
#include "objload.h"
#include <memory>

// Project includes
#include "ModelData.h"

namespace spvu
{
namespace ModelLoader
{    
    static std::shared_ptr< const spvs::ModelData > loadModel(const std::string & in)
    {
        obj::Model m = obj::loadModelFromFile(in);
        
        std::shared_ptr< spvs::ModelData > modelData =  std::make_shared< spvs::ModelData >(GL_TRIANGLES, GL_FLOAT, GL_UNSIGNED_BYTE);
        
        spvu::Color color = {.5f, 0.5f, 0.5f, 1.f};
        for( int i = 0; i <  (m.vertex.size()/3); i++)
        {
            int vi3 = i * 3;
            int vi2 = i * 2;
            
            auto x = m.vertex.at(vi3);
            auto y = m.vertex.at(vi3 + 1);
            auto z = m.vertex.at(vi3 + 2);
            
            spvu::Position position = {x,y, z};
            
            
            spvu::Normal normal;
            if ( m.normal.size() > 0)
            {
                 normal = {m.normal.at(vi3), m.normal.at(vi3 + 1), m.normal.at(vi3 + 2)};
            }
            else
            {
                normal = {0.0, 0.0, 0.0};
            }
            
            spvu::TextureCoordinates texCoords;
            if ( m.texCoord.size() > 0)
            {
                texCoords = {m.texCoord.at(vi2), m.texCoord.at(vi2 +1)};
            }
            else
            {
                texCoords = {0.0, 0.0};
            }
            
            modelData->addVertex(
                                 { position, normal, texCoords, color
                                 });
            
        }

        bool flag = true;
        for(auto faceList : m.faces)
        {
            if (flag)
            {
                for(auto face : faceList.second)
                {
                    modelData->addIndex((spvu::VertexIndex) face);
                }
                //flag = false;
            }
        }
        
        return modelData;
    }
    
    /**
     * Method that returns the data for a cube. 
     * @return Instance of ModelData that holds a cube. 
     */
    static std::shared_ptr< const spvs::ModelData > getCube();
};
}
#endif /* defined(SapanaViewerLibrary_ModelLoader_H_ */
