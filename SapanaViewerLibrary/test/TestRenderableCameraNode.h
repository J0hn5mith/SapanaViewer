//
//  TestRenderableCameraNode.h
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 02.01.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#ifndef SapanaViewerLibrary_TestRenderableCameraNode_H_
#define SapanaViewerLibrary_TestRenderableCameraNode_H_

// Base class includes

// External includes

// Project includes
#include "RenderableCameraNode.h"


namespace spvt{
class TestRenderableCameraNode  : public spvr::RenderableCameraNode
{
public:
      
    explicit TestRenderableCameraNode(std::shared_ptr< spvs::CameraNode >cNode);
    virtual ~TestRenderableCameraNode();
    
      
                  
};
}
#endif /* defined(SapanaViewerLibrary_TestRenderableCameraNode_H_ */
