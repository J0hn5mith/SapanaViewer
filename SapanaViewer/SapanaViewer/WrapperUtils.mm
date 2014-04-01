//
//  WrapperUtils.m
//  SapanaViewer
//
//  Created by Jan Meier on 18.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Class Definition
#import "WrapperUtils.h"

// Project Includes



@implementation WrapperUtils
+(TransMatrix *) create_matrix:(std::vector< std::vector< float > >) matrixW
{
    
    TransMatrix * transMatrix = [[TransMatrix alloc] init];
    NSInteger lineCount = 0;
    std::for_each(matrixW.begin(), matrixW.end(),
                  [&] (std::vector<float>line)
                  {
                      [self parseLine:line matrix:transMatrix lineNumber:lineCount];
                      lineCount++;
                  }
                  );
    
                  
    return transMatrix;
}

+(NSMutableArray  *) create_matrix_list:(std::vector< std::vector< std::vector<float> > >) matrixVector
{
    NSMutableArray * result = [[NSMutableArray alloc] init];
    
    std::for_each(matrixVector.begin(), matrixVector.end(),
                  [&] (std::vector< std::vector< float > > matrix)
                  {
                      [result addObject:[WrapperUtils create_matrix:matrix]];
                  }
                  );
                       return result;
}

+(void) parseLine:(std::vector<float>) line  matrix:(TransMatrix *) matrix lineNumber:(NSInteger) lineNumber
{
    NSInteger columnCount = 0;
    std::for_each(line.begin(), line.end(), [&](float entry)
    {
        [((NSMutableArray* )[[matrix elements] objectAtIndex:lineNumber])replaceObjectAtIndex:columnCount withObject:[NSNumber numberWithFloat:entry]];
        columnCount++;
    });
}
@end
