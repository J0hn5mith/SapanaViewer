#!/bin/bash
#===============================================================================
#
#          FILE:  build.sh
# 
#         USAGE:  ./build.sh 
# 
#   DESCRIPTION:  
# 
#       OPTIONS:  ---
#  REQUIREMENTS:  ---
#          BUGS:  ---
#         NOTES:  ---
#        AUTHOR:   (), 
#       COMPANY:  
#       VERSION:  1.0
#       CREATED:  19.12.2013 16:14:52 CET
#      REVISION:  ---
#===============================================================================

PROJECT_NAME="SapanaViewerLibrary"
TARGET_NAME="SapanaViewerLibrary"
LIB_NAME="lib"$PROJECT_NAME".a" 
LIB_NAME_COMBINED="lib"$PROJECT_NAME"-Combined.a" 

XCODEBUILD_PATH=/Applications/Xcode.app/Contents/Developer/usr/bin
XCODEBUILD=$XCODEBUILD_PATH/xcodebuild

$XCODEBUILD -project $PROJECT_NAME.xcodeproj -target "$TARGET_NAME" -sdk "iphonesimulator" -configuration "Release" clean build
$XCODEBUILD -project $PROJECT_NAME.xcodeproj -target "$TARGET_NAME" -sdk "iphoneos" -configuration "Release" clean build

lipo -create -output "lib/$LIB_NAME_COMBINED" "build/Release-iphoneos/$LIB_NAME" "build/Release-iphonesimulator/"$LIB_NAME
