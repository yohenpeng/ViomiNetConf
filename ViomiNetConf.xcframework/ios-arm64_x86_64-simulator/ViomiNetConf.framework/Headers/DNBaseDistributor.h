//
//  ViomiDNBaseDistributor.h
//  ViomiDistriNet
//
//  Created by 彭依汉 on 2021/5/11.
//

#import <Foundation/Foundation.h>
#import "ViomiDistriNetProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface DNBaseDistributor : NSObject

@property (weak, nonatomic) id<ViomiDistriNetProtocol> requestor;

+ (NSArray<ViomiDNBaseMilestoneModel *>*)milestoneList;

- (void)startDistribute:(id<ViomiDistriNetProtocol>)requestor;

- (void)asyncInMain:(void(^)(void))block;

- (NSString *)getModelWiFi:(NSString *)modelName;

@end

typedef NS_ENUM(NSInteger,CommonDistriErrorType){
    E_CommonDistriErrorType_ParamInvalid = 400, //输入参数非法
    E_CommonDistriErrorType_WiFiInvalid = 401,  //WiFi无效
    E_CommonDistriErrorType_ConnectTimeout = 402, //连接超时
    E_CommonDistriErrorType_Failure = 403,        //通用错误
    E_CommonDistriErrorType_AlreadyBinding = 404,  //已被绑定
    E_CommonDistriErrorType_DataFormatInValid = 405, //数据格式错误
};

NS_ASSUME_NONNULL_END
