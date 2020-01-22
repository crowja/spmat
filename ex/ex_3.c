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

   spmat_coo_insert(b, 0, 0, 10);
   spmat_coo_insert(b, 0, 1, 20);
   spmat_coo_insert(b, 1, 1, 30);
   spmat_coo_insert(b, 1, 3, 30);
   spmat_coo_insert(b, 2, 2, 50);
   spmat_coo_insert(b, 2, 3, 60);
   spmat_coo_insert(b, 2, 4, 70);
   spmat_coo_insert(b, 3, 5, 80);

   spmat_csr_from_coo(a, b);

   spmat_csr_free(&a);
   spmat_coo_free(&b);
  
   return 0;
}
