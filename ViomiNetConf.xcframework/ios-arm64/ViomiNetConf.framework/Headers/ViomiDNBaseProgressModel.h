//
//  ViomiDNBaseProgressModel.h
//  ViomiDistriNet
//
//  Created by 彭依汉 on 2021/5/11.
//

#import <Foundation/Foundation.h>
#import "ViomiDNBaseMilestoneModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface ViomiDNBaseProgressModel : NSObject

@property (assign, nonatomic) float progress;

@property (strong, nonatomic, nullable) NSNumber *milestoneIndexNum;

@property (assign, nonatomic) BOOL isFinish;

@property (strong, nonatomic, nullable) NSError* fatalError;

- (instancetype)initWithProgress:(float)progress milestoneIndex:(nullable NSNumber *)num isFinish:(BOOL)finish error:(nullable NSError*)error;

@end

NS_ASSUME_NONNULL_END
