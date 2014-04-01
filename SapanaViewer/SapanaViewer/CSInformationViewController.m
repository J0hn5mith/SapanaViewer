//
//  CSInformationViewController.m
//  SapanaViewer
//
//  Created by Jan Meier on 05.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#import "CSInformationViewController.h"

@interface CSInformationViewController ()

@end

@implementation CSInformationViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    self.noContentLabelVisible = true;
    // Do any additional setup after loading the view from its nib.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Getter and Setter
-(void) setNoContentLabelVisible:(bool)noContentLabelVisible
{
    _noContentLabelVisible =   noContentLabelVisible;
    [self.noContentLabel setHidden:!noContentLabelVisible];

}



@end
