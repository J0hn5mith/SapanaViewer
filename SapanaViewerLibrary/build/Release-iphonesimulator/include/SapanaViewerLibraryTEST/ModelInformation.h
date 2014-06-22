//
//  ModelInformation.h
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 26.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#ifndef SapanaViewerLibrary_ModelInformation_H_
#define SapanaViewerLibrary_ModelInformation_H_

// Base class includes

// External includes
#include <string>
// Project includes

namespace spvg
{
    class ModelInformation
    {
    public:
        
        explicit ModelInformation(int numVertrices, int numIndices, int numFaces, int sizeInBytes);
        virtual ~ModelInformation();
        
        std::string getNumVertices() {return numVertrices_;}
        std::string getNumIndices() {return numIndices_;}
        std::string getNumFaces() {return numFaces_;}
        std::string getSizeInBytes() {return sizeInBytes_;}
        
    private:
        std::string numVertrices_;
        std::string numIndices_;
        std::string numFaces_;
        std::string sizeInBytes_;
        
    };
}
#endif /* defined(SapanaViewerLibrary_ModelInformation_H_ */
