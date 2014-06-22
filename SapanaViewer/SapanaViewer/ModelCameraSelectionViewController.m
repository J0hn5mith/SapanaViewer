//
//  ModelCameraViewController.m
//  SapanaViewer
//
//  Created by Jan Meier on 05.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#import "ModelCameraSelectionViewController.h"

@interface ModelCameraSelectionViewController ()

@end

@implementation ModelCameraSelectionViewController 

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
    
    
    // Configure Table View
    self.tableView.frame = self.view.bounds;
    [self.tableView setDelegate:self];
   
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


#pragma mark - Getter and Setter
-(void)setSapanaViewer:(SapanaViewerWrapper *)sapanaViewer
{
    [super setSapanaViewer:sapanaViewer];
    
    self.modelList = [self.sapanaViewer getFlatModelList];
    self.cameraList = [self.sapanaViewer getFlatCameraList];
    
    
    [self displayModelNodes];

}


#pragma mark - GUI Action handlers
-(IBAction)categoryChanged:(id)sender
{
    if (self.categorySegmentController.selectedSegmentIndex == 0)
    {
        [self displayModelNodes];
    }
    else if (self.categorySegmentController.selectedSegmentIndex == 1)
    {
        [self displayCameraNodes];
    }
    else
    {
        
    }
}


#pragma mark - List Source Setters
-(void)displayModelNodes
{
    [self.tableView setDataSource:self.modelList];
    [self.tableView reloadData];
}

-(void)displayCameraNodes
{
    [self.tableView setDataSource:self.cameraList];
    [self.tableView reloadData];
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    UITableViewCell * selectedCell= [tableView cellForRowAtIndexPath:indexPath];
    
    if (self.categorySegmentController.selectedSegmentIndex == 0)
    {
        [self.modelSelectorDelegate modelSelected:selectedCell.tag];
    }
    else if (self.categorySegmentController.selectedSegmentIndex == 1)
    {
        [self.cameraSelectorDelegate cameraSelected:selectedCell.tag];
    }
    else
    {
        
    }
}

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section

{
    return @"My Title";
}

@end
