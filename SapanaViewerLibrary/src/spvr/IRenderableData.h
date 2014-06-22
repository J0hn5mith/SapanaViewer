//
//  IRenderableData.h
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 04.04.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#ifndef SapanaViewerLibrary_IRenderableData_h
#define SapanaViewerLibrary_IRenderableData_h

class IRenderableData
{
public:
    
    virtual void update() const =0;
    
};

#endif
