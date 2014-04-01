//
//  RenderableLeafNode.h
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 14.01.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#pragma once
#ifndef SapanaViewerLibrary_RenderableLeafNode_H_
#define SapanaViewerLibrary_RenderableLeafNode_H_

// Base class includes
#include "IObserver.h"

// External includes

// Project includes
#include "Util.h"
#include "ObserverImpl.h"

// Forward declaration
namespace spvs {
    class LeafNode;
}


namespace spvr{
//TODO: Dokumentation, class and memberfunctions
class RenderableLeafNode : public spvu::IObserver
{
public:
    
    explicit RenderableLeafNode( std::shared_ptr< const spvs::LeafNode > lNode);
    
    virtual ~RenderableLeafNode();
    
    //TODO: Does it make sense to return a pointer an not a value? 
    virtual std::shared_ptr< const spvu::TransMatrix > getTransMatrix() const;
    
    /**
     * Observer implementation
     */
    virtual void notify(std::shared_ptr< const spvu::INotification > notification ) const{observerImpl_->notify(notification);}
    
    // TODO: Doku
    virtual void update() const;

private:
    
    std::shared_ptr< const spvs::LeafNode > leafNode_;
    
    const std::shared_ptr<spvu::ObserverImpl > observerImpl_;
    
    spvu::TransMatrix transformationMatrix_;
    
    void handleNotifications( std::shared_ptr< std::list< std::shared_ptr<const spvu::INotification > > > notifications);
    
    void updateTransMatrix();
                  
};
}
#endif /* defined(SapanaViewerLibrary_RenderableLeafNode_H_ */
