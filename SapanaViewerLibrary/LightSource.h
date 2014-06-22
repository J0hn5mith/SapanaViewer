//
//  LightSource.h
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 04.04.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#ifndef SapanaViewerLibrary_LightSource_H_
#define SapanaViewerLibrary_LightSource_H_

// Base and Interface class includes
#include "IDataObject.h"

// External includes

// Project includes
#include "Util.h"

namespace spvs{
class LightSource : IDataObject
{    
public:    
      
    explicit LightSource();    
    virtual ~LightSource();
    
    spvu::Color getAmbient() const {return ambient_;}
    spvu::Color getDifuse() const {return difuse_;}
    spvu::Color getSpecular() const {return ambient_;}
    float getCutOff() const {return cutOff_;}

private:    
    spvu::Color ambient_;
    spvu::Color difuse_;
    spvu::Color specular_;
    float cutOff_;
};
}
#endif /* defined(SapanaViewerLibrary_LightSource_H_ */
