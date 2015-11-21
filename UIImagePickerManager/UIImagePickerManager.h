#import "RCTBridgeModule.h"
#import <UIKit/UIKit.h>
#import "ImageCropView.h"

typedef NS_ENUM(NSInteger, RNImagePickerTarget) {
  RNImagePickerTargetCamera = 1,
  RNImagePickerTargetLibrarySingleImage,
};

@interface UIImagePickerManager : NSObject <RCTBridgeModule, UINavigationControllerDelegate, UIActionSheetDelegate, UIImagePickerControllerDelegate, ImageCropViewControllerDelegate>

@end
