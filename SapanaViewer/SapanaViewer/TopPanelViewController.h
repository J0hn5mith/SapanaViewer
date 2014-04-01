//
//  TopPanelViewController.h
//  SapanaViewer
//
//  Created by Jan Meier on 04.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol TopPanelViewControllerDelegate <NSObject>

@optional


@required


@end
@interface TopPanelViewController : UIViewController

@property (nonatomic, assign) id<TopPanelViewControllerDelegate> delegate;

@end
