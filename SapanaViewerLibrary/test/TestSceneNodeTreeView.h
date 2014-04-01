//
//  TestSceneNodeTreeView.h
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 20.01.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#ifndef SapanaViewerLibrary_TestSceneNodeTreeView_H_
#define SapanaViewerLibrary_TestSceneNodeTreeView_H_

// Base class includes
#include "SceneNodeTreeView.h"
// External includes
#include <memory>

// Project includes

#include "TreeViewNode.h"

namespace spvt{
    
    
class TestSceneNodeTreeView : public spvg::SceneNodeTreeView
{
public:    

//    explicit TestSceneNodeTreeView(std::shared_ptr< const spvs::SceneGraph > sceneGraph);
//
//    virtual ~TestSceneNodeTreeView();
    /**
    * @ Test Implementation
    */
//    virtual std::vector< spvg::TreeViewNode > getItems() const;
//    
//    virtual void switchItem(int itemPosition);
    
    /**
    * Expands a node.
    */
//    virtual void expandItem(int position);
//
//    virtual void collapseItem(int position);

private:
    
//    std::list< std::shared_ptr< spvg::TreeViewNode >  > entries_;
//    
//    std::shared_ptr< const spv::SceneGraph > sceneGraph_;
//    /**
//     * Adds a tree view node to the TestSceneNodeTreeView
//     */
//    void addTreeViewNode(std::list< std::shared_ptr< spvg::TreeViewNode > >::iterator position, std::shared_ptr< const spvs::SceneNode > node, int level);
//    
//    /**
//     * Returns a name for a node.
//     */
//    std::string getNameOfNode(std::shared_ptr< const spvs::SceneNode > node);

};
    
}
#endif /* defined(SapanaViewerLibrary_TestSceneNodeTreeView_H_ */
