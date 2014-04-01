//
//  TestRenderableModelNode.h
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 29.12.13.
//  Copyright (c) 2013 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#ifndef SapanaViewerLibrary_TestRenderableModelNode_H_
#define SapanaViewerLibrary_TestRenderableModelNode_H_

// Base class includes
#include "renderableModelNode.h"
// External includes

// Project includes
#include "RenderableModel.h"

namespace spvt {

    class TestRenderableModelNode : public spvr::RenderableModelNode
{
public:
    explicit TestRenderableModelNode();
    
    ~TestRenderableModelNode();
private:

};
}
#endif /* defined(SapanaViewerLibrary_TestRenderableModelNode_H_ */
