//
//  ModelInformationViewController.m
//  SapanaViewer
//
//  Created by Jan Meier on 05.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#import "ModelInformationViewController.h"

@interface ModelInformationViewController ()

@end

@implementation ModelInformationViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
       
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
     [self setShowNoInformation:YES];
    // Do any additional setup after loading the view from its nib.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


#pragma mark - Accessors

-(void)setModelInformation:(ModelInformationWrapper *)modelInformation
{
    _modelInformation = modelInformation;
    
    self.numVerticesLabel.text = self.modelInformation.getNumVertices;
    self.numIndicesLabel.text = self.modelInformation.getNumIndices;
    self.numNormalsLabel.text = self.modelInformation.getNumFaces;
    self.sizeInBytesLabel.text = self.modelInformation.getSizeInBytes;
    
    [self setShowNoInformation:false];
}

-(void) setShowNoInformation:(BOOL)showNoInformation
{
    
    _showNoInformation = showNoInformation;
    
    if (_showNoInformation)
    {
        [self.informationView setHidden:true];
        [self.noInformatinLabel setHidden:false];
    }
    else
    {
        [self.informationView setHidden:false];
        [self.noInformatinLabel setHidden:true];
    }
}

@end
