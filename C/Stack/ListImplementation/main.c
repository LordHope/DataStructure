//
//  main.c
//  Stack
//
//  Created by Chen Ciro on 15/9/29.
//  Copyright © 2015年 Chen. All rights reserved.
//

#include <stdio.h>
#include "stackbylist.h"

int main(int argc, const char * argv[]) {
    Stack S = CreateStack();
    PringStack(S);
    Push(1, S);
    PringStack(S);
    //printf("Hello, World!\n");
    return 0;
}
