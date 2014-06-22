//
//  ModelCameraViewController.h
//  SapanaViewer
//
//  Created by Jan Meier on 05.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Includes Base Class
#import "SelectionViewController.h"

// Includes Protocols
#import "ModelSelectorDelegate.h"
#import "CameraSelectorDelegate.h"

@interface ModelCameraSelectionViewController : SelectionViewController < UITableViewDelegate >

#pragma mark - List Sources
@property ListWrapper * IBOutlet modelList;
@property ListWrapper * IBOutlet cameraList;

#pragma mark - Delegates
@property (nonatomic, assign) id< ModelSelectorDelegate > modelSelectorDelegate;
@property (nonatomic, assign) id< CameraSelectorDelegate > cameraSelectorDelegate;

#pragma mark - GUI Components
@property (weak, nonatomic) IBOutlet UISegmentedControl *categorySegmentController;


#pragma mark - GUI Action handlers
-(IBAction)categoryChanged:(id)sender;
@end
