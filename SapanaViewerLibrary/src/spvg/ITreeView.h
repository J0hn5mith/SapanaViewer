//
//  ITreeView.h
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 20.01.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#pragma once
#ifndef SapanaViewerLibrary_ITreeView_H_
#define SapanaViewerLibrary_ITreeView_H_

// Base class includes

// External includes
#include <vector>

// Project includes



namespace spvg{
    
// Forewared declarations
class TreeViewNode;
    
    //TODO: Synchoronise with SceneGraph
/**
 * The TreeView is a flat representation of a tree. Each item inside
 * the ree view is associated with a node (called the corresponding node) of a tree.
 */
class ITreeView
{    
public:
    
    /**
     * Returns the items inside the trew view in a vector.
     * @return A vector with the tree views items
     */
    virtual std::vector< TreeViewNode > getItems() const = 0;
        
    /**
     * Toggles the state of a item. If the item is expanded it gets collapsed and vice versa.
     * @param itemPosition Position of the item that is toggled.
     */
    virtual void toggleItem(int itemPosition) = 0 ;
    
    /**
     * Expands a item. When a item gets expanded, ITreeViewItem s for the
     * children of the corresponding node are inserted into the tree view.
     * If the item is already expanded, nothing happens.
     * @param itemPosition Position of the item that is expanded.
     */
    virtual void expandItem(int itemPosition) = 0;
    
    /**
     * Collaps a item. When a item gets collapsed, the ITreeViewItems
     * corresponding to the spcified node's children are removed from the
     * tree view.
     * If the item is already collapsed, nothing happens.
     * @param itemPosition Position of the item that is expanded.
     */
    virtual void collapseItem(int itemPosition) = 0;
    
private:    
              
};
}
#endif /* defined(SapanaViewerLibrary_ITreeView_H_ */
