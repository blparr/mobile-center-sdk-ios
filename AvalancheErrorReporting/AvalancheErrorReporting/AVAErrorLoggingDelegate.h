#import <Foundation/Foundation.h>

@class AVAErrorReport;
@class AVAErrorReporting;
@class AVAErrorAttachment;

@protocol AVAErrorLoggingDelegate <NSObject>

@optional

/**
 * Callback method to check if the crash should be processed by the SDK.
 * @param errorReporting instance of AVAErrorReporting.
 * @param errorReport object with error specific information. Use this to
 * determine if
 * the crash should be processed by the SDK.
 * @return YES if the SDK should process the crash, NO if you don't want it to
 * be sent to the server.
 */
- (BOOL)errorReporting:(AVAErrorReporting *)errorReporting shouldProcess:(AVAErrorReport *)errorReport;

/**
 * Create an AVAErrorAttachment that will be attached to the error report.
 * @param errorReporting instance of AVAErrorReporting.
 * @param errorReport The error report for the attachment.
 * @return instance of AVAErrorAttachment for custom data that the dev wants to
 * attach to the error.
 */
- (AVAErrorAttachment *)attachmentWithErrorReporting:(AVAErrorReporting *)errorReporting
                                      forErrorReport:(AVAErrorReport *)errorReport;

/**
 * Callback method that will be called before each error will be send to the
 * server.
 * @param instance of AVAErrorReporting.
 */
- (void)errorReportingWillSend:(AVAErrorReporting *)errorReporting;

/**
 * Callback that will be called for each single error report if all retries have
 * been used and sending an error has failed.
 * @param errorReporting the instance of AVAErrorReporting.
 * @param errorReport The error report that couldn't be send.
 * @param error The error object.
 */
- (void)errorReporting:(AVAErrorReporting *)errorReporting
        didFailSending:(AVAErrorReport *)errorReport
             withError:(NSError *)error;

/**
 * Callback that will be called for each single error report as the report was
 * sent to the server successfully.
 * @param errorReporting the instance of AVAErrorReporting.
 * @param errorReport The error report that was successfully sent.
 */
- (void)errorReporting:(AVAErrorReporting *)errorReporting didSucceedSending:(AVAErrorReport *)errorReport;

@end