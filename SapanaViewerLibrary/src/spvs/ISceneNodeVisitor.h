//
//  SceneNodeVisitor.h
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 07.04.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#ifndef SapanaViewerLibrary_ISceneNodeVisitor_h
#define SapanaViewerLibrary_ISceneNodeVisitor_h

// Base Class and Interface Includes
#include "IVisitor.h"

// Project Incluces

// External Includes
#include <memory>
namespace spvs
{
    class SceneNode;
}

namespace spvs
{

class ISceneNodeVisitor :public spvu::IVisitor
{
public:
    virtual void visit(std::shared_ptr< spvs::SceneNode > sceneNode) = 0;
};
}


#endif
