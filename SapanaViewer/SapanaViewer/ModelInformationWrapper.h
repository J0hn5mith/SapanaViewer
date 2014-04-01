//
//  ModelInformationWrapper.h
//  SapanaViewer
//
//  Created by Jan Meier on 26.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ModelInformationImpl;

@interface ModelInformationWrapper : NSObject

-(id) initWithModelInformation:(ModelInformationImpl *) modelInformation;

-(NSString *) getNumVertices;
-(NSString *) getNumIndices;
-(NSString *) getNumFaces;
-(NSString *) getSizeInBytes;
@end
