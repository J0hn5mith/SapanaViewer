//
//  CameraList.h
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 10.04.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#ifndef SapanaViewerLibrary_CameraList_H_
#define SapanaViewerLibrary_CameraList_H_

// Base class includes
#include "ListSpv.h"


// External includes
#include <memory>

// Project includes
#include "SceneGraph.h"

namespace spvg
{
class CameraList : public detail::IListSpv
{    
public:    
      
    explicit CameraList(std::shared_ptr< const spvs::SceneGraph > sceneGraph);
    virtual ~CameraList();
    
    
#pragma mark - IListSpv Implementation
    virtual void update();
    virtual std::vector < ListItemSpv > getListItems();
    virtual unsigned int getNumItems();

private:
    std::shared_ptr< const spvs::SceneGraph > sceneGraph_;
    std::vector < ListItemSpv > items_;
};
}
#endif /* defined(SapanaViewerLibrary_CameraList_H_ */
