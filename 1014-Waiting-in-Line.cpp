#include <algorithm>
#include <iomanip>
#include <iostream>
#include <queue>

#define OPENING_TIME 8, 00

using namespace std;

const int MAX_NUMBER_OF_WINDOWS = 20;
const int MAX_NUMBER_OF_CUSTOMERS = 1000;
const int MAX_NUMBER_OF_QUERIES = 1000;

struct Timer{
	int hour,
		minute;
	
	void set( int inputHour, int inputMinute ) {
		hour = inputHour;
		minute = inputMinute;
	}

	bool forward_minute( int minuteForward ) {
		hour = hour + ( minute + minuteForward ) / 60;
		minute = ( minute + minuteForward ) % 60;
		if ( hour >= 17 )
			return false;
		else
			return true;
	}

	void operator = ( const Timer & timer ) {
		hour = timer.hour;
		minute = timer.minute;
	}

	bool operator == ( const Timer & timer ) {
		return ( hour == timer.hour && minute == timer.minute );
	}
};

ostream & operator << ( ostream & os, const Timer & timer ) {
	os << setw(2) << setfill('0') << timer.hour <<  ':' 
	   << setw(2) << setfill('0') << timer.minute;
	return os;
}

struct Customer{
	int serialNumber;
	int processingTime;
};

struct Window{
	int windowNumber;
	Timer currentFinishTime;
	queue< Customer > customerQueue;
	
	void initialize() {
		currentFinishTime.set( OPENING_TIME );	
	}

	void push( Customer customer ){
		customerQueue.push( customer );
		if ( customerQueue.size() == 1 )
			currentFinishTime.forward_minute( customer.processingTime );
	}

	bool pop_according_to_time( const Timer & timer , int & popedCustomerNumber ) {
		if ( ! ( currentFinishTime == timer) || customerQueue.size() == 0 )
			return false;
		else {
			popedCustomerNumber = customerQueue.front().serialNumber;
			customerQueue.pop();

            if ( customerQueue.size() != 0 )
				currentFinishTime.forward_minute( customerQueue.front().processingTime );

			return true;
		}
	}

	// all servivce started before close time should be finished no matter when it will end
	bool pop_started( int & popedCustomerNumber, Timer & popedTime ) {
		if ( customerQueue.size() == 0 )
			return false;
		else {
			popedCustomerNumber = customerQueue.front().serialNumber;
			popedTime = currentFinishTime;
			customerQueue.pop();
			return true;
		}
	}

	bool operator < ( const Window & window ) const {
		if ( customerQueue.size() < window.customerQueue.size() )
			return true;
		else if ( windowNumber < window.windowNumber )
			return true;
		else
			return false;
	}
};

struct BufferArea{
	int numberOfWindows,
	    bufferSizePerWindow,
		totalBufferSize,
	    currentNumberOfCustomers;

	Window window[ MAX_NUMBER_OF_WINDOWS + 1 ];

	BufferArea( int inputNumberOfWindows, int inputBufferSizePerWindow ){
		numberOfWindows = inputNumberOfWindows;
		bufferSizePerWindow = inputBufferSizePerWindow;
		totalBufferSize = numberOfWindows * bufferSizePerWindow;
		currentNumberOfCustomers = 0;

		for ( int i = 0; i < numberOfWindows; i++ ) {
			window[i].initialize();
			window[i].windowNumber = i;
		}
	}

	bool push( const Customer & customer ){
		if ( currentNumberOfCustomers == totalBufferSize )
			return false;
		else{
			Window * pWindow = min_element( window, window + numberOfWindows );
			pWindow->push( customer );
			currentNumberOfCustomers++;
			return true;
		}
	}

	bool pop_according_to_time( Timer time, Timer * finishTime ){
		bool ifPoped = false ;
		for ( int i = 0; i < numberOfWindows ; i++ ) {
			int popedCustomerNumber;
			if ( window[i].pop_according_to_time( time, popedCustomerNumber ) ){
				finishTime[ popedCustomerNumber ] = time;
				currentNumberOfCustomers --;
				ifPoped = true;
			}
		}
		return ifPoped;
	}

	void pop_started( Timer * finishTime ) {
		for ( int i = 0; i < numberOfWindows ; i++ ) {
			int popedCustomerNumber;
			Timer popedTime;
			if ( window[i].pop_started( popedCustomerNumber, popedTime ) ){
				finishTime[ popedCustomerNumber ] = popedTime;
				currentNumberOfCustomers --;
			}
		}
	}
};

int main(){
	// N, M, K, Q
	int numberOfWindows, sizeOfBufferPerWindow,
		numberOfCustomers, numberOfQueries;
	
	cin >> numberOfWindows >> sizeOfBufferPerWindow
		>> numberOfCustomers >> numberOfQueries;

	queue< Customer > line;
	for ( int i =0; i < numberOfCustomers; i++ ) {
		Customer currentCustomer;
		currentCustomer.serialNumber = i;
		cin >> currentCustomer.processingTime;
		line.push( currentCustomer );
	}

	Timer finishTime[ MAX_NUMBER_OF_CUSTOMERS ];
	
	int query[ MAX_NUMBER_OF_QUERIES ];
	for ( int j = 0; j < numberOfQueries; j++ ) {
		cin >> query[j];
		query[j] --;
		finishTime[ query[j] ].set( -1, 0 );
	}

	Timer currentTime;
	currentTime.set( OPENING_TIME );

	BufferArea bufferArea( numberOfWindows, sizeOfBufferPerWindow );

	int totalBufferSize = numberOfWindows * sizeOfBufferPerWindow;

	int timesOfPush = min( numberOfCustomers, totalBufferSize );

	for ( int t = 1; t <= timesOfPush; t++  ) {
		bufferArea.push( line.front() );
		line.pop();
	}

	while(1) {
		if ( ( ! currentTime.forward_minute( 1 ) ) || bufferArea.currentNumberOfCustomers  == 0 )
			break;

		if ( bufferArea.pop_according_to_time( currentTime, finishTime ) ){
			while ( line.size() > 0 ) {
				if ( bufferArea.push( line.front() ) )
					line.pop();
				else
					break;
			}
		}
	}

	bufferArea.pop_started( finishTime );

	for (  int j = 0; j < numberOfQueries; j++ ) {
		if ( finishTime[ query[j] ].hour > 0 )
			cout << finishTime[ query[j] ];
		else
			cout << "Sorry";

		cout << endl;
	}

	char test;
	cin >> test;

	return 0;
}
