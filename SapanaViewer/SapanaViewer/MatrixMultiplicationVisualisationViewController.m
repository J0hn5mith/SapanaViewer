    //
//  MatrixMultiplicationVisualisationViewController.m
//  SapanaViewer
//
//  Created by Jan Meier on 23.03.14.
//  Copyright (c) 2014 Visualization and MultiMedia Lab, University of Zurich, Switzerland. All rights reserved.
//

// Class Definition
#import "MatrixMultiplicationVisualisationViewController.h"


@interface MatrixMultiplicationVisualisationViewController ()

@end

@implementation MatrixMultiplicationVisualisationViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
        self.matrixViews = [[NSMutableArray alloc]init];
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    
    // Set up Scroll view
    [self.scrollView setScrollEnabled:YES];
    [self.scrollView setFrame:self.view.frame];
    [self.scrollView setContentSize:self.contentView.frame.size];
    self.scrollView.delegate = self;
    [self.scrollView setFrame:self.view.frame];
    
    
    // Parse prototypes from xib
    self.matrixFrame = self.matrixPrototype.frame;
    
    self.spaceFrame = self.spaceLabelPrototype.frame;
    self.spaceLabelFont = self.spaceLabelPrototype.font;
    self.spaceLabelTextColor = self.spaceLabelPrototype.textColor;
    self.spaceLabelTextAlignment = self.spaceLabelPrototype.textAlignment;
    
    self.matrixLabelFrame = self.matrixLabelPrototype.frame;
    self.matrixLabelFont = self.matrixLabelPrototype.font;
    self.matrixLabelTextColor = self.matrixLabelPrototype.textColor;
    self.matrixLabelTextAlignment = self.matrixLabelPrototype.textAlignment;
    
    
    [self.matrixPrototype removeFromSuperview];
    [self.spaceLabelPrototype removeFromSuperview];
    
    // Set scale that first matrix fits
    [self.scrollView setZoomScale:0.9];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - UIScrollViewDelegate Implementation

- (UIView *)viewForZoomingInScrollView:(UIScrollView *)scrollView
{
    return self.contentView;
}

- (void)scrollViewDidZoom:(UIScrollView *)scrollView
{
    [self centerScrollViewContent:scrollView];
}

#pragma mark - Content Controll Methodes
-(void) refreshMatrices:( NSArray *) newMatrices
{
    if (newMatrices && [newMatrices count] > 0)
    {
        // Delete the previous matrixViews
        self.matrixViews = [[NSMutableArray alloc]init];
        
        NSInteger matrixWidth = self.matrixFrame.size.width; // TODO: Get this value from different place
        NSInteger matrixOffset = self.spaceFrame.size.width;
        NSInteger matrixWidthWithOffset = matrixWidth + matrixOffset;
        
        // Remove all matrices from center view
        [[self.centeredView subviews] makeObjectsPerformSelector:@selector(removeFromSuperview)];
        

        
        int matrixCounter = 0;
        const int numMatrices = [newMatrices count];
        
        for (TransMatrix * matrix in newMatrices)
        {
            
            int offset = (matrixWidthWithOffset * (matrixCounter));
            [self addMatrix:matrix xOffset:offset ];
            [self addMatrixLabel:matrix.label xOffset:offset ];
            if (matrixCounter == 0)
            {
                
                // Add = sign
                [self addSpaceWithLabel:@"=" xOffset:0];
            }
            else if (matrixCounter == (numMatrices -1))
            {
                // Last item has no sign
            }
            else
            {

                [self addSpaceWithLabel:@"x" xOffset:offset];
                
            }

            
            
            matrixCounter++;
        }
        
        CGRect newCVSize = self.contentView.frame;
        newCVSize.size.width = ((numMatrices +1) * matrixWidthWithOffset)*self.scrollView.zoomScale;
        [self.contentView setFrame:newCVSize];
        [self.scrollView setContentSize:newCVSize.size];
        
    }
}

#pragma mark - Util Methodes for Creating the Matrices
-(MatrixViewController *) addMatrix:(TransMatrix *)matrix xOffset:(int)xOffset
{
    MatrixViewController * resultMatrix = [[MatrixViewController alloc] init];
    [self.matrixViews addObject:resultMatrix.view];
    [self.centeredView addSubview:resultMatrix.view];
    [resultMatrix updateWithMatrix:matrix];
    
    // Set up frame
    CGRect frame = self.matrixFrame;
    frame.origin.x += xOffset;
    [resultMatrix.view setFrame:frame];
    
    return resultMatrix;
}


-( UILabel *) addSpaceWithLabel:(NSString * )label xOffset:(int)xOffset
{
    UILabel * spaceWithLabel = [[UILabel alloc] init];
    [self.centeredView addSubview:spaceWithLabel];
    
    [spaceWithLabel setText:label];
    [spaceWithLabel setTextColor:self.spaceLabelTextColor];
    [spaceWithLabel setBackgroundColor:[UIColor clearColor]];
    [spaceWithLabel setFont:self.spaceLabelFont];
    [spaceWithLabel setTextAlignment: self.spaceLabelTextAlignment];
    
    // Adjust frame
    CGRect frame = self.spaceFrame;
    frame.origin.x += xOffset;
    [spaceWithLabel setFrame:frame];
    
    return spaceWithLabel;
}

-( UILabel *) addMatrixLabel:(NSString * )label xOffset:(int)xOffset
{
    UILabel * matrixLabel = [[UILabel alloc] init];
    [self.centeredView addSubview:matrixLabel];
    
    [matrixLabel setText:label];
    [matrixLabel setTextColor:self.matrixLabelTextColor];
    [matrixLabel setBackgroundColor:[UIColor clearColor]];
    [matrixLabel setFont:self.matrixLabelFont];
    [matrixLabel setTextAlignment: self.matrixLabelTextAlignment];
    
    // Adjust frame
    CGRect frame = self.matrixLabelFrame;
    frame.origin.x += xOffset;
    [matrixLabel setFrame:frame];
    
    return matrixLabel;
}

#pragma mark UIScrollViewDelegate Implementation Utils
// Update the scrolled view (self.contentViewController.view) to be centered. Coppied from http://stackoverflow.com/questions/1316451/center-content-of-uiscrollview-when-smaller
-(void) centerScrollViewContent:(UIScrollView *)scrollView
{
    UIView *subView = [scrollView.subviews objectAtIndex:0];
    
    CGFloat offsetX = (scrollView.bounds.size.width > scrollView.contentSize.width)?
    (scrollView.bounds.size.width - scrollView.contentSize.width) * 0.5 : 0.0;
    
    
    CGFloat offsetY = (scrollView.bounds.size.height > scrollView.contentSize.height)?
    (scrollView.bounds.size.height - scrollView.contentSize.height) * 0.5 : 0.0;
    
    subView.center = CGPointMake(scrollView.contentSize.width * 0.5 + offsetX,
                                 scrollView.contentSize.height * 0.5 + offsetY);
}

@end
