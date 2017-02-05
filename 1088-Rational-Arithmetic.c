#include <stdio.h>

#define POSITIVE 1
#define NEGATIVE 0

void print_fraction_number( long int numerator, long int denominator ) {
    if ( numerator == 0 ) {
        printf("0");
        return;
    }
    
    int sign;
    if ( numerator > 0 ) 
        sign = POSITIVE;
    else {
        sign = NEGATIVE;
        numerator = - numerator;
    }
    
    long int integer = numerator / denominator;
    numerator = numerator % denominator;

    if ( sign == NEGATIVE )
        printf( "(-" );
    
    if ( integer != 0 )
        printf("%ld", integer);

    if ( numerator != 0 ) {
        if ( integer != 0 )
            printf(" ");
        printf( "%ld/%ld" , numerator, denominator );
    }

    if ( sign == NEGATIVE )
        printf( ")" );
}

long int find_gcf( long int num1, long int num2 ) {
    num1 = ( num1 >= 0 ) ? num1 : -num1 ; 

    long int r;
    do {
        r = num1 % num2;
        num1 = num2;
        num2 = r;
    }
    while ( r != 0 );
    return num1;
}

void simplify_fraction_number( long int *numerator, long int *denominator ) {
    if ( numerator != 0 ) {
       long int gcf = find_gcf( *numerator, *denominator );
       *numerator /= gcf;
       *denominator /= gcf;
    }
}


int main() {
    long int numerator1, numerator2, denominator1, denominator2;
   
    scanf("%ld/%ld %ld/%ld", &numerator1, &denominator1, &numerator2, &denominator2 );
    
    simplify_fraction_number( &numerator1, &denominator1 );
    simplify_fraction_number( &numerator2, &denominator2 );

    long int numeratorAdd, numeratorSub, denominatorAdd, denominatorSub;
    long int gcf = find_gcf( denominator1, denominator2 );

    denominatorAdd = denominatorSub 
                   = denominator1 / gcf * denominator2;
    
    numeratorAdd = denominator2 / gcf * numerator1
                 + denominator1 / gcf * numerator2;
    
    numeratorSub = denominator2 / gcf * numerator1
                 - denominator1 / gcf * numerator2;

    simplify_fraction_number( &numeratorAdd, &denominatorAdd );
    simplify_fraction_number( &numeratorSub, &denominatorSub );
    
    print_fraction_number( numerator1, denominator1 );
    printf(" + ");
    print_fraction_number( numerator2, denominator2 );
    printf(" = ");
    print_fraction_number( numeratorAdd, denominatorAdd );
    printf("\n");

    print_fraction_number( numerator1, denominator1 );
    printf(" - ");
    print_fraction_number( numerator2, denominator2 );
    printf(" = ");
    print_fraction_number( numeratorSub, denominatorSub );
    printf("\n");

    long int numeratorMul, numeratorDiv, denominatorMul, denominatorDiv;
    long int numerator1cp = numerator1, numerator2cp = numerator2,
             denominator1cp = denominator1, denominator2cp = denominator2;

    simplify_fraction_number( &numerator1cp, &denominator2cp );
    simplify_fraction_number( &numerator2cp, &denominator1cp );

    numeratorMul = numerator1cp * numerator2cp;
    denominatorMul = denominator1cp * denominator2cp;

    print_fraction_number( numerator1, denominator1 );
    printf(" * ");
    print_fraction_number( numerator2, denominator2 );
    printf(" = ");
    print_fraction_number( numeratorMul, denominatorMul );
    printf("\n");
      
    print_fraction_number( numerator1, denominator1 );
    printf(" / ");
    print_fraction_number( numerator2, denominator2 );
    printf(" = ");
    if ( numerator2 == 0 )
        printf("Inf");
    else {
        numerator1cp = numerator1, numerator2cp = numerator2,
        denominator1cp = denominator1, denominator2cp = denominator2;
        
        simplify_fraction_number( &numerator1cp, &numerator2cp );
        simplify_fraction_number( &denominator2cp, &denominator1cp );

        numeratorDiv = numerator1cp * denominator2cp;
        denominatorDiv = numerator2cp * denominator1cp;

        print_fraction_number( numeratorDiv, denominatorDiv );
    }
    printf("\n");

    return 0;
}
