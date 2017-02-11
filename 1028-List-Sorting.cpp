#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
// no need to include <string> to use cin and cout to input or output a string

#define MAX_NUMBER_OF_RECORDS 100000
#define NUMBER_OF_DIGIT_IN_ID 6
#define MAX_LENGTH_OF_NAME    8

typedef struct entry {
    int id[ NUMBER_OF_DIGIT_IN_ID ];
    char name[ MAX_LENGTH_OF_NAME + 1 ];
    int grade;
    // constructor
    entry() {
        id[0] = 0;
        name[0] = '\0'; 
        grade = 0;
    }
} record;

// id in increasing order
bool compare_column_1( const record &record1, const record &record2 ) {
    bool isSmaller = false;
    int i = 0;
    while ( record1.id[i] == record2.id[i] )
        i++;

    isSmaller = ( record1.id[i] < record2.id[i] );
    
    return isSmaller;
}

// name in non-decreasing order
bool compare_column_2( const record &record1, const record &record2 ) {
    int comparationResult = strcmp( record1.name, record2.name );
    if ( comparationResult < 0 )
        return true;
    else if ( comparationResult > 0 )
        return false;
    else
        return compare_column_1( record1, record2 );
}

// grade in non-decreasing order
bool compare_column_3( const record &record1, const record &record2 ) {
    if ( record1.grade < record2.grade )
        return true;
    else if ( record1.grade > record2.grade )
        return false;
    else
        return compare_column_1( record1, record2 );
}


int main() {
    int numberOfRecords, column;
    scanf( "%d %d", &numberOfRecords, &column );

    record inputRecords[ MAX_NUMBER_OF_RECORDS ];

    for ( int i = 0; i < numberOfRecords; i++ ) {
        scanf("\n");
        record currentRecord;

        char ch;

        int j = 0;
        while ( ( ch = getchar() ) != ' ' )
            currentRecord.id[ j++ ] = ch - '0';

        std::cin >> currentRecord.name;

        scanf( " %d", &currentRecord.grade );
        
        inputRecords[ i ] = currentRecord;    
    }

    switch ( column ) {
        case 1:
            std::sort( inputRecords, inputRecords + numberOfRecords, compare_column_1 );
            break;
        case 2:
            std::sort( inputRecords, inputRecords + numberOfRecords, compare_column_2 );
            break;
        case 3:
            std::sort( inputRecords, inputRecords + numberOfRecords, compare_column_3 );
    }

    for ( int i = 0; i < numberOfRecords; i++ ) {
        for ( int j = 0; j < NUMBER_OF_DIGIT_IN_ID; j++ )
            printf( "%d", inputRecords[i].id[j] );
        
        std::cout << " " << inputRecords[i].name;

        printf( " %d\n", inputRecords[i].grade );
    }

    return 0;
}
