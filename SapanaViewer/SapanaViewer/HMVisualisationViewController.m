//
//  HMVisualisationViewController.m
//  SapanaViewer
//
//  Created by Jan Meier on 23.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#import "HMVisualisationViewController.h"

@interface HMVisualisationViewController ()

@end

@implementation HMVisualisationViewController

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
    // Do any additional setup after loading the view from its nib.
    self.matrixMultiplicationVVC = [[MatrixMultiplicationVisualisationViewController alloc] init];
    [self addChildViewController:self.matrixMultiplicationVVC];
    [self.view addSubview:self.matrixMultiplicationVVC.view];
    
    [self.matrixMultiplicationVVC.view setFrame:self.view.frame];
    

}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Getter and Setter
-(void)setNodeModifier:(SceneNodeModifierWrapper *)nodeModifier
{
    _nodeModifier = nodeModifier;
    // DUMMY ATRICES
    NSMutableArray * ancestors = [nodeModifier getAncesterMatrices];
    
    NSMutableArray* reverseAncestors = [[NSMutableArray alloc] init];
    NSEnumerator*   reverseEnumerator = [ancestors reverseObjectEnumerator];
    
    TransMatrix * nodeTransformation = [nodeModifier getNodeTransformationMatrix];
    [nodeTransformation setLabel:@"Node Transformation"];
    TransMatrix * nodeWorldTrans = [nodeModifier getWorldTransformationMatrix];
    [nodeWorldTrans setLabel:@"Node World Transformation"];
    
    [reverseAncestors addObject:nodeWorldTrans];
    [reverseAncestors addObject:nodeTransformation];
 
    
    for (id object in reverseEnumerator)
    {
        [reverseAncestors addObject:object];
    }
    
     NSArray * dummyMatrices = [[NSArray alloc] initWithArray:reverseAncestors];
    [self.matrixMultiplicationVVC refreshMatrices:dummyMatrices];
    
}

@end
