//
//  VisualizationViewController.h
//  SapanaViewer
//
//  Created by Jan Meier on 04.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol VisualizationViewControllerDelegate <NSObject>

@optional

@required
-(CGRect) expandVisualizationView;
-(CGRect) shrinkVisualizationView;
@end


@interface VisualizationViewController : UIViewController

@property (nonatomic, strong) IBOutlet UITapGestureRecognizer *singleTapRecognizer;
@property (nonatomic, assign) id<VisualizationViewControllerDelegate > delegate;

@property bool expanded;
- (IBAction)singleTap:(UITapGestureRecognizer *)recognizer;

@end
