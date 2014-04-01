//
//  SceneNodeModifier.cpp
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 09.01.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Class definition include
#include "SceneNodeModifier.h"

// External includes
#include <math.h>
#include <memory>
#include <list>

// Project includes
#include "Util.h"
#include "SceneNode.h"
#include "NodeTransformationsList.h"
#include "NodeAncestorList.h"
#include "ModelNode.h"
#include "ModelData.h"

namespace spvs
{
namespace detail
{
class SceneNodeModifier : public ISceneNodeModifier
{
    
public:
    
    SceneNodeModifier(std::shared_ptr< spvs::SceneNode > sceneNode)
    : sceneNode_(sceneNode)
    , transformationList_(nullptr)
    , activeTransformationIndex_(0)
    , ancestorList_(new spvg::ListSpv(new spvg::NodeAncestorList(sceneNode)))
    {
        
    }
    
    // TODO: Remove
//    void setSceneNode(std::shared_ptr< spvs::SceneNode > sceneNode) { sceneNode_= sceneNode;}
    
    ~SceneNodeModifier()
    {
        // TODO: Implement
    }
    
#pragma mark update stuff
    virtual void update()
    {
        ancestorList_->update();
    }
    
    
#pragma mark - Transformations
    void rotateX(float angle)
    {
        spvu::TransMatrix tMatrix;
        vmml::identity(tMatrix);
        float xRotatoin = toRad(angle);
        tMatrix.rotate_x(xRotatoin);
        applyTransformation(tMatrix);
    }
    
    void rotateY(float angle)
    {
        spvu::TransMatrix tMatrix;
        vmml::identity(tMatrix);
        float yRotatoin = toRad(angle);
        tMatrix.rotate_y(yRotatoin);
        applyTransformation(tMatrix);
    }
    
    void rotateZ(float angle)
    {
        spvu::TransMatrix tMatrix;
        vmml::identity(tMatrix);
        float yRotatoin = toRad(angle);
        tMatrix.rotate_z(yRotatoin);
        applyTransformation(tMatrix);
    }
    
    void translateX(float distance)
    {
        spvu::TransMatrix tMatrix;
        vmml::identity(tMatrix);
        tMatrix[0][3] = distance;
        applyTransformation(tMatrix);
    }
    
    void translateY(float distance)
    {
        spvu::TransMatrix tMatrix;
        vmml::identity(tMatrix);
        tMatrix[1][3] = distance;
        applyTransformation(tMatrix);
    }
    
    void translateZ(float distance)
    {
        spvu::TransMatrix tMatrix;
        vmml::identity(tMatrix);
        tMatrix[2][3] = distance;
        applyTransformation(tMatrix);
    }
    
    void scaleX(float factor)
    {
        spvu::TransMatrix tMatrix;
        vmml::identity(tMatrix);
        tMatrix[0][0] = factor;
        applyTransformation(tMatrix);
    }
    
    void scaleY(float factor)
    {
        spvu::TransMatrix tMatrix;
        vmml::identity(tMatrix);
        tMatrix[1][1] = factor;
        applyTransformation(tMatrix);
    }
    
    void scaleZ(float factor)
    {
        spvu::TransMatrix tMatrix;
        vmml::identity(tMatrix);
        tMatrix[2][2] = factor;
        applyTransformation(tMatrix);
    }
    
#pragma mark - Properties
    bool getWireFrameMode()
    {
        return sceneNode_->getProperties().getWireFrameMode();
    }
    
    
    void setWireFrameMode(bool active)
    {
        spvs::SceneNodeProperties properties = sceneNode_->getProperties();
        properties.setWireFrameMode(active);
        sceneNode_->setProperties(properties);
    }
    
    virtual bool getShowCoordinateSystem()
    {
        return sceneNode_->getProperties().getShowCoordinateSystem();
    }
    
    void setShowCoordinateSystem(bool active)
    {
        spvs::SceneNodeProperties properties = sceneNode_->getProperties();
        properties.setShowCoordinateSystem(active);
        sceneNode_->setProperties(properties);
    }
    
    virtual bool getShowNormals()
    {
        return sceneNode_->getProperties().getShowNormals();
    }
    
    void setShowNormals(bool active)
    {
        spvs::SceneNodeProperties properties = sceneNode_->getProperties();
        properties.setShowNormals(active);
        sceneNode_->setProperties(properties);
    }
    
    #pragma mark - Transformatin List Manipulation
    spvg::ListSpv * getTransformationList()
    {
        transformationList_ = std::make_shared< spvg::ListSpv >( new spvg::NodeTransformationsList(sceneNode_));
        
        // WARNING: Ugly code TODO: remove
        return transformationList_.get();
    }
    
     void addTransformation()
    {
        sceneNode_->addTransformationMatrix();
    }
    
    void removeTransformation(int position)
    {
        sceneNode_->removeTransformationMatrix(position);
    }
    
    void shiftTransformation(int oldPosition, int newPosition)
    {
        sceneNode_->shiftTransformationMatrix(oldPosition, newPosition);
    }
    
    void setActiveTransformationIndex(unsigned int index) {
        if (index >= sceneNode_->getTransformationList().size())
        {
            std::cout << "SceneNodeModifier: Faild to set transformation index. Index is set to 0" << std::endl;
            index = 0;
        }
        
        activeTransformationIndex_ = (spvu::Index) index;
    }
    
    int getActiveTransformationIndex() {
        return activeTransformationIndex_;
    }
    
    std::vector< std::vector<float>>  getActiveTransformationMatrix()
    {
        
        std::list< spvu::TransMatrix > transformationList  = sceneNode_->getTransformationList();
        
        auto it = transformationList.begin();
        std::advance(it, activeTransformationIndex_);
        
        spvu::TransMatrix activeMatrix = *it;
        
        return spvu::matrix_to_vector(activeMatrix);
    }
    
    spvg::ListSpv * getAncestorList()
    {
        
        return ancestorList_;
    }

    std::vector< MatrixForGUI  > getAncesterMatrices()
    {
        auto ancestors =  sceneNode_->getAncestorNodes();
        
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
    
    
private:
    /**
     * The currently processed scene node.
     */
    std::shared_ptr< spvs::SceneNode > sceneNode_;
    
    /**
     * Reference to the List abstraction of the nodes transformation stack.
     */
    std::shared_ptr< spvg::ListSpv > transformationList_;
    
    /**
     * Index of the selected node
     */
    spvu::Index activeTransformationIndex_;
    
    /**
     * List with the nodes ancestors
     */
    spvg::ListSpv * ancestorList_;
    
    void applyTransformation(const spvu::TransMatrix tMatrix)
    {
        if (sceneNode_ != nullptr)
        {
           sceneNode_->transform(tMatrix, activeTransformationIndex_);
        }
    }
    
    /**
     * Transforms degree to radians.d
     * @param degree Angle in degrees
     * @return Angle in radians
     */
    float toRad(float degree)
    {
        float radians = degree * M_PI/ 180.0;
        return radians;
    }
};
}
    
std::shared_ptr< const spvs::SceneNode > SceneNodeModifier::getSceneNode() const
{
    return sceneNode_;
}
    
SceneNodeModifier::SceneNodeModifier(std::shared_ptr< spvs::SceneNode > sceneNode)
{
    sceneNode_ = sceneNode;
    
     //TODO: Remove, also remove the whole PIMPLE
    impl_ = new detail::SceneNodeModifier(sceneNode);
    
}

SceneNodeModifier::~SceneNodeModifier()
{
   //delete impl_;
}

}

