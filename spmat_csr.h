/**
 *  @file spmat_csr.h
 *  @version 0.2.1-dev0
 *  @date Thu Jan 16 22:46:39 CST 2020
 *  @copyright 2020 John A. Crow <crowja@gmail.com>
 *  @license Unlicense <http://unlicense.org/>
 */

#ifndef _SPMAT_CSR_H_
#define _SPMAT_CSR_H_

#ifdef  _PACKAGE_NAME
#undef  _PACKAGE_NAME
#endif
#define _PACKAGE_NAME "spmat_csr"

struct spmat_csr;

/**
 *  @brief Constructor.
 *  @details Create and return a new spmat_csr object.
 *  @returns New spmat_csr object.
 */
struct spmat_csr *spmat_csr_new(void);

/**
 *  @brief Destructor.
 *  @details Clean up and free a spmat_csr structure.
 *  @param[in, out] pp.
 */
void        spmat_csr_free(struct spmat_csr **pp);

/**
 *  @brief Return the version of this package.
 *  @returns Version string.
 */
const char *spmat_csr_version(void);

int         spmat_csr_from_coo(struct spmat_csr *a, struct spmat_coo *b);

#endif
