//
//  stackbylist.h
//  Stack
//
//  Created by Chen Ciro on 15/9/29.
//  Copyright © 2015年 Chen. All rights reserved.
//

typedef int ElementType;

#define Error( Str )        FatalError( Str )
#define FatalError( Str )   fprintf( stderr, "%s\n", Str ), exit( 1 )

#ifndef stackbylist_h
#define stackbylist_h

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;

int IsEmpty( Stack S );
Stack CreateStack( void );
void DisposeStack( Stack S );
void MakeEmpty( Stack S );
void Push( ElementType X, Stack S );
ElementType Top( Stack S );
void Pop( Stack S );
void PringStack( Stack S );

#endif /* stackbylist_h */
