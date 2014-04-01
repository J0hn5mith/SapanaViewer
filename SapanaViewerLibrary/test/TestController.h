//
//  TestController.h
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 20.12.13.
//  Copyright (c) 2013 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#ifndef TestController_H_
#define TestController_H_

// External includes
#include <vector>

// Internal includes
#include "IController.h"
#include "TreeViewNode.h"

namespace spvt {

namespace detail
{
    class TestController;
}

class TestController : public spv::IController
{
public:
    TestController();
    virtual ~TestController();

    /**
    * Updates the model and the renderer.
    */
    virtual void update(int timeDelta);

    /**
    * The renderer renders the scene.
    */
    virtual void draw();

    /**
    * Set the rotation along the y axis for the test model.
    * @ deprecated
    */
    virtual void setYRotation(float yRotation);
    
    /**
     * Selects a model node from the scene graph and makes
     * it the currently modifyied node
     */
    virtual void selectSceneNode(unsigned int nodeID);
    
    /**
    * Rotates the test model along x-axis.
    * @param angle in degrees
    */
    virtual void rotateX(float xRotation);

    /**
    * Rotates the test model along y-axis.
    * @param angle in degrees
    */
    virtual void rotateY(float yRotation);

    /**
    * Rotates the test model along z-axis.
    * @param angle in degrees
    */
    virtual void rotateZ(float zRotation);
    
    /**
     * Shifts the test model along the x-axis
     * @param delta in x-coordinates
     */
    void shiftX(float deltaX);
    
    /**
     * Shifts the test model along the y-axis
     * @param delta in y-coordinates
     */
    void shiftY(float deltaY);
    
    /**
    * Shifts the test model along the z-axis
    * @param delta in z-coordinates
    */
    virtual void shiftZ(float deltaZ);
    
    /**
     * Rotates the active camere along the x-axis
     * @param angle in degrees
     */
    virtual void rotateCameraX(float xRotaton);
    
    /**
     * Rotates the active camere along the x-axis
     * @param angle in degrees
     */
    virtual void rotateCameraY(float yRotaton);
    
    /**
     * Rotates the active camere along the x-axis
     * @param angle in degrees
     */
    virtual void rotateCameraZ(float zRotaton);
    
    /**
     * Shifts the camera along the z-axis
     * @param delta in x-coordinates
     */
    virtual void shiftCameraX(float deltaX);
    
    /**
     * Shifts the camera along the z-axis
     * @param delta in z-coordinates
     */
    virtual void shiftCameraY(float deltaY);
    
    /**
     * Shifts the camera along the z-axis
     * @param delta in z-coordinates
     */
    virtual void shiftCameraZ(float deltaZ);
    
    /**
     * Returns a tree View of the currently active scene
     */
    virtual std::vector< spvg::TreeViewNode > getTreeView();
    
    /**
     * Switches the toggle state of an item.
     */
    virtual void switchItem(int itemPosition);
    
    /**
     * Expands a node in the tree viwe
     */
    virtual void expandItem(int itemPosition);
    
    /**
     * Colapses a node in the tree view
     */
    virtual void collapseItem(int itemPosition);
    
    /**
     * Sets the viewport where the renderer renders the scene to
     */
    virtual void setViewport(int x, int y, int width, int height);
    
    /**
     * Delets a node from the active scene
     */
    virtual void deleteNode(unsigned int nodeID);
    
    /**
     * Adds a nod to the active scene.
     */
    virtual void addNode();

private:
    detail::TestController * impl_;
};
}
#endif /* defined(TestController_H_) */
