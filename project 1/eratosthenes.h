/* ******************* eratosthenes.h ******************* */
/*  Author: Marek Čupr (xcuprm01)                         */
/*  College: VUT FIT                                      */
/*  Subject: IJC - Project 1                              */
/*  Date: 23. 02. 2024                                    */
/*  Functionality: Header file for eratosthenes.c         */
/* ****************************************************** */

#ifndef ERATOSTHENES_H
#define ERATOSTHENES_H

#include "bitset.h"

/**
 * @brief Implements the sieve of Eratosthenes algorithm to find all the prime numbers up to the given limit.
 * 
 * @param arr Bitset array to find the prime numbers in.
 */
void Eratosthenes(bitset_t arr);

#endif

/* End of eratosthenes.h */