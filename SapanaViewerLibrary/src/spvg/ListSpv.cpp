//
//  ListSpv.cpp
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 06.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Class definition include
#include "ListSpv.h"

// External includes

// Project includes

namespace spvg
{
namespace detail
{
class ListSpv : public IListSpv
{
public:
    
    explicit ListSpv()
    :items_(std::vector< ListItemSpv >())
    {
        // TODO: Implement
    }
    
    virtual ~ListSpv()
    {
        // TODO: Implement
    }
    
    virtual void update()
    {
        
    }
    
    virtual unsigned int getNumItems()
    {
        return items_.size();
    }
    
    virtual std::vector < ListItemSpv > getListItems()
    {
        return items_;
    }
    
private:
    
    std::vector < ListItemSpv > items_;
    
};
} // End namespace detail

ListSpv::ListSpv()
: ListSpv(new detail::ListSpv())
{
    // TODO: Implement
}
ListSpv::ListSpv(detail::IListSpv * listImplementation)
: impl_(listImplementation)
{
    // TODO: Implement
}

ListSpv::~ListSpv()
{
    //delete impl_;
}
}


