#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <math.h>
#include <string.h>
#include "spmat_coo.h"
#include "tinytest.h"
#include "tinyhelp.h"

static void
test_coo_new(void)
{
   struct spmat_coo *z = spmat_coo_new();

   fprintf_test_info(stdout, "test_coo_new", "spmat_coo_new, spmat_coo_free");
   spmat_coo_free(&z);
   ASSERT_EQUALS(NULL, z);
}

/* 6 yy */
static void
test_stub(void)
{
   fprintf_test_info(stdout, "test_stub", NULL);
   ASSERT_EQUALS(0, 0);
}

int
main(void)
{
   printf("%s\n", spmat_coo_version());
   test_stub();                                  /* only to quiet compiler warnings */
   RUN(test_coo_new);

   return TEST_REPORT();
}
