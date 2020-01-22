/**
 *  @file spmat_csr.c
 *  @version 0.2.1-dev0
 *  @date Thu Jan 16 22:46:39 CST 2020
 *  @copyright 2020 John A. Crow <crowja@gmail.com>
 *  @license Unlicense <http://unlicense.org/>
 */

#include <stdlib.h>
#include <stdio.h>                               /* FIXME */
#include <float.h>
#include <string.h>                              /* FIXME */
#include "spmat_coo.h"
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
   unsigned    nrows;
   unsigned    nnz;
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
   tp->nnz = 0;

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

int
spmat_csr_from_coo(struct spmat_csr *a, struct spmat_coo *b)
{
   /* Initialize a with b */

   struct spmat_coo_iter *iter;
   unsigned    i, j;
   unsigned    i0 = 0;
   unsigned    nnz = 0;
   double      v;
   unsigned    rowptr[1000];                /* REMOVE THIS */

   /* First make sure a is in row-first format */
   spmat_coo_compact(b, 2 * DBL_MIN, 0);

   iter = spmat_coo_iter_new(b);

   rowptr[0] = 0;

   while (spmat_coo_iter_next(iter, &i, &j, &v)) {
      printf("Forming spmat_csr with %u %u %f\n", i, j, v);
      printf("... current row is %u and previous one was %u nzz is %u\n", i, i0, nnz);
      if (i != i0) {                             /* starting a new row */
         unsigned    iii;
	 /* I think here is where we realloc rowptr. It'll need at least i + 1 slots. */
         for (iii = i0; iii < i; iii++)
            rowptr[iii + 1] = nnz;
      }
      i0 = i;
      nnz++;
   }

   rowptr[i0 + 1] = nnz;

   for (i = 0; i < 7; i++)
      printf("ROWPTR[%u] = %u\n", i, rowptr[i]);

   spmat_coo_iter_free(&iter);

   return 0;
}


#undef  _IS_NULL
#undef  _FREE
