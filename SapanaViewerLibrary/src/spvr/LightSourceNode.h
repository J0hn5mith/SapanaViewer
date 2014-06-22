//
//  LightSourceNode.h
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 04.04.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#ifndef SapanaViewerLibrary_LightSourceNode_H_
#define SapanaViewerLibrary_LightSourceNode_H_

// Base class includes
#include "LeafNode.h"

// External includes

// Project includes
#include "LightSource.h"

namespace spvs{
class LightSourceNode : public LeafNode
{    
public:    
      
    explicit LightSourceNode(std::shared_ptr<const spvs::LightSource> lightSource);
    virtual ~LightSourceNode();    
    
#pragma mark - Getter and Setter
    std::shared_ptr<const LightSource> getLightSource() const {return lightSource_;}
    
    void setLightSource(std::shared_ptr<const LightSource> lightSource ){lightSource_ = lightSource;}
                        
private:
                        
  std::shared_ptr<const LightSource> lightSource_;
              
};
}
#endif /* defined(SapanaViewerLibrary_LightSourceNode_H_ */
