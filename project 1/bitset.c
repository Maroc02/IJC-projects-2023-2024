/* *********************** bitset.c *********************** */
/*  Author: Marek Čupr (xcuprm01)                           */
/*  College: VUT FIT                                        */
/*  Subject: IJC - Project 1                                */
/*  Date: 23. 02. 2024                                      */
/*  Functionality: Declare inline functions for bitset.h    */
/* ******************************************************** */

#include "bitset.h"

#ifdef USE_INLINE

extern inline void bitset_free(unsigned long arr_name[]);
extern inline bitset_index_t bitset_size(unsigned long arr_name[]);
extern inline void bitset_fill(unsigned long arr_name[], int bool);
extern inline void bitset_setbit(unsigned long arr_name[], bitset_index_t index, int bool);
extern inline unsigned long bitset_getbit(unsigned long arr_name[], bitset_index_t index);

#endif

/* End of bitset.c */