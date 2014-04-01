//
//  RendererUtils.h
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 14.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#ifndef SapanaViewerLibrary_RendererUtils_H_
#define SapanaViewerLibrary_RendererUtils_H_

// Base class includes

// External includes
#include <OpenGLES/ES1/gl.h> // TODO: Remove iOS dependency

// Project includes

namespace spvr
{
namespace RendererUtils
{
    static void drawLine(spvu::Position startPoint, spvu::Position endPoint, spvu::Color color)
    {
        // WARNING: OpenGL es 1.1 method
        
        // TODO: Move to own method, make normal color parameter
        // Draw line
        float coords[] = {startPoint.x, startPoint.y, startPoint.z, endPoint.x, endPoint.y, endPoint.z};
        
        glEnableClientState(GL_VERTEX_ARRAY);
        glColor4f(color.r,color.g,color.b,color.a); //line color
        
        glVertexPointer(3, GL_FLOAT, 0, coords);
        glEnableClientState(GL_VERTEX_ARRAY);
        glDrawArrays(GL_LINE_STRIP, 0, 2);
        glDisableClientState(GL_VERTEX_ARRAY);
        // End line
        
    }
    
};
}
#endif /* defined(SapanaViewerLibrary_RendererUtils_H_ */
