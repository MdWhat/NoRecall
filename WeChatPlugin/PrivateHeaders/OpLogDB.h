//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class WCDataBase, WCDataBaseTable;

@interface OpLogDB : NSObject
{
    WCDataBase *m_db;
    WCDataBaseTable *m_table;
}

+ (void)DeleteDB:(id)arg1;
- (void).cxx_destruct;
- (BOOL)DeleteOpLogs:(id)arg1;
- (id)GetOpLogOfTop:(unsigned int)arg1;
- (unsigned int)GetOpLogCount;
- (BOOL)InsertOpLog:(id)arg1;
- (id)initWithPath:(id)arg1;

@end
