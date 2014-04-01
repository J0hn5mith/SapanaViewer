//
//  NodeAncestorList.h
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 23.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#ifndef SapanaViewerLibrary_NodeAncestorList_H_
#define SapanaViewerLibrary_NodeAncestorList_H_

// Base class includes
#include "ListSpv.h"


// External includes
#include <memory>

// Project includes
#include "SceneNode.h"

namespace spvg
{
class NodeAncestorList : public detail::IListSpv
{    
public:    
  
  explicit NodeAncestorList(std::shared_ptr< const spvs::SceneNode > sceneNode);
  virtual ~NodeAncestorList();
    
    virtual void update();
    
  virtual std::vector < ListItemSpv > getListItems();
  virtual unsigned int getNumItems();
  
private:
  std::shared_ptr< const spvs::SceneNode > sceneNode_;
  std::vector < ListItemSpv > items_;
};

}
#endif /* defined(SapanaViewerLibrary_NodeAncestorList_H_ */
