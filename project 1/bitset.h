/* ********************** bitset.h ********************** */
/*  Author: Marek Čupr (xcuprm01)                         */
/*  College: VUT FIT                                      */
/*  Subject: IJC - Project 1                              */
/*  Date: 23. 02. 2024                                    */
/*  Functionality: Header file for bitset.c               */
/* ****************************************************** */

#include <limits.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#include "error.h"

#ifndef BITSET_H
#define BITSET_H

/**
 * @brief Type definition for a bit array.
 */
typedef unsigned long* bitset_t;

/**
 * @brief Type definition for a bit array index.
 */
typedef unsigned long bitset_index_t;

/**
 * @brief Extra item reserved to save the array size.
 */
#define ARR_RESERVED_ITEM 1

/**
 * @brief Size of unsigned long in bits.
 */
#define UL_BITS (sizeof(unsigned long) * CHAR_BIT)

/**
 * @brief Converts bits to the count of unsigned long items.
 */
#define CONVERT_BITS_TO_UL(bit_size) (((bit_size) / UL_BITS) + ((bit_size) % UL_BITS ? 1 : 0))

/**
 * @brief Creates an unsigned long array with the provided bit size.
 * 
 * @param arr_name Name of the array.
 * @param bit_size Size of the array in bits.
 */
#define bitset_create(arr_name, bit_size) \
    static_assert(bit_size > 0, "bitset_create: The passed array size is invalid!"); \
    unsigned long arr_name[CONVERT_BITS_TO_UL(bit_size) + ARR_RESERVED_ITEM] = {bit_size, 0};

/**
 * @brief Allocates memory for an unsigned long array with the provided bit size.
 * 
 * @param arr_name Name of the array.
 * @param bit_size Size of the array in bits.
 */
#define bitset_alloc(arr_name, bit_size) \
    assert(bit_size > 0); \
    bitset_t arr_name = (bitset_t) calloc(CONVERT_BITS_TO_UL(bit_size) + ARR_RESERVED_ITEM, sizeof(unsigned long)); \
    if (arr_name == NULL) \
        error_exit("bitset_alloc: Chyba alokace paměti"); \
    arr_name[0] = bit_size;

#ifndef USE_INLINE

/**
 * @brief Frees the allocated array memory.
 * 
 * @param arr_name Name of the array to dynamically free.
 */
#define bitset_free(arr_name) free(arr_name)

/**
 * @brief Returns the array size.
 * 
 * @param arr_name Name of the array to return the size of.
 * @return The size of the array.
 */
#define bitset_size(arr_name) (arr_name[0])

/**
 * @brief Sets every bit of the array to the value of 0 or 1 based on the bool value.
 * 
 * @param arr_name Name of the array.
 * @param bool Value that indicates what bit value to fill the array with.
 */
#define bitset_fill(arr_name, bool) \
    do { \
        for (bitset_index_t i = 1; i < (CONVERT_BITS_TO_UL(arr_name[0]) + ARR_RESERVED_ITEM); i++) { \
            if (bool) \
                arr_name[i] ^= ~(arr_name[i]); \
            else \
                arr_name[i] ^= (arr_name[i]); \
        } \
    } while(0)

/**
 * @brief Sets bit on the index position to the value of 0 or 1 based on the bool value.
 * 
 * @param arr_name Name of the array.
 * @param index Bit index position.
 * @param bool Indicates what bit value to set.
 */
#define bitset_setbit(arr_name, index, bool) \
    do { \
        if ((unsigned long)index >= arr_name[0]) \
            error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu", (unsigned long)index, (unsigned long)arr_name[0]); \
        if (bool) \
            arr_name[index / UL_BITS + 1] |= (1LU << (index % UL_BITS)); \
        else \
            arr_name[index / UL_BITS + 1] &= ~(1LU << (index % UL_BITS)); \
    } while(0)

/**
 * @brief Returns the bit value on the index position.
 * 
 * @param arr_name Name of the array.
 * @param index Bit index position.
 * @return The value of the bit at the index position.
 */
#define bitset_getbit(arr_name, index) (((unsigned long)index >= arr_name[0]) ? (error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu", (unsigned long)index, (unsigned long)arr_name[0]), 0) : ((arr_name[index / UL_BITS + 1] >> (index % UL_BITS)) & 1LU))

#else

/**
 * @brief Frees the allocated array memory.
 * 
 * @param arr_name Name of the array to dynamically free.
 */
inline void bitset_free(bitset_t arr_name){
    free(arr_name);
}

/**
 * @brief Returns the array size.
 * 
 * @param arr_name Name of the array to return the size of.
 * @return The size of the array.
 */
inline unsigned long bitset_size(bitset_t arr_name){
    return arr_name[0];
}

/**
 * @brief Sets every bit of the array to the value of 0 or 1 based on the bool value.
 * 
 * @param arr_name Name of the array.
 * @param bool Value that indicates what bit value to fill the array with.
 */
inline void bitset_fill(bitset_t arr_name, int bool){
    for (bitset_index_t i = 1; i < ((arr_name[0] / UL_BITS) + (arr_name[0] % UL_BITS ? 1 : 0) + ARR_RESERVED_ITEM); i++) {
        if (bool)
            arr_name[i] ^= ~(arr_name[i]);
        else
            arr_name[i] ^= (arr_name[i]);
    }
}

/**
 * @brief Sets bit on the index position to the value of 0 or 1 based on the bool value.
 * 
 * @param arr_name Name of the array.
 * @param index Bit index position.
 * @param bool Indicates what bit value to set.
 */
inline void bitset_setbit(bitset_t arr_name, bitset_index_t index, int bool){
    if ((unsigned long)index >= arr_name[0])
        error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu", (unsigned long)index, (unsigned long)arr_name[0]);

    if (bool)
        arr_name[index / UL_BITS + 1] |= (1LU << (index % UL_BITS));
    else
        arr_name[index / UL_BITS + 1] &= ~(1LU << (index % UL_BITS));
}

/**
 * @brief Returns the bit value on the index position.
 * 
 * @param arr_name Name of the array.
 * @param index Bit index position.
 * @return The value of the bit at the index position.
 */
inline unsigned long bitset_getbit(bitset_t arr_name, bitset_index_t index){
    if ((unsigned long)index >= arr_name[0])
        error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu", (unsigned long)index, (unsigned long)arr_name[0]);

    return ((arr_name[index / UL_BITS + 1] >> (index % UL_BITS)) & 1LU);
}

#endif // End of USE_INLINE 

#endif

/* End of bitset.h */