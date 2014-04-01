//
//  ModelInformation.cpp
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 26.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Class definition include
#include "ModelInformation.h"

// External includes

// Project includes

using namespace spvg;

ModelInformation::ModelInformation(int numVertrices, int numIndices, int numFaces, int sizeInBytes)
: numVertrices_(std::to_string(numVertrices))
, numIndices_(std::to_string(numIndices))
, numFaces_(std::to_string(numFaces))
, sizeInBytes_(std::to_string(sizeInBytes))
{
    
}

ModelInformation::~ModelInformation()
{
    // TODO: Implement
}
