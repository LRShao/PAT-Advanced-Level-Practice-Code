#include <stdio.h>
#include <math.h>

#define MAX_NUMBER_OF_INPUT 110
#define TRUE  1
#define FALSE 0

typedef long long LL;

LL greatest_common_factor( LL input_1, LL input_2 ){
    LL r;
    r = input_1 % input_2;
    while (r != 0){
        input_1 = input_2;
        input_2 = r;
        r = input_1 % input_2;
    }

    LL  gcf = input_2; 

    return gcf;
}


int main()
{
    long int numerator[MAX_NUMBER_OF_INPUT];
    long int denominator[MAX_NUMBER_OF_INPUT];

    long int numberOfInput;
    scanf("%ld\n", &numberOfInput);

    for( int i=0; i < numberOfInput; i++){
        scanf("%ld/%ld", &numerator[i], &denominator[i]);
    }

    // compute the least common multiple
    LL leastCommonMultiple = 1;
    for( int i=0; i < numberOfInput; i++){
            leastCommonMultiple = leastCommonMultiple * denominator[i]
                           / greatest_common_factor( denominator[i], leastCommonMultiple );
    }

    LL outputNumerator = 0,
       outputDenominator = leastCommonMultiple,
       outputInt = 0;

    for( int i=0; i < numberOfInput; i++){
        outputNumerator += leastCommonMultiple / denominator[i] * numerator[i];
        // TODO sequence of terms in the above expression is NOT interchangeable
    }

    int isNegative = ( outputNumerator < 0 )? TRUE : FALSE ;          
    if ( isNegative ) 
        outputNumerator = (LL) fabs( outputNumerator );

    LL gcf = 0;
    if ( outputNumerator != 0)
        gcf = greatest_common_factor( outputNumerator, outputDenominator );

    while ( outputNumerator >= outputDenominator){
            outputNumerator -= outputDenominator;
            outputInt ++;
    }

    // Print the integer part
    if ( isNegative ) outputInt = - outputInt;
    
    if ( outputInt != 0 ) 
        printf("%lld", outputInt );

    if ( outputInt == 0 && outputNumerator == 0)
        printf("0");

    // Print the fractional part
    if ( ( outputInt == 0 ) && isNegative )
        outputNumerator = - outputNumerator;

    if ( outputNumerator != 0){
        if ( outputInt != 0 ) printf(" ");
        // This condition is important for correct output format 
        outputNumerator /= gcf;
        outputDenominator /=gcf;
        printf("%lld/%lld", outputNumerator, outputDenominator);
    }

    return 0;
}
