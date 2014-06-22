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
         glDisable(GL_LIGHTING);
        
        
        // TODO: Move to own method, make normal color parameter
        // Draw line
        float coords[] = {startPoint.x, startPoint.y, startPoint.z, endPoint.x, endPoint.y, endPoint.z};
        
        glEnableClientState(GL_VERTEX_ARRAY);
        glColor4f(color.r,color.g,color.b,color.a); //line color
        
        glVertexPointer(3, GL_FLOAT, 0, coords);
        glEnableClientState(GL_VERTEX_ARRAY);
        glDrawArrays(GL_LINE_STRIP, 0, 2);
        glDisableClientState(GL_VERTEX_ARRAY);
        
        
        glEnable(GL_LIGHTING);
        
    }
    
    static void drawPlane(spvu::Position startPoint, spvu::Position endPoint, spvu::Color color)
    {
        // WARNING: OpenGL es 1.1 method
        glDisable(GL_LIGHTING);
        
        spvu::Position supportOne ={startPoint.x, endPoint.y, endPoint.z};
        spvu::Position supportTwo ={endPoint.x, startPoint.y, startPoint.z};
        
        // TODO: Move to own method, make normal color parameter
        // Draw line
        float coords[] = {
            startPoint.x, startPoint.y, startPoint.z,
            supportTwo.x, supportTwo.y, supportTwo.z,
            supportOne.x, supportOne.y, supportOne.z,
            endPoint.x, endPoint.y, endPoint.z,
        };
        
        glEnableClientState(GL_VERTEX_ARRAY);
        glColor4f(color.r,color.g,color.b,color.a);
        
        glVertexPointer(3, GL_FLOAT, 0, coords);
        glEnableClientState(GL_VERTEX_ARRAY);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
        glDisableClientState(GL_VERTEX_ARRAY);
        
        
        glEnable(GL_LIGHTING);
    }
    
    static void drawCoordinateSystem(float length, bool twoSided )
    {
        const spvu::Color xColor = {1.0, 0.0, 0.0, 1.0};
        const spvu::Color yColor = {0.0, 1.0, 0.0, 1.0};
        const spvu::Color zColor = {0.0, 0.0, 1.0, 1.0};
        
        float minValue = twoSided ? -length : 0;
        
        drawLine({minValue,0,0}, {length, 0, 0}, xColor);
        drawLine({0,minValue,0}, { 0, length, 0}, yColor);
        drawLine({0,minValue,0}, {0, 0, length }, zColor);
        
    }
    
    
    static void drawMashPlane(float length, float interval,  spvu::Color color, bool twoSided)
    {
        
        int numIntervals = 10;
        float minValue = twoSided ? -length : 0;
        int indexStart = twoSided ? -numIntervals : 0;
        
        for (int i = indexStart ; i <= 10; i++)
        {
            drawLine({minValue, 0, interval*i}, {length, 0, interval*i}, color);
        }
        
        for (int i = indexStart ; i <= 10; i++)
        {
            drawLine({interval*i,0,minValue}, {interval*i, 0, length}, color);
        }
        
        drawLine({0,0,0}, {0, length, 0}, color);
    }
    
 
    
};
}
#endif /* defined(SapanaViewerLibrary_RendererUtils_H_ */
