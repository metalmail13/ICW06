//
//  MyDataController.h
//  CoreDataInClass
//
//  Created by Administrator on 11/25/17.
//  Copyright © 2017 Albert Diaz. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreData/CoreData.h>

@interface MyDataController : NSObject

@property (strong, nonatomic) NSPersistentContainer *persistentContainer;

- (id)initWithCompletionBlock:(CallbackBlock)callback;

@end

@implementation MyDataController

- (id)init
{
    self = [super init];
    if (!self) return nil;
    
    self.persistentContainer = [[NSPersistentContainer alloc] initWithName:@"DataModel"];
    [self.persistentContainer loadPersistentStoresWithCompletionHandler:^(NSPersistentStoreDescription *description, NSError *error) {
        if (error != nil) {
            NSLog(@"Failed to load Core Data stack: %@", error);
            abort();
        }
        callback();
    }];
    
    return self;
}
