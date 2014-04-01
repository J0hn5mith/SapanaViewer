//
//  ListItemSpv.h
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 11.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#ifndef SapanaViewerLibrary_ListItemSpv_H_
#define SapanaViewerLibrary_ListItemSpv_H_

// Base class includes

// External includes
#include <string>

// Project includes
#include "TypeDefSpv.h"

namespace spvg{
class ListItemSpv
{    
public:    
      
    explicit ListItemSpv(spvu::ListItemID itemId, std::string label);
    virtual ~ListItemSpv();
    
    virtual std::string getLabel(){return label_;}
    
    virtual spvu::ListItemID getID(){return id_;}
    
  

private:
    
    std::string label_;
    spvu::ListItemID id_;
              
};
}
#endif /* defined(SapanaViewerLibrary_ListItemSpv_H_ */
