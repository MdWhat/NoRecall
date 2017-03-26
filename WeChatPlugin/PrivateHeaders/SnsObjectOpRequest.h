//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "PBGeneratedMessage.h"

@class BaseRequest, NSMutableArray;

@interface SnsObjectOpRequest : PBGeneratedMessage
{
    unsigned int hasBaseRequest:1;
    unsigned int hasOpCount:1;
    unsigned int opCount;
    BaseRequest *baseRequest;
    NSMutableArray *mutableOpListList;
}

+ (id)parseFromData:(id)arg1;
@property(retain, nonatomic) NSMutableArray *mutableOpListList; // @synthesize mutableOpListList;
@property(nonatomic, setter=SetOpCount:) unsigned int opCount; // @synthesize opCount;
@property(readonly, nonatomic) BOOL hasOpCount; // @synthesize hasOpCount;
@property(retain, nonatomic, setter=SetBaseRequest:) BaseRequest *baseRequest; // @synthesize baseRequest;
@property(readonly, nonatomic) BOOL hasBaseRequest; // @synthesize hasBaseRequest;
- (void).cxx_destruct;
- (void)addOpList:(id)arg1;
- (void)addOpListFromArray:(id)arg1;
- (id)mergeFromCodedInputStream:(id)arg1;
- (int)serializedSize;
- (void)writeToCodedOutputStream:(id)arg1;
- (BOOL)isInitialized;
@property(retain, nonatomic) NSMutableArray *opList; // @dynamic opList;
- (id)opListList;
- (id)init;

@end
