//
//  Util.h
//  SapanaViewer
//
//  Created by Jan Meier on 04.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Util : NSObject
+(CGPoint) CGPointAdd: (CGPoint) p1 p2:(CGPoint) p2;
+(CGRect) CGRectInRect: (CGRect) r1 r2:(CGRect) r2;

+(CGFloat) smoothenVelocity: (CGFloat) velocity;

#pragma mark - Color Parsing
+(UIColor*)colorFromHexString:(NSString*)hex;
+(UIColor*)colorFromIntRGB:(NSInteger) red  green:(NSInteger) green blue:(NSInteger) blue alpha:(NSInteger) alpha;


@end
