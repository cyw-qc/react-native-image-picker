//
//  Created by Ming Yang on 7/7/12.
//

#import <UIKit/UIKit.h>
#import "FXBlurView.h"

#pragma mark ControlPointView interface

@interface ControlPointView : UIView {
    CGFloat red, green, blue, alpha;
}

@property (nonatomic, retain) UIColor* color;

@end

#pragma mark ShadeView interface
@interface BlurredImageView : UIImageView
@end

@interface ShadeView : UIView {
    CGFloat cropBorderRed, cropBorderGreen, cropBorderBlue, cropBorderAlpha;
    CGRect cropArea;
    CGFloat shadeAlpha;
}

@property (nonatomic, retain) UIColor* cropBorderColor;
@property (nonatomic) CGRect cropArea;
@property (nonatomic) CGFloat shadeAlpha;
@property (nonatomic, strong) BlurredImageView *blurredImageView;

@end


CGRect SquareCGRectAtCenter(CGFloat centerX, CGFloat centerY, CGFloat size);

UIView* dragView;
typedef struct {
    CGPoint dragStart;
    CGPoint topLeftCenter;
    CGPoint bottomLeftCenter;
    CGPoint bottomRightCenter;
    CGPoint topRightCenter;
    CGPoint clearAreaCenter;
} DragPoint;

// Used when working with multiple dragPoints
typedef struct {
    DragPoint mainPoint;
    DragPoint optionalPoint;
    NSUInteger lastCount;
} MultiDragPoint;

#pragma mark ImageCropView interface

@interface CropAreaView : UIView
@end

@interface ImageCropView : UIView {
    UIImageView* imageView;
    CGRect imageFrameInView;
    CGFloat imageScale;
    
    CGFloat controlPointSize;
    ControlPointView* topLeftPoint;
    ControlPointView* bottomLeftPoint;
    ControlPointView* bottomRightPoint;
    ControlPointView* topRightPoint;
    NSArray *PointsArray;
    UIColor* controlColor;

    CropAreaView* cropAreaView;
    DragPoint dragPoint;
    MultiDragPoint multiDragPoint;
    
    UIView* dragViewOne;
    UIView* dragViewTwo;
  
//  CGFloat widthFactor;
//  CGFloat heightFactor;
  
  BOOL resizeAble;
}
- (id)initWithFrame:(CGRect)frame blurOn:(BOOL)blurOn;
- (void)setImage:(UIImage*)image;

@property (nonatomic) CGFloat controlPointSize;
@property (nonatomic, retain) UIImage* image;
@property (nonatomic) CGRect cropAreaInView;
@property (nonatomic) CGRect cropAreaInImage;
@property (nonatomic, readonly) CGFloat imageScale;
@property (nonatomic) CGFloat maskAlpha;
@property (nonatomic, retain) UIColor* controlColor;
@property (nonatomic, strong) ShadeView* shadeView;
@property (nonatomic) BOOL blurred;
@property (nonatomic) BOOL resizeAble;

//长宽的比例
@property (nonatomic) CGFloat widthFactor;
@property (nonatomic) CGFloat heightFactor;

@end

#pragma mark ImageCropViewController interface
@protocol ImageCropViewControllerDelegate <NSObject>

- (void)ImageCropViewController:(UIViewController* )controller didFinishCroppingImage:(UIImage *)croppedImage;
- (void)ImageCropViewControllerDidCancel:(UIViewController *)controller;

@end

@interface ImageCropViewController : UIViewController  <UIActionSheetDelegate > {
    ImageCropView * cropView;
    UIActionSheet * actionSheet;
}
@property (nonatomic, weak) id<ImageCropViewControllerDelegate> delegate;
@property (nonatomic) BOOL blurredBackground;
@property (nonatomic, retain) UIImage* image;
@property (nonatomic, retain) ImageCropView* cropView;
//长宽的比例
@property (nonatomic) CGFloat widthFactor;
@property (nonatomic) CGFloat heightFactor;


- (id)initWithImage:(UIImage*)image;
- (IBAction)cancel:(id)sender;
- (IBAction)done:(id)sender;

@end

@interface UIImage (fixOrientation)

- (UIImage *)fixOrientation;

@end

