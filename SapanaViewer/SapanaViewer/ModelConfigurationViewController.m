//
//  ModelConfigurationViewController.m
//  SapanaViewer
//
//  Created by Jan Meier on 05.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#import "ModelConfigurationViewController.h"

@interface ModelConfigurationViewController ()

@end

@implementation ModelConfigurationViewController

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
    
    // TODO Change TASK: BORDER COLOR
    [self setNoModelSelected:true];
    
    // Do any additional setup after loading the view from its nib.
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
    
    self.wireFrameSwitch.on = [sceneNodeModifier getWireFrameMode];
    self.coorSystemSwtich.on = [sceneNodeModifier getShowCoordinateSystem];
    self.normalsSwitch.on = [sceneNodeModifier getShowNormals];
    
    _sceneNodeModifier = sceneNodeModifier;
    [self setNoModelSelected:false];
}

-(void) setNoModelSelected:(BOOL)noModelSelected
{
    _noModelSelected = noModelSelected;
    
    if (noModelSelected)
    {
        [self.noModelSelectedLabel setHidden:false];
        [self.controllPanelView setHidden:true];
    }
    else
    {
        [self.noModelSelectedLabel setHidden:true];
        [self.controllPanelView setHidden:false];
    }
}

#pragma mark - Color Picker Delegate
- (void) colorPickerViewController:(NEOColorPickerBaseViewController *)controller didSelectColor:(UIColor *)color {
    // Do something with the color.
    self.colorPickerButton.backgroundColor = color;
    [self.colorPickerViewController removeFromParentViewController];
    [self.colorPickerViewController.view removeFromSuperview];
    self.colorPickerViewController = NULL;
    [controller dismissViewControllerAnimated:YES completion:nil];
}

-(void) colorPickerViewControllerDidCancel:(NEOColorPickerBaseViewController *)controller
{
    [self.colorPickerViewController removeFromParentViewController];
    [self.colorPickerViewController.view removeFromSuperview];
    self.colorPickerViewController = NULL;
    [controller dismissViewControllerAnimated:YES completion:nil];
}

#pragma mark - Action Handlers
-(IBAction)wireFrameSwitchChanged:(id)sender
{
    [self.sceneNodeModifier setWireFrameMode:self.wireFrameSwitch.on];
}

-(IBAction)coordSystemSwitchChanged:(id)sender
{
    [self.sceneNodeModifier setShowCoordinateSystem:self.coorSystemSwtich.on];
}

-(IBAction)normalsSwitchChanged:(id)sender
{
    [self.sceneNodeModifier setShowNormals:self.normalsSwitch.on];
}

-(IBAction)colorPickerButtonPressed:(id)sender
{
    NEOColorPickerViewController * controller = [[NEOColorPickerViewController alloc] init];
    controller.delegate = self;
    controller.selectedColor = NULL;
    controller.favoritesTitle = @"My dialog title";
    self.colorPickerViewController = [[UINavigationController alloc] initWithRootViewController:controller];
    
    [self.view addSubview:self.colorPickerViewController.view];
    [self addChildViewController:self.colorPickerViewController];
    //[self presentViewController:controller animated:YES completion:nil];
}

@end
