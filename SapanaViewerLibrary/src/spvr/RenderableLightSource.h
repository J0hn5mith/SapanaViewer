//
//  RenderableLightSource.h
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 04.04.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#ifndef SapanaViewerLibrary_RenderableLightSource_H_
#define SapanaViewerLibrary_RenderableLightSource_H_

// Base class includes
#include "IRenderableData.h"
// External includes

// Project includes
#include "LightSource.h"

namespace spvr{
class RenderableLightSource : public IRenderableData
{    
public:    
      
    explicit RenderableLightSource(std::shared_ptr< const  spvs::LightSource > lightSource);
    virtual ~RenderableLightSource();

#pragma mark - Getter
    spvu::Color getAmbient() const {return lightSource_->getAmbient();}
    spvu::Color getDifuse() const {return lightSource_->getDifuse();}
    spvu::Color getSpecular() const {return lightSource_->getSpecular();}
    float getCutOff() const {return lightSource_->getCutOff();}
    
#pragma mark - IRenderableData Impl
    virtual void update() const;

private:
    std::shared_ptr< const spvs::LightSource > lightSource_;
};
}
#endif /* defined(SapanaViewerLibrary_RenderableLightSource_H_ */
