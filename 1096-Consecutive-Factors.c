#include <stdio.h>
#include <math.h>

#define TRUE  1
#define FALSE 0

// do some estimation, 14! > 2^31, so number of consecutive factors is no larger than 13 

typedef unsigned long int UL;

int find_consecutive_factors( UL N, int numberOfConsecutiveFactors, int * p_startNumber ) {
    if ( numberOfConsecutiveFactors > 1) {
        int startNumber = 2,
            endNumber = startNumber + numberOfConsecutiveFactors - 1;
         UL product = 1;

        for ( int i = startNumber ; i <= endNumber ; i++ )
            product *= i;

         int factorsFound = FALSE;

        while ( product <= N && ( ! factorsFound ) ) {
            if ( N % product == 0 )  {
                factorsFound = TRUE;

            }

            product = product / ( startNumber ++ ) * ( ++ endNumber);
        }

        if ( factorsFound ) {
            * p_startNumber = startNumber - 1;
            return TRUE;
        }
        else
            return FALSE;
    }

// optimization is important for single factor, otherwise large prime number may cause timeout
    else {
        UL upperBound = sqrt(N);
        int factor = 2;
        while ( ( (N % factor) != 0 ) && ( factor <= upperBound ) ) 
            factor ++;
        
        if ( factor > upperBound)
            * p_startNumber = N;
        else
            * p_startNumber = factor;

        return TRUE;
    }
}

int main() 
{ 
    UL N;
    scanf("%lu", &N);

    if ( N == 1 ) {
        printf("0\n");
        return 0;
    }

    int startNumber, length;
    int factorsFound = FALSE;
    for  ( length = 13; length >= 1; length --) {
        if ( factorsFound = find_consecutive_factors( N, length, & startNumber ) )
            break;
    }

    if ( factorsFound ) {
        printf("%d\n", length);

        printf("%d", startNumber);
        if( length > 1)
            for ( int i = 1; i < length; i++)
                printf("*%d", startNumber + i );
    }

    return 0;
}
