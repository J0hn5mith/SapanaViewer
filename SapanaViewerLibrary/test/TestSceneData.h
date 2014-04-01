/*
 * TestSceneData.h
 *
 *  Created on: Dec 12, 2013
 *      Author: janmeier
 */

#ifndef TESTSCENEDATA_H_
#define TESTSCENEDATA_H_

// Base class includes


// External includes
#include <memory>

// Project internal includes
#include "TestModelNode.h"
#include "SceneGraph.h"


namespace spvt{
/**
 * Test scene data to test the scene renderer.
 * SHould be removed, was only to lazy implementing a test scene graph
 */
class TestSceneData
{
public:
    explicit TestSceneData();

    ~TestSceneData();
    std::shared_ptr< spvs::SceneGraph > getSceneGraph() {return sceneGraph_;}
    virtual std::shared_ptr< const spvs::CameraNode > getActiveCamerNode() const;
    std::shared_ptr< spvs::SceneGraph > sceneGraph_;
    
private:
  
};


#endif /* TESTSCENEDATA_H_ */
}