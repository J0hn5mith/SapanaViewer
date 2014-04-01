//
//  TransMatrix.m
//  SapanaViewer
//
//  Created by Jan Meier on 18.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#import "TransMatrix.h"

@implementation TransMatrix

- (instancetype)init
{
    self = [super init];
    if (self) {
        
        self.elements = [[NSMutableArray alloc] init];
        for (int i = 0; i < 4; i++)
        {
            NSMutableArray * lineArray = [[NSMutableArray alloc] init];
            for (int ii = 0; ii < 4; ii++)
            {
                if (i == ii)
                {
                    [lineArray addObject:[NSNumber numberWithFloat:1]];
                }
                else
                {
                    [lineArray addObject:[NSNumber numberWithFloat:0]];
                }
            }
            [self.elements addObject:lineArray];
        }
        
    }
    return self;
}

@end
