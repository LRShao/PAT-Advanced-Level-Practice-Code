#include <stdio.h>
#include <ctype.h>

void print_mars_number_high( int highPlace ) {
    switch( highPlace ) {
        case 1:
            printf("tam"); break;
        case 2:
            printf("hel"); break;
        case 3:
            printf("maa"); break;
        case 4:
            printf("huh"); break;
        case 5:
            printf("tou"); break;
        case 6:
            printf("kes"); break;
        case 7:
            printf("hei"); break;
        case 8:
            printf("elo"); break;
        case 9:
            printf("syy"); break;
        case 10:
            printf("lok"); break;
        case 11:
            printf("mer"); break;
        case 12:
            printf("jou");
    }
}

void print_mars_number_low ( int lowPlace ) {
    switch( lowPlace ) {
        case 1:
            printf("jan"); break;
        case 2:
            printf("feb"); break;
        case 3:
            printf("mar"); break;
        case 4:
            printf("apr"); break;
        case 5:
            printf("may"); break;
        case 6:
            printf("jun"); break;
        case 7:
            printf("jly"); break;
        case 8:
            printf("aug"); break;
        case 9:
            printf("sep"); break;
        case 10:
            printf("oct"); break;
        case 11:
            printf("nov"); break;
        case 12:
            printf("dec");
    }
}

int convert_mars_number_high( char * word ) {
    switch( word[0] ) {
        case 't':
            if ( word[1] == 'a' )
                return 1;
            else
                return 5;
        case 'h':
            if ( word[2] == 'l' )
                return 2;
            else if ( word[1] == 'u' )
                return 4;
            else 
                return 7; 
        case 'm':
            if ( word[1] == 'a' )
                return 3;
            else
                return 11;
        case 'k':
            return 6;
        case 'e':
            return 8;
        case 's':
            return 9;
        case 'l':
            return 10;
        case 'j':
            return 12;
    }
}

int convert_mars_number_low( char * word ) {
    switch( word[0] ) {
        case 'j':
            if ( word[1] == 'a' )
                return 1;
            else if ( word[1] == 'u' )
                return 6;
            else if ( word[1] == 'l' )
                return 7;
            else
                return 0;
        case 'f':
            return 2;
        case 'm':
            if ( word[1] == 'a' && word[2] == 'r' )
                return 3;
            else if ( word[2] == 'y' )
                return 5;
            else
                return 0;
        case 'a':
            if ( word[1] == 'p' )
                return 4;
            else
                return 8;
        case 's':
            if ( word[1] == 'e' )
                return 9;
            else
                return 0;
        case 'o':
            return 10;
        case 'n':
            return 11;
        case 'd':
            return 12;
        default:
            return 0;
    }
}

int main() {
    int N;
    scanf( "%d\n", &N );
    
    for( int i = 1; i <= N; i++ ) {
    
        char ch = getchar();

        if ( isdigit( ch ) ) {
            int number = ch - '0';
            while ( ( ch = getchar() ) != '\n' )
                number = number * 10 + ( ch - '0' );
            
            int highPlace = number / 13, 
                lowPlace  = number % 13;

            if ( highPlace != 0 ) {
                print_mars_number_high( highPlace );
            
                if ( lowPlace != 0) {
                    putchar(' ');
                    print_mars_number_low( lowPlace );
                }
            }
            else {
                if ( lowPlace != 0) 
                    print_mars_number_low( lowPlace );
                else
                    printf("tret");
            }

            putchar('\n');
        }
        else {
            // for two-place number: 0..2: highPlace; 3: space; 4..6/7:lowPlace
            char input[9];
            
            input[0] = ch;
            int i = 1;
            while( ( ch = getchar() ) != '\n' )
                input[ i++ ] = ch;

            if ( i == 4 )
                putchar('0');
            else if ( i == 3 ) {
                if ( convert_mars_number_low ( &input[0] ) )
                    printf( "%d", convert_mars_number_low( &input[0] ) );
                else
                    printf( "%d", 13 * convert_mars_number_high( &input[0] ) );
            }
            else {
                int number = 13 * convert_mars_number_high( &input[0] )
                            +     convert_mars_number_low( &input[4] ); 
                printf( "%d", number );
            }
     
            putchar('\n');
        }
            
    }
    
    return 0;
}
