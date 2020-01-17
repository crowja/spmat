/**
 *  @file spmat.c
 *  @version 0.1.0-dev0
 *  @date Thu Jan 16 22:46:39 CST 2020
 *  @copyright 2020 John A. Crow <crowja@gmail.com>
 *  @license Unlicense <http://unlicense.org/>
 */

#include <stdlib.h>
#include <stdio.h>                               /* FIXME */
#include <string.h>                              /* FIXME */
#include "spmat.h"

#ifdef  _IS_NULL
#undef  _IS_NULL
#endif
#define _IS_NULL(p)   ((NULL == (p)) ? (1) : (0))

#ifdef  _FREE
#undef  _FREE
#endif
#define _FREE(p)      ((NULL == (p)) ? (0) : (free((p)), (p) = NULL))

int
spmat_func1(const char *cp)
{
   /* Do some magic here ... */

   return 0;
}

const char *
spmat_version(void)
{
   return "0.1.0-dev0";
}

#undef _IS_NULL
#undef _FREE
