//
//  TestRenderableScene.h
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 20.12.13.
//  Copyright (c) 2013 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#ifndef TestRenderableScene_H_
#define TestRenderableScene_H_

// Base class include
#include "RenderableScene.h"

// External includes
#include <vector>
#include <memory>

// Project includes
#include "RenderableCameraNode.h"
#include "SceneGraph.h"

namespace spvt{
    class TestRenderableScene : public spvr::RenderableScene {
    
public:
        explicit TestRenderableScene(std::shared_ptr< spvs::SceneGraph > sceneData);
        
        ~TestRenderableScene();
      
//        virtual std::shared_ptr<const spvr::RenderableCameraNode> getActiveCameraNode() const;
        
        /**
         * @ Implementation
         */
        virtual std::vector<float> getClearColor() const;
      
    
    private:
      
//        std::shared_ptr<const spvr::RenderableCameraNode> testActiveCameraNode_;
         std::vector<float> testColor_;
};
}
#endif /* defined(TestRenderableScene_H_) */
