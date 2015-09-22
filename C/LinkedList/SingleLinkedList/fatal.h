//
//  fatal.h
//  DataStructure
//
//  Created by Chen Ciro on 15/9/22.
//  Copyright © 2015年 Chen Ciro. All rights reserved.
//

#ifndef fatal_h
#define fatal_h

#include <stdio.h>
#include <stdlib.h>

#define Error( Str )        FatalError( Str )
#define FatalError( Str )   fprintf( stderr, "%s\n", Str ), exit( 1 )

#endif /* fatal_h */
