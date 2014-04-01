//
//  HierarchicalModelList.h
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 17.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#ifndef SapanaViewerLibrary_HierarchicalModelList_H_
#define SapanaViewerLibrary_HierarchicalModelList_H_

// Base class includes
#include "HierarchicalList.h"

// External includes
#include <map>

// Project includes
#include "SceneGraph.h"
#include "Observerimpl.h"
#include "TypeDefSpv.h"
#include "HierarchicalListItem.h"

namespace spvg{
class HierarchicalModelList : public detail::IHierarchicalList
{    
public:    
      
    explicit HierarchicalModelList(std::shared_ptr< const spvs::SceneGraph> sceneGraph);
    virtual ~HierarchicalModelList();    
    
    
#pragma mark - IHierarchicalList implementatoin

    
    virtual void expandListItem(spvu::ListItemID listItemID);
    virtual void collapseListItem(spvu::ListItemID listItemID) ;
    virtual bool toggleListItem (spvu::ListItemID sceneNodeID);
    
    virtual bool canMoveToPosition(spvu::ListPosition oldPosition, spvu::ListPosition newPosition);
    
    virtual std::vector < HierarchicalListItem > getListItems();
    virtual unsigned int getNumItems();
    
#pragma mark - Observer Methodes
    virtual void notify(std::shared_ptr< const spvu::INotification > notification ) const{ observerImpl_->notify(notification);}
 
#pragma mark - GUIAbstraction implementation
// TODO: Create the GUI abstraction base class
virtual void update() const;
    
private:
    std::shared_ptr< const spvs::SceneGraph > sceneGraph_;

    /**
     * Holds a reference to all Scenen nodes that are in the model list.
     */
    std::map < spvu::SceneNodeID, HierarchicalListItem > nodesInList_;
    
    std::vector < HierarchicalListItem > items_;
    
    std::shared_ptr< spvu::ObserverImpl> observerImpl_;
    
    bool itemsHaveChanged_;

#pragma mark - Node List Management
    void addNode(spvu::SceneNodeID nodeID);
    void removeNode(spvu::SceneNodeID nodeID);
    void expandNode(spvu::SceneNodeID nodeID);
    void collapseNode(spvu::SceneNodeID nodeID);
    
#pragma mark - Item Management
    /**
     * Updates the items_ vector.
     */
    void updateItems();
    
    
    
    void insertItem(spvu::SceneNodeID nodeID);

#pragma mark - Observer Util Methodes
    void handleNotifications();
    void rebuildList();
    void readdNode(spvu::SceneNodeID nodeID, std::map < spvu::SceneNodeID, HierarchicalListItem > & oldNodes);
    void updateNodeLevel(spvu::SceneNodeID);
};
}
#endif /* defined(SapanaViewerLibrary_HierarchicalModelList_H_ */
