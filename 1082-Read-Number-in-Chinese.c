#include <stdio.h>
// abs is in stdlib.h instead of math.h
#include <stdlib.h>

#define MAX_NUMBER_OF_DIGIT 10

#define POSITIVE 1
#define NEGATIVE 0

void print_digit_in_chinese( int n ) {
    switch( n ) {
        case 0:
            printf( "ling" );   break;
        case 1:
            printf( "yi" );     break;
        case 2:
            printf( "er" );     break;
        case 3:
            printf( "san" );    break;
        case 4:
            printf( "si" );     break;
        case 5:
            printf( "wu" );     break;
        case 6:
            printf( "liu" );    break;
        case 7:
            printf( "qi" );     break;
        case 8:
            printf( "ba" );     break;
        case 9:
            printf( "jiu" );    break;
    };
}

int search_for_next_non_zero_position ( int position, int *digit ) {
    do {
        position ++;
    }
    while( digit[ position ] == 0 && position < 10 );

    return position;
}

int main() {
    long int number;
    scanf( "%ld", &number );

    if ( number == 0 ) {
        printf( "ling" );
        return 0;
    }

    // digit[0] stores the sign
    int digit[ MAX_NUMBER_OF_DIGIT ] = { 0 };

    digit[0] = ( number >= 0 ) ? POSITIVE : NEGATIVE;
    number = abs( number );

    int i = 9;
    while( number != 0 ) {
        digit[ i-- ] = number % 10;
        number = number / 10;
    }

    if ( digit[0] == NEGATIVE ) {
        printf( "Fu" );
        putchar( ' ' );
    }

    int place = search_for_next_non_zero_position( 0, digit );
    int next;
    while ( place <= 9 ) {
        switch( place ) {
            case 1:
                print_digit_in_chinese( digit[1] );                
                printf( " Yi" );
                next = search_for_next_non_zero_position( place, digit );
                if ( next != 10 ) { 
                    putchar( ' ' );
                    place ++;
                }
                else
                    place = 10;
                break;
            case 2:
                print_digit_in_chinese( digit[2] );
                if ( digit[2] != 0 )
                    printf( " Qian" );
                next = search_for_next_non_zero_position( place, digit );
                putchar( ' ' );
                if ( next != 10 ) {
                    if ( digit[2] != 0 ) { 
                        if ( next > 5 )
                            place = 5;
                        else
                            place ++;
                    }
                    else 
                        place = next;
                }
                else
                    place = 5;
                break;
            case 3:
                print_digit_in_chinese( digit[3] );
                if ( digit[3] != 0 )
                    printf( " Bai" );
                next = search_for_next_non_zero_position( place, digit );
                putchar( ' ' );
                if ( next != 10 ) {
                    if ( next > 5 ) 
                        place = 5;
                    else {
                        if ( digit[3] != 0 )
                            place ++;
                        else 
                            place = next;
                    }
                }
                else
                    place = 5;
                break;
            case 4:
                if ( digit[4] != 1 ) {
                    print_digit_in_chinese( digit[4] );
                    putchar( ' ' );
                }
                if ( digit[4] != 0 ) {
                    printf( "Shi" );
                    putchar( ' ' );
                }
                next = search_for_next_non_zero_position( place, digit );
                if ( next != 10 ) 
                    place ++;
                else
                    place = 5;
                break;
            case 5:
                if ( digit[5] != 0 ) {
                    print_digit_in_chinese( digit[5] );
                    putchar( ' ' );
                }
                printf( "Wan" );
                next = search_for_next_non_zero_position( place, digit );
                if ( next != 10 ) {
                    putchar( ' ' );
                    place ++;
                }
                else
                    place = 10;
                break;
            case 6:
                print_digit_in_chinese( digit[6] );
                if ( digit[6] != 0 )
                    printf( " Qian" );
                next = search_for_next_non_zero_position( place, digit );
                if ( next != 10 ) {
                    putchar( ' ' );
                    if ( digit[6] != 0 )
                        place ++;
                    else
                        place = next;
                }
                else
                    place = 10;
                break;
            case 7:
                print_digit_in_chinese( digit[7] );
                if ( digit[7] != 0 )
                    printf( " Bai" );
                next = search_for_next_non_zero_position( place, digit );
                if ( next != 10 ) {
                    putchar( ' ' );
                    if ( digit[7] != 0 )    
                        place ++;
                    else
                        place = next;
                }
                else
                    place = 10;
                break;
            case 8:
                if ( digit[8] != 1 ) {
                    print_digit_in_chinese( digit[8] );
                    putchar( ' ' );
                }
                if ( digit[8] != 0 )
                    printf( "Shi" );
                next = search_for_next_non_zero_position( place, digit );
                if ( next != 10 ) {
                    if ( digit[8] != 0 )
                        putchar( ' ' );
                    place ++;
                }
                else
                    place = 10;
                break;
            case 9:
                print_digit_in_chinese( digit[9] );
                place ++;
        }
    }
    
    return 0;
}
