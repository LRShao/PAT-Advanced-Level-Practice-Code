#include <algorithm>
#include <iostream>
#include <string>

const int MAX_NUMBER_OF_RECORD = 10000;
const int MAX_LEN_OF_STRING = 11;

typedef struct entry {
    char name[ MAX_LEN_OF_STRING ];
    char id[ MAX_LEN_OF_STRING ];
    int grade;
} record;

// grade in non-increasing order, i.e. decreasing since grade are distinct )
bool compare_grade( const record & record1, const record & record2 ) {
    if ( record1.grade > record2.grade )
        return true;
    else 
        return false;
}

int main(){
    int numberOfRecords;
    std::cin >> numberOfRecords;

    record inputRecords[ MAX_NUMBER_OF_RECORD ];

    for ( int i = 0; i < numberOfRecords; i++ ) {
        record currentRecord;
        std::cin >> currentRecord.name;
        std::cin >> currentRecord.id;
        std::cin >> currentRecord.grade;

        inputRecords[ i ] = currentRecord;
    }
    
    std::sort( inputRecords, inputRecords + numberOfRecords, compare_grade );

    int grade1, grade2;
    std::cin >> grade1 >> grade2;

    int outputCounter = 0;

    for ( int i = 0; i < numberOfRecords; i++ ) {
        if ( inputRecords[i].grade < grade1 )
            break;
        if ( inputRecords[i].grade <= grade2 ) {
            std::cout << inputRecords[i].name << " "
                 << inputRecords[i].id << std::endl;
            outputCounter ++;
        }
    }

    if ( outputCounter == 0 )
        std::cout << "NONE";

    return 0;
}
