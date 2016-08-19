//
//  IOSNDKHelper.cpp
//  EasyNDK-for-cocos2dx
//
//  Created by Amir Ali Jiwani on 23/02/2013.
//
//

#import "IOSNDKHelper.h"
#import "NDKHelper.h"

#pragma mark -
#pragma mark Private To IOSNDKHelper.mm

static NSObject *helperInstance = nil;

void IOSNDKHelperImpl::setNDKReceiver(void *receiver)
{
    helperInstance = (NSObject *)receiver;
}

NSObject *getHelperInstance()
{
    return helperInstance;
}

#pragma mark -
#pragma mark IOSNDKHelperImpl Methods

void IOSNDKHelperImpl::receiveCPPMessage(const char *methodName, const char *methodParams)
{
    NSObject *receiver = getHelperInstance();
    if (receiver == nil) {
        return;
    }
    
    if (methodName == NULL) {
        return;
    }
    
    const char *methodCalled = methodName;//json_string_value(methodName);
    NSString *methodCalledStr = [NSString stringWithFormat:@"%@:", [NSString stringWithUTF8String:methodCalled]];
    NSLog(@"%@", methodCalledStr);
    SEL selectorToBeCalled;
    
    @try {
        selectorToBeCalled = NSSelectorFromString(methodCalledStr);
        
        // Return from message if the selector won't respond to our receiver
        if (![receiver respondsToSelector:selectorToBeCalled]) {
            NSLog(@"Receiver won't respond to selector : %@", methodCalledStr);
            return;
        }
    } @catch (NSException *e) {
        NSLog(@"Exception trying to find selector to be called : %@", methodCalledStr);
        return;
    }
    
    if (methodParams != NULL) {
        // Convert the parameters into NSDictionary
//        char *jsonStrLocal = json_dumps(methodParams, JSON_COMPACT | JSON_ENSURE_ASCII);
        NSString *methodParamsJson = [[NSString alloc] initWithUTF8String:methodParams];
//        free(jsonStrLocal);
        
        NSData *jsonData = [methodParamsJson dataUsingEncoding:NSUTF8StringEncoding];
        [methodParamsJson release];
        methodParamsJson = nil;
    
        //parse out the json data
        NSError *error = nil;
        NSDictionary *json = [NSJSONSerialization JSONObjectWithData:jsonData
                                                             options:kNilOptions
                                                               error:&error];
        
        // If parameters are available call the respective selector with parameters
        if (error == nil) {
            [receiver performSelector:selectorToBeCalled withObject:json];
        } else {
            return;
        }
    } else {
        [receiver performSelector:selectorToBeCalled withObject:[NSDictionary dictionary]];
    }
}

#pragma mark -
#pragma mark IOSNDKHelper Implementation

@implementation IOSNDKHelper

+ (void)sendMessage:(NSString *)methodName withParameters:(NSDictionary *)parameters
{
    if (parameters != nil) {
        NSError *error = nil;
        NSData *jsonData = [NSJSONSerialization dataWithJSONObject:parameters
                                                           options:NSJSONWritingPrettyPrinted
                                                             error:&error];
        
        if (error != nil) {
            return;
        }
        
        NSString *jsonParametersString = [[NSString alloc] initWithData:jsonData
                                                               encoding:NSUTF8StringEncoding];
        
        const char* jsonParametersStr = [jsonParametersString UTF8String];
        
        const char* methodNameStr = [methodName UTF8String];
        NDKHelper::handleMessage(methodNameStr, jsonParametersStr);
        
        [jsonParametersString release];
        jsonParametersString = nil;
        
    }
}

+ (void)setNDKReceiver:(NSObject *)receiver
{
    IOSNDKHelperImpl::setNDKReceiver((void *)receiver);
}

@end
