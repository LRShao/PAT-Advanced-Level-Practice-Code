#include <stdio.h>

#define MAX_NUMBER_OF_EXITS 100001

// in order to avoid timeout, store the accumulative distance instead of interval distance

int main() {
    int N;
    long int accumulativeDistance[ MAX_NUMBER_OF_EXITS ] = {0};
    
    scanf("%d", &N);
    
    long int D;
    for( int i = 1; i <= N; i++ ) {
        scanf(" %ld", &D );
        accumulativeDistance[ i ] += accumulativeDistance[ i-1 ] + D;
    }

    int M;
    scanf("\n%d", &M );

    int E1, E2;
    long int totalDistance = accumulativeDistance[ N ];
    long int onewayDistance;
    for( int j = 1; j <= M; j++ ) {
        scanf("\n%d %d", &E1, &E2 );

        if ( E2 < E1 ) {
            int t  = E1;
            E1 = E2;
            E2 = t;
        }

        onewayDistance = accumulativeDistance[ --E2 ] - accumulativeDistance[ --E1 ];
        
        if ( 2 * onewayDistance > totalDistance )
            onewayDistance = totalDistance - onewayDistance;
        
        printf("%ld\n", onewayDistance );
    }

    return 0;
}
