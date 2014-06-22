//
//  ModelSelectionViewController.h
//  SapanaViewer
//
//  Created by Jan Meier on 05.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Base class include
#import "SelectionViewController.h"

#import "ListWrapper.h"

//External includes
#import <UIKit/UIKit.h>


@protocol ModelSelectionViewControllerDelegate

@required
- (void) modelSelected:(int) modelId;
@end

@interface ModelSelectionViewController : SelectionViewController < UITableViewDelegate >

#pragma mark - GUI Elements
@property (weak, nonatomic) IBOutlet UIButton *addButton;
@property (weak, nonatomic) IBOutlet UIButton *removeButton;
@property (weak, nonatomic) IBOutlet UITableView *tableView;

#pragma mark - Delegates
@property (nonatomic, assign) id< ModelSelectionViewControllerDelegate > delegate;

// Sapana Viewer

@property ListWrapper * IBOutlet modelList;

@end
