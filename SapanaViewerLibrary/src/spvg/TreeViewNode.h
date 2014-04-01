//
//  TreeViewNode.h
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 20.01.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#pragma once
#ifndef SapanaViewerLibrary_TreeViewNode_H_
#define SapanaViewerLibrary_TreeViewNode_H_

// Base class includes
#include "ITreeViewItem.h"

// External includes
#include <String> 

// Project includes
#include "TypeDefSpv.h"

namespace spvg
{
/**
 * ITreeViewItem for SceneNodeTreeView.
 */
class TreeViewNode : public ITreeViewItem
{    
public:    
      
    explicit TreeViewNode(int level,
                          int id,
                          std::string label);
    virtual ~TreeViewNode();
    
    /**
     * @ Implementatoin
     */
    virtual int getLevel() const {return level_;}
    
    /**
     * @ Implementatoin
     */
    virtual spvu::SceneNodeID getId() const {return id_;}
    
    /**
     * @ Implementatoin
     */
    virtual bool isExpanded() const {return expanded_;}
    
    /**
     * @ Implementatoin
     */
    virtual void setExpanded(bool expanded) { expanded_ = expanded;}
    
    /**
     * @ Implementatoin
     */
    virtual std::string getLabel() const {return label_;}


private:
    
    int level_;
    int id_;
    bool expanded_;
    std::string label_;
              
};
}
#endif /* defined(SapanaViewerLibrary_TreeViewNode_H_ */
