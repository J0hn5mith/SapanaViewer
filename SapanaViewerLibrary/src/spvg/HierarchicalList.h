//
//  HierarchicalList.h
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 06.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#ifndef SapanaViewerLibrary_HierarchicalList_H_
#define SapanaViewerLibrary_HierarchicalList_H_

// Base class includes
#include "ListSpv.h"
#include "TypeDefSpv.h"
// External includes

// Project includes
#include "HierarchicalListItem.h"

namespace spvg{
namespace detail
{
class IHierarchicalList
{
public:

    
    
    
    virtual void expandListItem(spvu::ListItemID listItemID) = 0;
    virtual void collapseListItem(spvu::ListItemID listItemID) = 0;
    virtual bool toggleListItem(spvu::ListItemID listItemID) = 0;
    virtual bool canMoveToPosition(spvu::ListPosition oldPosition, spvu::ListPosition newPosition) = 0;
    virtual std::vector < HierarchicalListItem > getListItems() = 0;
    virtual unsigned int getNumItems() = 0;
    virtual void update() const = 0;
    
private:
    
};
}
    
class HierarchicalList
{    
public:    
      
    explicit HierarchicalList();
    explicit HierarchicalList(detail::IHierarchicalList * listImplementation);
    ~HierarchicalList();
    
    void expandListItem(spvu::ListItemID listItemID){return impl_->expandListItem(listItemID);}
    void collapseListItem(spvu::ListItemID listItemID){return impl_->collapseListItem(listItemID);}
    bool toggleListItem(spvu::ListItemID listItemID) {return impl_->toggleListItem(listItemID);}
    
    bool canMoveToPosition(spvu::ListPosition oldPosition, spvu::ListPosition newPosition) {return impl_->canMoveToPosition(oldPosition,newPosition);}
    
    unsigned int getNumItems() {return impl_->getNumItems();}
    std::vector < HierarchicalListItem > getListItems(){return impl_->getListItems();}
    
    void update() const {impl_->update();}
    
private:
     spvg::detail::IHierarchicalList * impl_;
};
}
#endif /* defined(SapanaViewerLibrary_HierarchicalList_H_ */
