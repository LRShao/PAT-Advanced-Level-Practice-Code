#include <stdio.h>
#include <algorithm>

#define MAX_LEN_OF_NAME 8
#define MAX_NUMBER_OF_PROFILE 100000

#define PRIOR     1
#define INFERIOR  0

typedef struct entry {
    // terminating with \0
    char name[ MAX_LEN_OF_NAME + 1 ];
    int age;
    int netWorth;
} profile;

int compare_profile( profile profile1, profile profile2 ) {
    // deal with empty profile, which should be inferior to any input profile
    if ( profile2.name[0] == '\0' )
        return PRIOR;

    if ( profile1.netWorth > profile2.netWorth )
        return PRIOR;
    else if ( profile1.netWorth < profile2.netWorth )
        return INFERIOR;
    else {
        if ( profile1.age < profile2.age )
            return PRIOR;
        else if ( profile1.age > profile2.age )
            return INFERIOR;
        else {
            int i;
            for ( i = 0; profile1.name[i] == profile2.name[i]; i++ )
                ;
            if ( profile1.name[i] < profile2.name[i] )
                return PRIOR;
            else
                return INFERIOR;
        }
    }
}

int main() {
    int numberOfProfile, numberOfQuery;
    scanf( "%d %d", &numberOfProfile, &numberOfQuery );

    profile inputProfile[ MAX_NUMBER_OF_PROFILE ] = {{{ 0 }}};

    for ( int i = 0; i < numberOfProfile; i++ ) {
        // input '\n';
        scanf( "\n" );

        profile currentProfile = {{ 0 }};

        char ch;
        int k = 0;
        while ( ( ch = getchar() ) != ' ' ) {
             currentProfile.name[k++] = ch;
        }
        currentProfile.name[k] = '\0';

        scanf( "%d %d", &currentProfile.age, &currentProfile.netWorth );

        inputProfile[i] = currentProfile;
    }

    std::sort( inputProfile, inputProfile + numberOfProfile, compare_profile );

    for ( int k = 1; k <= numberOfQuery; k++ ) {
        getchar();
        
        int maxNumberOfOutput,
            minAge, maxAge;
        scanf( "%d %d %d", &maxNumberOfOutput, &minAge, &maxAge );

        printf( "Case #%d:\n", k );

        int outputCounter = 0;
        
        for ( int i = 0; i < numberOfProfile; i++ ) {
            if ( inputProfile[i].age >= minAge && inputProfile[i].age <= maxAge ) {
                int j = 0;
                while ( inputProfile[i].name[j] != '\0' )
                    putchar( inputProfile[i].name[j++] );
                printf( " %d %d\n", inputProfile[i].age, inputProfile[i].netWorth );
                outputCounter ++;

                if ( outputCounter == maxNumberOfOutput )
                    break;
            }
        }

        if ( outputCounter == 0 )
            printf( "None\n" );
    }
    
    return 0;
}
