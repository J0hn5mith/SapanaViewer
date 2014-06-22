//
//  SapanaViewer.m
//  SapanaViewer
//
//  Created by Jan Meier on 06.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
// Singleton was coppied from http://www.galloway.me.uk/tutorials/singleton-classes/
//

// Class definition
#import "SapanaViewerWrapper.h"

// Project Includes
#include "SceneNodeControllerImpl.h"
#import "SapanaViewerImpl.h"
#include "ListWrapper.h"
#import "ListWrapperImpl.h"
#import "HierarchicalListControllerWrapper.h"
#import "HierarchicalListControllerWrapperImpl.h"

// External Includes


// Configuration
#include "Config.h"

@implementation SapanaViewerWrapper
{
    SapanaViewerImpl * impl;
    NSTimer * updateTimer;
}



#pragma mark Singleton Methods

//+ (id) getSharedManager
//{
//    static SapanaViewerWrapper *sharedMyManager = nil;
//    static dispatch_once_t onceToken;
//    dispatch_once(&onceToken, ^{
//        sharedMyManager = [[self alloc] init];
//    });
//    return sharedMyManager;
//}


- (id) init
{
    self = [super init];
    if (self)
    {
        impl = [SapanaViewerImpl alloc];
        impl.sapanaViewer=  new spv::SapanaViewer();
        // Set up updating
        updateTimer = [NSTimer scheduledTimerWithTimeInterval:SV_UPDATE_INTERVAL target:self selector:@selector(update) userInfo:nil repeats:YES];
        
        //self.topicContainerCollection = [[TopicContainerCollection alloc] init];
        
    }
    return self;
}

-(void)dealloc {
   // delete impl;
}

#pragma mark - Callback Methodes

-(void) initOpenGL
{
    impl.sapanaViewer->initOpenGL();
}

-(void) update
{
    impl.sapanaViewer->update();
}

-(void) drawScene
{
    impl.sapanaViewer->drawScene();
}

-(SceneNodeModifierWrapper * ) getObserverCameraModifier
{
    
    SceneNodeControllerImpl * snmImpl =  [SceneNodeControllerImpl alloc];
    snmImpl.controller = impl.sapanaViewer->getObserverCameraModifier();
    SceneNodeModifierWrapper * snModifier = [[SceneNodeModifierWrapper alloc] initWithModifier:snmImpl sapanaViewerWrapper:self];
    
    return snModifier;
}

-(void) selectModelNode:(unsigned long) nodeId
{
    impl.sapanaViewer->selectSceneNode(nodeId);
}

-(SceneNodeModifierWrapper *) getSelectedNodeModifier
{
    SceneNodeControllerImpl * snmImpl =  [SceneNodeControllerImpl alloc];
    
    snmImpl.controller = impl.sapanaViewer->getSelectedNodeModifier();
    
    SceneNodeModifierWrapper * snModifier = [[SceneNodeModifierWrapper alloc] initWithModifier:snmImpl sapanaViewerWrapper:self];
    
    return snModifier;
}

-(ListWrapper *) getFlatModelList
{
    ListWrapperImpl * listImpl = [[ListWrapperImpl alloc] init];
    listImpl.list = impl.sapanaViewer->getFlatModelList();
    ListWrapper * wrappedList = [[ListWrapper alloc] initWithList:listImpl];
    return wrappedList;
}

// TODO: Change
-(HierarchicalListControllerWrapper *) getHierarchicalModelList
{
    HierarchicalListControllerWrapperImpl * listImpl = [[HierarchicalListControllerWrapperImpl alloc] init];
    
    listImpl.listController = impl.sapanaViewer->getHierarchicalModelListController();
    
    HierarchicalListControllerWrapper * wrappedList = [[HierarchicalListControllerWrapper alloc] initWithList:listImpl];
    return wrappedList;
}

-(ListWrapper *) getFlatCameraList
{
    ListWrapperImpl * listImpl = [[ListWrapperImpl alloc] init];
    listImpl.list = impl.sapanaViewer->getFlatCameraList();
    ListWrapper * wrappedList = [[ListWrapper alloc] initWithList:listImpl];
    return wrappedList;
}

-(void) moveNode:(unsigned long)childID newParent:(unsigned long)parentID
{
    impl.sapanaViewer->moveNode(childID, parentID);
}

-(NSString *) getSceneNodeName:(unsigned long) nodeID
{
    std::string string = impl.sapanaViewer->getNameForNode(nodeID);
    
    NSString * name = [NSString stringWithUTF8String:string.c_str()];
    return name;
}

@end
