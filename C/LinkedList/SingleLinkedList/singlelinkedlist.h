//
//  singlelinkedlist.c.h
//  DataStructure
//
//  Created by Chen Ciro on 15/9/22.
//  Copyright © 2015年 Chen Ciro. All rights reserved.
//

typedef int ElementType;

#ifndef singlelinkedlist_h
#define singlelinkedlist_h

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List MakeEmpty( List L );
int IsEmpty( List L );
int IsLast( Position P, List L );
Position Find( ElementType X, List L );
void Delete( ElementType X, List L );
Position FindPrevious( ElementType X, List L );
void Insert( ElementType X, List L, Position P );
void InsertBefore( ElementType X, List L, Position P ); /* Insert (before legal position P) */
void DeleteList( List L );
Position Header( List L );
Position First( List L );
Position Advance( Position P );
ElementType Retrieve( Position P );

void PrintList( List L );
List Reverse( List L);

#endif /* singlelinkedlist_h */