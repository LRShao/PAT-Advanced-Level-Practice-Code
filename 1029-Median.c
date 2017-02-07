#include <stdio.h>
#include <limits.h>

#define MAX_LENGTH_OF_ONE_SEQUENCE 1000000

typedef long int LL;

LL median;

int main() {
    LL len1, len2,
       sequence1[ MAX_LENGTH_OF_ONE_SEQUENCE + 1 ] = {0};

    scanf( "%ld", &len1 );
    LL i;
    for ( i = 0 ; i < len1; i++ ) {
        scanf( "%ld", &sequence1[ i ] );
    }
    sequence1[ i ] = LONG_MAX;
    
    scanf( "\n%ld", &len2 );

    LL count = ( len1 + len2 + 1 ) / 2;
    
    LL current;
    scanf( "%ld", &current );
    
    // deal with the special case where len1 == len2 == 1
    if ( len1 == 1 && len2 == 1 ) {
        median = ( sequence1[0] < current ) ? sequence1[0] : current ;
        printf( "%ld", median );
        return 0;
    }
    
    LL j= 0;
    
    i = 0;
    do {
        while ( sequence1[ i ] < current ) {
            i++;
            count--;
            if ( count == 1)
                goto OutOfLoop;
        }

        if ( j < len2 ) {
            count--;
            j++;
        }

        if ( j < len2 )
            scanf( "%ld", &current );
        else
            current = LONG_MAX;

    }
    while ( count >= 2 );

    OutOfLoop:

    median = ( sequence1[ i ] < current ) ? sequence1[ i ] : current ;

    printf( "%ld", median );
    
    return 0;
}
