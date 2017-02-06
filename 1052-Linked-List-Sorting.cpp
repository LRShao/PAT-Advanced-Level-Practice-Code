#include <stdio.h>
#include <algorithm>

#define MAX_NUMBER_OF_INPUT 100000

#define NUMBER_OF_INFO 2
#define KEYWORD 0
#define NEXT    1

#define NULL_POINTER -1

struct node {
    int address;
    int keyword;
  bool operator < ( const node &x ) const {
      return ( keyword < x.keyword );
  }
};


int storage[ MAX_NUMBER_OF_INPUT + 1 ][ NUMBER_OF_INFO ];
struct node listNodes[ MAX_NUMBER_OF_INPUT + 1 ];

void swap( struct node *num1, struct node *num2 ) {
    struct node t = *num1;
    *num1 = *num2;
    *num2 = t;
}

void quick_sort_list_nodes( int begin , int end ) {
    if ( begin < end ) {
        int pivot = listNodes[ begin ].keyword;
        int i = begin,
            j = end;
        while( 1 ) {
            while( listNodes[i].keyword < pivot )
                i++;
            while( listNodes[j].keyword > pivot )
                j--;

            if ( i >= j )
                break;

            std::swap( listNodes[i], listNodes[j] );
        }
        quick_sort_list_nodes( begin , j );
        quick_sort_list_nodes( j+1 , end );
    }
}

int main() {

    int numberOfInputNodes;
        
    // address of head node is stored in storage[0][NEXT];
    scanf( "%d %d", &numberOfInputNodes, &storage[ 0 ][ NEXT ] );
    
    for( int i = 1; i <= numberOfInputNodes ; i++ ) {
        int address;
        scanf( "\n%d ", &address);
        scanf( "%d %d", &storage[ address ][ KEYWORD ],
                        &storage[ address ][ NEXT ]  );
    }

    int numberOfListNodes = 0,
        currentNode = 0;
    
    while( storage[ currentNode ][ NEXT ] != NULL_POINTER ) {
        currentNode = listNodes[ ++ numberOfListNodes ].address
                    = storage[ currentNode ][ NEXT ];
        listNodes[ numberOfListNodes ].keyword = storage[ currentNode ][ KEYWORD ];
     }

    // quick sort, to avoid timeout for test 3
    std::sort( listNodes + 1, listNodes + numberOfListNodes + 1 );

    // special case, appeared in test 4
    if ( numberOfListNodes == 0 ) {
        printf("0 -1");
        return 0;
    }

    printf( "%d %05d", numberOfListNodes, listNodes[1].address );
    printf("\n");
    
    for ( int i = 1; i <= numberOfListNodes; i++ ) {
        printf( "%05d %d ", listNodes[ i ].address, listNodes[i].keyword );
        
        if ( i != numberOfListNodes ) {
            printf( "%05d\n", listNodes[ i+1 ].address );
        }
        else
            printf("-1");
    }
        
    return 0;
}
