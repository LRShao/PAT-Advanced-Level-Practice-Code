#include <algorithm>
#include <iostream>

using namespace std;

const int MAX_NUMBER_OF_COUPON_OR_PRODUCT = 100000;

int main() {
    int numberOfCoupon, numberOfProduct;
    long int couponCoefficient[ MAX_NUMBER_OF_COUPON_OR_PRODUCT ] = {0},
             productValue     [ MAX_NUMBER_OF_COUPON_OR_PRODUCT ] = {0};

    cin >> numberOfCoupon;
    for ( int i = 0; i < numberOfCoupon; i++ )
        cin >> couponCoefficient[ i ];

    cin >> numberOfProduct;
    for ( int j = 0; j < numberOfProduct; j++ )
        cin >> productValue[ j ];

    sort( couponCoefficient, couponCoefficient + numberOfCoupon );
    sort( productValue, productValue + numberOfProduct );

    // test
/*
    cout << "couponCoefficient[]:" << endl;
    for ( int i = 0; i < numberOfCoupon; i++ )
        cout << couponCoefficient[ i ] << " ";

    cout << endl;

    cout << "productValue[]:" << endl;
    for ( int j = 0; j < numberOfProduct; j++ )
        cout << productValue[ j ] << " ";
*/
    long int totalMoney = 0;

    int k = 0;
    while ( couponCoefficient[ k ] < 0 && productValue[ k ] < 0 ) {
        totalMoney += couponCoefficient[ k ] * productValue[ k ];
        k++;
    }

    int l = 1;
    while ( couponCoefficient[ numberOfCoupon - l ] > 0
             && productValue[ numberOfProduct - l ] > 0 ) {
        totalMoney += couponCoefficient[ numberOfCoupon - l ]
                      *   productValue[ numberOfProduct - l ];
        l++;        
    }

    cout << totalMoney;

    return 0;
}
