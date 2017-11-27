//
//  AAAEmployeeMO.h
//  CoreDataInClass
//
//  Created by Brian Martinez on 11/26/17.
//  Copyright © 2017 Albert Diaz. All rights reserved.
//

#import <CoreData/CoreData.h>

@interface AAAEmployeeMO : NSManagedObject

@property (nonatomic, strong) NSString *name;

@end

@implementation AAAEmployeeMO

@dynamic name;

NSError *error = nil;
if ([[self managedObjectContext] save:&error] == NO) {
    NSAssert(NO, @"Error saving context: %@\n%@", [error localizedDescription], [error userInfo]);
}

NSManagedObjectContext *moc = …;
NSFetchRequest *request = [NSFetchRequest fetchRequestWithEntityName:@"Employee"];


NSString *firstName = @"Trevor";
[fetchRequest setPredicate:[NSPredicate predicateWithFormat:@"firstName == %@", firstName]];


NSError *error = nil;
NSArray *results = [moc executeFetchRequest:request error:&error];
if (!results) {
    NSLog(@"Error fetching Employee objects: %@\n%@", [error localizedDescription], [error userInfo]);
    abort();
}
#define CellDetailIdentifier @"CellDetailIdentifier"

- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    id destination = [segue destinationViewController];
    if ([[segue identifier] isEqualToString:CellDetailIdentifier]) {
        NSIndexPath *indexPath = [[self tableView] indexPathForSelectedRow];
        id selectedObject = [[self fetchedResultsController] objectAtIndexPath:indexPath];
        [destination setEmployee:selectedObject];
        return;
    }
}

@end

@end
