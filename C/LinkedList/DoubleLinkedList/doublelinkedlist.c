//
//  doublelinkedlist.c
//  DoubleLinkedList
//
//  Created by Chen Ciro on 15/9/25.
//  Copyright © 2015年 Lord Hope. All rights reserved.
//

#include "doublelinkedlist.h"
#include <stdlib.h>
#include "fatal.h"

/* Place in the interface file */
struct Node
{
    ElementType Element;
    Position    Next;
    Position    Prior;
};

List MakeEmpty( List L )
{
    Position Tail;
    //DeleteList
    L = malloc( sizeof( struct Node ) );
    if ( L == NULL ) {
        FatalError( "Out of memory!" );
    }
    Tail = malloc( sizeof( struct Node ) );
    if ( Tail == NULL ) {
        FatalError( "Out of memory!" );
    }
    
    L->Prior    = NULL;
    L->Next     = Tail;
    Tail->Prior = L;
    Tail->Next  = NULL;
    return L;
}

/* Return true if L is empty */

int IsEmpty( List L )
{
    return (L->Prior == NULL) && (L->Next->Next == NULL);
}

/* Return true if P is the first position in list L */
/* Parameter L is unused in this implementation */

int IsFirst( Position P, List L )
{
    return P->Prior == NULL;
}

/* Return true if P is the last position in list L */
/* Parameter L is unused in this implementation */

int IsLast( Position P, List L )
{
    return P->Next == NULL;
}

/* Return Position of X in L; NULL if not found */

Position Find( ElementType X, List L )
{
    Position P;
    
    P = L->Next;
    while( P != NULL && P->Element != X )
        P = P->Next;
    
    return P;
}

/* Delete from a list */
/* Cell pointed to by P->Next is wiped out */
/* Assume that the position is legal */
/* Assume use of a header node */

void Delete( ElementType X, List L )
{
    Position TmpCell;
    
    TmpCell = Find( X, L );
    
    if ( (!IsLast( TmpCell, L )) && (!IsFirst( TmpCell, L )) ) {
        TmpCell->Prior->Next = TmpCell->Next;
        TmpCell->Next->Prior = TmpCell->Prior;
        free( TmpCell );
    }
}

/* Insert (after legal position P) */
/* Header implementation assumed */
/* Parameter L is unused in this implementation */

void InsertAfter( ElementType X, List L, Position P )
{
    Position TmpCell;
    
    TmpCell = malloc( sizeof( struct Node ) );
    if( TmpCell == NULL )
        FatalError( "Out of space!!!" );
    
    TmpCell->Element = X;
    TmpCell->Next    = P->Next;
    TmpCell->Prior   = P;
    P->Next->Prior   = TmpCell;
    P->Next          = TmpCell;
}

/* Insert (before legal position P) */
/* Header implementation assumed */
/* Parameter L is used in this implementation */

void InsertBefore( ElementType X, List L, Position P )
{
    Position TmpCell;
    
    TmpCell = malloc( sizeof( struct Node ) );
    if( TmpCell == NULL )
        FatalError( "Out of space!!!" );

    TmpCell->Element = X;
    TmpCell->Prior   = P->Prior;
    TmpCell->Next    = P;
    P->Prior->Next   = TmpCell;
    P->Prior         = TmpCell;
}

void DeleteList( List L )
{
    Position P, TmpCell;
    
    P = L->Next;
    if ( P->Next != NULL) {
        TmpCell = P->Next;
        free( P );
        P = TmpCell;
    }
    
    L->Next = P;
}

Position Header( List L )
{
    return L;
}

Position First( List L )
{
    return L->Next;
}

Position Advance( Position P )
{
    return P->Next;
}

ElementType Retrieve( Position P )
{
    return P->Element;
}

void PrintList( List L )
{
    Position P;
    
    P = L->Next;
    while ( P->Next != NULL )
    {
        printf("%d ", P->Element );
        P = P->Next;
    }
}
