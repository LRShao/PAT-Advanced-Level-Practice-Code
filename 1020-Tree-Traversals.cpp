#include <cstdio>

// notice this implementation has a flaw. It may overflow or timeout if the binary tree has too many levels.
const int MAX_NUMBER_OF_NODES = 100000;

int postOrderTraversal[ MAX_NUMBER_OF_NODES ];
int inOrderTraversal [ MAX_NUMBER_OF_NODES ];
int levelOrderTraversal [ MAX_NUMBER_OF_NODES ];

void build_binary_tree( int levelOrderPosition, int postOrderBegin, int inOrderBegin, int numberOfTreeNodes ){
	if( numberOfTreeNodes <= 0 ) {
		return;
	}
	
	int rootValue = postOrderTraversal[ postOrderBegin + numberOfTreeNodes - 1 ];
	levelOrderTraversal[ levelOrderPosition ] = rootValue;
	
	int i;
	for ( i = inOrderBegin; i < ( inOrderBegin + numberOfTreeNodes ); i++ )
		if ( inOrderTraversal[ i ] == rootValue )
			break;
	
	int inOrderRoot = i,
		numberOfLeftTreeNodes = inOrderRoot - inOrderBegin,
		numberOfRightTreeNodes = inOrderBegin + numberOfTreeNodes - 1 - inOrderRoot;
	
	build_binary_tree( levelOrderPosition * 2 + 1, postOrderBegin, inOrderBegin, numberOfLeftTreeNodes );
	build_binary_tree( levelOrderPosition * 2 + 2, postOrderBegin + numberOfLeftTreeNodes, inOrderRoot + 1, numberOfRightTreeNodes );
}

int main() {
	int numberOfTreeNodes;
	scanf( "%d\n", &numberOfTreeNodes );
	
	for ( int i = 0; i < numberOfTreeNodes; i++ )
		scanf( "%d", &postOrderTraversal[i] );
	
	for ( int i = 0; i < numberOfTreeNodes; i++ )
		scanf( "%d", &inOrderTraversal[i] );
	
	build_binary_tree( 0, 0, 0, numberOfTreeNodes );
	
	int counter = 0;
	for ( int i = 0; counter < numberOfTreeNodes; i++ ){
		if ( levelOrderTraversal[ i ] ){
			counter ++;
			printf( "%d", levelOrderTraversal[ i ] );
			if ( counter < numberOfTreeNodes )
				printf( " " );
		}
	}

	return 0;
}