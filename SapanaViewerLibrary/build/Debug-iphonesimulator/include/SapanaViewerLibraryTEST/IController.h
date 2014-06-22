//
//  IController.h
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 27.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#ifndef SapanaViewerLibrary_IController_h
#define SapanaViewerLibrary_IController_h

#include <vector>
namespace spv
{

/**
 * @brief Interface for all controller classes.
 */
class IController
{
public:
    
    /**
     * @brief Updates the controller and all its child controllers.
     */
    virtual void update() const = 0;
    
    /**
     * @brief Returns all the child controller of the controler.
     * @return Child controllers of the controller.
     */
    virtual std::vector< std::shared_ptr< const spv::IController > >getChildController() const = 0;
};
}


#endif
