//
//  WeChatPlugin.m
//  WeChatPlugin
//
//  Created by CorbinChen on 2017/3/24.
//  Copyright (c) 2017年 CorbinChen. All rights reserved.
//

#import "WeChatPlugin.h"

#import "PrivateHeaders/MessageService.h"

#pragma mark - Plugin

@implementation NSBundle (WeChatPlugin)

+ (instancetype)pluginBundle {
    return [NSBundle bundleWithIdentifier:@"cn.chaitin.WeChatPlugin"];
}

@end

@implementation NSObject (WeChatPlugin)

#pragma mark - MMLogger

+ (void)cb_logWithMMLogLevel:(int)arg1 module:(const char *)arg2 file:(const char *)arg3 line:(int)arg4 func:(const char *)arg5 message:(id)arg6 {
    NSLog(@"[%s] %s %s %@", arg2, arg3, arg5, arg6);
}

#pragma mark - AppDelegate

- (void)cb_applicationDidFinishLaunching:(id)arg {
    [self cb_applicationDidFinishLaunching:arg];
    if ([WeChatService(AccountService) canAutoAuth]) {
        [WeChatService(AccountService) AutoAuth];
    }
}

- (NSApplicationTerminateReply)cb_applicationShouldTerminate:(NSApplication *)sender {
    return NSTerminateNow;
}

#pragma mark - MessageService

- (void)cb_onRevokeMsg:(id)arg {
    NSLog(@"prevent message recall");
}

@end

@implementation NSViewController (WeChatPlugin)


@end

static void __attribute__((constructor)) initialize(void) {
    NSLog(@"++++++++ WeChatPlugin loaded ++++++++");
    
    CBHookClassMethod(MMLogger, @selector(logWithMMLogLevel:module:file:line:func:message:), @selector(cb_logWithMMLogLevel:module:file:line:func:message:));
    
    CBHookInstanceMethod(MessageService, @selector(onRevokeMsg:), @selector(cb_onRevokeMsg:));
    
    CBHookInstanceMethod(AppDelegate, @selector(applicationDidFinishLaunching:), @selector(cb_applicationDidFinishLaunching:));
    CBHookInstanceMethod(AppDelegate, @selector(applicationShouldTerminate:), @selector(cb_applicationShouldTerminate:));
    
}
