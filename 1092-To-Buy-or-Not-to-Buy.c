#include <stdio.h>
#include <ctype.h>

#define NUMBER_OF_COLORS 62

int main() {
    // 0..9: 0-9, 10..35: a-z, 36..61: A-Z
    int beads[ NUMBER_OF_COLORS ] = {0};
    
    char ch;
    while( ( ch = getchar() ) != '\n' ) {
        if ( isdigit( ch ) )
            beads[ ch - '0' ] ++;
        else if ( islower( ch ) )
            beads[ ch - 'a' + 10 ] ++;
        else
            beads[ ch - 'A' + 36 ] ++;
    }

    int numberOfMissingBeads = 0;

    while( ( ch = getchar() ) != '\n' ) {
        if ( isdigit( ch ) ) {
            if( beads[ ch - '0' ] > 0 )
                beads[ ch - '0' ] --;
            else
                numberOfMissingBeads ++;
        }
        else if ( islower( ch ) ) {
            if( beads[ ch - 'a' + 10 ] > 0 )
                beads[ ch - 'a' + 10 ] --;
            else
                numberOfMissingBeads ++;
        }
        else {
            if( beads[ ch - 'A' + 36 ] > 0 )
                beads[ ch - 'A' + 36 ] --;
            else
                numberOfMissingBeads ++;
        }
    }

    if ( numberOfMissingBeads == 0 ) {
        printf("Yes ");
        int numberOfExtraBeads = 0;
        for ( int i = 0; i < NUMBER_OF_COLORS; i++ )
            numberOfExtraBeads += beads[i];
        printf("%d", numberOfExtraBeads );
    }
    else {
        printf("No %d", numberOfMissingBeads );
    }

    return 0;
}
