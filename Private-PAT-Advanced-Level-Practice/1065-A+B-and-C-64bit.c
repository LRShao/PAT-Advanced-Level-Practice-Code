:w#include <stdio.h>

#define MAX_NUMBER_OF_BINARY_BITS 65

#define TRUE  1
#define FALSE 0

int main() {

    int T;
    scanf("%d", &T);

    for( int i = 0; i < T ; i++ ){
        long int dA, dB, dC;

        scanf("%ld %ld %ld", &dA, &dB, &dC);
        if( i != T-1 )
            scanf("\n");        

        long int sum = dA + dB;
        int isSumBigger;

        if ( dA > 0 && dB > 0 && sum <= 0 )
            isSumBigger = TRUE;
        else if ( dA < 0 && dB < 0 && sum >= 0 )
            isSumBigger = FALSE;
        else if ( sum > dC )
            isSumBigger = TRUE;
        else if ( sum <= dC )
            isSumBigger = FALSE;            

        printf("Case #%d: ", i+1);
        if ( isSumBigger )
            printf("true\n");
        else
            printf("false\n");
    }

    return 0;
}
