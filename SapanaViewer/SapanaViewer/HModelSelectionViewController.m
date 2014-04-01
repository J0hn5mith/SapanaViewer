//
//  HModelSelectionViewController.m
//  SapanaViewer
//
//  Created by Jan Meier on 05.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Project Includes
#import "HModelSelectionViewController.h"
#import "HierarchicalListItemWrapper.h"

@interface HModelSelectionViewController ()

@end

@implementation HModelSelectionViewController

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
-(void) setDelegate:(id<HModelSelectionViewControllerDelegate>)delegate
{
    _delegate = delegate;
}

-(void) setSapanaViewer:(SapanaViewerWrapper *)sapanaViewer
{
    [super setSapanaViewer:sapanaViewer];
    self.hierarchicalModelList = [self.sapanaViewer getHierarchicalModelList];
    
    [self.tableView setDataSource:self];
    [self.tableView setDelegate:self];
    [self.tableView reloadData];
}

#pragma mark - Action Handlers
-(IBAction)oneFingerDoubleTapRecognizer:(UITapGestureRecognizer *)recognizer
{
    CGPoint position = [recognizer locationInView:recognizer.view];
    NSIndexPath * indexPath = [ self.tableView indexPathForRowAtPoint:position ];
    [self toogleListItem:indexPath];
}

-(void) toogleListItem:(NSIndexPath *) indexPath
{
    if (indexPath )
    {
        unsigned long nodeID = [self.tableView cellForRowAtIndexPath:indexPath].tag;
        [self.hierarchicalModelList toggleItem:nodeID];
        [self.tableView reloadData];
    }
}

-(IBAction)rearagneButton:(UIButton *)sender
{
    
    if ([sender tag] == 0 )
    {
        [[self tableView] setEditing:TRUE];
        sender.tag = 1;
    }
    else
    {
        [[self tableView] setEditing:FALSE];
        sender.tag = 0;
    }
}

#pragma mark -
#pragma mark UITableView Delegate

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    UITableViewCell * selectedCell= [tableView cellForRowAtIndexPath:indexPath];
    if (indexPath.row == 0)
    {
        [self toogleListItem:indexPath];
        [self.delegate modelSelected:-1];
    }
    else
    {
        [self.delegate modelSelected:[selectedCell tag]];
    }

}

- (UITableViewCellEditingStyle)tableView:(UITableView *)tableView editingStyleForRowAtIndexPath:(NSIndexPath *)indexPath
{
    if ([self tableView].editing)
    {
        return UITableViewCellEditingStyleNone;
    }
    else
    {
        return UITableViewCellEditingStyleDelete;
    }
    
}

- (BOOL)tableView:(UITableView *)tableview shouldIndentWhileEditingRowAtIndexPath:(NSIndexPath *)indexPath {
    return NO;
}

- (NSIndexPath *)tableView:(UITableView *)tableView targetIndexPathForMoveFromRowAtIndexPath:(NSIndexPath *)sourceIndexPath toProposedIndexPath:(NSIndexPath *)proposedDestinationIndexPath
{
    NSInteger proposedRow = proposedDestinationIndexPath.row;
    HierarchicalListItemWrapper * sourceItem = (HierarchicalListItemWrapper *) [ tableView cellForRowAtIndexPath:sourceIndexPath];
    
    if ([self.hierarchicalModelList canMoveToPosition:sourceIndexPath.row newPosition:proposedDestinationIndexPath.row])
    {
        
        if (proposedDestinationIndexPath.row > sourceIndexPath.row)
        {
            return [NSIndexPath indexPathForRow:proposedDestinationIndexPath.row inSection:sourceIndexPath.section];
        }
        else
        {
            return [NSIndexPath indexPathForRow:proposedDestinationIndexPath.row+1 inSection:sourceIndexPath.section];
        }

    };
    
//    if (proposedRow == 0) // Can't insert before root node
//    {
//        return [NSIndexPath indexPathForRow:1 inSection:sourceIndexPath.section];
//    }
//    
//    // Avoid insertation as own child
//    if ( sourceIndexPath.row < proposedDestinationIndexPath.row)
//    {
//        bool isOwnChild = true;
//        for (int i  = sourceIndexPath.row + 1; i <= proposedDestinationIndexPath.row; i++)
//        {
//            HierarchicalListItemWrapper * childItem = (HierarchicalListItemWrapper *) [ tableView cellForRowAtIndexPath:[NSIndexPath indexPathForRow:i inSection:sourceIndexPath.section]];
//            
//            if (childItem.level < sourceItem.level )
//            {
//                isOwnChild = false;
//            }
//            else if ( childItem.level == sourceItem.level && childItem.expanded)
//            {
//                isOwnChild = false;
//            }
//        }
//        
//        if (isOwnChild)
//        {
//            return sourceIndexPath;
//        }
//    }
//    
//    HierarchicalListItemWrapper * newParent = (HierarchicalListItemWrapper *) [ tableView cellForRowAtIndexPath:[NSIndexPath indexPathForRow:proposedDestinationIndexPath.row inSection:proposedDestinationIndexPath.section]];
//    
//    
//    if (newParent.expanded)
//    {
//        NSIndexPath * newPosition = [NSIndexPath indexPathForRow:proposedDestinationIndexPath.row inSection:sourceIndexPath.section];
//        ;
//        [[tableView cellForRowAtIndexPath:newPosition].textLabel setText:@"Selected"];
//        return proposedDestinationIndexPath;
//    }
    

    return sourceIndexPath;
}



#pragma mark -
#pragma mark UITableView Source

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:
(NSInteger)section{
    
    // There is one additional field for adding another transformation matrix
    return [self.hierarchicalModelList tableView:tableView numberOfRowsInSection:section];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:
(NSIndexPath *)indexPath
{
    
    HierarchicalListItemWrapper * cell = (HierarchicalListItemWrapper * )[self.hierarchicalModelList tableView:tableView cellForRowAtIndexPath:indexPath];
    
    cell.valueLabel.text = [self.sapanaViewer getSceneNodeName:cell.tag];
    
    return cell;
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return [self.hierarchicalModelList numberOfSectionsInTableView:tableView];
}

- (void)tableView:(UITableView *)tableView commitEditingStyle:(UITableViewCellEditingStyle)editingStyle forRowAtIndexPath:(NSIndexPath *)indexPath
{
    
}

- (BOOL)tableView:(UITableView *)tableView canEditRowAtIndexPath:(NSIndexPath *)indexPath
{
    return indexPath.row != 0 ? YES: NO;
}

- (BOOL)tableView:(UITableView *)tableView canMoveRowAtIndexPath:(NSIndexPath *)indexPath
{
    return YES;
}

// This method assumes that the new parent is valid
- (void)tableView:(UITableView *)tableView moveRowAtIndexPath:(NSIndexPath *)fromIndexPath toIndexPath:(NSIndexPath *)toIndexPath
{
    
    if (fromIndexPath.row == toIndexPath.row)
    {
        return;
    }
    // Find new Parent
    HierarchicalListItemWrapper * newParent = (HierarchicalListItemWrapper *) [ tableView cellForRowAtIndexPath:[NSIndexPath indexPathForRow:toIndexPath.row - 1 inSection:toIndexPath.section]];
    

    
    unsigned long childID = [tableView cellForRowAtIndexPath:fromIndexPath].tag;
    unsigned long parentID = newParent.tag;
    
    if (childID == parentID)
    {
        return;
    }
    
    [self.sapanaViewer moveNode:childID newParent:parentID];
    [self.hierarchicalModelList refreshItems];
    [tableView setEditing:false];
    [tableView reloadData];
    
//    NSInteger row = [fromIndexPath row];
//    UITableViewCell * fromCell = [tableView cellForRowAtIndexPath:fromIndexPath];
//    NSInteger fromTag = [fromCell tag];
//    fromTag++;
//    if (fromIndexPath.row == toIndexPath.row)
//    {
//        return;
//    }
////    [tableView endUpdates];
////    [tableView beginUpdates];
////    
////    //[tableView deleteRowsAtIndexPaths: withRowAnimation:UITableViewRowAnimationFade];
////    //[tableView moveRowAtIndexPath:[NSIndexPath indexPathForRow:3 inSection:toIndexPath.section] toIndexPath:[NSIndexPath indexPathForRow:4 inSection:toIndexPath.section]];
//////    [tableView deleteRowsAtIndexPaths:[NSArray arrayWithObject:[NSIndexPath indexPathForRow:0 inSection:toIndexPath.section]] withRowAnimation:UITableViewRowAnimationFade];
////    
////    [tableView endUpdates];
    
}

// Util method


#pragma mark -
#pragma mark Memory Management
- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end

