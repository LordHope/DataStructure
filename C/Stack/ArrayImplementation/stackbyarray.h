//
//  stackbyarray.h
//  StackByArray
//
//  Created by Chen Ciro on 15/9/29.
//  Copyright © 2015年 Chen. All rights reserved.
//

typedef int ElementType;

#define Error( Str )        FatalError( Str )
#define FatalError( Str )   fprintf( stderr, "%s\n", Str ), exit( 1 )

#ifndef stackbyarray_h
#define stackbyarray_h

struct StackRecord;
typedef struct StackRecord *Stack;

int IsEmpty( Stack S );
int IsFull( Stack S );
Stack CreateStack( int MaxElements );
void DisposeStack( Stack S );
void MakeEmpty( Stack S );
void Push( ElementType X, Stack S );
ElementType Top( Stack S );
void Pop( Stack S );
ElementType TopAndPop( Stack S );
void PrintStack( Stack S );

#endif /* stackbyarray_h */
