//
//  TestCameraNode.h
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 13.01.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#ifndef SapanaViewerLibrary_TestCameraNode_H_
#define SapanaViewerLibrary_TestCameraNode_H_

// Base class includes
#include "CameraNode.h"

// External includes

// Project includes

namespace spvt{
    class TestCameraNode : public spvs::CameraNode
  {    
    public:    
          
        explicit TestCameraNode();    
        virtual ~TestCameraNode();    

    private:
      
                  
  };
}
#endif /* defined(SapanaViewerLibrary_TestCameraNode_H_ */
