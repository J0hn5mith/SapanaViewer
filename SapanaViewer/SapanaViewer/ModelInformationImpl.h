//
//  ModelInformationImpl.h
//  SapanaViewer
//
//  Created by Jan Meier on 26.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ModelInformation.h"

@interface ModelInformationImpl : NSObject

@property spvg::ModelInformation * modelInformation;

-(id) initWithModelInformation:(spvg::ModelInformation *) modelInformation;
@end
