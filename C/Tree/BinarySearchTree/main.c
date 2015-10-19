//
//  main.c
//  BinarySearchTree
//
//  Created by Chen Ciro on 15/10/14.
//  Copyright © 2015年 Chen. All rights reserved.
//

#include <stdio.h>
#include "binarysearchtree.h"

int main(int argc, const char * argv[]) {
    SearchTree st = NULL;
    st = MakeEmpty(st);

    st = Insert(3, st);
    st = Insert(2, st);
    st = Insert(1, st);
    st = Insert(9, st);
    
    printf("\n");
    PrintTree(st, 0);
    printf("\n");
    printf("Hello, World!\n");
    return 0;
}
