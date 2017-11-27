//
//  AppDelegate.h
//  CoreDataInClass
//
//  Created by Administrator on 11/20/17.
//  Copyright © 2017 Albert Diaz. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreData/CoreData.h>

@interface AppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) DataController *dataController;
@property (strong, nonatomic) UIWindow *window;

@property (readonly, strong) NSPersistentContainer *persistentContainer;

- (void)saveContext;


@end

