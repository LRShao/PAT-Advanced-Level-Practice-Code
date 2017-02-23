#include <cctype>
#include <cstdio>
#include <iostream>
#include <string>
#include <stack>

using namespace std;

const int MAX_VALUE_OF_KEY = 100000;
int keyCounter[ MAX_VALUE_OF_KEY + 1 ] = {0};

// If using linear searching algorithm, large test sets will cause time-out
// use a data structure called Binary Index Tree

int identify_command( char * inputCommand ){
	string command = inputCommand;

	if ( command ==  "Push" )
		return 1;
	else if ( command == "Pop" )
		return 2;
	else if ( command == "PeekMedian" )
		return 3;
	else
		return 0;	// invalid command
}

int lowbit( int i ){
	return i & ( - i );
}

int counterSum( int key ){
	int sum = 0;
	for ( int i = key; i; i -= lowbit( i ) )
		sum += keyCounter[i];
	return sum;
}

int main(){
	int numberOfCommands;
	scanf( "%d", &numberOfCommands );
	getchar(); // deal with first '\n'

	stack< int > stack;

	for ( int i = 1; i <= numberOfCommands; i++ ) {		
		char command[20];
		scanf( "%s", command );

		int commandType = identify_command( command );

		switch( commandType ){
			case 0:{
				printf( "Invalid\n" );
			}
			break;

			case 1:{
				int key;
				scanf( "%d\n", &key );

				if ( key <= 0 || key > MAX_VALUE_OF_KEY )
					printf( "Invalid\n" );
				else{
					for ( int i = key; i <= MAX_VALUE_OF_KEY; i += lowbit( i )  )
						keyCounter[ i ] ++;

					stack.push( key );
				}
			}

			break;

			case 2:{
				if ( stack.size() == 0 )
					printf( "Invalid\n" );
				else {
					int poppedKey = stack.top();
					printf( "%d\n", poppedKey );
					for ( int i = poppedKey; i <= MAX_VALUE_OF_KEY; i += lowbit( i )  )
						keyCounter[ i ] --;

					stack.pop();
				}
			}
			break;
			
			case 3:{
				if ( stack.size() == 0 )
					printf( "Invalid\n" );
				else {
					int size = stack.size();
					int middlePosition = ( size + 1 ) / 2;

					int left = 1,
						right = MAX_VALUE_OF_KEY,
						mid = ( left + right ) / 2;
					do {
						if ( counterSum( mid ) >= middlePosition )
							right = mid;
						else if ( counterSum( mid ) < middlePosition )
							left = mid + 1;
						
						mid = ( left + right ) / 2;
					}
					while ( left != right );

					cout << left << endl;
				}
			}
		}
	}

	return 0;
}