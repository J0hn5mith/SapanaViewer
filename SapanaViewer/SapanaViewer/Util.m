//
//  Util.m
//  SapanaViewer
//
//  Created by Jan Meier on 04.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#import "Util.h"

@implementation Util
+(CGPoint) CGPointAdd: (CGPoint) p1 p2:(CGPoint) p2;
{
    return CGPointMake(p1.x + p2.x, p1.y + p2.y);
}


+(CGRect) CGRectInRect: (CGRect) r1 r2:(CGRect) r2
{

    return CGRectMake(r2.origin.x + r1.origin.x, r2.origin.y + r1.origin.y, r1.size.width, r1.size.width);
}

+(CGFloat) smoothenVelocity:(CGFloat) velocity
{
    if (velocity < 1 && velocity >= 0 )
    {
        velocity = 1;
    }
    else if (velocity > -1 && velocity < 0 )
    {
        velocity = -1;
    }
    
    CGFloat absValue = ABS(velocity);
    CGFloat sign = velocity/absValue;

    return sqrtf(absValue) * sign;
}


#pragma mark - Color Parsing
+(UIColor*)colorFromHexString:(NSString*)hex
{
    NSString *cString = [[hex stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]] uppercaseString];
    
    // String should be 6 or 8 characters
    if ([cString length] < 6) return [UIColor grayColor];
    
    // strip 0X if it appears
    if ([cString hasPrefix:@"0X"]) cString = [cString substringFromIndex:2];
    
    if ([cString length] != 6) return  [UIColor grayColor];
    
    // Separate into r, g, b substrings
    NSRange range;
    range.location = 0;
    range.length = 2;
    NSString *rString = [cString substringWithRange:range];
    
    range.location = 2;
    NSString *gString = [cString substringWithRange:range];
    
    range.location = 4;
    NSString *bString = [cString substringWithRange:range];
    
    // Scan values
    unsigned int r, g, b;
    [[NSScanner scannerWithString:rString] scanHexInt:&r];
    [[NSScanner scannerWithString:gString] scanHexInt:&g];
    [[NSScanner scannerWithString:bString] scanHexInt:&b];
    
    return [UIColor colorWithRed:((float) r / 255.0f)
                           green:((float) g / 255.0f)
                            blue:((float) b / 255.0f)
                           alpha:1.0f];
}

+(UIColor*)colorFromIntRGB:(NSInteger)red green:(NSInteger)green blue:(NSInteger)blue alpha:(NSInteger)alpha
{
    return [UIColor colorWithRed:(red/255.0) green:(green/255.0) blue:(blue/255.0) alpha:(alpha/255.0)];
}

@end
