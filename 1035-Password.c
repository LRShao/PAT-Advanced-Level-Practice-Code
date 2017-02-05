#include <stdio.h>

#define MAX_INFO_LEN 22
#define MAX_NUMBER_OF_ACCOUNT 1000

#define TRUE  1
#define FALSE 0

int main() {
    int N;
    scanf("%d\n", &N );
    
    // entries 0..10 to store username, 11..21 to store password, end with -1 
    char modifiedAccounts[ MAX_NUMBER_OF_ACCOUNT ][ MAX_INFO_LEN ] = {0};
    int numberOfAccountsModified = 0;

    for( int i = 1; i <= N; i++ ){
        char ch;

        int j = 0;
        while( ( ch = getchar() ) != ' ' ) {
            modifiedAccounts[ numberOfAccountsModified ][ j++ ] = ch;
        }
        modifiedAccounts[ numberOfAccountsModified ][ j ] = -1;

        int isModified = FALSE;
        j = 11;
        while( ( ch = getchar() ) != '\n' ) {
            if ( ch == '1') 
                ch = '@', isModified = TRUE;
            else if ( ch == '0' )
                ch = '%', isModified = TRUE;
            else if ( ch == 'l' )
                ch = 'L', isModified = TRUE;
            else if ( ch == 'O' )
                ch = 'o', isModified = TRUE;

            modifiedAccounts[ numberOfAccountsModified ][ j++ ] = ch;            
        }
        modifiedAccounts[ numberOfAccountsModified ][ j ] = -1;

        if ( isModified )
            numberOfAccountsModified ++;
    }

    if ( numberOfAccountsModified == 0 ) {
        if ( N == 1 )
            printf("There is 1 account and no account is modified\n");
        else
            printf("There are %d accounts and no account is modified\n", N );
     }
    else {
        printf("%d\n", numberOfAccountsModified );

        for( int k = 0; k < numberOfAccountsModified; k++ ) {
            for ( int j = 0; modifiedAccounts[ k ][ j ] != -1; j++ )
                putchar( modifiedAccounts[ k ][ j ] );
            putchar(' ');
            for ( int j = 11; modifiedAccounts[ k ][ j ] != -1; j++ )
                putchar( modifiedAccounts[ k ][ j ] );
            putchar('\n');
        }
    }
    
    return 0;    
}
