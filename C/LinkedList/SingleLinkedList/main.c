//
//  main.c
//  DataStructure
//
//  Created by Chen Ciro on 15/9/22.
//  Copyright © 2015年 Chen Ciro. All rights reserved.
//

#include <stdio.h>
#include "list.h"

int main(int argc, const char * argv[]) {
    List L;
    L = MakeEmpty( L );
    for (int i = 10; i != 0; i--) {
        Insert(i, L, L);
    }
    PrintAll( L );
    printf("\n");
    L = Reverse( L );
    PrintAll( L );
    //printf("Hello, World!\n");
    return 0;
}
