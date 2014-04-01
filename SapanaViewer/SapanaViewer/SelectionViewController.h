//
//  SelectionViewController.h
//  SapanaViewer
//
//  Created by Jan Meier on 05.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Project Includes
#import "SapanaViewerWrapper.h"

// External Includes
#import <UIKit/UIKit.h>



@interface SelectionViewController : UIViewController

@property (nonatomic) SapanaViewerWrapper * sapanaViewer;

// GUI Elements
@property (weak, nonatomic) IBOutlet UIView *headerView;
@property (weak, nonatomic) IBOutlet UITableView *tableView;
@property (weak, nonatomic) IBOutlet UIView *footerView;

@end
