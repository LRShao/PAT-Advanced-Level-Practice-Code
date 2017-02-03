#include <stdio.h>

#define MAX_LENGTH_OF_STRING 10001
#define MAX_NUMBER_OF_ASCII_CHARACTERS 128

#define TRUE  1
#define FALSE 0

// there are total 128 ASCII characters, store the result in an array to save time.

int main() {
    char string1[ MAX_LENGTH_OF_STRING ] = {0};
    int isInString2[ MAX_NUMBER_OF_ASCII_CHARACTERS ] = { FALSE };

    int i = 0;
    char ch;

    while( ( ch = getchar() ) != '\n' )
        string1[i++] = ch;
    int string1Len = i;

    while( ( ch = getchar() ) != '\n' ) {
        isInString2[ (int) ch ] = TRUE;
    }
   
    for ( int j = 0; j < string1Len; j++ ) {
        if ( ! isInString2[ string1[j] ] )
            putchar( string1[j] );
    }
    
    return 0;
}
