//
//  SceneNodeModifierWrapper.m
//  SapanaViewer
//
//  Created by Jan Meier on 10.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Class Definition
#import "SceneNodeModifierWrapper.h"

// Project Includes
#include "SceneNodeControllerImpl.h"
#include "SapanaViewerWrapper.h"
#import "ListWrapperImpl.h"
#import "WrapperUtils.h"
#include "MatrixForGUI.h"
#include "ModelInformationImpl.h"

// External Includes

@implementation SceneNodeModifierWrapper{
    SceneNodeControllerImpl * impl;
    SapanaViewerWrapper* _sapanaViewer;
}

-(id) initWithModifier: (SceneNodeControllerImpl *) snModifier sapanaViewerWrapper:(SapanaViewerWrapper*) sapanaViewer
{
    self = [super init];
    if (self)
    {
        impl = snModifier;
        _sapanaViewer = sapanaViewer;
    }
    return self;
}

#pragma mark - Actions Transformations
-(void) translateX:(float) distance
{
    impl.controller->translateX(distance);
}

-(void) translateY:(float) distance
{
    impl.controller->translateY(distance);
}

-(void) translateZ:(float) distance
{
    impl.controller->translateZ(distance);
}


-(void) rotateX:(float) angle
{
    
    impl.controller->rotateX(angle);
}

-(void) rotateY:(float) angle
{
    impl.controller->rotateY(angle);
}

-(void) rotateZ:(float) angle
{
    
    impl.controller->rotateZ(angle);
}

-(void) scaleX:(float) factor
{
    impl.controller->scaleX(factor);
}

-(void) scaleY:(float) factor
{
    impl.controller->scaleY(factor);
}

-(void) scaleZ:(float) factor
{
    impl.controller->scaleZ(factor);
}

#pragma mark - Actions Properties
-(bool) getWireFrameMode
{
    return impl.controller->getWireFrameMode();
}

-(void) setWireFrameMode:(bool) active
{
    impl.controller->setWireFrameMode(active);
}

-(bool) getShowCoordinateSystem
{
     return impl.controller->getShowCoordinateSystem();
}

-(void) setShowCoordinateSystem:(bool) active
{
    impl.controller->setShowCoordinateSystem(active);
}

-(bool) getShowNormals
{
     return impl.controller->getShowNormals();
}
-(void) setShowNormals:(bool) active
{
    impl.controller->setShowNormals(active);
}

#pragma mark - Transformation Stack
-(ListWrapper *) getTransformationStack
{
    ListWrapperImpl * transformationStackImpl = [[ListWrapperImpl alloc] init];
    transformationStackImpl.list = impl.controller->getTransformationStackList();
    
    ListWrapper * transformationStack = [[ListWrapper alloc] initWithList:transformationStackImpl];
    
    return transformationStack;
}

-(void) addTransformation
{
    impl.controller->addTransformation();
}

-(void) removeTransformation:(int) position
{
    impl.controller->removeTransformation(position);
}

-(void) shiftTransformation:(int) oldPosition newPosition:(int) newPosition
{
    impl.controller->shiftTransformation(oldPosition, newPosition);
}

-(void) setActiveTransformationIndex:(unsigned int) index
{
    impl.controller->setActiveTransformationIndex(index);
}

-(int) getActiveTransformationIndex
{
    return impl.controller->getActiveTransformationIndex();
    return 0;
}

-(TransMatrix *) getActiveTransformationMatrix
{
    return [WrapperUtils create_matrix:impl.controller->getActiveTransformationMatrix()];
}

-(NSMutableArray *) getTransformationMatrixList
{
    NSMutableArray * result = [[NSMutableArray alloc] init];
    auto matrixVector = impl.controller->getTransformationMatrixList();
    
    std::for_each(matrixVector.begin(), matrixVector.end(),
                  [&] (MatrixForGUI guiMatrix)
                  {
                      TransMatrix * matrix =[WrapperUtils create_matrix:guiMatrix.getMatrix()];
                      matrix.label = [[NSString alloc] initWithUTF8String:guiMatrix.getLabel().c_str()];
                      [result addObject:matrix];
                  }
                  );
    
    return result;
}


-(TransMatrix *) getWorldTransformationMatrix
{
    return [WrapperUtils create_matrix:impl.controller->getWorldTransformationMatrix()];
}

-(TransMatrix *) getNodeTransformationMatrix
{
    return [WrapperUtils create_matrix:impl.controller->getNodeTransformationMatrix()];
}


-(ListWrapper *) getAncesterList
{
    ListWrapperImpl * ancestorListImpl = [[ListWrapperImpl alloc] init];
    ancestorListImpl.list = impl.controller->getAncestorList();
    
    ListWrapper * transformationStack = [[ListWrapper alloc] initWithList:ancestorListImpl];
    
    return transformationStack;
}

-(NSMutableArray *) getAncesterMatrices
{
    NSMutableArray * result = [[NSMutableArray alloc] init];
    auto matrixVector = impl.controller->getAncesterMatrices();
    
    std::for_each(matrixVector.begin(), matrixVector.end(),
                  [&] (MatrixForGUI guiMatrix)
                  {
                      TransMatrix * matrix =[WrapperUtils create_matrix:guiMatrix.getMatrix()];
                      matrix.label =  [_sapanaViewer getSceneNodeName:guiMatrix.getReferenceID()];
                      [result addObject:matrix];
                  }
                  );
    return result;
    }

-(ModelInformationWrapper *) getModelNodeInformation
{
    ModelInformationImpl * modelInformation = [ModelInformationImpl alloc];
    modelInformation.modelInformation = impl.controller->getModelNodeInformation();
    
    return [[ModelInformationWrapper alloc] initWithModelInformation:modelInformation];
}
@end

