//
//  ViomiBleDistributor.h
//  ViomiDistriNet
//
//  Created by 彭依汉 on 2021/5/11.
//

#import "DNBaseDistributor.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger,ViomiBleErrorType){
    ViomiBle_DeviceNotFound = 3001, //无法搜索到设备
    ViomiBle_ParamInvalid = 3005,  //配网数据不合法
    ViomiBle_BluetoothConnectTimeOut = 3201,  //蓝牙连接超时失败
    ViomiBle_BluetoothPeripheralEmpty = 3202,  //蓝牙外设实例为空
    ViomiBle_BluetoothDisconnect = 3203,  //蓝牙已断开链接
    ViomiBle_BluetoothDisable = 3204,  //蓝牙未启用
    ViomiBle_BluetoothCannotBeNotify = 3205,  //读属性无法订阅
    ViomiBle_BluetoothSubscribeNotifyFail = 3206,  //读属性订阅失败
    ViomiBle_SendNegotiateDataFail = 3207,  //发送协商数据失败
    ViomiBle_SendWiFiPwdFail = 3208,  //向设备发送配网信息失败
    ViomiBle_ReponseSequenceVerify = 3209,  //接收的设备数据Sequence校验失败
    ViomiBle_PackageLengthVerifyFail = 3210,  //接收的数据包长度校验失败
    ViomiBle_PackageCRCVerifyFail = 3211,  //接收的数据包CRC校验失败
    ViomiBle_UnsupportMainType = 3212,  //接收的数据包含有不支持的MainType类型
    ViomiBle_NegotiateDataToStringFail= 3213,  //接收的设备协商数据包转String失败
    ViomiBle_DeviceCloudVerifyFail = 3214,  //设备云端校验失败
    ViomiBle_DeviceOPStateException = 3215,  //设备OP状态异常
    ViomiBle_DeviceConnectWiFiFail = 3216,  //设备连接WiFi失败
    ViomiBle_WiFiPasswordError = 3217,  //Wi-Fi 密码错误
    ViomiBle_RouterError = 3218,  //路由器错误
    ViomiBle_CannotConnect5GWiFi = 3219,  //无法连接 5G Wi-Fi错误
    ViomiBle_FetchBindingDeviceTimeout = 3220,  //发送配网信息后扫描设备超时失败
    ViomiBle_UnknownError = 3221, //未知错误
    ViomiBle_SendACKResponseFail = 3222, //回复ACK包失败
    
    ViomiBle_BluetoothResponse_LoginFail = 3300,  //蓝牙获取设备上线状态，上线失败
    ViomiBle_BluetoothResponse_FetchTokenFail = 3301,  //蓝牙获取设备上线状态，设备获取用户token失败
    ViomiBle_BluetoothResponse_UnknownError = 3302,  //蓝牙获取设备上线状态，未知错误
};


@class ViomiBleInputModel;
@class ViomiBleProgressModel;
@class VIOTBLEDeviceModel;

@protocol ViomiBleDistributorProtocol <ViomiDistriNetProtocol>

@required
/// 配网输入参数
@property (strong, nonatomic, nullable) __kindof ViomiBleInputModel *inputModel;
/// 配网回调刷新Block
@property (copy, nonatomic, nullable) void(^progressUpdateBlock)(__kindof ViomiBleProgressModel *model);

@end


@interface ViomiBleDistributor : DNBaseDistributor

- (void)startDistribute:(id<ViomiBleDistributorProtocol>)requestor;

@end

#pragma mark ---------- 输入和输出
@interface ViomiBleInputModel : ViomiDNBaseInputModel

@property (copy, nonatomic) NSString *viomiUserId;

@property (copy, nonatomic) NSString *meshId;

@property (copy, nonatomic) NSString *meshHost;

@property (strong, nonatomic) VIOTBLEDeviceModel *rootDevice;

@property (copy, nonatomic) NSArray<VIOTBLEDeviceModel *> *deviceList;

- (instancetype)initWithWiFiName:(NSString *)name wifiPassword:(NSString *)password meshId:(NSString *)meshId meshHost:(NSString *)meshHost rootDevice:(VIOTBLEDeviceModel *)rootDevice deviceList:(NSArray<VIOTBLEDeviceModel *>*)deviceList viomiUserId:(NSString *)viomiUserId;

@end

@interface ViomiBleProgressModel : ViomiDNBaseProgressModel

//全部成功或者部分成功fatalError为空，全部成功则connectFailedDevices为nil，connectFailedDevices不为nil则部分成功
//全部失败则错误原因在fatalError，ErrorCode见ViomiBleDistriErrorType
@property (copy, nonatomic, nullable) NSArray<VIOTBLEDeviceModel *>* connSuccDevices;

@property (copy, nonatomic, nullable) NSArray<VIOTBLEDeviceModel *>* connectFailedDevices;

@end


typedef NS_ENUM(NSInteger,ViomiBleDistriErrorType){
    E_ViomiBleDistriErrorType_AllFail = 500, //全部失败
    E_ViomiBleDistriErrorType_WiFiPwd,       //WiFi密码错误
    E_ViomiBleDistriErrorType_5GWiFi,        //5GWiFi错误
    E_ViomiBleDistriErrorType_OtherException,//配网其他异常
};

NS_ASSUME_NONNULL_END
