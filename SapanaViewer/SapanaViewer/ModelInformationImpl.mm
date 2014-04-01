//
//  ModelInformationImpl.m
//  SapanaViewer
//
//  Created by Jan Meier on 26.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#import "ModelInformationImpl.h"

@implementation ModelInformationImpl

-(id) initWithModelInformation:(spvg::ModelInformation *) modelInformation
{
    self = [super init];
    if (self)
    {
        _modelInformation = modelInformation;
    }
    return self;
}

@end
