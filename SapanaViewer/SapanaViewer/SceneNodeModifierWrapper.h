//
//  SceneNodeModifierWrapper.h
//  SapanaViewer
//
//  Created by Jan Meier on 10.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Project Includes
#import "ListWrapper.h"
#import "TransMatrix.h"
#import "ModelInformationWrapper.h"

// External Includes
#import <Foundation/Foundation.h>

// Forward Declarations
@class SceneNodeControllerImpl;
@class SapanaViewerWrapper;

@interface SceneNodeModifierWrapper : NSObject
-(id) initWithModifier:(SceneNodeControllerImpl * ) snModifier sapanaViewerWrapper:(SapanaViewerWrapper*) sapanaViewer;



#pragma mark - Actions Transformations
-(void) translateX:(float) distance;
-(void) translateY:(float) distance;
-(void) translateZ:(float) distance;

-(void) rotateX:(float) angle;
-(void) rotateY:(float) angle;
-(void) rotateZ:(float) angle;

-(void) scaleX:(float) factor;
-(void) scaleY:(float) factor;
-(void) scaleZ:(float) factor;

#pragma mark - Actions Properties
-(bool) getWireFrameMode;
-(void) setWireFrameMode:(bool) active;
-(bool) getShowCoordinateSystem;
-(void) setShowCoordinateSystem:(bool) active;
-(bool) getShowNormals;
-(void) setShowNormals:(bool) active;

#pragma mark - Transformation Stack
-(ListWrapper *) getTransformationStack;
-(void) addTransformation;
-(void) removeTransformation:(int) position;
-(void) shiftTransformation:(int) oldPosition newPosition:(int) newPosition;
-(void) setActiveTransformationIndex:(unsigned int) index;
-(int) getActiveTransformationIndex;
-(TransMatrix *) getActiveTransformationMatrix;
-(NSMutableArray *) getTransformationMatrixList;
-(TransMatrix *) getWorldTransformationMatrix;
-(TransMatrix *) getNodeTransformationMatrix;

#pragma mark - Some Information fetcher methodes

-(ListWrapper * ) getAncesterList;
-(NSMutableArray *) getAncesterMatrices;
-(ModelInformationWrapper *) getModelNodeInformation;

@end
