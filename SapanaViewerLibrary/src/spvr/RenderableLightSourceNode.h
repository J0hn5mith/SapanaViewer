//
//  RenderableLightSourceNode.h
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 04.04.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#ifndef SapanaViewerLibrary_RenderableLightSourceNode_H_
#define SapanaViewerLibrary_RenderableLightSourceNode_H_

// Base class includes
#include "RenderableLeafNode.h"

// External includes
#include <memory>

// Project includes
#include "LightSourceNode.h"
#include "RenderableLightSource.h"

namespace spvr{
class RenderableLightSourceNode : public RenderableLeafNode
{    
public:    
      
    explicit RenderableLightSourceNode(std::shared_ptr< const spvs::LightSourceNode > lightSourceNode);
    virtual ~RenderableLightSourceNode();
    
    std::shared_ptr< const spvr::RenderableLightSource > getRenderableLightSource() const {return renderableLightSource_;}

private:
  std::shared_ptr< const spvs::LightSourceNode > lightSourceNode_;
  
  std::shared_ptr< const RenderableLightSource > renderableLightSource_;
              
};
}
#endif /* defined(SapanaViewerLibrary_RenderableLightSourceNode_H_ */
