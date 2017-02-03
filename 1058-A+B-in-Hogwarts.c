#include <stdio.h>

#define NUMBER_OF_KNUTS_IN_ONE_SICKLE 29
#define NUMBER_OF_SICKLES_IN_ONE_GALLEON 17

int main() {
    long int galleonA, galleonB, galleonSum;
    int      sickleA , sickleB , sickleSum ,
             knutA   , knutB   , knutSum   ;

    scanf("%ld.%d.%d %ld.%d.%d", &galleonA, &sickleA, &knutA, 
                                   &galleonB, &sickleB, &knutB );

    knutSum   = ( knutA + knutB ) % NUMBER_OF_KNUTS_IN_ONE_SICKLE ; 
    int carry = ( knutA + knutB ) / NUMBER_OF_KNUTS_IN_ONE_SICKLE ;

    sickleSum = ( sickleA + sickleB + carry ) % NUMBER_OF_SICKLES_IN_ONE_GALLEON ;
    carry     = ( sickleA + sickleB + carry ) / NUMBER_OF_SICKLES_IN_ONE_GALLEON ;

    galleonSum = galleonA + galleonB + carry;
    
    printf("%ld.%d.%d", galleonSum, sickleSum, knutSum );

    return 0;
}
