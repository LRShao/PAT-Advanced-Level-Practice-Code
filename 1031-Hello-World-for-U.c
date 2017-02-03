#include <stdio.h>

#define MAX_STRING_LEN 80

int main() {
    char string[ MAX_STRING_LEN ];

    int i = 0;
    char ch;
    while( ( ch = getchar() ) != '\n' )
        string[i++] = ch;
    int N = i;

    int n1 = ( N + 2 ) / 3,
        n3 = N + 2 - ( 2 * n1 );

    for( int j = 0; j < ( n1 - 1 ) ; j++ ) {
        putchar( string[j] );
        for( int k = 1; k <= ( n3 - 2 ); k++ )
            putchar(' ');
        putchar( string[ N - j - 1 ] );
        putchar('\n');
    }
    for( int k = 0; k< n3; k++ )
        putchar( string[ n1 + k - 1 ] );    

    return 0;
}
