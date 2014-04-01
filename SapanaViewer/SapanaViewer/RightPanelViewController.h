//
//  RightPanelViewController.h
//  SapanaViewer
//
//  Created by Jan Meier on 03.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol RightPanelViewControllerDelegate <NSObject>

@optional

@required

@end

@interface RightPanelViewController : UIViewController

@property (nonatomic, assign) id<RightPanelViewControllerDelegate> delegate;

@end
