//
//  ModelSelectionViewController.m
//  SapanaViewer
//
//  Created by Jan Meier on 05.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#import "ModelSelectionViewController.h"

@interface ModelSelectionViewController ()

@end

@implementation ModelSelectionViewController

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
    
    
}

#pragma mark - Getter and Setter
-(void) setDelegate:(id<ModelSelectionViewControllerDelegate>)delegate
{
    _delegate = delegate;
    // TODO: Selects first model but probably not necessary
//    NSIndexPath *indexPath = [[self.tableView indexPathsForSelectedRows] objectAtIndex:0];
//     UITableViewCell * selectedCell= [self.tableView cellForRowAtIndexPath:indexPath];
//    [self.delegate modelSelected:selectedCell.tag];
}

-(void)setSapanaViewer:(SapanaViewerWrapper *)sapanaViewer
{
    [super setSapanaViewer:sapanaViewer];
    self.modelList = [self.sapanaViewer getFlatModelList];
    [self.tableView setDataSource:self.modelList];
    [self.tableView setDelegate:self];
    [self.tableView reloadData];
    
    // Select first item
    if ([self.tableView numberOfRowsInSection:1 ] > 0)
    {
        NSIndexPath *indexPath=[NSIndexPath indexPathForRow:0 inSection:0];
        [self.tableView selectRowAtIndexPath:indexPath animated:YES  scrollPosition:UITableViewScrollPositionBottom];
    }
}

#pragma mark - Sapana Viewer
- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark -
#pragma mark UITableView Delegate

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    UITableViewCell * selectedCell= [tableView cellForRowAtIndexPath:indexPath];
    
    [self.delegate modelSelected:[selectedCell tag]];
}

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section

{
    return @"My Title";
}

@end
