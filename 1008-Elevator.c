#include <stdio.h>

int main() {
    int floorsUp   = 0,
        floorsDown = 0,
        floorsStop;
        
    scanf("%d", &floorsStop);

    int previousFloor = 0,
        currentFloor;
    for( int i = 1; i <= floorsStop; i++ ) {
        scanf(" %d", &currentFloor );
        if ( currentFloor >= previousFloor ) 
            floorsUp += ( currentFloor - previousFloor );
        else
            floorsDown += - ( currentFloor - previousFloor );
        
        previousFloor = currentFloor;
        
    }

    int secondsTaken = 6 * floorsUp + 4 * floorsDown + 5 * floorsStop;
    printf("%d", secondsTaken );
    
    return 0;
}
