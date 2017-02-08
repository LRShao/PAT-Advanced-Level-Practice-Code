#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAX_NUMBER_OF_DIGIT 10

#define LARGER   1
#define EQUAL    0
#define SMALLER -1

int compare_unknown_radix( long int unknownRadix, long int valueKnown,
                           int * digitsWithUnknownRadix, int lenUnknown ) {
    long int valueUnknown = 0;
    for ( int i = 0; i < lenUnknown; i++ ) {
        valueUnknown = valueUnknown * unknownRadix + digitsWithUnknownRadix[i];
        // compare inside the loop to avoid or deal with overflow and save time
        if ( valueUnknown > valueKnown || valueUnknown < 0 )
            return LARGER;
    }
    if ( valueUnknown < valueKnown )
        return SMALLER;
    else
        return EQUAL;
}

int main() {
    int N1[ MAX_NUMBER_OF_DIGIT ],
        N2[ MAX_NUMBER_OF_DIGIT ];
    
    char ch;
    int i = 0;
    while ( ( ch = getchar() ) != ' ' )
        N1 [ i++ ] = isdigit( ch ) ? ( ch - '0' ) : ( ch - 'a' + 10 );
    int len1 = i;

    i = 0;
    while ( ( ch = getchar() ) != ' ' )
        N2 [ i++ ] = isdigit( ch ) ? ( ch - '0' ) : ( ch - 'a' + 10 );
    int len2 = i;

    int tag; 
    long int radix;
    scanf( "%d %ld", &tag, &radix );

    int * digitsWithKnownRadix, * digitsWithUnknownRadix;
    int lenKnown, lenUnknown;
    if ( tag == 1 ) {
        digitsWithKnownRadix = N1;
        digitsWithUnknownRadix = N2;
        lenKnown = len1;
        lenUnknown = len2;
    }
    else {
        digitsWithKnownRadix = N2;
        digitsWithUnknownRadix = N1;
        lenKnown = len2;
        lenUnknown = len1;
    }

    long int valueKnown = 0;
    for ( int i = 0; i < lenKnown; i++ ) {
        valueKnown = valueKnown * radix + digitsWithKnownRadix[i];
    }

    long int lowerBoundaryOfUnknownRadix = 2;
    for ( int i = 0; i < lenUnknown; i++ )
        if ( lowerBoundaryOfUnknownRadix < ( digitsWithUnknownRadix[ i ] + 1 )  )
            lowerBoundaryOfUnknownRadix = digitsWithUnknownRadix[ i ] + 1;
    // further optimization for large value known
    int temp;
    if ( lowerBoundaryOfUnknownRadix 
        < ( temp = round ( pow ( (double)( valueKnown / 35 ), ( 1. / lenUnknown ) ) ) ) ) 
        lowerBoundaryOfUnknownRadix = temp;

    // deal with special case
    if ( valueKnown != 0 && lenUnknown == 1 && digitsWithUnknownRadix[0] == 0 ) {
        printf("Impossible");
        return 0;
    }

    long int unknownRadix,
             upperBoundaryOfUnknownRadix = ( valueKnown > lowerBoundaryOfUnknownRadix ) ? 
                                           valueKnown : lowerBoundaryOfUnknownRadix ;
    int comparationResult = LARGER;
    while ( lowerBoundaryOfUnknownRadix <= upperBoundaryOfUnknownRadix ) {
        // Use binary search method in case of extremely large value
        long int attemptedRadix = ( lowerBoundaryOfUnknownRadix + upperBoundaryOfUnknownRadix ) / 2;

        comparationResult = compare_unknown_radix( attemptedRadix, valueKnown,
                                                   digitsWithUnknownRadix, lenUnknown );
        switch ( comparationResult ) {
            case EQUAL:             
                unknownRadix = attemptedRadix;
                // need to find the smallest possible value
                upperBoundaryOfUnknownRadix = attemptedRadix;
                // avoid looping infinitely
                if ( upperBoundaryOfUnknownRadix == lowerBoundaryOfUnknownRadix ) 
                    goto OutOfLoop;
                break;
            case LARGER:
                upperBoundaryOfUnknownRadix = attemptedRadix - 1;
                break;
            case SMALLER:
                lowerBoundaryOfUnknownRadix = attemptedRadix + 1;
        }
    }

    OutOfLoop:
    if ( comparationResult == EQUAL )
        printf( "%ld", unknownRadix );
    else
        printf("Impossible");
    
    return 0;
}
