//
//  stackbylist.c
//  Stack
//
//  Created by Chen Ciro on 15/9/29.
//  Copyright © 2015年 Chen. All rights reserved.
//

#include "stackbylist.h"
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    ElementType Element;
    PtrToNode   Next;
};

int IsEmpty( Stack S )
{
    return S->Next == NULL;
}

Stack CreateStack( void )
{
    Stack S;
    
    S = malloc( sizeof( struct Node ) );
    if( S == NULL )
        FatalError( "Out of space!!!" );
    S->Next = NULL;
    MakeEmpty( S );
    return S;
}

void MakeEmpty( Stack S )
{
    if( S == NULL )
        Error( "Must use CreateStack first" );
    else
        while( !IsEmpty( S ) )
            Pop( S );
}

void DisposeStack( Stack S )
{
    MakeEmpty( S );
    free( S );
}

/* Push by Insert Element at the Top of List */

void Push( ElementType X, Stack S )
{
    PtrToNode TmpCell;
    
    TmpCell = malloc( sizeof( struct Node ) );
    if( TmpCell == NULL )
        FatalError( "Out of space!!!" );
    else
    {
        TmpCell->Element = X;
        TmpCell->Next = S->Next;
        S->Next = TmpCell;
    }
}

ElementType Top( Stack S )
{
    if( !IsEmpty( S ) )
        return S->Next->Element;
    Error( "Empty stack" );
    return 0;  /* Return value used to avoid warning */
}

/* Pop by Delete the First Element of List */

void Pop( Stack S )
{
    PtrToNode FirstCell;
    
    if( IsEmpty( S ) )
        Error( "Empty stack" );
    else
    {
        FirstCell = S->Next;
        S->Next = S->Next->Next;
        free( FirstCell );
    }
}

void PringStack( Stack S )
{
    PtrToNode P;
    
    P = S->Next;
    while ( P != NULL )
    {
        printf("%d ",P->Element);
        P = P->Next;
    }
    
    printf("\n");
}