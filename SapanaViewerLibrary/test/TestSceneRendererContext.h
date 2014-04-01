//
//  TestSceneRendererContext.h
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 20.12.13.
//  Copyright (c) 2013 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#ifndef TestSceneRendererContext_H_
#define TestSceneRendererContext_H_

// Project includes

#include "SceneRendererContext.h"

namespace spvt{
    class TestSceneRendererContext : public spvr::SceneRendererContext
{
public:
     explicit TestSceneRendererContext();
    ~TestSceneRendererContext();
private:
    
};
#endif /* defined(TestSceneRendererContext_H_) */
}