/* ******************** eratosthenes.c ******************** */
/*  Author: Marek Čupr (xcuprm01)                           */
/*  College: VUT FIT                                        */
/*  Subject: IJC - Project 1                                */
/*  Date: 23. 02. 2024                                      */
/*  Functionality: Find prime numbers in a bit array        */
/* ******************************************************** */

#include <math.h>

#include "eratosthenes.h"

void Eratosthenes(bitset_t arr) {
    // Set all the bits in the array to 1
    bitset_fill(arr, 1);

    // Set bits at index 0 and 1 to 0 since they are not prime numbers
    bitset_setbit(arr, 0, 0);
    bitset_setbit(arr, 1, 0);

    // Iterate over the numbers starting from 2 up to the square root of the array size
    for (bitset_index_t i = 2; i < sqrt((double) bitset_size(arr)); i++){
        if (bitset_getbit(arr, i) == 1) { // Index i is a prime number 
            // Multiples of i are not prime numbers
            for (bitset_index_t j = i * i; j < bitset_size(arr); j += i)
                bitset_setbit(arr, j, 0);
        }
    }
}

/* End of eratosthenes.c */