//
//  VIOTBLEConstant.h
//  WaterPurifier
//
//  Created by 谢立颖 on 2020/9/19.
//  Copyright © 2020 Viomi. All rights reserved.
//

#ifndef VIOTBLEConstant_h
#define VIOTBLEConstant_h

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, VIOTBLEConnProgress) {
    VIOTBLEConnProgressInit = 2,                    // 初始进度
    VIOTBLEConnBLESucc = 4,                         // 蓝牙连接成功
    VIOTBLEConnBLEDiscoveryServer = 6,              // 发现蓝牙服务
    VIOTBLEConnBLEProtocolOpen = 8,                 // 打开读写协议
    VIOTBLEConnProgressDeviceAuthed = 20,           // 完成安全校验，开始发送 Wi-Fi 等信息给固件
    VIOTBLEConnProgressSendWifiInfo = 36,           // 固件成功接收到WiFi等信息，等待固件配网确认信息正确
    VIOTBLEConnProgressReceivedSuccRes = 40,        // 固件确认WiFi等信息正确，APP开始mdns和udp查询配网结果
    VIOTBLEConnProgressDone = 100,                  // 设备完成全部配网流程
};

typedef NS_ENUM(NSUInteger, VIOTBLEConnStatus) {
    VIOTBLEConnWiFi = 40,                           // 设备已连上 Wi-Fi
    VIOTBLEConnDone = 99,                           // 只有部分设备配网成功
    VIOTBLEConnSucc = 100,                          // 全部设备配网成功
    VIOTBLEConnFail = -100,                         // 全部设备配网失败
    
    VIOTBLEConnErrorTimeout = -1,                   // 超时
    VIOTBLEConnErrorBLEOff = -2,                    // 蓝牙未打开
    VIOTBLEConnErrorSendDataFail = -3,              // 无法发送蓝牙数据
    VIOTBLEConnErrorDeviceAuthedFail = -4,          // 设备校验失败
    VIOTBLEConnErrorDeviceDisconnect = -5,          // 设备断开连接
    VIOTBLEConnErrorWiFiPwdError = -10,             // Wi-Fi 密码错误
    VIOTBLEConnError5GWiFiError = -12,              // 无法连接 5G Wi-Fi
    VIOTBLEConnErrorDeviceReleaseFail = -20,        // 设备上线失败
    VIOTBLEConnErrorFetchUserTokenFail = -21,       // 无法获取用户 token
    VIOTBLEConnErrorOther = -98,                    // 其它错误
    VIOTBLEConnErrorUnknown = -99,                  // 未知错误
};

#endif /* VIOTBLEConstant_h */
