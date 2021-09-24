//
//  ViomiNetConfManager.h
//  ViomiNetConf
//
//  Created by 彭依汉 on 2021/9/13.
//

#import <Foundation/Foundation.h>
#import "VIOTBLEConstant.h"
#import "VIOTBLEDeviceModel.h"

NS_ASSUME_NONNULL_BEGIN

typedef void(^BLEScanSuccHandler)(VIOTBLEDeviceModel * _Nullable device);
typedef void(^BLEScanFailHandler)(VIOTBLEConnStatus status, NSString * _Nullable desc);
typedef void(^BLEScanFinishedHandler)(void);
typedef void(^BLEPairFinishedHandler)(NSError * _Nullable error, NSArray<VIOTBLEDeviceModel *>* _Nullable succDevices,NSArray<VIOTBLEDeviceModel *>* _Nullable failedDevices);
typedef void(^UploadLogFinishedHandler)(NSError * _Nullable error);

@protocol ViomiNetConfManagerProtocol <NSObject>

- (void)syncUserResult:(nullable NSError *)error;

@end

@interface ViomiNetConfManager : NSObject

+ (instancetype)shareManager;

/// 初始化结果回调代理
@property (weak ,nonatomic, nullable) id<ViomiNetConfManagerProtocol> delegate;


/// SDK 初始化
/// @param appKey AppKey
/// @param appSecret AppSecret
- (void)initSDKWithAppKey:(NSString *)appKey appSecret:(NSString *)appSecret;


/// SDK 同步用户信息
/// @param token 用户 token
/// @param viomiUserId 用户 id
/// @param testEnv 判断是否使用测试环境
/// @param appIdForLog 打印Id
/// @param appIdForSDK 第三方厂商Id
/// @param isViomiOAuth 当前token是否使用云米OAuth授权登录后获取
- (void)syncUserWithToken:(NSString *)token viomiUserId:(NSString *)viomiUserId testEnv:(BOOL)testEnv appIdForLog:(NSString *)appIdForLog appIdForSDK:(NSString *)appIdForSDK isViomiOAuth:(BOOL)isViomiOAuth;


///  扫描蓝牙设备
/// @param succHandler <#succHandler description#>
/// @param failHandler <#failHandler description#>
/// @param finishedHandler <#finishedHandler description#>
/// @param timeout <#timeout description#>
- (void)startScanWithSuccHandler:(BLEScanSuccHandler _Nullable)succHandler
                     failHandler:(BLEScanFailHandler _Nullable)failHandler
                 finishedHandler:(BLEScanFinishedHandler _Nullable)finishedHandler
                         timeout:(NSUInteger)timeout;

/// 停止扫描
- (void)stopScan;

/// 配网结束
- (void)deinitBleManager;

/// <#Description#>
/// @param name <#name description#>
/// @param password <#password description#>
/// @param rootDevice <#rootDevice description#>
/// @param deviceList <#deviceList description#>
/// @param finishedHandler <#finishedHandler description#>
- (void)startPairWthWiFiName:(NSString *)name wifiPassword:(NSString *)password rootDevice:(VIOTBLEDeviceModel *)rootDevice deviceList:(NSArray<VIOTBLEDeviceModel *>*)deviceList finishedHandler:(BLEPairFinishedHandler _Nullable)finishedHandler;


/// 上传日志
/// @param completeBlock <#completeBlock description#>
- (void)uploadLog:(UploadLogFinishedHandler _Nullable)completeBlock;

@end

NS_ASSUME_NONNULL_END
