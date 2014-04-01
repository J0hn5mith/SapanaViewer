//
//  NodeTransformationsList.h
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 13.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#ifndef SapanaViewerLibrary_NodeTransformationsList_H_
#define SapanaViewerLibrary_NodeTransformationsList_H_
// Base class includes
#include "ListSpv.h"


// External includes
#include <memory>

// Project includes
#include "SceneNode.h"

namespace spvg{
class NodeTransformationsList : public detail::IListSpv
{
public:
    
    explicit NodeTransformationsList(std::shared_ptr< const spvs::SceneNode > sceneNode);
    virtual ~NodeTransformationsList();
    void update();
    virtual std::vector < ListItemSpv > getListItems();
    virtual unsigned int getNumItems();
    
private:
    std::shared_ptr< const spvs::SceneNode > sceneNode_;
    std::vector < ListItemSpv > items_;
};
}
#endif /* defined(SapanaViewerLibrary_NodeTransformationsList_H_ */
