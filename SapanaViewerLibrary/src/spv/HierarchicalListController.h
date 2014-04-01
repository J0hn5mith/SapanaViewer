//
//  HierarchicalListController.h
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 28.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#ifndef SapanaViewerLibrary_HierarchicalListController_H_
#define SapanaViewerLibrary_HierarchicalListController_H_

// Base class includes
#include "IController.h"

// External includes
#include <vector>
// Project includes
#include "TypeDefSpv.h"

// Forward Declarations
namespace spvg
{
    class HierarchicalList;
    class HierarchicalListItem;
}

namespace spv{
class HierarchicalListController : public IController
{    
public:    
      
    explicit HierarchicalListController(spvg::HierarchicalList * hierarchicalModeList);
    virtual ~HierarchicalListController();
    
    void expandListItem(spvu::ListItemID listItemID);
    void collapseListItem(spvu::ListItemID listItemID);
    bool toggleListItem(spvu::ListItemID listItemID);
    
    bool canMoveToPosition(spvu::ListPosition oldPosition, spvu::ListPosition newPosition);
    
    std::vector < spvg::HierarchicalListItem > getListItems();
    spvg::HierarchicalListItem getItemAtPosition(spvu::ListPosition position);
    spvu::ListSize getNumItems();
    
    void refreshItems();
    
#pragma mark - Implementation of IController Interface
    void update() const;
    
private:    
    spvg::HierarchicalList * hierarchicalList_;
};
}
#endif /* defined(SapanaViewerLibrary_HierarchicalListController_H_ */
