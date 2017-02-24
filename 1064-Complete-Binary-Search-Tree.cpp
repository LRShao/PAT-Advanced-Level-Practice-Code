#include <algorithm>
#include <stdio.h>

#define MAX_NUMBER_OF_INPUT 1000

int counter = 0;
int inputKeys[ MAX_NUMBER_OF_INPUT ];
int inOrderTraversalResult[ MAX_NUMBER_OF_INPUT ];

struct TreeNode{
	int value;
	struct TreeNode * left;
	struct TreeNode * right;
};

struct TreeNode * generate_complete_binary_tree( int value, int totalNumberOfTreeNodes ){
	if ( value > totalNumberOfTreeNodes )
		return NULL;
	else {
		struct TreeNode * newNode = ( struct TreeNode * )malloc( sizeof( TreeNode ) );
		newNode->value = value;	// level order traversal position
		newNode->left =	generate_complete_binary_tree( 2 * value, totalNumberOfTreeNodes );
		newNode->right = generate_complete_binary_tree( 2 * value + 1, totalNumberOfTreeNodes );
		return newNode;
	}
}

void in_order_traversal( struct TreeNode * node ) {
	if ( node == NULL )
		return;
	else{
		in_order_traversal( node->left );
		inOrderTraversalResult[ node->value - 1 ] = inputKeys[ counter ++ ];
		in_order_traversal( node->right );
	}
}

int main(){
	int numberOfInput;
	scanf( "%d", &numberOfInput );

	for ( int i = 0; i < numberOfInput; i++ )
		scanf( "%d", & inputKeys[i] );

	std::sort( inputKeys, inputKeys + numberOfInput );

	struct TreeNode * root = generate_complete_binary_tree( 1, numberOfInput );
	
	in_order_traversal( root );

	int i;
	for ( i = 0; i < numberOfInput - 1; i++ )
		printf( "%d ", inOrderTraversalResult[i] );
	printf( "%d", inOrderTraversalResult[i] );

	return 0;
}