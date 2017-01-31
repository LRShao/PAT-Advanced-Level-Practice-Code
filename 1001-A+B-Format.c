#include <stdio.h>

#define MAX_NUMBER_OF_DIGIT 8 

// the standard format of 1000 is 1,000 instead of 100,0 !
int main() {
    long int a, b;

    scanf("%ld %ld", &a, &b );

    long int sum = a + b;

    int digitSum[MAX_NUMBER_OF_DIGIT] = {0};
    
    if ( sum < 0) {
        printf("-");
        sum = - sum ;
    }
    
    int i = 0;

    int r = sum % 10;
    sum = sum / 10;
    while ( sum != 0 ) {
        digitSum[i++] = r;
        r = sum % 10;
        sum = sum / 10;
    }
    digitSum[i++] = r;
    
    int lengthOfSum = i;

    for( int j = lengthOfSum - 1 ; j >= 0 ; j-- ) {
        printf("%d", digitSum[ j ] );
        if ( ( ( j ) % 3 == 0) && ( j != 0 ) )
            printf(",");    
    }

    return 0;
}
