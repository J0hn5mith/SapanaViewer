//
//  HierarichcalListItem.h
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 17.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#ifndef SapanaViewerLibrary_HierarichcalListItem_H_
#define SapanaViewerLibrary_HierarichcalListItem_H_

// Base class includes
#include "ListItemSpv.h"

// External includes

// Project includes
#include "TypeDefSpv.h"

namespace spvg {
class HierarchicalListItem    : public ListItemSpv
{
public:    
      
    explicit HierarchicalListItem(spvu::ListItemID itemID, std::string label, bool expanded, bool expandable, unsigned int level);
    virtual ~HierarchicalListItem();
    

    bool isExpanded() {return isExpanded_;}
    void setExpanded(bool isExpaneded) {isExpanded_ = isExpaneded;}
    void setExpandable(bool isExpandable) {isExpandedable_ = isExpandable;}
    bool isExpandable() {return isExpandedable_;}
    unsigned int getLevel() const {return level_;}
    void setLevel(unsigned int newLevel) {level_ = newLevel;}

private:
    bool isExpandedable_;
    bool isExpanded_;
    unsigned int level_;
};
}
#endif /* defined(SapanaViewerLibrary_HierarichcalListItem_H_ */
