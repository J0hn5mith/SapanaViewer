//
//  ITreeViewItem.h
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 20.01.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#pragma once
#ifndef SapanaViewerLibrary_ITreeViewItem_H_
#define SapanaViewerLibrary_ITreeViewItem_H_

// Base class includes

// External includes
#include <string>

// Project includes
#include "TypeDefSpv.h"
namespace spvg{

/**
 * A item for a ITreeView. Each ITreeViewItem represents a tree node (corresponding (tree) node).
 */
class ITreeViewItem
{    
public:

    /**
     * Returns the level of the item. The level of a item corresponds
     * to the depth of a node in a tree.
     * @return Level of the node.
     */
    virtual int getLevel() const = 0;
    
    /**
     * Returns the ID of the tree node the ITreeViewItem represents.
     * @return ID of the tree node
     */
    virtual spvu::SceneNodeID getId() const = 0;
    
    /**
     * Returns whether the node is expanded or not.
     * @return true if the node is expanded
     */
    virtual bool isExpanded() const = 0;
    
    /**
     * Set the expanded status of the node.
     * @param expanded New value for the expanded mamber
     */
    virtual void setExpanded(bool expanded) = 0;
    
    /**
     * Returns the label of the ITreeViewItem.
     * @return label of the ITreeViewItem
     */
    virtual std::string getLabel() const = 0;

private:
      
};
}
#endif /* defined(SapanaViewerLibrary_ITreeViewItem_H_ */
