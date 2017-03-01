#include <algorithm>
#include <cstdio>
#include <stack>

using namespace std;

struct TreeNode{
	int value;
	TreeNode * left;
	TreeNode * right;

	TreeNode( int inputNumber ){
		value = inputNumber;
		left = NULL;
		right = NULL;
	}
};

int node_height( TreeNode * node ){
	if ( node == NULL )
		return -1;
	else
		return max( node_height( node->left ), node_height( node->right ) ) + 1 ;
}

void right_rotation( TreeNode * pRoot ){
	TreeNode * pX = pRoot -> left,
			 * pY = pRoot,
			 * pA = pX -> left,
			 * pB = pX -> right,
			 * pC = pY -> right;
	// Rotate
	swap( *pX, *pY );
	pY -> left = pA;
	pY -> right = pX;
	pX -> left = pB;
	pX -> right = pC;
}

void left_rotation( TreeNode * pRoot ){
	TreeNode * pX = pRoot,
			 * pY = pX -> right,
			 * pA = pX -> left,
			 * pB = pY -> left,
			 * pC = pY -> right;
	// Rotate
	swap( *pX, *pY );
	pX -> left = pY;
	pX -> right = pC;
	pY -> left = pA;
	pY -> right = pB;
}

TreeNode * insert_into_AVL_tree( int number, TreeNode * pRoot){
	if ( pRoot == NULL ){
		pRoot = new TreeNode( number );
		return pRoot;
	}

	stack < TreeNode * > insertionPath;

	// deternmine insertion place
	TreeNode * pPath = pRoot;
	insertionPath.push( pPath );
	while( 1 ){
		if ( pPath->value > number ){
			if ( pPath->left != NULL )
				pPath = pPath->left;
			else
				break;
		}
		else{
			if ( pPath->right != NULL )
				pPath = pPath->right;
			else
				break;
		}

		insertionPath.push( pPath );
	}

	stack < TreeNode * > insertionPathCopy = insertionPath;

	// insert
	TreeNode  * newNode = new TreeNode( number );
	if ( pPath->value > number )
		pPath->left = newNode;
	else
		pPath->right = newNode;

	// fix height
	TreeNode * pPrev = NULL;
	while( insertionPath.size() != 0 ){
		if ( pPrev == NULL )
			pPrev = newNode;
		else
			pPrev = pPath;
		pPath = insertionPath.top();
		insertionPath.pop();
	}

	// find first node along the path that is out of balance
	do{
		pPath = insertionPathCopy.top();
		insertionPathCopy.pop();
	}
	while( insertionPathCopy.size() != 0 && ( abs( node_height( pPath -> left ) - node_height( pPath -> right ) ) < 2  ) );

	if ( node_height( pPath -> left ) - node_height( pPath -> right )  == 2 ){			// left heavy
		if ( node_height( pPath -> left -> left ) > node_height( pPath -> left -> right ) )
			right_rotation( pPath );
		else{
			left_rotation( pPath -> left );
			right_rotation( pPath );
		}
	}
	else if ( node_height( pPath -> left ) - node_height( pPath -> right )  == -2 ){	// right heavy
		if ( node_height( pPath -> right -> right ) > node_height( pPath -> right -> left ) )
			left_rotation( pPath );
		else{
			right_rotation( pPath -> right );
			left_rotation( pPath );
		}
	}

	return pRoot;
}

int main(){
	int numberOfTreeNodes;
	scanf( "%d", &numberOfTreeNodes );

	TreeNode * pRoot = NULL;
	for( int i = 0; i < numberOfTreeNodes; i++ ){
		int inputNumber;
		scanf( "%d", &inputNumber );
		pRoot = insert_into_AVL_tree( inputNumber, pRoot );
	}

	printf( "%d", pRoot->value );

	return 0;
}