//
//  TransformationInformationViewController.h
//  SapanaViewer
//
//  Created by Jan Meier on 05.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#import "InformationViewController.h"

// Project Includes
#import "MatrixViewController.h"

@interface TransformationInformationViewController : InformationViewController
@property MatrixViewController * matrixVC;
@property (weak, nonatomic) IBOutlet UIView *matrixProtopye;
@property (weak, nonatomic) IBOutlet UILabel *noMatrixLabel;

-(void) showNoMatrixSelected:(BOOL) show;
-(void) hideMatrix:(BOOL) hide;
@end
