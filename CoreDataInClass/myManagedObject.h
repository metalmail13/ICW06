//
//  myManagedObject.h
//  CoreDataInClass
//
//  Created by Brian Martinez on 11/26/17.
//  Copyright © 2017 Albert Diaz. All rights reserved.
//

#import <CoreData/CoreData.h>

@interface myManagedObject : NSManagedObject

@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) NSDate *date;

@end
