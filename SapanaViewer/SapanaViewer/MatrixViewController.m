//
//  MatrixViewController.m
//  SapanaViewer
//
//  Created by Jan Meier on 18.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#import "MatrixViewController.h"

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
        
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    self.labelMatrix = [[NSMutableArray alloc] init];
    NSArray *line = [[NSArray alloc] initWithObjects:self.field00, self.field01, self.field02, self.field03, nil];
    [self.labelMatrix addObject:line];
    
    line = [[NSArray alloc] initWithObjects:self.field10, self.field11, self.field12, self.field13, nil];
    [self.labelMatrix addObject:line];
    
    line = [[NSArray alloc] initWithObjects:self.field20, self.field21, self.field22, self.field23, nil];
    [self.labelMatrix addObject:line];
    
    line = [[NSArray alloc] initWithObjects:self.field30, self.field31, self.field32, self.field33, nil];
    [self.labelMatrix addObject:line];
    
    // Do any additional setup after loading the view from its nib.
    
    TransMatrix * mat = [[TransMatrix alloc] init];
    
    [self updateWithMatrix:mat];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreadted.
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
                UILabel * targetLabel = [[self.labelMatrix objectAtIndex:lineCounter] objectAtIndex:elementCounter];
                
                targetLabel.text = [self floatToString:number];
                targetLabel.textColor = [UIColor redColor];
                
//                [UIView animateWithDuration:2.0 animations:^{
//                    targetLabel.layer.backgroundColor = [UIColor greenColor].CGColor;
//                } completion:NULL];
                
            }
            elementCounter++;
        }
        lineCounter++;
    }
    
    self.currentMatrix = matrix;
}
-(void) updateWithMatrix:(TransMatrix * ) matrix
{
    
    // TODO: use itteration
    self.field00.text = [self floatToString:(NSNumber *)[[[matrix elements] objectAtIndex:0] objectAtIndex:0]];
    self.field01.text = [self floatToString:(NSNumber *)[[[matrix elements] objectAtIndex:0] objectAtIndex:1]]
    ;
    self.field02.text = [self floatToString:(NSNumber *)[[[matrix elements] objectAtIndex:0] objectAtIndex:2]];
    self.field03.text = [self floatToString:(NSNumber *)[[[matrix elements] objectAtIndex:0] objectAtIndex:3]];
    
    self.field10.text = [self floatToString:(NSNumber *)[[[matrix elements] objectAtIndex:1] objectAtIndex:0]];
    self.field11.text = [self floatToString:(NSNumber *)[[[matrix elements] objectAtIndex:1] objectAtIndex:1]];
    self.field12.text = [self floatToString:(NSNumber *)[[[matrix elements] objectAtIndex:1] objectAtIndex:2]];
    self.field13.text = [self floatToString:(NSNumber *)[[[matrix elements] objectAtIndex:1] objectAtIndex:3]];
//
    self.field20.text = [self floatToString:(NSNumber *)[[[matrix elements] objectAtIndex:2] objectAtIndex:0]];
    self.field21.text = [self floatToString:(NSNumber *)[[[matrix elements] objectAtIndex:2] objectAtIndex:1]];
    self.field22.text = [self floatToString:(NSNumber *)[[[matrix elements] objectAtIndex:2] objectAtIndex:2]];
    self.field23.text = [self floatToString:(NSNumber *)[[[matrix elements] objectAtIndex:2] objectAtIndex:3]];
//
    self.field30.text = [self floatToString:(NSNumber *)[[[matrix elements] objectAtIndex:3] objectAtIndex:0]];
    self.field31.text = [self floatToString:(NSNumber *)[[[matrix elements] objectAtIndex:3] objectAtIndex:1]];
    self.field32.text = [self floatToString:(NSNumber *)[[[matrix elements] objectAtIndex:3] objectAtIndex:2]];
    self.field33.text = [self floatToString:(NSNumber *)[[[matrix elements] objectAtIndex:3] objectAtIndex:3]];
    
     self.currentMatrix = matrix;
}

-(NSString *) floatToString:(NSNumber *) number
{
    return [self.numberFormater stringFromNumber:number];
}

@end
