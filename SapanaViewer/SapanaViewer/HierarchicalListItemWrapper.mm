//
//  HierarchicalListItem.m
//  SapanaViewer
//
//  Created by Jan Meier on 17.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

#import "HierarchicalListItemWrapper.h"
#import "Config.h"
// TODO: Remove
#define IMG_HEIGHT_WIDTH 20
#define CELL_HEIGHT 44
#define SCREEN_WIDTH 320
#define LEVEL_INDENT 32
#define YOFFSET 12
#define XOFFSET 6

@implementation HierarchicalListItemWrapper

- (id)initWithStyle:(UITableViewCellStyle)style
    reuseIdentifier:(NSString *)reuseIdentifier
             level_:(NSUInteger)level
          canExpand_:(BOOL)canExpand
          expanded_:(BOOL)expanded
            nodeID_:(unsigned long) nodeID
{
    self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
    
    if (self)
    {
        
        _level = level;
        _canExpand = canExpand;
        _expanded = expanded;
       
        self.valueLabel =  [[UILabel alloc] initWithFrame:CGRectZero];
        self.valueLabel.font = TABLE_FONT;
        self.valueLabel.numberOfLines = 0;
        self.valueLabel.textAlignment = NSTextAlignmentLeft;
//        [self
//         newLabelWithPrimaryColor:[UIColor blackColor]
//         selectedColor:[UIColor whiteColor]
//         fontSize:20.0
//         bold:false];
        
       
        
        self.expandedLabel = [[UILabel alloc] initWithFrame:CGRectZero];
        self.expandedLabel.font = TABLE_FONT;
        self.expandedLabel.numberOfLines = 0;
        
        UIView * content = self.contentView;
        [content addSubview:self.valueLabel];
        
        if( self.canExpand)
        {
            self.expandedLabel.text = self.expanded ? @"+" : @"-";
            [content addSubview:self.expandedLabel];
        }
        
    }
    return self;
}

- (void)layoutSubviews
{
    [super layoutSubviews];
    if (!self.editing)
    {
        CGRect contentRect = self.contentView.bounds;
        CGFloat boundsX = contentRect.origin.x;
        
        CGRect labelFrame = CGRectMake((boundsX + self.level + 1) * LEVEL_INDENT,
                                                       0,
                                                       SCREEN_WIDTH - (self.level * LEVEL_INDENT),
                                                       CELL_HEIGHT);
        labelFrame.origin.x = labelFrame.origin.x;
        [self.valueLabel setFrame:labelFrame];
        
        CGRect expandedFrame;
        expandedFrame = CGRectMake(((boundsX + self.level + 1) * LEVEL_INDENT) - (IMG_HEIGHT_WIDTH + XOFFSET),
                              YOFFSET,
                              IMG_HEIGHT_WIDTH,
                              IMG_HEIGHT_WIDTH);
        self.expandedLabel.frame = expandedFrame;
        
        //[content release];
    }
    else
    {
//        self.valueLabel.text = @"EDITING";
    }
}
    
- (UILabel *) newLabelWithPrimaryColor:(UIColor *)primaryColor selectedColor:(UIColor *)selectedColor fontSize:(CGFloat)fontSize bold:(BOOL)bold
{
    UIFont *font;
    if (bold) {
        font = [UIFont boldSystemFontOfSize:fontSize];
    } else {
        font = [UIFont systemFontOfSize:fontSize];
    }
    
    UILabel *newLabel = [[UILabel alloc] initWithFrame:CGRectZero];
    newLabel.backgroundColor = [UIColor whiteColor];
    newLabel.opaque = YES;
    newLabel.textColor = primaryColor;
    newLabel.highlightedTextColor = selectedColor;
    newLabel.font = font;
    newLabel.numberOfLines = 0;
    
    return newLabel;
}

UILabel *newLabel = [[UILabel alloc] initWithFrame:CGRectZero];

@end


