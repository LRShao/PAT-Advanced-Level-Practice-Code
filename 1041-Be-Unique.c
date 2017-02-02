#include <stdio.h>

#define MAX_NUMBER_RANGE 10000
#define MAX_NUMBER_OF_INPUT 100000

int main() {
    int numberOfInput = 0;
    scanf("%d", &numberOfInput );

    int input[ MAX_NUMBER_OF_INPUT ];
    for( int i; i < numberOfInput; i++ )
        scanf(" %d", &input[i] );

    int counter[ MAX_NUMBER_RANGE + 1 ];
    for ( int i = 1; i < numberOfInput; i++ ) {
        counter[ input[i] ] ++;
    }

    int winnerNum = -1;
    for ( int i = 1; i < numberOfInput; i++ ) {
        if ( counter[ input[i] ] == 1 ) {
            winnerNum = input[i];
            break;
        }
    }

    if ( winnerNum == -1)
        printf("None");
    else
        printf("%d", winnerNum);

    return 0;
}
