//
//  TransformationConfigurationViewController.h
//  SapanaViewer
//
//  Created by Jan Meier on 05.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Base Class
#import "ConfigurationViewController.h"

// Project Indcludes
#import "SceneNodeModifierWrapper.h"
#import "ListWrapper.h"

@protocol TransformationConfigurationViewControllerDelegate <NSObject>

@required
// The matrix selected flag is used to tell the delegate, that currently no matrix is selected.
-(void) transformationSelected:(BOOL) matrixSelected;

-(void) transformationModified;

-(void) transformationMoved:(NSInteger)fromPosition toPosition:(NSInteger ) toPosition;

-(void) transformationListModified:(BOOL) matrixAdded; //If false, a matrix was removed

@end
/**
 * The TransformationConfigurationViewController wraps the tableViewSource
 * because deleting the entries can not be handled there.
 */
@interface TransformationConfigurationViewController : ConfigurationViewController < UIPageViewControllerDataSource, UIPageViewControllerDelegate, UITableViewDataSource, UITableViewDelegate >



#pragma mark - Member Variables
@property (nonatomic) SceneNodeModifierWrapper * sceneNodeModifier;
@property (nonatomic, assign) id< TransformationConfigurationViewControllerDelegate > delegate;

#pragma mark - View Related Member Variables
@property NSInteger viewIndex;
@property NSArray * pageViews;

#pragma mark - Views and View Controllers
@property UIPageViewController * IBOutlet pvController;
@property ListWrapper * tableViewSource;
@property (weak, nonatomic) IBOutlet UITableView *tableView;
@property (weak, nonatomic) IBOutlet UIView *pageViewContainer;
@property (weak, nonatomic) IBOutlet UIView *lineView;
@property (weak, nonatomic) IBOutlet UIView *noModelLabel;

@property (strong, nonatomic) IBOutlet UIViewController * rotationViewController;
@property (strong, nonatomic) IBOutlet UIViewController * translationViewController;
@property (strong, nonatomic) IBOutlet UIViewController * scalingViewController;
@property (strong, nonatomic) IBOutlet UIViewController * shearingViewController;

#pragma mark - GUI Components
@property (weak, nonatomic) IBOutlet UIButton *prevButton;
@property (weak, nonatomic) IBOutlet UIButton *nextButton;
@property (weak, nonatomic) IBOutlet UIButton *rearangeButton;

#pragma mark - GUI Component Management
@property (nonatomic) bool noModelSelected;


#pragma mark - GUI Action Handlers
-(IBAction)nextSubView:(id)sender;
-(IBAction)prevSubView:(id)sender;

#pragma mark - Transformation List Action Handlers
-(IBAction)addTransformation:(id)sender;
-(IBAction)removeTransformation:(id)sender;
-(IBAction)rearagneButton:(id)sender;

#pragma mark - Transformation Manipulation Action Handlers
-(IBAction)xTranslationChanged:(id)sender;
-(IBAction)yTranslationChanged:(id)sender;
-(IBAction)zTranslationChanged:(id)sender;

-(IBAction)xRotationChanged:(id)sender;
-(IBAction)yRotationChanged:(id)sender;
-(IBAction)zRotationChanged:(id)sender;

-(IBAction)xScalingChanged:(id)sender;
-(IBAction)yScalingChanged:(id)sender;
-(IBAction)zScalingChanged:(id)sender;

-(IBAction)xShearingChanged:(id)sender;
-(IBAction)yShearingChanged:(id)sender;
-(IBAction)zShearingChanged:(id)sender;
@end
