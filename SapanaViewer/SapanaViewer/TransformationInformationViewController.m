//
//  TransformationInformationViewController.m
//  SapanaViewer
//
//  Created by Jan Meier on 05.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#import "TransformationInformationViewController.h"

@interface TransformationInformationViewController ()

@end

@implementation TransformationInformationViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        _matrixVC = [[MatrixViewController alloc] init];
        [self addChildViewController:self.matrixVC];
        [self.view addSubview:self.matrixVC.view];
        self.matrixVC.view.frame = self.matrixProtopye.frame;
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    
	// Do any additional setup after loading the view.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(void) hideMatrix:(BOOL) hide
{
    [self.matrixVC.view setHidden:hide];
}

-(void) showNoMatrixSelected:(BOOL) show
{
    [self.noMatrixLabel setHidden:!show];
}

@end
