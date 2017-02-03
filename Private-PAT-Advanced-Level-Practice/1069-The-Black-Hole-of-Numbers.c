#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N );
    
    int digit[4];
    for( int i = 0; i < 4; i++ ) {
        digit[3-i] = N % 10;
        N = N / 10;
    }

    if ( (digit[0] == digit[1]) && (digit[1] == digit[2]) && (digit[2] == digit[3]) ) {
        printf("%d%d%d%d - %d%d%d%d = 0000", digit[0], digit[1], digit[2], digit[3],
                                             digit[0], digit[1], digit[2], digit[3]);
    return 0;
    }

    do {
        int counter[10] = {0};
        for( int i = 0; i < 4; i++) {
            counter[ digit[i] ] ++;
        }
    
        int descend[4] = {0},
            ascend [4] = {0};

        int i = 0;
        for( int j = 0; j <= 9; j++ ) {
            while( counter[j] > 0 ) {
                descend[3-i] = j;
                ascend[i++] = j;
                counter[j] --;
            }
        }

        N = ( 1000*descend[0] + 100*descend[1] + 10*descend[2] + descend[3] )
           -( 1000*ascend [0] + 100*ascend [1] + 10*ascend [2] + ascend [3] );
       
        for( int i = 0; i < 4; i++ ) {
            digit[3-i] = N % 10;
            N = N / 10;
        }

        printf("%d%d%d%d - %d%d%d%d = %d%d%d%d\n",
                descend[0], descend[1], descend[2], descend[3], 
                ascend [0], ascend [1], ascend [2], ascend [3],
                digit  [0], digit  [1], digit  [2], digit  [3] );
        
    }
    while( ( 1000 * digit[0] + 100 * digit[1] + 10 * digit[2] + digit[3] ) != 6174 );

    return 0;
}
