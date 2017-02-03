#include <stdio.h>

#define MAX_LENGTH 30

#define TRUE  1
#define FALSE 0

void count_digit( int *counter , int *number, int length ) {
    int i;
    if ( counter[0] == 0) 
        i = 1;
    else
        i = 0;

    for ( ; i < length; i++ ) {
        counter[ number[i] ] ++;
    }
}

int main() {
    
    int numberOriginal[MAX_LENGTH] = {0};
    
    // original number is stored in entry [1 ... ]
    char ch = getchar();
    int i = 1;
    while( ch != '\n' ) {
        numberOriginal[ i++ ] = ch - '0';
        ch = getchar();
    }
    
    int length = i;
    int numberDouble[MAX_LENGTH];

    int carry = 0;
    for ( int j = length - 1 ; j >= 0 ; j-- ) {
       numberDouble[j] = ( numberOriginal[j] * 2 + carry ) % 10;
       carry = ( numberOriginal[j] * 2 + carry ) / 10;       
    }
    
    // Don't forget to initialize
    int counterOriginal[10] = {0},
        counterDouble[10] = {0};

    count_digit( counterOriginal, numberOriginal, length );
    count_digit( counterDouble, numberDouble, length );

    int isPermutation = TRUE;
    for ( int j = 0; j < 10 ; j++) {
        if ( counterOriginal[j] != counterDouble[j] )
            isPermutation = FALSE;
    }

    if ( isPermutation ) 
        printf("Yes\n");
    else
        printf("No\n");

    // print the doubled number
    int j;

    if ( numberDouble[0] != 0) 
        j = 0;
    else
        j = 1;

    for ( ; j < length; j++ )
        printf("%d", numberDouble[j] );

    return 0;
}
