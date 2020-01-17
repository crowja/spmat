/**
 *  @file spmat_csr.h
 *  @version 0.1.0-dev0
 *  @date Thu Jan 16 20:37:14 CST 2020
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
 *  @param[in, out] p.
 */
void        spmat_csr_free(struct spmat_csr **pp);

/**
 *  @brief Initialize a spmat_csr object.
 *  @details FIXME longer description here ...
 *  @param[in,out] p Pointer to a spmat_csr object
 *  @param[in] x FIXME
    @returns FIXME
 */
int         spmat_csr_init(struct spmat_csr *p, void *x);

/**
 *  @brief Return the version of this package.
 *  @returns Version string.
 */
const char *spmat_csr_version(void);

#endif
