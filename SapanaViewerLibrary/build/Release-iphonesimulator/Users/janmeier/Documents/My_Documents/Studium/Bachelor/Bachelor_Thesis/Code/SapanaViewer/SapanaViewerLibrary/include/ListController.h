//
//  ListController.h
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 01.04.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#ifndef SapanaViewerLibrary_ListController_H_
#define SapanaViewerLibrary_ListController_H_

// Base class includes
#include "IController.h"

// External includes
#include <vector>
// Project includes
#include "TypeDefSpv.h"

namespace spvg
{
    class ListSpv;
    class ListItemSpv;
}

namespace spv{
    class ListController : public spv::IController
{
public:    
      
    explicit ListController(spvg::ListSpv * list);
    virtual ~ListController();
    
    virtual std::vector < spvg::ListItemSpv > getListItems();
    virtual spvu::ListSize getNumItems();
    
#pragma mark - Implementation of IController Interface
    virtual void update() const;
    
    virtual std::vector< std::shared_ptr< const spv::IController > > getChildController() const;
private:
    spvg::ListSpv * list_;
    

    
};
}
#endif /* defined(SapanaViewerLibrary_ListController_H_ */
