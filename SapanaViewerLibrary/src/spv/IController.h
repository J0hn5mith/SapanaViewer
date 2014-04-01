//
//  IController.h
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 27.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#ifndef SapanaViewerLibrary_IController_h
#define SapanaViewerLibrary_IController_h

namespace spv
{
class IController
{
public:
    virtual void update() const = 0;
};
}


#endif
