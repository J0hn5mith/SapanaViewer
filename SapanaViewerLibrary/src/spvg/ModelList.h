//
//  ModelList.h
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 12.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#ifndef SapanaViewerLibrary_ModelList_H_
#define SapanaViewerLibrary_ModelList_H_

// Base class includes
#include "ListSpv.h"


// External includes
#include <memory>

// Project includes
#include "SceneGraph.h"

namespace spvg{
class ModelList : public detail::IListSpv
{
public:    
      
    explicit ModelList(std::shared_ptr< const spvs::SceneGraph > sceneGraph);
    virtual ~ModelList();    
    
    virtual void update();
    virtual std::vector < ListItemSpv > getListItems();
    virtual unsigned int getNumItems();
    
    
private:
    std::shared_ptr< const spvs::SceneGraph > sceneGraph_;
    std::vector < ListItemSpv > items_;
};
}
#endif /* defined(SapanaViewerLibrary_ModelList_H_ */
