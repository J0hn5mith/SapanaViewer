//
//  PreviewViewController.m
//  SapanaViewer
//
//  Created by Jan Meier on 04.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#import "PreviewViewController.h"

// Config
#include "Config.h"

@interface PreviewViewController ()

@end

@implementation PreviewViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
        _expanded = false;
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

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(IBAction)singleTap:(UITapGestureRecognizer *)recognizer
{
    CGRect newframe;
    
    if(!_expanded)
    {
        newframe = [_delegate expandPreviewView];
    }
    else{
        newframe = [_delegate shrinkPreviewView];
    }
    
    _expanded = !_expanded;
}

@end
