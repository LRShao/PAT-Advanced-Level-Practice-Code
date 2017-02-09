#include <stdio.h>

#define MAX_NUMBER_OF_SIGNIFICANT_DIGIT 100
#define TRUE  1
#define FALSE 0

void scan_number( int * num ) {
    char ch;
    // i = -1 haven't met the first non-zero significant digit or decimal point
    // i = 0  have met decimal point but not first significant digit
    // i > 0  have met first significant digit, isFraction indicates if decimal point is met 
    int i = -1,
        exponent = 0,
        isFraction = FALSE;
    while( ( ch = getchar() ) != ' ' && ch != '\n' ) {
        if ( i == -1 ) {
            if ( ch == '0' ) {
                ;
            }
            else if ( ch == '.' ) {
                isFraction = TRUE;
                i = 0;
            }
            else {
                i = 1;
                num[i++] = ch - '0';
                exponent ++;
            }
        }
        else if ( i == 0 ) {
            if ( ch == '0' )
                exponent --;
            else {
                i = 1;
                num[i++] = ch - '0';
            }
        }
        else {
            if ( ! isFraction ) {
                if ( ch == '.' )
                    isFraction = TRUE;
                else {
                    num[i++] = ch - '0';
                    exponent ++;
                }
            }
            else {
                num[i++] = ch - '0';
            }
        }
    }

    // in case the input number is 0, 00000 or 00.00
    if ( i > 0 ) {
        num[i] = -1;
        num[0] = exponent;
    }
    else {
        num[1] = -1;
        num[0] = 0;
    }
} 

void process_number( int * num , int numberOfSignificantDigit ) {
    int i;
    for ( i = 1; i <= numberOfSignificantDigit; i++ ) {
        if ( num[i] == -1 ){
            num[i] = 0;
            num[i + 1] = -1;
        }
    }
    num[i] = -1;
}

int compare_number( int * num1, int * num2, int numberOfSignificantDigit ) {
    int isEqual = TRUE;
    for ( int i = 0; i <= numberOfSignificantDigit; i++ ) {
        if ( num1[i] != num2[i] ) {
            isEqual = FALSE;
            break;
        }
    }
    return isEqual;
}

void print_number( int * num ) {
    printf("0.");
    for ( int i = 1; num[i] != -1; i++ )
            printf( "%d", num[i] );
    
    printf( "*10^%d", num[0] );

}

int main() {
    int numberOfSignificantDigit;
    // num_[0] is used to store k
    int num1[ MAX_NUMBER_OF_SIGNIFICANT_DIGIT + 1 ] = {0},
        num2[ MAX_NUMBER_OF_SIGNIFICANT_DIGIT + 1 ] = {0};

    scanf( "%d ", &numberOfSignificantDigit );
    
    scan_number( num1 );
    scan_number( num2 );

    process_number( num1, numberOfSignificantDigit );
    process_number( num2, numberOfSignificantDigit );

    if ( compare_number( num1, num2, numberOfSignificantDigit ) == TRUE ) {
        printf( "YES ");
        print_number( num1 );
    }
    else {
        printf( "NO " );
        print_number( num1 );
        printf(" ");
        print_number( num2 );
    }

    return 0;
}
