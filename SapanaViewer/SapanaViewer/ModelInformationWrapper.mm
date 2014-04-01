//
//  ModelInformationWrapper.m
//  SapanaViewer
//
//  Created by Jan Meier on 26.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Class Definition and Implementation
#import "ModelInformationWrapper.h"
#import "ModelInformationImpl.h"
//
@implementation ModelInformationWrapper
{
    ModelInformationImpl * impl;
}

-(id) initWithModelInformation: (ModelInformationImpl *) modelInformation
{
    self = [super init];
    if (self)
    {
        impl = modelInformation;
    }
    return self;
}

-(NSString *) getNumVertices
{
    return [[NSString alloc] initWithUTF8String:impl.modelInformation->getNumVertices().c_str()];
}

-(NSString *) getNumIndices
{
    return [[NSString alloc] initWithUTF8String:impl.modelInformation->getNumIndices().c_str()];
}

-(NSString *) getNumFaces
{
    return [[NSString alloc] initWithUTF8String:impl.modelInformation->getNumFaces().c_str()];
}

-(NSString *) getSizeInBytes
{
    return [[NSString alloc] initWithUTF8String:impl.modelInformation->getSizeInBytes().c_str()];
}


@end
