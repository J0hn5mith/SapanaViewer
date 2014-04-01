//
//  CameraNode.h
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 13.01.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#pragma once
#ifndef SapanaViewerLibrary_CameraNode_H_
#define SapanaViewerLibrary_CameraNode_H_

// Base class includes
#include "LeafNode.h"
// External includes

// Project includes

namespace spvs {
    class Camera;
}

namespace spvs{
/**
 * A scene graph node that has a reference to a camera.
 */
class CameraNode : public LeafNode
{
public:
    
    /**
     * Constructs a new camera node object.
     */
    explicit CameraNode(std::shared_ptr< Camera > camera);
    
    /**
     * Destroys the camera node object.
     */
    virtual ~CameraNode();
      
    /**
     * Returns a reference to the camera nodes camera camera object.
     * @return A reference to the camera nodes camera object.
     */
    virtual std::shared_ptr< Camera > getCamera() const {return camera_;}
      
    /**
     * Replaces the camera node's camera object reference.
     * @param camera A reference to the new camera object.
     */
    virtual void setCamera( std::shared_ptr< Camera > camera) { camera_ = camera;}

private:
    
    /**
     * Reference to the camera node's camera object. 
     */
    std::shared_ptr< spvs::Camera > camera_;
};
}
#endif /* defined(SapanaViewerLibrary_CameraNode_H_ */
