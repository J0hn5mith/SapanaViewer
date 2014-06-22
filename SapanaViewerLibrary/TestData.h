//
//  TestData.h
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 16.04.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#ifndef SapanaViewerLibrary_TestData_H_
#define SapanaViewerLibrary_TestData_H_

// Base class includes

// External includes

// Project includes
#include "SceneGraphController.h"
#include "ModelData.h"
namespace spvu{
namespace TestData
{
  std::shared_ptr< spv::SceneGraphController > getTestSceneController();
    
     std::shared_ptr< spvs::ModelData > getTestModelData();
}
}
#endif /* defined(SapanaViewerLibrary_TestData_H_ */
