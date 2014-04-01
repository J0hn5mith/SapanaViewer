/*
 * RenderableModelInstance.h
 *
 *  Created on: Dec 12, 2013
 *      Author: janmeier
 */

#pragma once
#ifndef RENDERABLEMODELINSTANCE_H_
#define RENDERABLEMODELINSTANCE_H_

// Base class includes
#include "IObserver.h"

// External includes
#include <memory>

// Project includes
#include "ObserverImpl.h"
#include "SceneNodeProperties.h"
#include "Util.h"


// Forwared declaration
namespace spvr {
    class RenderableModel;
}

namespace spvs {
    class ModelNode;
}

namespace spvr{

  /**
 * A RenderableModel that belongs to a RenderableScene.
 * The vertices of the RenderableModelInstance are defined by a
 * renderable model. The transformation, that define its position,
 * orientation etc. are defined by a transformation matrix.
 * RendererableModelInstances are the renderable version of a
 * scene graph's ModelNode.
 */
    //TODO: Make derivative of RenderableLeafNode
class RenderableModelNode : public spvu::IObserver
{
    //TODO: Some method's doku is missing
public:
    explicit RenderableModelNode(std::shared_ptr< const  spvs::ModelNode > modelNode);

    ~RenderableModelNode();

    const virtual std::shared_ptr< const RenderableModel > getRenderableModel() const {return renderableModel_;}
    
    /**
    * Returns the transformation Matrix for the renderable
    * model node.
    * @return transformation matrix that defines the models positin
    * in terms of the world coordinate system.
    */
    virtual std::shared_ptr< const spvu::TransMatrix > getTransMatrix() const;
    
    /**
     * Returns the model nodes final properties. Final means, that they
     * might be inherited from the parent nodes.
     */
    virtual const spvs::SceneNodeProperties getModelNodeProperties() const;
  
    /**
     * Observer implementation
     */
    virtual void notify(std::shared_ptr< const spvu::INotification > notification ) const{observerImpl_->notify(notification);}
  
    virtual void update() const;
  
private:
    /**
    * Holds a reference to the ModelNode the RenderableModelInstance
    * is built of.
    */
    std::shared_ptr< const spvs::ModelNode > modelNode_;
    
    /**
    * Reference to the RenderableModel the RenderableModelInstance
    * uses.
    */
    std::shared_ptr< const RenderableModel > renderableModel_;
    
    /**
    * Transformation matrix that defines the models position
    * in regard to the world coordinates.
    */
    spvu::TransMatrix transformationMatrix_;
  
    // TODO: Doku
    const std::shared_ptr< spvu::ObserverImpl > observerImpl_;
  
    void handleNotifications( std::shared_ptr< std::list< std::shared_ptr<const spvu::INotification > > > notifications);
  
    /**
     * Sets the RenderableModelNode's transformation matrix to the current
     * transformation matrix of the represented ModelNode.
     */
    void updateTransMatrix();
  
};

}
#endif /* RENDERABLEMODELINSTANCE_H_ */
