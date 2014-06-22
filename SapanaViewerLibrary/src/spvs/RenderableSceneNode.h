//
//  RenderableSceneNode.h
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 10.04.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#ifndef SapanaViewerLibrary_RenderableSceneNode_H_
#define SapanaViewerLibrary_RenderableSceneNode_H_

// Base class includes
#include "IObserver.h"

// External includes

// Project includes
#include "ObserverImpl.h"
#include "Util.h"
#include "SceneNodeProperties.h"

// Forward Declarations
namespace spvs {
    class SceneNode;
}
namespace spvr{
class RenderableSceneNode : public spvu::IObserver
{    
public:
    
#pragma mark - Getter and Setter Methodes
    explicit RenderableSceneNode(std::shared_ptr< const  spvs::SceneNode > sceneNode);
    virtual ~RenderableSceneNode();    

    
#pragma mark - Getter and Setter Methodes
    /**
     * Returns the transformation Matrix for the renderable
     * model node.
     * @return transformation matrix that defines the models positin
     * in terms of the world coordinate system.
     */
     virtual const spvu::TransMatrix  getWorldTransMatrix() const;
    
    virtual const spvu::TransMatrix  getNodeTransMatrix() const;
    
    /**
     * Returns the model nodes final properties. Final means, that they
     * might be inherited from the parent nodes.
     */
    const spvs::SceneNodeProperties getModelNodeProperties() const;
    
    
#pragma mark - Implementation IObserver Interface
    virtual void notify(std::shared_ptr< const spvu::INotification > notification ) const;
    
    virtual void update() const;
    
private:
    
#pragma mark - Private Member Variables
    std::shared_ptr< const spvs::SceneNode > sceneNode_;
    spvu::TransMatrix worldTransMatrix_;
    spvu::TransMatrix nodeTransMatrix_;
    spvs::SceneNodeProperties sceneNodeProperties_;
    
    const std::shared_ptr< spvu::ObserverImpl > observerImpl_;
    
#pragma mark - Private Methodes
    void handleNotifications( std::shared_ptr< std::list< std::shared_ptr<const spvu::INotification > > > notifications);
    void updateTransMatrix();
    void updateProperties();
};
}
#endif /* defined(SapanaViewerLibrary_RenderableSceneNode_H_ */
