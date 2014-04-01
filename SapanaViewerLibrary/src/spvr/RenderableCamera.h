//
//  RenderableCamera.h
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 14.01.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#pragma once
#ifndef SapanaViewerLibrary_RenderableCamera_H_
#define SapanaViewerLibrary_RenderableCamera_H_

// Base class includes

// External includes
#include <memory> 

// Project includes
#include "Camera.h"

namespace spvr{
    // TODO: Update mechanism, Documentation
class RenderableCamera
{
public:
          
    explicit RenderableCamera(std::shared_ptr< spvs::Camera > camera);
    virtual ~RenderableCamera();
      
    virtual std::shared_ptr< const vmml::frustumf > getViewFrustum() const;

private:
    
    std::shared_ptr< spvs::Camera > camera_;
    
    vmml::frustumf frustum_;
    
};
}
#endif /* defined(SapanaViewerLibrary_RenderableCamera_H_ */
