//
//  SceneNodeRenderer.h
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 10.04.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#ifndef SapanaViewerLibrary_SceneNodeRenderer_H_
#define SapanaViewerLibrary_SceneNodeRenderer_H_

// Base class includes

// External includes
#include <memory>

// Project includes
#include "RenderableSceneNode.h"

namespace spvr
{
class SceneNodeRenderer
{    
public:    

#pragma mark - Constructor & Destructor
    explicit SceneNodeRenderer();    
    virtual ~SceneNodeRenderer();
    
    
#pragma mark - Render Methodes
    void renderSceneNode(std::shared_ptr< const spvr::RenderableSceneNode >);

#pragma mark Render Utlity Methodes
    void setPosition(std::shared_ptr< const RenderableSceneNode > node) const;
    void unsetPosition() const;
    
    void drawCoordinateSystem(std::shared_ptr< const RenderableSceneNode > node);
    
    void drawLineToParent(std::shared_ptr< const RenderableSceneNode > node) const;
    
    void drawLineToOrigin(std::shared_ptr< const RenderableSceneNode > node) const;
    
private:
    spvu::Color getParentLineColor() const{ return parentLineColor_;}
    
    const spvu::Color parentLineColor_;
    const spvu::Color originLineColor_;
    
};
}
#endif /* defined(SapanaViewerLibrary_SceneNodeRenderer_H_ */
