#import <Foundation/Foundation.h>

@class MSDevice;

@protocol MSLog

/**
 * Log type.
 */
@property(nonatomic, copy) NSString *type;

/**
 * Corresponds to the number of milliseconds elapsed between the time the
 * request is sent and the time the log is emitted.
 */
@property(nonatomic) NSNumber *toffset;

/**
 * A session identifier is used to correlate logs together. A session is an abstract concept in the API and
 * is not necessarily an analytics session, it can be used to only track crashes.
 */
@property(nonatomic, copy) NSString *sid;

/**
 * Device properties associated to this log.
 */
@property(nonatomic) MSDevice *device;

/**
 * Checks if the object's values are valid.
 *
 * @return YES, if the object is valid.
 */
- (BOOL)isValid;

@end
