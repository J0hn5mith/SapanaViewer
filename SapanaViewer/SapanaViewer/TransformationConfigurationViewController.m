//
//  TransformationConfigurationViewController.m
//  SapanaViewer
//
//  Created by Jan Meier on 05.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Class Definition
#import "TransformationConfigurationViewController.h"


// Project Indlcludes
#import "ModelSelectionViewController.h"

// Config
#include "Config.h"

@interface TransformationConfigurationViewController ()

@end

@implementation TransformationConfigurationViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        self.viewIndex = 0;

    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    // Set up page views
    self.pageViews = [NSArray arrayWithObjects: self.rotationViewController, self.translationViewController, self.scalingViewController, self.shearingViewController, nil];
    // Set up table view controller
    
    [self setUpTableView];
    [self setUpPageView];

    [self setNoModelSelected:true];
    // Layout
//    _tableView.layer.cornerRadius = CORNER_RADIUS_TOPIC_SUBSUBVIEW;
//      // TODO Change TASK: BORDER COLOR
//    self.view.layer.borderColor = [UIColor blueColor].CGColor;
//    self.view.layer.borderWidth = 0.5f;
    
    
}

-(void) setUpTableView
{
    [self.tableView setDelegate:self];
}
-(void) setUpPageView
{
    self.pvController = [[UIPageViewController alloc] initWithTransitionStyle:UIPageViewControllerTransitionStyleScroll navigationOrientation:UIPageViewControllerNavigationOrientationHorizontal options:nil];
    
    self.pvController.dataSource = self;
    self.pvController.delegate = self;
    
    [[self.pvController view] setFrame:[self.pageViewContainer frame]];
    NSArray *viewControllers = [NSArray arrayWithObject:[self viewControllerAtIndex:0]];
    
    [self.pvController setViewControllers:viewControllers direction:UIPageViewControllerNavigationDirectionForward animated:NO completion:nil];
    
    [self addChildViewController:self.pvController];
    [self.view addSubview:[self.pvController view]];
    [self.pvController didMoveToParentViewController:self];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
    
}


-(IBAction)nextSubView:(id)sender
{
    [self showSubViewAtPosition:(_viewIndex+1)];
}

-(IBAction)prevSubView:(id)sender
{
    [self showSubViewAtPosition:(_viewIndex-1)];
}

- (void) showSubViewAtPosition:(NSInteger) position
{
    
    if (position < 0)
    {
        position = 0;
    }
    
    if (!(position < self.pageViews.count))
    {
        position = self.pageViews.count -1;
    }
    
    if (position == self.viewIndex)
    {
        return;
    }
    
    
    
    NSArray *viewControllers = [NSArray arrayWithObject:[self viewControllerAtIndex:position]];
    
    [self.pvController setViewControllers:viewControllers direction: UIPageViewControllerNavigationDirectionForward animated:true completion:NULL];
    self.viewIndex = position;
    
    self.viewIndex = position;
}

#pragma mark - Getter and Setter
- (void) setSceneNodeModifier:(SceneNodeModifierWrapper *)sceneNodeModifier;
{
    _sceneNodeModifier = sceneNodeModifier;
    self.tableViewSource = [sceneNodeModifier getTransformationStack];
    [self setNoModelSelected:false];
    [self.tableView setDataSource:self];
    [self.tableView reloadData];
}

-(void) setNoModelSelected:(bool)noModelSelected
{
    if (self.noModelSelected == noModelSelected)
    {
        return;
    }
    
    _noModelSelected = noModelSelected;
    if (noModelSelected)
    {
        // Hide vies and show Message
        [self.tableView setHidden:true];
        [self.pvController.view setHidden:true];
        [self.lineView setHidden:true];
        [self.rearangeButton setHidden:true];
        [self.noModelLabel setHidden:false];
    }
    else
    {
        // Show views and hid message
        [self.tableView setHidden:false];
        [self.pvController.view setHidden:false];
        [self.lineView setHidden:false];
        [self.rearangeButton setHidden:false];
        [self.noModelLabel setHidden:true];
    }
}


#pragma mark - UIPageViewDelegate Methodes
-(void)pageViewController:(UIPageViewController *) pageViewController willTransitionToViewControllers:(NSArray *)pendingViewControllers
{
//    NSInteger newIndex = [self.pageViews indexOfObject:[pendingViewControllers objectAtIndex:0]];
//    
//    self.viewIndex = newIndex;
}

-(void)pageViewController:(UIPageViewController *) pageViewController didFinishAnimating:(BOOL)finished previousViewControllers:(NSArray *)previousViewControllers transitionCompleted:(BOOL)completed
{
    if(completed)
    {
        UIViewController * newController = [pageViewController.viewControllers objectAtIndex:0];
        NSInteger newIndex = [self.pageViews indexOfObject:newController];
        self.viewIndex = newIndex;
    }

}




#pragma mark - UIPageViewDataSource Methodes
-(UIViewController *) pageViewController:(UIPageViewController *)pageViewController viewControllerBeforeViewController:(UIViewController *)viewController
{

    if (self.viewIndex == 0) {
        return nil;
    }
    
    return [self viewControllerAtIndex:self.viewIndex -1];
}

-(UIViewController *) pageViewController:(UIPageViewController *)pageViewController viewControllerAfterViewController:(UIViewController *)viewController
{
    if ((self.viewIndex  + 1) == [self.pageViews count])
    {
        return nil;
    }

    return [self viewControllerAtIndex:self.viewIndex + 1];
    
}

- (UIViewController *)viewControllerAtIndex:(NSUInteger)index {
    
    return [self.pageViews objectAtIndex:index];
}

- (NSInteger)presentationCountForPageViewController:(UIPageViewController *)pageViewController {
    // The number of items reflected in the page indicator.
    return  [self.pageViews count];
}

- (NSInteger)presentationIndexForPageViewController:(UIPageViewController *)pageViewController {
    // The selected item reflected in the page indicator.
    return 0;
}

#pragma mark - Transformation List Action Handlers
-(IBAction)addTransformation:(id)sender
{
    [self.sceneNodeModifier addTransformation];
    self.tableViewSource = [self.sceneNodeModifier getTransformationStack];
    [self.tableView reloadData];
    
    
}

-(IBAction)removeTransformation:(id)sender
{
    self.tableViewSource = [self.sceneNodeModifier getTransformationStack];
    [self.tableView reloadData];
    [self.delegate transformationListModified:false];
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

#pragma mark - UITableViewDelegate Methodes
- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    int numRows = [self.tableViewSource tableView:tableView numberOfRowsInSection:indexPath.section];
    
    if (indexPath.row < numRows)
    {
        [self.sceneNodeModifier setActiveTransformationIndex:(unsigned int)indexPath.row];
    }
    else{
        
        // TODO
        [self.sceneNodeModifier addTransformation];
        self.tableViewSource = [self.sceneNodeModifier getTransformationStack];
        [self tmModified];
        [self.tableView reloadData];
        
        [self.delegate transformationListModified:true];
    }
    
    [self tmSelected];
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

#pragma mark - UITableViewDataSource Methodes
#pragma mark Required
- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:
(NSIndexPath *)indexPath
{
    
    if (![self isSpecialCell:indexPath])
    {
        return [self.tableViewSource tableView:tableView cellForRowAtIndexPath:indexPath];
    }
    else
    {
        UITableViewCell * addTransformationCell = [[UITableViewCell alloc] init];
        addTransformationCell.textLabel.text = @"Add Transformation";
        addTransformationCell.textLabel.textAlignment = NSTextAlignmentCenter;
        // TODO: Put color into config file or else wehre
        addTransformationCell.textLabel.textColor = [UIColor grayColor];
        return addTransformationCell;
    }
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:
(NSInteger)section{
    
    // There is one additional field for adding another transformation matrix
    return [self.tableViewSource tableView:tableView numberOfRowsInSection:section] + 1;
}

#pragma mark Optional
- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return [self.tableViewSource numberOfSectionsInTableView:tableView];
}

- (void)tableView:(UITableView *)tableView commitEditingStyle:(UITableViewCellEditingStyle)editingStyle forRowAtIndexPath:(NSIndexPath *)indexPath
{
    [self.sceneNodeModifier removeTransformation:indexPath.row];
    // TODO: Remove
    self.tableViewSource = [self.sceneNodeModifier getTransformationStack];
    [self.tableView reloadData];
    
    [self.delegate transformationListModified:true];
}

- (BOOL)tableView:(UITableView *)tableView canEditRowAtIndexPath:(NSIndexPath *)indexPath
{
    
    return (![self isSpecialCell:indexPath]);
}


- (BOOL)tableView:(UITableView *)tableView canMoveRowAtIndexPath:(NSIndexPath *)indexPath
{
    return (![self isSpecialCell:indexPath]);
}

- (void)tableView:(UITableView *)tableView moveRowAtIndexPath:(NSIndexPath *)fromIndexPath toIndexPath:(NSIndexPath *)toIndexPath
{
    [self.sceneNodeModifier shiftTransformation:fromIndexPath.row newPosition:toIndexPath.row];
    
    [self.delegate transformationMoved:fromIndexPath.row toPosition:toIndexPath.row];
}

#pragma mark - Transformation Manipulation Action Handlers
-(IBAction)xTranslationChanged:(id)sender
{
    UIStepper * sendingStepper =((UIStepper *) sender);
    [self.sceneNodeModifier translateX:sendingStepper.value];
    sendingStepper.value = 0;
    [self tmModified];
}

-(IBAction)yTranslationChanged:(id)sender
{
    UIStepper * sendingStepper =((UIStepper *) sender);
    [self.sceneNodeModifier translateY:sendingStepper.value];
    sendingStepper.value = 0;
    [self tmModified];
}

-(IBAction)zTranslationChanged:(id)sender
{
    UIStepper * sendingStepper =((UIStepper *) sender);
    [self.sceneNodeModifier translateZ:sendingStepper.value];
    sendingStepper.value = 0;
    [self tmModified];
}

-(IBAction)xRotationChanged:(id)sender
{
    UIStepper * sendingStepper =((UIStepper *) sender);
    [self.sceneNodeModifier rotateX:sendingStepper.value];
    sendingStepper.value = 0;
    [self tmModified];
}

-(IBAction)yRotationChanged:(id)sender
{
    UIStepper * sendingStepper =((UIStepper *) sender);
    [self.sceneNodeModifier rotateY:sendingStepper.value];
    sendingStepper.value = 0;
    [self tmModified];
}

-(IBAction)zRotationChanged:(id)sender
{
    UIStepper * sendingStepper =((UIStepper *) sender);
    [self.sceneNodeModifier rotateZ:sendingStepper.value];
    sendingStepper.value = 0;
    [self tmModified];
}

-(IBAction)xScalingChanged:(id)sender
{
    UIStepper * sendingStepper =((UIStepper *) sender);
    [self.sceneNodeModifier scaleX:sendingStepper.value];
    sendingStepper.value = 1;
    [self tmModified];
}

-(IBAction)yScalingChanged:(id)sender
{
    UIStepper * sendingStepper =((UIStepper *) sender);
    [self.sceneNodeModifier scaleY:sendingStepper.value];
    sendingStepper.value = 1;
    [self tmModified];
}

-(IBAction)zScalingChanged:(id)sender
{
    UIStepper * sendingStepper =((UIStepper *) sender);
    [self.sceneNodeModifier scaleZ:sendingStepper.value];
    sendingStepper.value = 1;
    [self tmModified];
}

-(IBAction)xShearingChanged:(id)sender
{
    UIStepper * sendingStepper =((UIStepper *) sender);
    [self tmModified];
}

-(IBAction)yShearingChanged:(id)sender
{
    UIStepper * sendingStepper =((UIStepper *) sender);
    [self tmModified];
}

-(IBAction)zShearingChanged:(id)sender
{
    UIStepper * sendingStepper =((UIStepper *) sender);
    [self tmModified];
}

#pragma mark - Some Util Methodes


// Returns true if the cell has custom behaviour (is not normal transformation _
-(BOOL) isSpecialCell:(NSIndexPath *)indexPath
{
    return !(indexPath.row < [self.tableViewSource tableView:NULL numberOfRowsInSection:indexPath.section]);
}

-(void) tmSelected
{
    //TODO: Implement case that no matrix is selected
    [self.delegate transformationSelected:YES];
}

-(void) tmModified
{
     [self.delegate transformationModified];
}
@end
