#include <stdio.h>
#include <ctype.h>

void print_digit_in_letter( int digit ) {
    switch( digit ) {
    case 0:
        printf("zero"); break;
    case 1:   
        printf("one");  break;
    case 2:
        printf("two");  break;
    case 3:
        printf("three");break;
    case 4:
        printf("four"); break;
    case 5:
        printf("five"); break;
    case 6:
        printf("six");  break;
    case 7:
        printf("seven");break;
    case 8:
        printf("eight");break;
    case 9:    
        printf("nine"); break;
    }
}

int main() {
    int sum;
    
    char ch = getchar();
    for( int i = 0; isdigit(ch) ; i++ ) {
        sum += ( ch - '0' );
        ch = getchar();
    }

    // the max possible sum is 900
    int digitOfSum[3] = {0};
    int i = 2;

    if ( sum == 0 ) {
        print_digit_in_letter( 0 );
        return 0;
    }

    do {
        digitOfSum[i--] = sum % 10;
        sum = sum / 10;
    }
    while ( sum != 0);

    int j;
    for( j = 0; digitOfSum[j] == 0; j++ )
        ;

    while( j < 3 ) {
        print_digit_in_letter( digitOfSum[j] );
        if ( j <= 1 )
            putchar(' ');
        j++;
    }
    

    return 0;
}
