/**
 *  @file spmat_csr.c
 *  @version 0.0.0
 *  @date Thu Jan 16 20:37:14 CST 2020
 *  @copyright 2020 John A. Crow <crowja@gmail.com>
 *  @license Unlicense <http://unlicense.org/>
 */

#include <stdlib.h>
#include <stdio.h>                               /* FIXME */
#include <string.h>                              /* FIXME */
#include "spmat_csr.h"

#ifdef  _IS_NULL
#undef  _IS_NULL
#endif
#define _IS_NULL(p)   ((NULL == (p)) ? (1) : (0))

#ifdef  _FREE
#undef  _FREE
#endif
#define _FREE(p)      ((NULL == (p)) ? (0) : (free((p)), (p) = NULL))

struct spmat_csr {
   void       *x;
};

struct spmat_csr *
spmat_csr_new(void)
{
   struct spmat_csr *tp;

   tp = (struct spmat_csr *) malloc(sizeof(struct spmat_csr));
   if (_IS_NULL(tp))
      return NULL;

   /* Do some magic here ... */

   return tp;
}

void
spmat_csr_free(struct spmat_csr **pp)
{

   /* Do some magic here ... */

   _FREE(*pp);
   *pp = NULL;
}

int
spmat_csr_init(struct spmat_csr *p, void *x)
{

   /* Do some magic here ... */
   p->x = x;                                     /* FIXME */

   return 0;
}

const char *
spmat_csr_version(void)
{
   return "0.0.0";
}

#undef  _IS_NULL
#undef  _FREE
