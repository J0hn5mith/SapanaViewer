//
//  HMInformationViewController.m
//  SapanaViewer
//
//  Created by Jan Meier on 05.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Class Definition Include
#import "HMInformationViewController.h"

// Project Includes
#import "Config.h"
@interface HMInformationViewController ()

@end

@implementation HMInformationViewController

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
    
    [self showNoNodeSelected:false];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}
#pragma mark - Getter and Setter
- (void) setSceneNodeModifier:(SceneNodeModifierWrapper *)sceneNodeModifier;
{
    
    _sceneNodeModifier = sceneNodeModifier;
    [self showNoNodeSelected:false];
    self.tableViewSource = [sceneNodeModifier getAncesterList];
    [self.tableView setDataSource:self];
    [self.tableView reloadData];
}

-(void) showNoNodeSelected:(BOOL) show
{
    [self.noNodeLabel setHidden:!show];
    [self.tableView setHidden:show];
}

#pragma mark - UITableViewDataSource Methodes
#pragma mark Required
- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:
(NSIndexPath *)indexPath
{
    if (indexPath.row == 0) // Return World coordinate node
    {
        UITableViewCell * firstCell = [[UITableViewCell alloc] init];
        firstCell.textLabel.text =  @"World Coordinates";
        firstCell.textLabel.font = TABLE_FONT;
        return firstCell;
    }
    else if (indexPath.row ==  [self tableView:tableView numberOfRowsInSection:indexPath.section] -1)
    {
         UITableViewCell * lastCell = [[UITableViewCell alloc] init];
        lastCell.textLabel.text =  @"Model Coordinates";
        lastCell.textLabel.font = TABLE_FONT;
        return lastCell;
    }
    else
    {
        return [self.tableViewSource tableView:tableView cellForRowAtIndexPath:indexPath];
    }
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:
(NSInteger)section
{
    return [self.tableViewSource tableView:tableView numberOfRowsInSection:section] + 1;
}

@end
