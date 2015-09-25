//
//  main.c
//  DoubleLinkedList
//
//  Created by Chen Ciro on 15/9/25.
//  Copyright © 2015年 Chen Ciro. All rights reserved.
//

#include <stdio.h>
#include "doublelinkedlist.h"

int main(int argc, const char * argv[]) {
    List L;
    Position P;
    L = MakeEmpty( L );
    printf("%d\n",IsEmpty(L));
    InsertAfter(1, L, L);
    InsertAfter(2, L, L);
    P = Find(1, L);
    printf("%d\n", Retrieve(P));
    InsertBefore(3, L, P);
    PrintList(L);
    Delete(3, L);
    printf("\n");
    PrintList(L);
    DeleteList(L);
    printf("\n");
    printf("%d\n",IsEmpty(L));
    //printf("Hello, World!\n");
    return 0;
}
