//
//  HierarchicalList.cpp
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 06.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Class definition include
#include "HierarchicalList.h"

// External includes

// Project includes
#include "TypeDefSpv.h"
// Debug Includes
#include <iostream>

namespace spvg
{
namespace detail
{
class HierarchicalList : public IHierarchicalList
{
public :
    explicit HierarchicalList()
    :items_(std::vector< HierarchicalListItem >())
    {
        // TODO: Implement
        
    }
    
    virtual ~HierarchicalList()
    {
        // TODO: Implement
    }
    
    virtual void expandListItem(spvu::ListItemID listItemID)
    {
        std::cout << "HierarchicalList: Item was expanded" << std::endl;
    }
    
    virtual void collapseListItem(spvu::ListItemID listItemID)
    {
        std::cout << "HierarchicalList: Item was expanded" << std::endl;
    }
    
    virtual bool toggleListItem(spvu::ListItemID sceneNodeID)
    {
        std::cout << "HierarchicalList: Item was toggled" << std::endl;
        return true;
    }
    
    bool canMoveToPosition(spvu::ListPosition oldPosition, spvu::ListPosition newPosition)
    {
        std::cout << "HierarchicalList:canMoveToPosition" << std::endl;
        return true;
    }
    
    virtual unsigned int getNumItems()
    {
        return items_.size();
    }
    
    virtual std::vector < HierarchicalListItem > getListItems()
    {
        return items_;
    }
    
    virtual void update() const
    {
        
    }
private:
    
    std::vector < HierarchicalListItem > items_;
};
} // End namespace detail
    
HierarchicalList::HierarchicalList()
: impl_(new detail::HierarchicalList())
{
    // TODO: Implement
}

HierarchicalList::HierarchicalList(detail::IHierarchicalList * listImplementation)
: impl_(listImplementation)
{
    // TODO: Implement
}

HierarchicalList::~HierarchicalList()
{
    // TODO: Implement
}
    
} // End namespace spvg


