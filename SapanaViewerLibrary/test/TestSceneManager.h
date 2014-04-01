////
////  TestSceneNodeManager.h
////  SapanaViewerLibrary
////
////  Created by Jan Meier on 13.01.14.
////  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
////
//
//#ifndef SapanaViewerLibrary_TestSceneManager_H_
//#define SapanaViewerLibrary_TestSceneManager_H_
//
//// Base class includes
//#include "SceneManager.h"
//
//// External includes
//
//// Project includes
//
//
//namespace spvt{
//    class TestSceneManager : public spv::SceneManager
//  {
//    public:
//        
//      explicit TestSceneManager(std::shared_ptr< spvs::SceneGraph > scene);
//      
//        virtual ~TestSceneManager();
//        
//        /**
//         * @ Implementation
//         */
//        virtual void setActiveSceneNode(std::shared_ptr< spvs::SceneNode > pointer);
//        
//      /**
//       * @ Implementation
//       */
//        virtual const std::shared_ptr< spv::SceneNodeModifier > getActiveSceneNodeModifier();
//        
//      /**
//       * @ Implementation
//       */
//        virtual void setActiveCamera( std::shared_ptr< spvs::CameraNode > );
//        
//      /**
//       * @ Implementation
//       */
//        virtual const std::shared_ptr< spv::SceneNodeModifier > getActiveCameraNodeModifier();
//        
//    private:
//      
//      std::shared_ptr< const spvs::SceneNode > testActiveSceneNode_;
//      std::shared_ptr< const spvs::SceneNode > testActiveCameraNode_;
//      std::shared_ptr< spv::SceneNodeModifier > testActiveCameraNodeModifier_;
//        
//    };
//}
//#endif /* defined(SapanaViewerLibrary_TestSceneManager_H_ */
