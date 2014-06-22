//
//  MatrixList.cpp
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 02.04.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Class definition include
#include "SceneNodeTransformationList.h"

// External includes

// Project includes

using namespace spvs;
                                                                                
SceneNodeTransformationList::SceneNodeTransformationList()
:transformationList_()
{                                                                               
    spvu::TransMatrix identityMatrix;
    vmml::identity(identityMatrix);
    transformationList_.push_back(identityMatrix);
}                                                                               
                                                                                
SceneNodeTransformationList::~SceneNodeTransformationList()
{                                                                               
  // TODO: Implement
}

std::list< spvu::TransMatrix > SceneNodeTransformationList::getTransformationList() const
{
    return transformationList_;
}

spvu::TransMatrix SceneNodeTransformationList::getResultingTransMatrix() const
{
    spvu::TransMatrix result;
    vmml::identity(result);
    for (auto tMatrix : transformationList_)
    {
        spvu::TransMatrix tmp = result;
        result.multiply(tMatrix, tmp);
    }
    return result;
}



void SceneNodeTransformationList::addTransformationMatrix()
{
    spvu::TransMatrix identityMatrix;
    vmml::identity(identityMatrix);
    transformationList_.push_back(identityMatrix);
}

void SceneNodeTransformationList::moveTransformationMatrix(spvu::ListPosition oldPosition, spvu::ListPosition newPosition)
{
    
    if (oldPosition >= transformationList_.size())
    {
        // TODO Exception Handling
        return;
    }
    
    if (newPosition >= transformationList_.size())
    {
        // TODO Exception Handling
        return;
    }
    
    if ( newPosition > oldPosition )
    {
        newPosition++;
    }
    
    auto  itOld = transformationList_.begin();
    std::advance( itOld, oldPosition);
    
    auto itNew = transformationList_.begin();
    std::advance( itNew, newPosition);
    
    transformationList_.splice(itNew, transformationList_, itOld);
    
}

void SceneNodeTransformationList::removeTransformationMatrix(spvu::ListPosition position)
{
    if ( transformationList_.empty() )
    {
        return;
    }
    auto it = transformationList_.begin();
    std::advance( it, position);
    
    transformationList_.erase(it);
}

void SceneNodeTransformationList::transformMatrix(const spvu::TransMatrix tMatrix, spvu::ListPosition  index)
{
    
    if ( transformationList_.empty() || transformationList_.size() <= index)
    {
        // TODO: Exception handling
        return;
        
    }
    
    auto it = transformationList_.begin();
    std::advance( it, index);
    
    const spvu::TransMatrix  previousMatrix = *it;
    spvu::TransMatrix resultMatrix;
    vmml::identity(resultMatrix);
    resultMatrix.multiply(tMatrix, previousMatrix);
    
    (*it) = resultMatrix;
    
}