//
//  VIOTBLEDeviceModel.h
//  ViomiIoTKit
//
//  Created by 谢立颖 on 2020/7/14.
//  Copyright © 2020 viomi. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, VIOTBLEType) {
    VIOTBLETypeNormalBLE = 1,       // 普通蓝牙
    VIOTBLETypeCombo = 2,           // 蓝牙 Wi-Fi 双模
    VIOTBLETypeMesh = 3,            // 蓝牙 Wi-Fi 双模 Mesh
    VIOTBLETypeAndroidBLE = 4,      // Android 屏蓝牙
    VIOTBLETypeMeshSubDevice = 100, // BLE Mesh 子设备
};

@interface VIOTBLEDeviceModel : NSObject

@property(nonatomic, assign) VIOTBLEType bleType;
@property(nonatomic, copy) NSString *model;
@property(nonatomic, copy) NSString *mac;
@property(nonatomic, copy) NSString *UUID;
@property(nonatomic, copy) NSString *name;
@property(nonatomic, copy) NSString *localName;     // 取自蓝牙广播数据的 0x09（local name）字段
@property(nonatomic, copy) NSString *iconUrl;
@property(nonatomic, copy) NSString *did;
@property(nonatomic, assign) NSUInteger pid;
@property(nonatomic, assign) NSInteger RSSI;
@property(nonatomic, assign) NSInteger version;
@property(nonatomic, assign) BOOL isSupportOneKeyConfig;    // 是否支持一键配网
@property(nonatomic, assign) NSInteger sequeue;

@end

NS_ASSUME_NONNULL_END
