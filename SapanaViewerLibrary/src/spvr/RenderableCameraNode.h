//
//  RenderableCameraNode.h
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 02.01.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#pragma once
#ifndef SapanaViewerLibrary_RenderableCameraNode_H_
#define SapanaViewerLibrary_RenderableCameraNode_H_

// Base class includes
#include "RenderableLeafNode.h"

// External includes

// Project includes

// Forward declaration

namespace spvs {
    class CameraNode;
}

namespace spvr {
    class RenderableCamera;
}

namespace spvr {
    //TODO: Doku
class RenderableCameraNode : public RenderableLeafNode
{
public:
    explicit RenderableCameraNode(std::shared_ptr< const spvs::CameraNode > cNode);
        
    ~RenderableCameraNode();
        
    virtual std::shared_ptr< const RenderableCamera > getRenderableCamera() const;
        
private:
        
    std::shared_ptr< const spvs::CameraNode > cameraNode_;
        
    std::shared_ptr< const RenderableCamera > rCamera_;
        
        
    };
}


#endif /* defined(SapanaViewerLibrary_RenderableCameraNode_H_ */
