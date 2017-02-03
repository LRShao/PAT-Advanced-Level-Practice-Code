#include <stdio.h>
#include <math.h>

// 10^5 < 2^17 
#define MAX_NUMBER_OF_DIGIT 20

#define TRUE  1
#define FALSE 0

// converted number is stored in an array digit by digit, ending with -1
void convert_to_base_and_reverse( int * p_num , int base , long int N ) {
   int r = N % base;
       N = N / base;

   int i = 0;

   while( N != 0 ) {
       p_num[i] = r;
       r = N % base,
       N = N / base;
       i++;
   }

   p_num[i] = r;
   p_num[i+1] = -1;
}

long int convert_to_decimal( int * p_num , int base ) {
    long int decimalValue = 0;
    
    for ( int i = 0 ; p_num[i] != -1 ; i++ )
        decimalValue = decimalValue * base + p_num[i];
    
    return decimalValue;
}


int is_prime( long int x ) {
    long int squareRoot = sqrt(x);
    
// deal with simple special case first, which appears test set 1
    if ( x == 1 ) 
        return FALSE;

    int i = 2;
    for ( ; i <= squareRoot ; i++ ) {
        if ( ( x % i ) == 0 ) 
            break;
    }
    
    if ( i > squareRoot)
        return TRUE;
    else
        return FALSE;
}

int main() {
   
    long int N;

    scanf("%ld ", &N );  

    while( N >= 0 ) {
        int D;
        scanf("%d\n", &D);

        int reversedN[MAX_NUMBER_OF_DIGIT] = {0};

        convert_to_base_and_reverse( reversedN, D, N );

        long int valueReversedN = convert_to_decimal( reversedN , D );        
            
        if ( is_prime( N ) && is_prime( valueReversedN ) )
            printf("Yes\n");
        else
            printf("No\n");

        scanf("%ld", &N );
    }

    return 0;
}
