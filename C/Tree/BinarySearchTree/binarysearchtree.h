//
//  BinarySearchTree.h
//  BinarySearchTree
//
//  Created by Chen Ciro on 15/10/14.
//  Copyright © 2015年 Chen. All rights reserved.
//

typedef int ElementType;

#ifndef binarysearchtree_h
#define binarysearchtree_h

#define Error( Str )        FatalError( Str )
#define FatalError( Str )   fprintf( stderr, "%s\n", Str ), exit( 1 )

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

SearchTree MakeEmpty( SearchTree T );
Position Find( ElementType X, SearchTree T );
Position FindMin( SearchTree T );
Position FindMax( SearchTree T );
SearchTree Delete( ElementType X, SearchTree T );
SearchTree Insert( ElementType X, SearchTree T );
ElementType Retrieve( Position P );
void PrintTree( SearchTree T, int level );

#endif /* binarysearchtree_h */
