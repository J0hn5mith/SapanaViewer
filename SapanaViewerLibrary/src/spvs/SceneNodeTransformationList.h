//
//  MatrixList.h
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 02.04.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#ifndef SapanaViewerLibrary_MatrixList_H_
#define SapanaViewerLibrary_MatrixList_H_

// Base class includes

// External includes

// Project includes
#include "Util.h"
#include "TypeDefSpv.h"

namespace spvs{
class SceneNodeTransformationList
{    
public:    

    explicit SceneNodeTransformationList();
    virtual ~SceneNodeTransformationList();

    virtual std::list< spvu::TransMatrix > getTransformationList() const ;
    
    /**
    * Returns the te trans matrix the results when multiplying all
    * matrices in the list beginning with the first one.
    */
    virtual spvu::TransMatrix getResultingTransMatrix() const;


    virtual void addTransformationMatrix();
    virtual void moveTransformationMatrix(spvu::ListPosition oldPosition, spvu::ListPosition newPosition);
    virtual void removeTransformationMatrix(spvu::ListPosition position);
    
    virtual void transformMatrix(const spvu::TransMatrix tMatrix, spvu::ListPosition  index);
  

  
private:
    std::list< spvu::TransMatrix > transformationList_;
              
};
}
#endif /* defined(SapanaViewerLibrary_MatrixList_H_ */
