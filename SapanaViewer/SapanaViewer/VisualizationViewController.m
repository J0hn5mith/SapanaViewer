//
//  VisualizationViewController.m
//  SapanaViewer
//
//  Created by Jan Meier on 04.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#import "VisualizationViewController.h"

// Config
#include "Config.h"

@interface VisualizationViewController ()

@end

@implementation VisualizationViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
        _expanded = false;
        self.view.clipsToBounds = YES;
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    
    // Layout
    self.view.layer.cornerRadius = CORNER_RADIUS_TOPIC_SUBVIEW;
    
}

-(IBAction)singleTap:(UITapGestureRecognizer *)recognizer
{
    CGRect newframe;
    
    if(!_expanded)
    {
       newframe = [_delegate expandVisualizationView];
    }
    else{
        newframe = [_delegate shrinkVisualizationView];
    }
    
    _expanded = !_expanded;
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
