//
//  ModelConfigurationViewController.h
//  SapanaViewer
//
//  Created by Jan Meier on 05.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Super class
#import "ConfigurationViewController.h"

// Project Indcludes
#import "SceneNodeModifierWrapper.h"

// External Includes
#import <UIKit/UIKit.h>
#import "NEOColorPickerViewController.h"

@interface ModelConfigurationViewController : ConfigurationViewController <NEOColorPickerViewControllerDelegate >
@property (nonatomic) SceneNodeModifierWrapper * sceneNodeModifier;

#pragma mark - Views and View Controller
@property UINavigationController * colorPickerViewController;

#pragma mark - No Model Selected
@property (nonatomic) BOOL noModelSelected;
@property (weak, nonatomic) IBOutlet UILabel *noModelSelectedLabel;

#pragma mark - GUI Components
@property (weak, nonatomic) IBOutlet UIView *controllPanelView;
@property (weak, nonatomic) IBOutlet UISwitch *normalsSwitch;
@property (weak, nonatomic) IBOutlet UISwitch * wireFrameSwitch;
@property (weak, nonatomic) IBOutlet UISwitch *coorSystemSwtich;
@property (weak, nonatomic) IBOutlet UIButton *colorPickerButton;

#pragma mark - Getter and Setter
- (void) setSceneNodeModifier:(SceneNodeModifierWrapper *)sceneNodeModifier;

#pragma mark - Action Handlers
-(IBAction)wireFrameSwitchChanged:(id)sender;
-(IBAction)coordSystemSwitchChanged:(id)sender;
-(IBAction)normalsSwitchChanged:(id)sender;
-(IBAction)colorPickerButtonPressed:(id)sender;

@end
