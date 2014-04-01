//
//  SceneNodeController.h
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 27.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#ifndef SapanaViewerLibrary_SceneNodeController_H_
#define SapanaViewerLibrary_SceneNodeController_H_


// Base Class and Interface Includes
#include "IController.h"

// Project includes
#include "SceneNodeModifier.h"


// External includes
#include <memory>
#include "ListController.h"
#include "MatrixForGUI.h"
#include "ModelInformation.h"


// Forward Declarations
namespace spvs
{
    class SceneNode;
    class SceneNodeModifier;
}

namespace spv
{
    class SceneGraphController;
}


namespace spv
{
namespace detail
    {
class ISceneNodeController
{
public:
    
    virtual void update() const = 0;
    // Transformation
    virtual void rotateX(float angle) = 0;
    virtual void rotateY(float angle) = 0;
    virtual void rotateZ(float angle) = 0;
    
    virtual void translateX(float deltaX) = 0;
    virtual void translateY(float deltaY) = 0;
    virtual void translateZ(float deltaZ) = 0;
    
    virtual void scaleX(float factor) = 0;
    virtual void scaleY(float factor) = 0;
    virtual void scaleZ(float factor) = 0;
    
    // Properties
    virtual bool getWireFrameMode() = 0;
    virtual void setWireFrameMode(bool active) = 0;
    
    virtual bool getShowCoordinateSystem() = 0;
    virtual void setShowCoordinateSystem(bool active) = 0;
    
    virtual bool getShowNormals() = 0;
    virtual void setShowNormals(bool active) = 0;
    
    // Transformation Stack
    virtual spv::ListController * getTransformationList() = 0;
    virtual void addTransformation() = 0;
    virtual void removeTransformation(int position) = 0;
    virtual void shiftTransformation(int oldPosition, int newPosition) = 0;
    virtual void setActiveTransformationIndex(unsigned int index) = 0;
    virtual int getActiveTransformationIndex() = 0;
    virtual std::vector< std::vector<float>>  getActiveTransformationMatrix() = 0;
    virtual std::vector< std::vector< std::vector< float > > >  getTransformationMatrixList() = 0;
    virtual std::vector< std::vector< float > >  getWorldTransformationMatrix() = 0;
    virtual std::vector< std::vector< float > > getNodeTransformationMatrix() = 0;
    
    // Various methodes for getting information
    virtual spv::ListController * getAncestorList() =0;
    virtual std::vector< MatrixForGUI > getAncesterMatrices() = 0;
    virtual spvg::ModelInformation * getModelNodeInformation() = 0;
    
};
}

/**
 * Provides a interface for the modification of scene nodes.
 */
class SceneNodeController
{
public:
    
    // TODO: Remove. Wasn't remove imedatly because of unknown consequences
    /**
     * Creates a new SceneNodeController that has currently no scene node
     * that is processed.
     */
    //    explicit SceneNodeController();
    
    /**
     * Creates a new SceneNodeController that operates on sceneNode.
     * @param sceneNode The scene node that is modified.
     */
    explicit SceneNodeController(std::shared_ptr< spvs::SceneNodeModifier > sceneNodeModifier);//, std::shared_ptr< spv::SceneGraphController > sceneGraphController);
    virtual ~SceneNodeController();
    
    /**
     * Updates the scene node modifier. The ancestor list is
     * updated.
     */
    void update() const {impl_->update();}
    
#pragma mark - Transformation Methodes
    /**
     * Rotates the scene node along the x-axis.
     * @param angle Angle of rotation in degrees.
     */
    void rotateX(float angle){impl_->rotateX(angle);}
    
    /**
     * Rotates the scene node along the y-axis.
     * @param angle Angle of rotation in degrees.
     */
    void rotateY(float angle){impl_->rotateY(angle);}
    
    /**
     * Rotates the scene node along the z-axis.
     * @param angle Angle of rotation in degrees.
     */
    void rotateZ(float angle){impl_->rotateZ(angle);}
    
    /**
     * Translates the scene node along the x-axis
     * @param distance Distance of transition.
     */
    void translateX(float distance){impl_->translateX(distance);}
    
    /**
     * Translates the scene node along the y-axis
     * @param distance Distance of transition.
     */
    void translateY(float distance){impl_->translateY(distance);}
    
    /**
     * Translates the scene node along the z-axis
     * @param distance Distance of transition.
     */
    void translateZ(float distance){impl_->translateZ(distance);}
    
    /**
     * Scales the node along the x axis.
     */
    void scaleX(float factor){impl_->scaleX(factor);}
    
    /**
     * Scales the node along the y axis.
     */
    void scaleY(float factor){impl_->scaleY(factor);}
    
    /**
     * Scales the node along the z axis.
     */
    void scaleZ(float factor){impl_->scaleZ(factor);}
    
#pragma mark - Properties Methodes
    /**
     * Returns true if the nodes wire frame mode is true.
     */
    bool getWireFrameMode() {return impl_->getWireFrameMode();}
    
    /**
     * Activates the wire frame mode of the scene node.
     */
    void setWireFrameMode(bool active){impl_->setWireFrameMode(active);}
    
    /**
     * Returns true if the nodes show coordinate property is set.
     */
    virtual bool getShowCoordinateSystem(){return impl_->getShowCoordinateSystem();}
    
    /**
     * Activates the coordinate system of the model
     */
    void setShowCoordinateSystem(bool active){impl_->setShowCoordinateSystem(active);}
    
    /**
     * Returns true if the show normals flag is set.
     */
    bool getShowNormals(){return impl_->getShowNormals();}
    
    /**
     * Sets the show normals flag.
     */
    void setShowNormals(bool active){impl_->setShowNormals(active);}
    
#pragma mark - Transformatin List Manipulation
    /**
     * Returns a list containing the transformations of a node
     */
    spv::ListController * getTransformationStackList() {return impl_->getTransformationList();}
    
    /**
     * Adds a transformation matrix at the end of the transformation list.
     */
    void addTransformation() {impl_->addTransformation();}
    
    /**
     * Removes the transformation at the provided position from the node
     * transformation list.
     */
    void removeTransformation(int position) {impl_->removeTransformation(position);}
    
    /**
     * Changes the position of a transformation in the transformation list.
     */
    void shiftTransformation(int oldPosition, int newPosition) {impl_->shiftTransformation( oldPosition, newPosition);}
    
    /**
     * Set the index of the transformation matrix the transformations are applied to.
     */
    void setActiveTransformationIndex(unsigned int index) {impl_->setActiveTransformationIndex(index);}
    
    /**
     * Returns the index of the selected transformation. If there is no matrix selected -1 is re
     */
    int getActiveTransformationIndex() { return impl_->getActiveTransformationIndex();}
    
    /**
     * Returns a 4x4 matrix representing the active tm of the node.
     */
    std::vector< std::vector<float> >  getActiveTransformationMatrix() {return impl_->getActiveTransformationMatrix();}
    
    /**
     * Returns a vector with all transformations of the node
     */
    std::vector< std::vector< std::vector<float> > >  getTransformationMatrixList() {return impl_->getTransformationMatrixList();}
    
    /**
     * Returns the matrix, that defines the nodes transformation regarding the world
     */
    std::vector< std::vector<float> >  getWorldTransformationMatrix() {return impl_->getWorldTransformationMatrix();}
    
    
    /**
     * Returns the matrix, that defines the nodes transformation regarding the parent
     */
    std::vector< std::vector<float> > getNodeTransformationMatrix() {return impl_->getNodeTransformationMatrix();}
    
#pragma mark - Some Information fetcher methodes
    /*
     * Returns a list with the nodes ancestors
     */
    spv::ListController * getAncestorList() {return impl_->getAncestorList();}
    
    /*
     * Returns a list with the nodes ancestors
     */
    std::vector< MatrixForGUI >getAncesterMatrices() {return impl_->getAncesterMatrices();}
    
    /**
     * If the managed node is a model node, some
     * information is returned
     */
    spvg::ModelInformation * getModelNodeInformation() {return impl_->getModelNodeInformation();}
    
    
    
private:
    detail::ISceneNodeController * impl_;
    
};
}
#endif /* defined(SapanaViewerLibrary_SceneNodeController_H_ */
