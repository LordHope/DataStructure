//
//  stackbyarray.c
//  StackByArray
//
//  Created by Chen Ciro on 15/9/29.
//  Copyright © 2015年 Chen. All rights reserved.
//

#include "stackbyarray.h"
#include <stdio.h>
#include <stdlib.h>

#define EmptyTOS ( -1 )
#define MinStackSize ( 5 )

struct StackRecord
{
    int Capacity;
    int TopOfStack;
    ElementType *Array;
};

int IsEmpty( Stack S )
{
    return S->TopOfStack == EmptyTOS;
}


int IsFull( Stack S )
{
    return S->TopOfStack == S->Capacity - 1;
}


Stack CreateStack( int MaxElements )
{
    Stack S;
    
    if( MaxElements < MinStackSize )
        Error( "Stack size is too small" );
    
    S = malloc( sizeof( struct StackRecord ) );
    if( S == NULL )
        FatalError( "Out of space!!!" );
    
    S->Array = malloc( sizeof( ElementType ) * MaxElements );
    if( S->Array == NULL )
        FatalError( "Out of space!!!" );
    S->Capacity = MaxElements;
    MakeEmpty( S );
    
    return S;
}

void MakeEmpty( Stack S )
{
    S->TopOfStack = EmptyTOS;
}

void DisposeStack( Stack S )
{
    if( S != NULL )
    {
        free( S->Array );
        free( S );
    }
}

void Push( ElementType X, Stack S )
{
    if( IsFull( S ) )
        Error( "Full stack" );
    else
        S->Array[ ++S->TopOfStack ] = X;
}

ElementType Top( Stack S )
{
    if( !IsEmpty( S ) )
        return S->Array[ S->TopOfStack ];
    Error( "Empty stack" );
    return 0;  /* Return value used to avoid warning */
}

void Pop( Stack S )
{
    if( IsEmpty( S ) )
        Error( "Empty stack" );
    else
        S->TopOfStack--;
}

ElementType TopAndPop( Stack S )
{
    if( !IsEmpty( S ) )
        return S->Array[ S->TopOfStack-- ];
    Error( "Empty stack" );
    return 0;  /* Return value used to avoid warning */
}

void PrintStack( Stack S )
{
    if( IsEmpty( S ) )
    {
        Error( "Empty stack" );
    }
    else
    {
        for (int i = 0; i <= S->TopOfStack; ++i) {
            printf("%d ", S->Array[i]);
        }
    }
    
    printf("\n");
}
