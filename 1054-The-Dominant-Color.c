#include <stdio.h>

#define MAX_WIDTH  800
#define MAX_HEIGHT 600

// Optimization is very crutial for this program not to timeout
int main() {
    int M, N;
    
    scanf("%d %d", &M, &N );
    getchar();

    long int color[ MAX_HEIGHT ][ MAX_WIDTH ] = {0};
    int counter[ MAX_HEIGHT ][ MAX_WIDTH ] = {0};

    int halfPixel = ( M * N ) / 2 + 1;
    long int dominantColor;

    // read input, count and determine dominant color done in one block of nested loops
    for( int i = 0; i < N; i++ ) {
        for( int j = 0; j < M; j++ ) {
            if (i == 0)
                scanf("%ld", &color[i][j] );
            else
                scanf(" %ld", &color[i][j] );

            for( int k = i ; k >= 0 ; k-- ) {
                for( int l = (k == i)?j:(M-1) ; l >= 0; l-- )
                    if ( color[i][j] == color[k][l] ) {
                        // saves time for large number
                        counter[i][j] =  counter[k][l] + 1;
                        if ( ( j != l ) || ( i != k ) )
                        goto HalfOutOfNestedLoop;
                    }
            }
        
        HalfOutOfNestedLoop:

        if ( counter[i][j] >= halfPixel ) {
            dominantColor = color[i][j];
            // there can only be one strictly dominant color, no need for futher comparison
            goto OutOfNestedLoop;
            }
        }
        // deal with newline character
        getchar();
    }

    OutOfNestedLoop:
   
    /* only for testing

    printf("Counter:\n");
    for( int i = 0 ; i < N; i++ ) {
        for( int j = 0; j < M; j++ ) {
            printf("%d ", counter[i][j] );
        }
        printf("\n");
    }
    */

    printf("%ld", dominantColor);
   
    return 0;
}
