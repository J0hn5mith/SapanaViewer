/*
 * ModelRenderer.h
 *
 *  Created on: Dec 9, 2013
 *      Author: janmeier
 */

#pragma once
#ifndef MODELRENDERER_H_
#define MODELRENDERER_H_

// Base class includes

// External includes
#include <vector>
#include <memory>

// Project include


// Forward declaration
namespace spvr {
    class RenderableModelNode;
    class RenderableModel;
    class SceneNodeRenderer;
}

namespace spvr{

/**
 * The model renderer is used by a SeceneRenderer to 
 * render RenderableModelNodes.
 */
class ModelRenderer
{
public:
#pragma mark - Constructor & Destructor
    explicit ModelRenderer(std::shared_ptr< spvr::SceneNodeRenderer > sceneNodeRenderer);
    ~ModelRenderer();

    
#pragma mark - Render Methodes
    void renderModel(std::shared_ptr< const RenderableModelNode > modelNode) const;

    void renderModels(std::shared_ptr< std::vector< std::shared_ptr< const RenderableModelNode > > > models) const;


private:
#pragma mark - Decorated Class
    std::shared_ptr< SceneNodeRenderer > sceneNodeRenderer_;
    
#pragma mark - Render Methodes

    /**
     * Binds the buffers used by the rendered model and sets the various pointers.
     */
    void bindBuffers(std::shared_ptr< const RenderableModel > model) const;

    /**
     * Unbinds the buffers used by the rendered model releases the various pointers.
     */
    void unbindBuffers(std::shared_ptr< const RenderableModel > model) const;
    
    /**
     * Draws a model node. (Model and all helping structure)
     */
    void drawModelNode(std::shared_ptr< const RenderableModelNode > modelNode) const;

    
    /**
     * Actually draws the renderable model.
     */
    void drawModel(std::shared_ptr< const RenderableModel > model) const;
    
    /**
     * Actually draws the renderable model.
     */
    void drawModel(std::shared_ptr< const RenderableModel > model, bool useWireframe) const;

    /**
     * Applies the transformation matrix of the RenderableModel
     * Node to the GL_MODELVIEW matrix. 
     */
    void setPosition(std::shared_ptr< const RenderableModelNode > modelNode) const;

    /**
     * Sets the GL_MODELVIEW matrix back to the state it had before
     * rendering the model
     */
    void unsetPosition() const;
    
#pragma mark - Methodes Related to the Suport constructs
    /**
     * Draws support models such as coordinate systems and normals.
     */
    void drawModelNodeSupport(std::shared_ptr< const RenderableModelNode > modelNode) const;
    
    
    /**
     * Draws a line from the models cs origin to the 
     * world cs origin
     */
    void drawLineToParentNode(std::shared_ptr< const RenderableModelNode > modelNode) const;

};

}
#endif /* MODELRENDERER_H_ */
