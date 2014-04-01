//
//  ListSpv.h
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 06.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#ifndef SapanaViewerLibrary_FlatList_H_
#define SapanaViewerLibrary_FlatList_H_

// Base class includes

// External includes
#include <vector>

// Project includes
#include "ListItemSpv.h"

namespace spvg
{
namespace detail
{
class IListSpv
{
public:
    
    virtual void update() =0;
    virtual std::vector < ListItemSpv > getListItems() = 0;
    virtual unsigned int getNumItems() = 0;
};
}
class ListSpv
{    
public:    
    
    explicit ListSpv();
    explicit ListSpv(detail::IListSpv * listImplementation);
    virtual ~ListSpv();
    
    virtual void update() {impl_->update();}
    
    virtual std::vector < ListItemSpv > getListItems(){return impl_->getListItems();}
    virtual unsigned int getNumItems() {return impl_->getNumItems();}

    
  
private:
    spvg::detail::IListSpv * impl_;
    
};
}
#endif /* defined(SapanaViewerLibrary_FlatList_H_ */
