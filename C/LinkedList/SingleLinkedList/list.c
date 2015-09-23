//
//  list.c
//  DataStructure
//
//  Created by Chen Ciro on 15/9/22.
//  Copyright © 2015年 Chen Ciro. All rights reserved.
//

#include "list.h"
#include <stdlib.h>
#include "fatal.h"

/* Place in the interface file */
struct Node
{
    ElementType Element;
    Position    Next;
};

List MakeEmpty( List L )
{
    if( L != NULL )
        DeleteList( L );
    L = malloc( sizeof( struct Node ) );
    if( L == NULL )
        FatalError( "Out of memory!" );
    L->Next = NULL;
    return L;
}

/* Return true if L is empty */

int IsEmpty( List L )
{
    return L->Next == NULL;
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
    Position P, TmpCell;
    
    P = FindPrevious( X, L );
    
    if( !IsLast( P, L ) )  /* Assumption of header use */
    {                      /* X is found; delete it */
        TmpCell = P->Next;
        P->Next = TmpCell->Next;  /* Bypass deleted cell */
        free( TmpCell );
    }
}

/* If X is not found, then Next field of returned value is NULL */
/* Assumes a header */

Position FindPrevious( ElementType X, List L )
{
    Position P;
    
    P = L;
    while( P->Next != NULL && P->Next->Element != X )
        P = P->Next;
    
    return P;
}

/* Insert (after legal position P) */
/* Header implementation assumed */
/* Parameter L is unused in this implementation */

void Insert( ElementType X, List L, Position P )
{
    Position TmpCell;
    
    TmpCell = malloc( sizeof( struct Node ) );
    if( TmpCell == NULL )
        FatalError( "Out of space!!!" );
    
    TmpCell->Element = X;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
}

/* Insert (before legal position P) */
/* Header implementation assumed */
/* Parameter L is used in this implementation */

void InsertBefore( ElementType X, List L, Position P )
{
    Position TmpCell;
    Position Previous;
    
    TmpCell = malloc( sizeof( struct Node ) );
    if( TmpCell == NULL )
        FatalError( "Out of space!!!" );
    
    Previous = FindPrevious(P->Element, L);
    Previous->Next = TmpCell;
    TmpCell->Element = X;
    TmpCell->Next = P;
}

#if 0

/* Incorrect DeleteList algorithm */

void DeleteList( List L )
{
    Position P;
    
    P = L->Next;  /* Header assumed */
    L->Next = NULL;
    while( P != NULL )
    {
        free( P );
        P = P->Next;
    }
}

#endif

/* Correct DeleteList algorithm */

void DeleteList( List L )
{
    Position P, Tmp;
    
    P = L->Next;  /* Header assumed */
    L->Next = NULL;
    while( P != NULL )
    {
        Tmp = P->Next;
        free( P );
        P = Tmp;
    }
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

void PrintAll( List L )
{
    Position P;
    
    P = L->Next;
    while ( P != NULL )
    {
        printf("%d ", P->Element );
        P = P->Next;
    }
}

List Reverse( List L)
{
    Position POne, PTwo, PThree;
    
    if ( (L->Next == NULL) || (L->Next->Next == NULL) )
    {
        return L;
    }
    
    POne = L->Next;
    PTwo = POne->Next;
    while ( PTwo != NULL )
    {
        PThree = PTwo->Next;
        PTwo->Next = POne;
        POne = PTwo;
        PTwo = PThree;
    }
    
    L->Next->Next = NULL;
    L->Next = POne;
    return L;
}