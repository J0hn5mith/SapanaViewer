//
//  SapanaViewer.h
//  SapanaViewer
//
//  Created by Jan Meier on 06.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Project Includes
#import "SceneNodeModifierWrapper.h"
#import "ListWrapper.h"
#import "HierarchicalListControllerWrapper.h"

// External Includes
#import <Foundation/Foundation.h>

@interface SapanaViewerWrapper : NSObject


// TODO: Move is here because tis is the only singleton class
#pragma mark Singleton Methods

#pragma mark - Callback Methodes
-(void)initOpenGL;
-(void) update;

-(void) drawScene;

#pragma Acess Methodes
-(void) selectModelNode:(unsigned long) nodeId;
-(SceneNodeModifierWrapper *) getSelectedNodeModifier;

-(SceneNodeModifierWrapper * ) getObserverCameraModifier;

-(ListWrapper *) getFlatModelList;

// TODO: Change to hierarchical list
-(HierarchicalListControllerWrapper *) getHierarchicalModelList;

-(ListWrapper *) getFlatCameraList;

-(void) moveNode:(unsigned long)childID newParent:(unsigned long)parentID;

-(NSString *) getSceneNodeName:(unsigned long) nodeID;

@end
