//
//  TreeViewNode.cpp
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 20.01.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Class definition include
#include "TreeViewNode.h"

// External includes

// Project includes

using namespace spvg;
                                                                                
TreeViewNode::TreeViewNode(int level,
                           int id,
                           std::string label
                           )
: level_(level)
, id_(id)
, expanded_(false)
, label_(label)
{                                                                               
    
}                                                                               
                                                                                
TreeViewNode::~TreeViewNode()                                      
{                                                                               
    
}
