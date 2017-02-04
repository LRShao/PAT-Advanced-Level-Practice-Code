#include <stdio.h>

void print_result_to_bet( int n ) {
    switch( n ) {
        case 0:
            putchar('W');   break;
        case 1:
            putchar('T');   break;
        case 2:
            putchar('L');
    }
}

int main() {
    double odd[3][3];

    int bet[3] = { 0 };
    
    for( int i = 0; i < 3 ; i++ ) {
        for( int j = 0; j < 3 ; j++ ) {
            scanf("%lf", &odd[i][j] );
            if ( ( i != 2 ) || ( j != 2 ) )
                getchar();

            if ( odd[i][j] > odd[i][ bet[i] ] )
                bet[i] = j;
        }
    }

    double profit = ( odd[0][ bet[0] ] * odd[1][ bet[1] ] * odd[2][ bet[2] ] * 0.65 - 1 ) * 2;

    for( int i = 0; i < 3; i++ ) {
        print_result_to_bet( bet[i] );
        putchar(' ');
    }
    
    printf("%.2f", profit );

    return 0;
}
