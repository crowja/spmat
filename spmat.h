/**
 *  @file spmat.h
 *  @version 0.2.0-dev0
 *  @date Thu Jan 16 22:46:39 CST 2020
 *  @copyright 2020 John A. Crow <crowja@gmail.com>
 *  @license Unlicense <http://unlicense.org/>
 */

#ifndef _SPMAT_H_
#define _SPMAT_H_

#ifdef  _PACKAGE_NAME
#undef  _PACKAGE_NAME
#endif
#define _PACKAGE_NAME "spmat"

/**
 *  @brief FIXME Example function.
 *  @details FIXME longer description here ...
 *  @param cp[in] Pointer to a string.
 *  @returns FIXME.
 */
int         spmat_func1(const char *cp);

/**
 *  @brief Return the version of this package.
 *  @details FIXME longer description here ...
 *  @returns Version string.
 */
const char *spmat_version(void);

#endif
