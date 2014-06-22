//
//  ModelSelectorDelegate.h
//  SapanaViewer
//
//  Created by Jan Meier on 10.04.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol ModelSelectorDelegate <NSObject>
@required
- (void) modelSelected:(int) modelID;
@end