//
//  MatrixViewController.h
//  SapanaViewer
//
//  Created by Jan Meier on 18.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TransMatrix.h"

@interface MatrixViewController : UIViewController

#pragma mark - Number Fields and Operands
@property NSMutableArray * labelMatrix;
@property (weak, nonatomic) IBOutlet UILabel *field00;
@property (weak, nonatomic) IBOutlet UILabel *field01;
@property (weak, nonatomic) IBOutlet UILabel *field02;
@property (weak, nonatomic) IBOutlet UILabel *field03;

@property (weak, nonatomic) IBOutlet UILabel *field10;
@property (weak, nonatomic) IBOutlet UILabel *field11;
@property (weak, nonatomic) IBOutlet UILabel *field12;
@property (weak, nonatomic) IBOutlet UILabel *field13;

@property (weak, nonatomic) IBOutlet UILabel *field20;
@property (weak, nonatomic) IBOutlet UILabel *field21;
@property (weak, nonatomic) IBOutlet UILabel *field22;
@property (weak, nonatomic) IBOutlet UILabel *field23;

@property (weak, nonatomic) IBOutlet UILabel *field30;
@property (weak, nonatomic) IBOutlet UILabel *field31;
@property (weak, nonatomic) IBOutlet UILabel *field32;
@property (weak, nonatomic) IBOutlet UILabel *field33;




#pragma mark - Util Members
@property TransMatrix * currentMatrix;
@property NSNumberFormatter * numberFormater;

#pragma mark - Update Methods
-(void) updateWithMatrix:(TransMatrix * ) matrix;
-(void) updateWithMatrixWithHighlight:(TransMatrix * ) matrix;

#pragma mark - Util Methods
-(NSString *) floatToString:(NSNumber *) number;
@end
