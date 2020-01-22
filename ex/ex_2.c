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

   spmat_coo_insert(b, 0, 0, 7.5);
   spmat_coo_insert(b, 0, 1, 2.9);
   spmat_coo_insert(b, 0, 2, 2.8);
   spmat_coo_insert(b, 0, 3, 2.7);

   spmat_coo_insert(b, 1, 0, 6.8);
   spmat_coo_insert(b, 1, 1, 5.7);
   spmat_coo_insert(b, 1, 2, 3.8);

   spmat_coo_insert(b, 2, 0, 2.4);
   spmat_coo_insert(b, 2, 1, 6.2);
   spmat_coo_insert(b, 2, 2, 3.2);

   spmat_coo_insert(b, 3, 0, 9.7);
   spmat_coo_insert(b, 3, 3, 2.3);

   spmat_coo_insert(b, 4, 4, 5.8);
   spmat_coo_insert(b, 4, 5, 5.0);

   spmat_coo_insert(b, 5, 4, 6.6);
   spmat_coo_insert(b, 5, 5, 8.1);

   spmat_csr_from_coo(a, b);

   spmat_csr_free(&a);
   spmat_coo_free(&b);
  
   return 0;
}
