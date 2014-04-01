//
//  HierarchicalListItem.h
//  SapanaViewer
//
//  Created by Jan Meier on 17.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//


// External Includes
#import <Foundation/Foundation.h>

@interface HierarchicalListItemWrapper : UITableViewCell

#pragma mark - GUI Elements
@property UIView * content;
@property UILabel * valueLabel;
@property UILabel * expandedLabel;

@property int level;
@property bool expanded;
@property NSString *  labelText;


- (id)initWithStyle:(UITableViewCellStyle)style
    reuseIdentifier:(NSString *)reuseIdentifier
             level_:(NSUInteger)level
          expanded_:(BOOL)expanded
            nodeID_:(unsigned long) nodeID;

- (UILabel *)newLabelWithPrimaryColor:(UIColor *)primaryColor selectedColor:(UIColor *)selectedColor fontSize:(CGFloat)fontSize bold:(BOOL)bold;

@end
