#include <stdio.h>
#define MAX_STRING_LENGTH 60

void get_string( char * string ) {
    char ch = getchar();
    for( int i= 0; ch != '\n'; i++ ) {
        string[i] = ch;
        ch = getchar();
    }
}

int is_letter( char ch ) {
    if ( (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') )
        return 1;
    else 
        return 0;
}

// The pitfall is in checking legimacy of characters, just apply the most strict boundary implied
int is_weekday_letter( char ch) {
    if ( ch >= 'A' && ch <= 'G' )
        return 1;
    else
        return 0;
}

int is_hour_letter( char ch ) {
    if ( ( ch >= 'A' && ch <= 'N' ) || ( ch >= '0' && ch <= '9' ) )
        return 1;
    else
        return 0;
}

int main()
{
    char string1[MAX_STRING_LENGTH] = {},
         string2[MAX_STRING_LENGTH] = {},
         string3[MAX_STRING_LENGTH] = {},
         string4[MAX_STRING_LENGTH] = {};

    get_string( string1 );
    get_string( string2 );
    get_string( string3 );
    get_string( string4 );
    
    // find the first common capital English letter in first & second string
    int i = 0;
    for ( ; (string1[i] != string2[i]) || ( ! is_weekday_letter(string1[i]) ) ; i++ )
        ;
    char first_common_capital_letter = string1[i];
    int letter_position = first_common_capital_letter - 'A' + 1;
    
    // print weekday
    switch ( letter_position ) {
        case 1: printf("MON"); break;
        case 2: printf("TUE"); break;
        case 3: printf("WED"); break;
        case 4: printf("THU"); break;
        case 5: printf("FRI"); break;
        case 6: printf("SAT"); break;
        case 7: printf("SUN"); break;
        default: printf("WWW");
    }

    printf(" ");

    // find the second common character in first & second string
    for ( i++; (string1[i] != string2[i]) || ( ! is_hour_letter(string1[i] ) ) ; i++ )
        ;
    char second_common_character = string2[i];

    // print hour
    int hour;
    if( is_letter( second_common_character ) ) { 
        hour = second_common_character - 'A' + 10;
        printf("%d", hour);
    }
    else {
        hour = second_common_character - '0';
        printf("0%d", hour);
    }

    printf(":");

    // find the common english letter in third & forth string
    int j = 0;
    for ( ; ( string3[j] != string4[j] ) || ( ! is_letter( string3[j] ) ) ; j++ )
        ;

    // print minute
    int minute = j;
    if ( minute < 10 )
        printf( "0%d", minute );
    else
        printf( "%d", minute );

    return 0;
}
