/*
 * SceneRendererContext.h
 *
 *  Created on: Dec 13, 2013
 *      Author: janmeier
 */

#pragma once
#ifndef SCENERENDERERCONTEXT_H_
#define SCENERENDERERCONTEXT_H_

// External includes

// Base class includes

// Project internal includes

namespace spvr{

  class SceneRendererContext
{
public:
        explicit SceneRendererContext(
            int vpXPos,
            int vpYPos,
            int vpWidth,
            int vpHeight
            );

        ~SceneRendererContext();

        const int getViewportXPosition() const {return vpXPos_;}
        const int getViewportYPosition() const {return vpYPos_;}
        const int getViewportWidth() const {return vpWidth_;}
        const int getViewportHeight() const {return vpHeight_;}

private:

        int vpXPos_;
        int vpYPos_;
        int vpWidth_;
        int vpHeight_;
    

};
        }

#endif /* SCENERENDERERCONTEXT_H_ */
