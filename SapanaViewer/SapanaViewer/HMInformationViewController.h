//
//  HMInformationViewController.h
//  SapanaViewer
//
//  Created by Jan Meier on 05.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//
// Base Class Include
#import "InformationViewController.h"

// Project Includes
#import "SceneNodeModifierWrapper.h"
#import "ListWrapper.h"

@interface HMInformationViewController : InformationViewController < UITableViewDataSource >
@property (nonatomic) SceneNodeModifierWrapper * sceneNodeModifier;
@property ListWrapper * tableViewSource;

@property (weak, nonatomic) IBOutlet UITableView *tableView;
@property (weak, nonatomic) IBOutlet UILabel *noNodeLabel;
-(void) showNoNodeSelected:(BOOL) show;
@end
