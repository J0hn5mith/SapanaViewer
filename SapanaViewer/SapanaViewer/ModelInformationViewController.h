//
//  ModelInformationViewController.h
//  SapanaViewer
//
//  Created by Jan Meier on 05.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Base Class
#import "InformationViewController.h"

// Project Includes
#import "SceneNodeModifierWrapper.h"
#import "ModelInformationWrapper.h"

// External Includes
#import <UIKit/UIKit.h>

@interface ModelInformationViewController : InformationViewController

#pragma mark - Information Source
@property (nonatomic) ModelInformationWrapper * modelInformation;

#pragma mark - Sub Views
@property (weak, nonatomic) IBOutlet UIView *informationView;
@property (weak, nonatomic) IBOutlet UILabel *noInformatinLabel;

@property (weak, nonatomic) IBOutlet UILabel *numVerticesLabel;
@property (weak, nonatomic) IBOutlet UILabel *numIndicesLabel;
@property (weak, nonatomic) IBOutlet UILabel *numNormalsLabel;
@property (weak, nonatomic) IBOutlet UILabel *sizeInBytesLabel;

#pragma mark - Accessors
@property (nonatomic) BOOL showNoInformation;

@end
