//
//  IRenderer
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 16.01.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#pragma once
#ifndef SapanaViewerLibrary_RENDERER_H_
#define SapanaViewerLibrary_RENDERER_H_

// Base class includes

// External includes
#include <OpenGLES/ES1/gl.h>

// Internal includes

namespace spvr{
/**
 * Abstract interface for renderers. A renderer renders
 * various data into a OpenGL view. ( Could also use different libraries
 * thatn OpenGL.)
 * The purpose of this intervace is simplyfied cascading rendering. (Not
 * used yet)
 */
class IRenderer
{

public:
    
    /**
     * Inisialize the open gl for this renderer
     */
    virtual void init() const = 0;

    /**
     * Sets the viewport this renderer renders into;
     */
    virtual void setViewport(GLint x, GLint y, GLint width, GLint height) const = 0;
    
    /**
     * The renderer renders the associated data to the iewport.
     */
    virtual void render() const = 0;
};

}

#endif /* SapanaViewerLibrary_RENDERER_H_ */
