#include <algorithm>
#include <iomanip>
#include <iostream>

using namespace std;

const int MAX_NUMBER_OF_INPUT_CASES = 100 * 300;
const int MAX_NUMBER_OF_TEST_LOCATIONS = 100;

struct TesteeInfo {
    long int registrationNumber;
    int grade;
    int locationNumber;
    
    TesteeInfo() {
        registrationNumber = 0;
        grade = 0;
        locationNumber = 0;
    }
};

struct RankCounter {
    int currentRanking;
    int currentGrade;
    int currentGradeCounter;
    
    RankCounter() {
        currentRanking = 0;
        currentGrade = 101;
        currentGradeCounter = 1;
    }

    int rank( int grade ) {
        if ( grade < currentGrade ) {
            currentRanking += currentGradeCounter;
            currentGrade = grade;
            currentGradeCounter = 1;
            return currentRanking;
        }
        else {
            currentGradeCounter ++;
            return currentRanking;
        }
    }
};

// non-increasing order of grade, non-decreasing order of registration number
bool compare_grade( const TesteeInfo &case1, const TesteeInfo &case2 ) {
    if ( case1.grade > case2.grade )
        return true;
    else if ( case1.grade < case2.grade )
        return false;
    else { 
        if ( case1.registrationNumber <= case2.registrationNumber )
            return true;
        else
            return false;
    }
}

int main() {
    TesteeInfo inputCases[ MAX_NUMBER_OF_INPUT_CASES ];

    int numberOfTestLocations;
    cin >> numberOfTestLocations;

    int totalNumberOfInputCases = 0;
    for ( int locationNumber = 1; locationNumber <= numberOfTestLocations; locationNumber++ ) {
        int numberOfCasesInCurrentLocation;
        cin >> numberOfCasesInCurrentLocation;
        for ( int j = 1; j <= numberOfCasesInCurrentLocation; j++ ) {
            TesteeInfo currentCase;

            cin >> currentCase.registrationNumber >> currentCase.grade;
            currentCase.locationNumber = locationNumber;
            
            inputCases[ totalNumberOfInputCases ++ ] = currentCase;
        }
    }

    sort( inputCases, inputCases + totalNumberOfInputCases, compare_grade );
    
    cout << totalNumberOfInputCases << endl;

    // counter[0] is the global counter
    RankCounter counter[ MAX_NUMBER_OF_TEST_LOCATIONS + 1 ];

    for ( int k = 0; k < totalNumberOfInputCases; k++ ) {
        TesteeInfo currentCase = inputCases[ k ];
        cout << setfill('0') << setw(13) << currentCase.registrationNumber;
        cout << " " << counter[0].rank( currentCase.grade );
        cout << " " << currentCase.locationNumber;
        cout << " " << counter[ currentCase.locationNumber ].rank( currentCase.grade );
        cout << endl;
    }

    return 0;
}
