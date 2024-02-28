/* ******************************** bitset.h ******************************* */
/*  Author: Marek Čupr (xcuprm01)                                            */
/*  Subject: IJC - Project                                                   */
/*  Date: 23. 02. 2024                                                       */
/*  Functionality: Header file for bitset.c                                  */
/* ************************************************************************* */

#include <limits.h>
#include <stdlib.h>
#include <assert.h>
#include "error.h"

#ifndef BITSET_H
#define BITSET_H

typedef unsigned long * bitset_t; // Type of bit array
typedef unsigned long bitset_index_t; // Type of bit array index

// Extra byte reserved for the first index to save the array size
#define ARR_RESERVED_SIZE 1

// Size of unsigned long in bits
#define UL_BITS (sizeof(unsigned long) * CHAR_BIT)

#define bitset_create(arr_name, bit_size) \
    unsigned long arr_name[((bit_size) / UL_BITS) + ((bit_size) % UL_BITS ? 1 : 0) + ARR_RESERVED_SIZE] = {bit_size, 0}; \
    static_assert(bit_size > 0 && bit_size <= ULONG_MAX, "Warning at bitset_create: The passed array size is invalid!")

#define bitset_alloc(arr_name, bit_size) \
    assert(bit_size > 0); \
    bitset_t arr_name = (bitset_t) calloc((bit_size / UL_BITS) + (bit_size % UL_BITS ? 1 : 0) + ARR_RESERVED_SIZE, sizeof(unsigned long)); \
    if (arr_name == NULL){ \
        error_exit("bitset_alloc: Chyba alokace paměti"); \
    } \
    arr_name[0] = bit_size;

#ifndef USE_INLINE

#define bitset_free(arr_name) free((arr_name))

#define bitset_size(arr_name) ((arr_name)[0])

#define bitset_fill(arr_name, bool) \
    do { \
        for (bitset_index_t i = 1; i < ((arr_name[0] / UL_BITS) + (arr_name[0] % UL_BITS ? 1 : 0) + ARR_RESERVED_SIZE); i++) { \
            if (bool) { \
                arr_name[i] ^= ~(arr_name[i]); \
            } else { \
                arr_name[i] ^= (arr_name[i]); \
            } \
        } \
    } while(0)

#define bitset_setbit(arr_name,index,bool) \
    do { \
        if (bool) \
            arr_name[index / UL_BITS + 1] |= (1LU << (index % UL_BITS)); \
        else \
            arr_name[index / UL_BITS + 1] &= ~(1LU << (index % UL_BITS)); \
    } while(0)

#define bitset_getbit(arr_name,index) ((arr_name[index / UL_BITS + 1] >> (index % UL_BITS)) & 1LU)

# else

static inline void bitset_free(bitset_t arr_name[]){
    if (arr_name != NULL)
        free(arr_name);
}

static inline bitset_index_t bitset_size(bitset_t arr_name[]){
    return arr_name[0];
}

static inline void bitset_fill(unsigned long arr_name[], int bool){
    for (bitset_index_t i = 1; i < ((arr_name[0] / UL_BITS) + (arr_name[0] % UL_BITS ? 1 : 0) + ARR_RESERVED_SIZE); i++) {
        if (bool)
            arr_name[i] ^= ~(arr_name[i]);
        else
            arr_name[i] ^= (arr_name[i]);
    }
}

static inline void bitset_setbit(unsigned long arr_name[], bitset_index_t index, int bool){
    if (bool)
        arr_name[index / UL_BITS + 1] |= (1LU << (index % UL_BITS));
    else 
        arr_name[index / UL_BITS + 1] &= ~(1LU << (index % UL_BITS));
}

static inline unsigned long bitset_getbit(unsigned long arr_name[], bitset_index_t index){
    return ((arr_name[index / UL_BITS + 1] >> (index % UL_BITS)) & 1LU);
}

#endif

#endif