SHELL = /bin/sh

GCC_STRICT_FLAGS = -pedantic -ansi -W -Wall -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations -O2
GCC_SANITIZE_FLAGS = -fsanitize=address -fsanitize=undefined -fno-omit-frame-pointer
OTHER_SOURCE = -I./t
OTHER_INCLUDE =
CPPFLAGS = -g -I. $(OTHER_INCLUDE)
CFLAGS = $(GCC_STRICT_FLAGS) 
LDFLAGS =
LDFLAGS_EFENCE = -L/usr/lib -lefence $(LDFLAGS)
#VALGRIND_FLAGS = --verbose --leak-check=full --undef-value-errors=yes --track-origins=yes
VALGRIND_FLAGS = --leak-check=full --undef-value-errors=yes
STAMPER = stamper

INDENT_FLAGS = -TFILE -Tsize_t -Tuint8_t

.PHONY: all check check-examples scheck-examples vcheck scheck echeck indent stamp clean

TESTS = t/test
EXAMPLES = ex/ex_1 ex/ex_2 ex/ex_3

all: spmat.o spmat_coo.o spmat_csr.o

spmat.o: spmat.c spmat.h
	$(CC) -c $(CPPFLAGS) $(CFLAGS) -o $@ $*.c

spmat_coo.o: spmat_coo.c spmat_coo.h
	$(CC) -c $(CPPFLAGS) $(CFLAGS) -o $@ $*.c

spmat_csr.o: spmat_csr.c spmat_csr.h spmat_coo.h
	$(CC) -c $(CPPFLAGS) $(CFLAGS) -o $@ $*.c

check:
	@for i in $(TESTS); \
	do \
	  echo "--------------------"; \
	  echo "Running test $$i"; \
	  ( $(CC)    $(CPPFLAGS) $(OTHER_INCLUDE) $(CFLAGS) $(OTHER_SOURCE) \
		-o t/a.out $$i.c spmat.c spmat_coo.c spmat_csr.c $(LDFLAGS) ) \
	  && ( t/a.out ); \
	done 

check-examples:
	@for i in $(EXAMPLES); \
	do \
	  echo "--------------------"; \
	  echo "Running example $$i"; \
	  ( $(CC) -g $(CPPFLAGS) $(OTHER_INCLUDE) $(CFLAGS) $(OTHER_SOURCE) \
		-o ex/a.out $$i.c spmat.c spmat_coo.c spmat_csr.c $(LDFLAGS) ) \
	  && ( valgrind $(VALGRIND_FLAGS) ex/a.out ); \
	done 

scheck-examples:
	@for i in $(EXAMPLES); \
	do \
	  echo "--------------------"; \
	  echo "Running example $$i"; \
	  ( $(CC) -g $(CPPFLAGS) $(OTHER_INCLUDE) $(CFLAGS) $(GCC_SANITIZE_FLAGS) $(OTHER_SOURCE) \
		-o ex/a.out $$i.c spmat.c spmat_coo.c spmat_csr.c $(LDFLAGS) ) \
	  && ( ex/a.out ); \
	done 

vcheck:
	@for i in $(TESTS); \
	do \
	  echo "--------------------"; \
	  echo "Running test $$i"; \
	  ( $(CC) -g $(CPPFLAGS) $(OTHER_INCLUDE) $(CFLAGS) $(OTHER_SOURCE) \
		-o t/a.out $$i.c spmat.c spmat_coo.c spmat_csr.c $(LDFLAGS) ) \
	  && ( valgrind $(VALGRIND_FLAGS) t/a.out ); \
	done 

scheck:
	@for i in $(TESTS); \
	do \
	  echo "--------------------"; \
	  echo "Running test $$i"; \
	  ( $(CC)    $(CPPFLAGS) $(OTHER_INCLUDE) $(CFLAGS) $(GCC_SANITIZE_FLAGS) $(OTHER_SOURCE) \
		-o t/a.out $$i.c spmat.c spmat_coo.c spmat_csr.c $(LDFLAGS) ) \
	  && ( t/a.out ); \
	done 

echeck:
	@for i in $(TESTS); \
	do \
	  echo "--------------------"; \
	  echo "Running test $$i"; \
	  ( $(CC)    $(CPPFLAGS) $(OTHER_INCLUDE) $(CFLAGS) $(OTHER_SOURCE) \
		-o t/a.out $$i.c spmat.c spmat_coo.c spmat_csr.c $(LDFLAGS_EFENCE) ) \
	  && ( LD_PRELOAD=libefence.so t/a.out ) ; \
	done 

indent: 
	@indent $(INDENT_FLAGS) spmat.c
	@indent $(INDENT_FLAGS) spmat.h
	@indent $(INDENT_FLAGS) spmat_coo.c
	@indent $(INDENT_FLAGS) spmat_coo.h
	@indent $(INDENT_FLAGS) spmat_csr.c
	@indent $(INDENT_FLAGS) spmat_csr.h
	@for i in $(TESTS); \
	do \
	  indent $(INDENT_FLAGS) $$i.c; \
	done

stamp:
	@$(STAMPER) spmat.c
	@$(STAMPER) spmat.h
	@$(STAMPER) spmat_coo.c
	@$(STAMPER) spmat_coo.h
	@$(STAMPER) spmat_csr.c
	@$(STAMPER) spmat_csr.h

clean:
	@/bin/rm -f spmat.o *.o *~ *.BAK *.bak core.* a.out
	@/bin/rm -f t/*.o t/*~ t/*.BAK t/*.bak t/core.* t/a.out
	@/bin/rm -f ex/*.o ex/*~ ex/*.BAK ex/*.bak ex/core.* ex/a.out

