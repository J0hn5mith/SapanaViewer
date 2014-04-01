/*
 * ScreenRendererContext.cpp
 *
 *  Created on: Dec 13, 2013
 *      Author: janmeier
 */

#include"SceneRendererContext.h"

using namespace spvr;
SceneRendererContext::SceneRendererContext(
    int vpXPos,
    int vpYPos,
    int vpWidth,
    int vpHeight
    )
: vpXPos_(vpXPos)
, vpYPos_(vpYPos)
, vpWidth_(vpWidth)
, vpHeight_(vpHeight)
{

}

SceneRendererContext::~SceneRendererContext()
{
    
}


