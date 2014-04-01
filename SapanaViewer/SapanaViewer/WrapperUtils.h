//
//  WrapperUtils.h
//  SapanaViewer
//
//  Created by Jan Meier on 18.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#import <Foundation/Foundation.h>

// Project Includes
#include "TransMatrix.h"

// External Includes
#include <vector>

// Foreward Declarations


@interface WrapperUtils : NSObject
+(TransMatrix *) create_matrix:(std::vector< std::vector<float> >) matrixW;

+(NSMutableArray  *) create_matrix_list:(std::vector< std::vector< std::vector<float> > >) matrixVector;
@end
