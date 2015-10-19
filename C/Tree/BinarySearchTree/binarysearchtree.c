//
//  BinarySearchTree.c
//  BinarySearchTree
//
//  Created by Chen Ciro on 15/10/14.
//  Copyright © 2015年 Chen. All rights reserved.
//

#include "binarysearchtree.h"
#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    ElementType Element;
    SearchTree	Left;
    SearchTree	Right;
};

SearchTree MakeEmpty( SearchTree T )
{
    if( T != NULL )
    {
        MakeEmpty( T->Left );
        MakeEmpty( T->Right );
        free( T );
    }
    
    return NULL;
}

Position Find( ElementType X, SearchTree T )
{
    if( T == NULL )
    {
        return NULL;
    }
    if( X < T->Element )
    {
        return Find( X, T->Left );
    }
    else if( X > T->Element )
    {
        return Find( X, T->Right );
    }
    else
    {
        return T;
    }
}

Position FindMin( SearchTree T )
{
    if( T == NULL )
    {
        return NULL;
    }
    else if( T->Left == NULL )
    {
        return T;
    }
    else
    {
        return FindMin( T->Left );
    }
}

Position FindMax( SearchTree T )
{
    if( T != NULL )
    {
        while( T->Right != NULL )
            T = T->Right;
    }
    
    return T;
}

SearchTree Insert( ElementType X, SearchTree T )
{
    if( T == NULL )
    {
        /* Create and return a one-node tree */
        T = malloc( sizeof( struct TreeNode ));
        if ( T == NULL )
        {
            printf("Out of Space!!!");
        }
        else
        {
            T->Element = X;
            T->Left = T->Right = NULL;
        }
    }
    else if( X < T->Element )
    {
        T->Left = Insert( X, T->Left);
    }
    else if( X > T->Element )
    {
        T->Right = Insert( X, T->Right);
    }
    /* Else X is in the tree already; we'll do nothing */
    
    return T;
}

SearchTree Delete( ElementType X, SearchTree T )
{
    Position TmpCell;
    
    if( T == NULL )
    {
        Error( "Element not found" );
    }
    else if( X < T->Element )/* Go left */
    {
        T->Left = Delete( X, T->Left );
    }
    else if( X > T->Element )  /* Go right */
    {
        T->Right = Delete( X, T->Right );
    }
    /* Found element to be deleted */
    else if( T->Left && T->Right )  /* Two children */
    {
        /* Replace with smallest in right subtree */
        TmpCell = FindMin( T->Right );
        T->Element = TmpCell->Element;
        T->Right = Delete( T->Element, T->Right );
    }
    else  /* One or zero children */
    {
        TmpCell = T;
        if( T->Left == NULL ) /* Also handles 0 children */
        {
            T = T->Right;
        }
        else if( T->Right == NULL )
        {
            T = T->Left;
        }
        free( TmpCell );
    }
    
    return T;
}

ElementType Retrieve( Position P )
{
    return P->Element;
}

void PrintTree( SearchTree T, int level )
{
    if ( T == NULL )
    {
        padding(level);
        puts("~");
    }
    else
    {
        PrintTree(T->Right, level+1);
        padding(level);
        printf("%d\n", T->Element);
        PrintTree(T->Left, level+1);
    }
}

void padding(int n )
{
    int i;
    for (i = 0; i < n; ++i)
    {
        printf("    ");
    }
}
