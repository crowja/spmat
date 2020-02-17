/**
 *  @file spmat.c
 *  @version 0.2.1-dev0
 *  @date Sun Feb 16, 2020 08:30:34 PM CST
 *  @copyright 2020 John A. Crow <crowja@gmail.com>
 *  @license Unlicense <http://unlicense.org/>
 */

#include <stdlib.h>
#include <stdio.h>
#include "spmat_coo.h"
#include "spmat_csr.h"
#include "spmat.h"

#ifdef  IS_NULL
#undef  IS_NULL
#endif
#define IS_NULL(p)   ((NULL == (p)) ? (1) : (0))

#ifdef  FREE
#undef  FREE
#endif
#define FREE(p)      ((NULL == (p)) ? (0) : (free((p)), (p) = NULL))

const char *
spmat_version(void)
{
   return "0.2.1-dev0";
}

#undef IS_NULL
#undef FREE
