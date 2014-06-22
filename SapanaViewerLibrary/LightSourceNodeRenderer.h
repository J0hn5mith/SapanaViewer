//
//  LightSourceNodeRenderer.h
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 04.04.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#ifndef SapanaViewerLibrary_LightSourceNodeRenderer_H_
#define SapanaViewerLibrary_LightSourceNodeRenderer_H_

// Base class includes

// External includes

// Project includes
#include "RenderableLightSourceNode.h"

namespace spvr
{
class LightSourceNodeRenderer
{    
public:    
      
    explicit LightSourceNodeRenderer();    
    virtual ~LightSourceNodeRenderer();
    
    void renderLightSourceNode(std::shared_ptr< const spvr::RenderableLightSourceNode > renderLightSourceNode, unsigned int lightNumber ) const;
    
    void setPosition(std::shared_ptr< const RenderableLightSourceNode > node) const;

    void unsetPosition() const;
    
private:    
              
};
}
#endif /* defined(SapanaViewerLibrary_LightSourceNodeRenderer_H_ */
