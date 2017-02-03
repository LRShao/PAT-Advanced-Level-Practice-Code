#include <stdio.h>

char mars_notation( int num ) {
    if ( num <= 9 ) 
        return ( (char)( '0' + num ) );
    else
        switch( num ) {
            case 10:
                return 'A'; break;
            case 11:
                return 'B'; break;
            case 12:
                return 'C'; break;
        }
}

void convert_and_print_in_mars_radix( int num ) {
    int high = num / 13,
        low  = num % 13;

    putchar( mars_notation( high ) );
    putchar( mars_notation( low ) );
}

int main() {
    int R, G, B;
    scanf("%d %d %d", &R, &G, &B );
    
    printf("#");
    convert_and_print_in_mars_radix( R );
    convert_and_print_in_mars_radix( G );
    convert_and_print_in_mars_radix( B );

    return 0;
}
