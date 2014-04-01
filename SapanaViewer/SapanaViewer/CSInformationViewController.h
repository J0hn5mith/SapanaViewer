//
//  CSInformationViewController.h
//  SapanaViewer
//
//  Created by Jan Meier on 05.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#import "InformationViewController.h"

@interface CSInformationViewController : InformationViewController
@property (weak, nonatomic) IBOutlet UILabel *noContentLabel;
@property (nonatomic) bool noContentLabelVisible;

@end
