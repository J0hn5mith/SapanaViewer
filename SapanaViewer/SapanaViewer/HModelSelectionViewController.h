//
//  HModelSelectionViewController.h
//  SapanaViewer
//
//  Created by Jan Meier on 05.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Base Class Include
#import "SelectionViewController.h"

// Project Includes
#import "SapanaViewerWrapper.h"
#import "HierarchicalListControllerWrapper.h"

@protocol HModelSelectionViewControllerDelegate

@required
// If no model is selected, the mode id is -1
- (void) modelSelected:(int) modelId;
@end

@interface HModelSelectionViewController : SelectionViewController < UITableViewDelegate, UITableViewDataSource >
@property (nonatomic, assign) id< HModelSelectionViewControllerDelegate > delegate;

@property HierarchicalListControllerWrapper * IBOutlet hierarchicalModelList;


#pragma mark - Action Handlers
-(IBAction)oneFingerDoubleTapRecognizer:(UITapGestureRecognizer *)sender;
-(IBAction)rearagneButton:(UIButton *)sender;
@end
