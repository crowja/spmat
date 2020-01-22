#include <stdlib.h>
#include <stdio.h>
#include "spmat.h"
#include "spmat_coo.h"
#include "spmat_csr.h"

int
main(int argc, char *argv[])
{
   struct spmat_csr *a = spmat_csr_new();
   struct spmat_coo *b = spmat_coo_new();

   spmat_coo_insert(b, 5, 5, 10);
   spmat_coo_insert(b, 5, 4, 10);
   spmat_coo_insert(b, 5, 3, 10);
   spmat_coo_insert(b, 5, 2, 10);
   spmat_coo_insert(b, 5, 1, 10);
   spmat_coo_insert(b, 5, 0, 10);
   spmat_coo_insert(b, 4, 5, 10);
   spmat_coo_insert(b, 4, 4, 10);
   spmat_coo_insert(b, 4, 3, 10);
   spmat_coo_insert(b, 4, 2, 10);
   spmat_coo_insert(b, 4, 1, 10);
   spmat_coo_insert(b, 4, 0, 10);
   spmat_coo_insert(b, 3, 5, 10);
   spmat_coo_insert(b, 3, 4, 10);
   spmat_coo_insert(b, 3, 3, 10);
   spmat_coo_insert(b, 3, 2, 10);
   spmat_coo_insert(b, 3, 1, 10);
   spmat_coo_insert(b, 3, 0, 10);
   spmat_coo_insert(b, 2, 5, 10);
   spmat_coo_insert(b, 2, 4, 10);
   spmat_coo_insert(b, 2, 3, 10);
   spmat_coo_insert(b, 2, 2, 10);
   spmat_coo_insert(b, 2, 1, 10);
   spmat_coo_insert(b, 2, 0, 10);
   spmat_coo_insert(b, 0, 0, 10);
   spmat_coo_insert(b, 0, 1, 10);
   spmat_coo_insert(b, 0, 2, 10);
   spmat_coo_insert(b, 0, 3, 10);
   spmat_coo_insert(b, 0, 4, 10);
   spmat_coo_insert(b, 0, 5, 10);
   spmat_coo_insert(b, 1, 0, 10);
   spmat_coo_insert(b, 1, 1, 10);
   spmat_coo_insert(b, 1, 2, 10);
   spmat_coo_insert(b, 1, 3, 10);
   spmat_coo_insert(b, 1, 4, 10);
   spmat_coo_insert(b, 1, 5, 10);

   spmat_csr_from_coo(a, b);

   spmat_csr_free(&a);
   spmat_coo_free(&b);
  
   return 0;
}
