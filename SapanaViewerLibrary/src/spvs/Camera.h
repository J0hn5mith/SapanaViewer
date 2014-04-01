//
//  Camera.h
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 13.01.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#pragma once
#ifndef SapanaViewerLibrary_Camera_H_
#define SapanaViewerLibrary_Camera_H_

// Base class includes

// External includes
#include "vmmlib/frustum.hpp"
#include <memory> 

// Project includes


namespace spvs{

/**
 * The camera class is used to specify view ports.
 * TODO: Orthogonal projections
 */
class Camera
{
public:
    
    /**
     * Constructs a new camera object.
     */
    explicit Camera();
    
    /**
     * Constructs a new camera onject based on a veiw frustum.
     */
    explicit Camera(std::shared_ptr< vmml::frustumf > frustum);
    
    /**
     * Destroys the camera object.
     */
    virtual ~Camera();
    
    /**
     * Returns a reference to the view frustum of the camera object.
     * @return A reference to the cameras view frustum.
     */
    virtual std::shared_ptr< vmml::frustumf > getViewFrustum() const {return viewFrustum_;}
    
    /**
     * Sets the veiw frustum reference of the camera. The previously frustum
     * is removed.
     * @param frustum A reference to the new view frustum.
     */
    virtual void setViewFrustum(std::shared_ptr< vmml::frustumf > frustum){viewFrustum_ = frustum;}

private:
    
    /**
     * Reference to the cameras view frustum. 
     */
    std::shared_ptr< vmml::frustumf > viewFrustum_;
                  
  };
}
#endif /* defined(SapanaViewerLibrary_Camera_H_ */
