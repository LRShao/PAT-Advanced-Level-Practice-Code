#include <stdio.h>

#define MAX_LEN_OF_FRACTIONAL_PART 20000

#define POSITIVE 1
#define NEGATIVE 0

int main() {
    int signInteger, signExponent, exponent;
    char integer;
    char fraction[ MAX_LEN_OF_FRACTIONAL_PART ] = {0};

    char ch = getchar();
    signInteger = ( ch == '+' ) ? POSITIVE : NEGATIVE; 

    ch = getchar();
    integer = ch;
    
    // decimal point
    getchar();
    
    int i = 0;
    while ( ( ch = getchar() ) != 'E' )
        fraction[ i++ ] = ch;
    int lenFraction = i;

    // exponent
    ch = getchar();
    signExponent = ( ch == '+' ) ? POSITIVE : NEGATIVE;

    scanf("%d", &exponent );

    // in case exponent is "-0"
    if ( exponent == 0 ) 
        signExponent = POSITIVE;

    // output
    if ( signInteger == NEGATIVE )
        putchar('-');

    if ( signExponent == POSITIVE ) {
        putchar( integer );
        for( int i = 0; i < lenFraction; i++ ) {
            if ( exponent == 0 )
                putchar('.');
            putchar( fraction[ i ] );
            exponent --;
        }
        while ( exponent > 0 ) {
            putchar('0');
            exponent --;
        }
    }
    else {
        printf("0.");
        exponent --;
        while ( exponent > 0) {
            putchar('0');
            exponent --;
        }
        putchar( integer );
        for( int i = 0; i < lenFraction; i++ ) {
            putchar( fraction[ i ] );
        }
    }

    return 0;
}

