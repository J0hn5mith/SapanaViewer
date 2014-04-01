//
//  IRenderable.h
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 29.01.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#ifndef SapanaViewerLibrary_IRenderable_H_
#define SapanaViewerLibrary_IRenderable_H_

// Base class includes

// External includes

// Project includes

namespace spvr{

/**
 * Interface for renderable data. Each renderable data entity has 
 * associated data entity.
 */
class IRenderable :
{    
public:
    
    virtual void update() =0;

private:    
              
};
}
#endif /* defined(SapanaViewerLibrary_IRenderable_H_ */
