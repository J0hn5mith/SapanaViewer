//
//  MatrixViewController.m
//  SapanaViewer
//
//  Created by Jan Meier on 18.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#import "MatrixViewController.h"
#import "Config.h"
 #import <CoreText/CoreText.h>

@interface MatrixViewController ()

@end

@implementation MatrixViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        self.numberFormater = [[NSNumberFormatter alloc] init];
        [self.numberFormater setPositiveFormat:@"0.##"];
        [self.numberFormater setNegativeFormat:@"0.##"];
        _isHighlighted = false;
        
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    self.labelMatrix = [[NSMutableArray alloc] init];
    NSArray *line = [[NSArray alloc] initWithObjects:
                     [self labelToTextLayer:self.field00],
                     [self labelToTextLayer:self.field01],
                     [self labelToTextLayer:self.field02],
                     [self labelToTextLayer:self.field03],
                     nil];
    [self.labelMatrix addObject:line];
    
    line = [[NSArray alloc] initWithObjects:
            [self labelToTextLayer:self.field10],
            [self labelToTextLayer:self.field11],
            [self labelToTextLayer:self.field12],
            [self labelToTextLayer:self.field13],
            nil];
    [self.labelMatrix addObject:line];
    
    line = [[NSArray alloc] initWithObjects:
            [self labelToTextLayer:self.field20],
            [self labelToTextLayer:self.field21],
            [self labelToTextLayer:self.field22],
            [self labelToTextLayer:self.field23],
            nil];
    [self.labelMatrix addObject:line];
    
    line = [[NSArray alloc] initWithObjects:
            [self labelToTextLayer:self.field30],
            [self labelToTextLayer:self.field31],
            [self labelToTextLayer:self.field32],
            [self labelToTextLayer:self.field33],
            nil];
    [self.labelMatrix addObject:line];
    

    
    TransMatrix * mat = [[TransMatrix alloc] init];
    [self updateWithMatrixWithHighlight:mat];
   
    
    self.view.layer.cornerRadius = CORNER_RADIUS_MATRIX_VIEW;
    [self.view clipsToBounds];
    
    self.highLightColor = [UIColor whiteColor];
    self.fontColor = [UIColor blackColor];
    self.fontHighlightColor = [UIColor greenColor];
    
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreadted.
}

#pragma mark - Setter and Getter Methodes
-(void) setIsHighlighted:(BOOL *)isHighlighted
{
    _isHighlighted = isHighlighted;
    
    if(_isHighlighted)
    {
        [self.view setBackgroundColor:self.highLightColor];
    }
    else
    {
        [self.view setBackgroundColor:self.highLightColor];
    }
}

-(void) updateWithMatrixWithHighlight:(TransMatrix * ) matrix
{
    int lineCounter = 0;
    for (NSMutableArray * line in matrix.elements)
    {
        int elementCounter = 0;
        for (NSNumber * number in line)
        {
            NSNumber * oldNumber = [[self.currentMatrix.elements objectAtIndex:lineCounter] objectAtIndex:elementCounter];
            if ( number.floatValue != oldNumber.floatValue)
            {
                CATextLayer * targetTextLayer = [[self.labelMatrix objectAtIndex:lineCounter] objectAtIndex:elementCounter];
                
                [targetTextLayer setString:[self floatToString:number]];
                [self textColorAnimation:targetTextLayer ];
            }
            elementCounter++;
        }
        lineCounter++;
    }
    
    self.currentMatrix = matrix;
}
-(void) updateWithMatrix:(TransMatrix * ) matrix
{
    int lineCounter = 0;
    for (NSMutableArray * line in matrix.elements)
    {
        int elementCounter = 0;
        for (NSNumber * number in line)
        {
            CATextLayer * targetTextLayer = [[self.labelMatrix objectAtIndex:lineCounter] objectAtIndex:elementCounter];
            [targetTextLayer setString:[self floatToString:number]];
            
            elementCounter++;
        }
        lineCounter++;
    }
    
    self.currentMatrix = matrix;
}

-(NSString *) floatToString:(NSNumber *) number
{
    return [self.numberFormater stringFromNumber:number];
}

-(CATextLayer *) labelToTextLayer:(UILabel *) label
{
    CATextLayer *textLayer = [CATextLayer layer];
    
    [textLayer setString:label.text];
    [textLayer setForegroundColor:label.textColor.CGColor];
    [textLayer setFontSize:label.font.pointSize];
    CTFontRef myCTFont = CTFontCreateWithName( (CFStringRef)label.font.fontName, label.font.pointSize, NULL);
    [textLayer setFont:myCTFont];
    [textLayer setFrame:label.frame];
    [textLayer setAlignmentMode:@"kCAAlignmentCenter"];
    [[self.matrixLabelView layer] addSublayer:textLayer];
    
    [label removeFromSuperview];
    
    return textLayer;
}
#pragma mark - Utils
-(void) textColorAnimation:(CATextLayer*)textLayer
{
    
    
//    [textLayer setString:@"Hello World"];
//    [textLayer setForegroundColor:[UIColor purpleColor].CGColor];
//    [textLayer setFontSize:30];
//    [textLayer setFrame:CGRectMake(20, 200, 300, 40)];
//    [[self.view layer] addSublayer:textLayer];
    
    CGFloat animationDuration = 1.5;
    CABasicAnimation *colorAnimation = [CABasicAnimation
                                        animationWithKeyPath:@"foregroundColor"];
    colorAnimation.duration = animationDuration;
    colorAnimation.fillMode = kCAFillModeForwards;
    colorAnimation.removedOnCompletion = NO;
    colorAnimation.fromValue = (id)self.fontHighlightColor.CGColor;
    colorAnimation.toValue = (id)self.fontColor.CGColor;
    colorAnimation.timingFunction = [CAMediaTimingFunction
                                     functionWithName:kCAMediaTimingFunctionLinear];
    
    CAAnimationGroup *animationGroup = [CAAnimationGroup animation];
    animationGroup.duration = animationDuration;
    animationGroup.timingFunction = [CAMediaTimingFunction
                                     functionWithName:kCAMediaTimingFunctionLinear];
    animationGroup.fillMode = kCAFillModeForwards;
    animationGroup.removedOnCompletion = NO;
    animationGroup.animations =
    [NSArray arrayWithObjects:colorAnimation, nil];
    
    [textLayer addAnimation:animationGroup forKey:@"animateColor"];
    
}
@end
