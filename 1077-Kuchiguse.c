#include <stdio.h>

#define MAX_NUMBER_OF_LINE 101
#define MAX_STRING_LEN 257

int main() {
    int N;
// cannot use scanf("%d\n", &N ) here, since \n means skipping any whitespace character
    scanf( "%d", &N );
    getchar();

    char line[MAX_NUMBER_OF_LINE][MAX_STRING_LEN] = {0};
    int length[MAX_NUMBER_OF_LINE] = {0};
    
    for( int i = 1; i <= N; i++ ) {
        int j = 0;
        char ch = getchar();

        while ( ch != '\n') {
            line[i][j++] = ch;
            ch = getchar();
        }
        
        length[i] = j;
    }

    int lengthOfCommonSuffix = length[1];
    
    for( int i = 2; i <= N ; i++ ) {
        int k = 0;
        while( (line[1][ length[1] - k - 1 ] == line[i][ length[i] - k - 1 ]) 
             && ( k < lengthOfCommonSuffix ) && ( k < length[i] ) )
            k++;
        if ( k < lengthOfCommonSuffix )
            lengthOfCommonSuffix = k;
     }

    if ( lengthOfCommonSuffix == 0 )
        printf("nai");
    else {
        for ( int j = lengthOfCommonSuffix ; j >= 1 ; j-- ) {
            printf("%c", line[1][ length[1] - j ]);
        }
    } 

    return 0;
}
