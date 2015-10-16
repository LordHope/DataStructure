//
//  main.c
//  StackByArray
//
//  Created by Chen Ciro on 15/9/29.
//  Copyright © 2015年 Chen. All rights reserved.
//

#include <stdio.h>
#include "stackbyarray.h"

int main(int argc, const char * argv[]) {
    Stack s = CreateStack(9);
    
    for (int i = 0; i < 9; ++i) {
        Push(i, s);
    }
    PrintStack(s);
    
    printf("Hello, World!\n");
    return 0;
}
