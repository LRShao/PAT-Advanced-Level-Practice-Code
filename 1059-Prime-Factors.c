#include <stdio.h>
#include <math.h>

#define TRUE  1
#define FALSE 0

void print_next_smallest_prime_factor_and_exponent( long int number,
                                                    long int formerFactor ) {
    int isFirst = ( formerFactor == 1 ) ? TRUE : FALSE;

    if ( number == 1 ) {
        if ( isFirst )
            printf("1");

        return;
    }

    long int squareRoot = sqrt( number ) + 1;
    
    long int test;
    for ( test = formerFactor + 1; test <= squareRoot; test++ ) {
        if ( number % test == 0 )
            break;
    }

    // if the number itself is not prime
    if ( test < squareRoot ) {
        long int primeFactor = test;
        int  exponent = 0;
        while ( number % primeFactor == 0 ) {
            number = number / primeFactor;
            exponent ++;
        }
        
        if ( ! isFirst )
            printf( "*" );
        printf( "%ld", primeFactor );
        if ( exponent > 1 ) 
            printf( "^%d", exponent );
        
        print_next_smallest_prime_factor_and_exponent( number, primeFactor );
    }
    else {
        if ( ! isFirst )
            printf( "*" );
        printf( "%ld", number );
    }
}

int main() {
    long int N;
    scanf( "%ld", &N );

    printf( "%ld=", N );
    print_next_smallest_prime_factor_and_exponent( N, 1 );

    return 0;
}
