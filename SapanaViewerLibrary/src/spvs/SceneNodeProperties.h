//
//  SceneNodeProperties.h
//  SapanaViewerLibrary
//
//  Created by Jan Meier on 12.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#ifndef SapanaViewerLibrary_SceneNodeProperties_H_
#define SapanaViewerLibrary_SceneNodeProperties_H_

// Base class includes

// External includes

// Project includes

namespace spvs{
class SceneNodeProperties
{    
public:
      
    explicit SceneNodeProperties();    
    virtual ~SceneNodeProperties();
    
    
    void setWireFrameMode(bool state) {this->wireFrameMode_ = state;}
    bool getWireFrameMode() const { return this->wireFrameMode_;}
    
    void setShowNormals(bool state) {this->showNormals_ = state;}
    bool getShowNormals() const { return this->showNormals_;}
    
    void setShowCoordinateSystem(bool state) {this->showCoordinateSystem_ = state;}
    bool getShowCoordinateSystem() const { return this->showCoordinateSystem_;}
    
private:
    
    bool wireFrameMode_;
    
    bool showNormals_;
    
    bool showCoordinateSystem_;
};
}
#endif /* defined(SapanaViewerLibrary_SceneNodeProperties_H_ */
