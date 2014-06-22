//
//  SceneNodeController.cpp
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 27.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Class definition include
#include "SceneNodeController.h"

// External includes
#include <math.h>
#include <memory>
#include <list>

// Project includes
#include "SceneGraphController.h"
#include "Util.h"
#include "SceneNode.h"
#include "NodeTransformationsList.h"
#include "NodeAncestorList.h"
#include "ModelNode.h"
#include "ModelData.h"

namespace spv
{
    namespace detail
    {
        class SceneNodeController : public ISceneNodeController
        {
            
        public:
            
            SceneNodeController(std::shared_ptr< spvs::SceneNodeModifier > sceneNodeModifier)
            : sceneNodeModifier_(sceneNodeModifier)
            , sceneNodeReference_(sceneNodeModifier->getSceneNode())
            , transformationList_(nullptr)
            , activeTransformationIndex_(0)
            , ancestorList_(new spv::ListController( new spvg::ListSpv(new spvg::NodeAncestorList(sceneNodeReference_))))
            {
                
            }
            
            // TODO: Remove
            //    void setSceneNode(std::shared_ptr< spvs::SceneNode > sceneNode) { sceneNode_= sceneNode;}
            
            ~SceneNodeController()
            {
                // TODO: Implement
            }
            
#pragma mark update stuff
            virtual void update() const
            {
                ancestorList_->update();
            }
            
            virtual std::vector< std::shared_ptr< const spv::IController > > getChildController() const
            {
                auto childControllers = std::vector< std::shared_ptr< const spv::IController > >();
                
                
               // childControllers.push_back(selectedNodeController_);
                return childControllers;
            }
            
            
#pragma mark - Transformations
            void rotateX(float angle)
            {
                sceneNodeModifier_->rotateX(angle);
            }
            
            void rotateY(float angle)
            {
                 sceneNodeModifier_->rotateY(angle);
            }
            
            void rotateZ(float angle)
            {
                 sceneNodeModifier_->rotateZ(angle);
            }
            
            void translateX(float distance)
            {
                sceneNodeModifier_->translateX(distance);
            }
            
            void translateY(float distance)
            {
                sceneNodeModifier_->translateY(distance);
            }
            
            void translateZ(float distance)
            {
                sceneNodeModifier_->translateZ(distance);
            }
            
            void scaleX(float factor)
            {
                sceneNodeModifier_->scaleX(factor);
            }
            
            void scaleY(float factor)
            {
                sceneNodeModifier_->scaleY(factor);
            }
            
            void scaleZ(float factor)
            {
                sceneNodeModifier_->scaleZ(factor);
            }
            
#pragma mark - Properties
            bool getWireFrameMode()
            {
                return sceneNodeReference_->getProperties().getWireFrameMode();
            }
            
            void setWireFrameMode(bool active)
            {
                sceneNodeModifier_->setWireFrameMode(active);
            }
            
            virtual bool getShowCoordinateSystem()
            {
                return sceneNodeReference_->getProperties().getShowCoordinateSystem();
            }
            
            void setShowCoordinateSystem(bool active)
            {
                sceneNodeModifier_->setShowCoordinateSystem(active);
            }
            
            virtual bool getShowNormals()
            {
                return sceneNodeReference_->getProperties().getShowNormals();
            }
            
            void setShowNormals(bool active)
            {
                 sceneNodeModifier_->setShowNormals(active);
            }
            
#pragma mark - Transformatin List Manipulation
            spv::ListController * getTransformationList()
            {
                transformationList_ = std::make_shared< spv::ListController>( new spvg::ListSpv(new spvg::NodeTransformationsList(sceneNodeReference_)));
                
                // WARNING: Ugly code TODO: remove
                return transformationList_.get();
            }
            
            void addTransformation()
            {
                sceneNodeModifier_->addTransformation();
            }
            
            void removeTransformation(int position)
            {
                sceneNodeModifier_->removeTransformation(position);
            }
            
            void shiftTransformation(int oldPosition, int newPosition)
            {
                sceneNodeModifier_->shiftTransformation(oldPosition, newPosition);
            }
            
            void setActiveTransformationIndex(unsigned int index) {
                if (index >= sceneNodeReference_->getTransformationList().size())
                {
                    std::cout << "SceneNodeController: Faild to set transformation index. Index is set to 0" << std::endl;
                    index = 0;
                }
                
                sceneNodeModifier_->setActiveTransformationIndex(index);
                activeTransformationIndex_ = (spvu::Index) index;
            }
            
            int getActiveTransformationIndex() {
                return activeTransformationIndex_;
            }
            
            std::vector< std::vector<float>>  getActiveTransformationMatrix()
            {
                
                std::list< spvu::TransMatrix > transformationList  = sceneNodeReference_->getTransformationList();
                
                auto it = transformationList.begin();
                std::advance(it, activeTransformationIndex_);
                
                spvu::TransMatrix activeMatrix = *it;
                
                return spvu::matrix_to_vector(activeMatrix);
            }
            
            std::vector<  MatrixForGUI >  getTransformationMatrixList()
            {
                
                
                auto transMatrices =  sceneNodeReference_->getTransformationList();
                
                std::vector< MatrixForGUI > result = std::vector<  MatrixForGUI > ();
                int i = 1;
                std::for_each (transMatrices.begin(), transMatrices.end(),
                               [&]( spvu::TransMatrix matrix)
                               {
                                   auto vectorMatrix  = spvu::matrix_to_vector(matrix);
                                   std::string label = "Transformation " + std::to_string(i++);
                                   result.push_back(MatrixForGUI(label, 0, vectorMatrix ));
                                   
                               }
                               );
                
                return result;
            }
            
            std::vector< std::vector<float> >  getWorldTransformationMatrix()
            {
                return spvu::matrix_to_vector(sceneNodeReference_->getWorldTransMatrix());
            }
            
            
            std::vector< std::vector<float> > getNodeTransformationMatrix()
            {
                auto matrix = sceneNodeReference_->getNodeTransMatrix();
                return spvu::matrix_to_vector(matrix);
            }
            
            spv::ListController * getAncestorList()
            {
                
                return ancestorList_;
            }
            
            
            std::vector< MatrixForGUI  > getAncesterMatrices()
            {
                auto ancestors =  sceneNodeReference_->getAncestorNodes();
                
                std::vector< MatrixForGUI > matrices = std::vector<  MatrixForGUI > ();
                
                std::for_each (ancestors.begin(), ancestors.end(),
                               [&]( std::shared_ptr < spvs::SceneNode > node)
                               {
                                   
                                   auto vectorMatrix  = spvu::matrix_to_vector(node->getTransMatrix());
                                   
                                   matrices.push_back(MatrixForGUI("Name", node->getID(), vectorMatrix ));
                                   
                                   //TODO: Using the name would be better, but because scenenode modifier do not know the scene manager, the name is not available, let the scene node midifier know it scene manager and change that. To do so, the scene nod manager can no longer be created inside the scene graph. (What is cleaner anyway). Alternative, a scene node manager class could be created that uses a scene node modifier what anyway would be better.
                               }
                               );
                
                return matrices;
            }
            
            spvg::ModelInformation * getModelNodeInformation()
            {
                if (sceneNodeReference_->getSceneNodeType() == spvs::SceneNode::MODEL_NODE)
                {
                    auto data =  std::static_pointer_cast< const spvs::ModelNode >(sceneNodeReference_)->getModelData();
                    return new spvg::ModelInformation(data->getNumVertices(),data->getNumIndices(),(data->getNumIndices()/3),data->getSizeOfVertices());
                }
                else
                {
                    return new spvg::ModelInformation(-1, -1, -1, -1);
                }
                
            }
            
        private:
            /**
             * The currently processed scene node.
             */
            std::shared_ptr< spvs::SceneNodeModifier > sceneNodeModifier_;
            
            std::shared_ptr< const spvs::SceneNode > sceneNodeReference_;
            
            /**
             * Reference to the List abstraction of the nodes transformation stack.
             */
            std::shared_ptr< spv::ListController > transformationList_;
            
            /**
             * Index of the selected node
             */
            spvu::Index activeTransformationIndex_;
            
            /**
             * List with the nodes ancestors
             */
            spv::ListController * ancestorList_;
            
        };
    }
    
    
    SceneNodeController::SceneNodeController(std::shared_ptr< spvs::SceneNodeModifier > sceneNodeModifier)//, std::shared_ptr< spv::SceneGraphController > sceneGraphController)
    {
        impl_ = new detail::SceneNodeController(sceneNodeModifier);
    }
    
    SceneNodeController::~SceneNodeController()
    {
        //delete impl_;
    }
    
}
