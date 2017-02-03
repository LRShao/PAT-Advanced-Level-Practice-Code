#include <stdio.h>
#include <ctype.h>

#define MAX_STRING_LEN 80
#define NUMBER_OF_KEYS 37 

#define TRUE  1
#define FALSE 0

int main() {
    char string[ MAX_STRING_LEN ];

    char ch;
    int i = 0;
    while( ( ch = getchar() ) != '\n' )
        string[ i++ ] = ch;
    int stringLen = i;

    // since each key should only be printed out once, we need to store the flag
    // position - key correspondence: 0-9:num, 10-35:A-Z, 36:_(space)
    int isWornOut[ NUMBER_OF_KEYS ] = { FALSE };
    
    i = 0;
    ch = getchar();
    while( ( ch != '\n' ) || ( i < stringLen ) ) {
        // test
        // printf( "\nchecking: %c\ti:%d\tstring[i]:%c\t", ch , i, string[i] );
        while( ( ch != string[i] ) && ( i < stringLen ) ) {
            if ( islower( string[i] ) )
                string[i] = (char) ( string[i] + 'A' - 'a' );
            
            // there should not be else if, otherwise we have to use nested if to complement
            if ( isdigit( string[i] ) && ( isWornOut[ string[i] - '0' ] != TRUE ) ) {
                putchar( string[i] );
                isWornOut[ string[i] - '0' ] = TRUE;
            }

            if ( isalpha( string[i] ) 
                     && ( isWornOut[ string[i] - 'A' + 10 ] != TRUE) ) {
                putchar( string[i] );
                isWornOut[ string[i] - 'A' + 10 ] = TRUE;
            }

            if ( string[i] == '_' && isWornOut[36] != TRUE ) {
                putchar('_');
                isWornOut[36] = TRUE;
            }

            i++;
        }
        i++;
        if ( ch != '\n' )
            ch = getchar();
    }

    return 0;
}
