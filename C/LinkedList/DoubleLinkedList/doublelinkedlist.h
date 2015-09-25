//
//  doublelinkedlist.h
//  DoubleLinkedList
//
//  Created by Chen Ciro on 15/9/25.
//  Copyright © 2015年 Lord Hope. All rights reserved.
//

typedef int ElementType;

#ifndef doublelinkedlist_h
#define doublelinkedlist_h

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List MakeEmpty( List L );
int IsEmpty( List L );
int IsFirst( Position P, List L );
int IsLast( Position P, List L );
Position Find( ElementType X, List L );
void Delete( ElementType X, List L );
void InsertAfter( ElementType X, List L, Position P );
void InsertBefore( ElementType X, List L, Position P );
void DeleteList( List L );
Position Header( List L );
Position First( List L );
Position Advance( Position P );
ElementType Retrieve( Position P );
void PrintList( List L );

#endif /* doublelinkedlist_h */
