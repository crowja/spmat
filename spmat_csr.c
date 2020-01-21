/**
 *  @file spmat_csr.c
 *  @version 0.2.1-dev0
 *  @date Thu Jan 16 22:46:39 CST 2020
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

struct cv {
   unsigned    colind;
   double      val;
};

struct spmat_csr {
   void       *x;
   unsigned   *rowptr;
   struct cv  *colval;
   unsigned nrows;
};

struct spmat_csr *
spmat_csr_new(void)
{
   struct spmat_csr *tp;

   tp = (struct spmat_csr *) malloc(sizeof(struct spmat_csr));
   if (_IS_NULL(tp))
      return NULL;

   tp->rowptr = NULL;
   tp->colval = NULL;
   tp->nrows = 0;

   return tp;
}

void
spmat_csr_free(struct spmat_csr **pp)
{

   /* Do some magic here ... */

   _FREE((*pp)->rowptr);
   _FREE((*pp)->colval);
   _FREE(*pp);
   *pp = NULL;
}

const char *
spmat_csr_version(void)
{
   return "0.2.1-dev0";
}

#undef  _IS_NULL
#undef  _FREE
