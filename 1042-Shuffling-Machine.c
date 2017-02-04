#include <stdio.h>

#define NUMBER_OF_CARDS 54

enum suits { J, S, H, C, D };

void print_suit( enum suits s ) {
    switch( s ) {
        case J:
            putchar('J'); break;
        case S:
            putchar('S'); break;
        case H:
            putchar('H'); break;
        case C:
            putchar('C'); break;
        case D:
            putchar('D');
    }
}

int main() {
    enum suits suitBefore[ NUMBER_OF_CARDS + 1 ];
    int   numBefore [ NUMBER_OF_CARDS + 1 ];
    
    for( int i = 1; i <= 52 ; i++ ) {
        suitBefore[i] = ( enum suits )( ( i-1 ) / 13 + 1 );
        numBefore [i] =  ( i-1 ) % 13 + 1;
    }
    
    suitBefore[53] = suitBefore[54] = J,
    numBefore [53] = 1,
    numBefore [54] = 2;

    int timesOfShuffling;
    scanf("%d", &timesOfShuffling );

    int shufflingOrder[ NUMBER_OF_CARDS + 1 ];
    for( int i = 1; i <= 54 ; i++ ) {
        scanf("%d", &shufflingOrder[ i ] );
        if ( i != 54 )
            getchar();
    }
    
    enum suits suitAfter[ NUMBER_OF_CARDS + 1 ];
    int   numAfter [ NUMBER_OF_CARDS + 1 ];

    for( int j = 1; j <= timesOfShuffling; j++ ) {
        for( int i = 1; i <= 54; i++ ) {
            suitAfter[ shufflingOrder[ i ] ] = suitBefore[ i ];
            numAfter [ shufflingOrder[ i ] ] = numBefore [ i ];
        }
        for( int i = 1; i <= 54; i++ ) {
            suitBefore[ i ] = suitAfter[ i ];
            numBefore [ i ] = numAfter [ i ];
        }
    }

    for( int i = 1; i <= 54; i++ ) {
        print_suit( suitAfter[ i ] );
        printf("%d", numAfter[ i ] );

        if ( i != 54 )
            putchar(' ');
    }
     
    return 0;
}
