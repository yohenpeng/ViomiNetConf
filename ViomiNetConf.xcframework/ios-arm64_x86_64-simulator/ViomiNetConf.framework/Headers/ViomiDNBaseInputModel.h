//
//  ViomiDNBaseInputModel.h
//  ViomiDistriNet
//
//  Created by 彭依汉 on 2021/5/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ViomiDNBaseInputModel : NSObject

@property (copy, nonatomic) NSString *wifiName;

@property (copy, nonatomic) NSString *wifiPassword;

@property (assign, readonly, nonatomic) BOOL isValid;

- (instancetype)initWithWiFiName:(NSString *)name wifiPassword:(NSString *)password;

@end

NS_ASSUME_NONNULL_END
