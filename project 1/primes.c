/* ******************************* primes.c ******************************* */
/*  Author: Marek Čupr (xcuprm01)                                           */
/*  College: VUT FIT                                                        */
/*  Subject: IJC - Project 1                                                */
/*  Date: 23. 02. 2024                                                      */
/*  Functionality: Print the 10 largest prime numbers in the bitset array   */
/* ************************************************************************ */

#include <stdio.h>
#include <time.h>

#include "bitset.h"
#include "eratosthenes.h"

#define BITSET_SIZE 666000000L

int main() {
    // Create clock to meassure the program run time
    clock_t start_clock = clock();

    // Create the desired bitset array
    bitset_create(p, BITSET_SIZE);

    // Find all the prime numbers
    Eratosthenes(p);

    // Initialize an array to save the prime numbers
    unsigned long primes[10] = {0};
    int primes_num = 9; // Used for array indexing

    // Find the 10 largest prime numbers in the array
    for (int i = 665999999; i >= 2; i-=2){
        if (bitset_getbit(p, i) == 1) {
            primes[primes_num] = i;
            primes_num--;

            if (primes_num < 0) // We've found the prime numbers
                break;
        }
    }

    // Print the prime numbers
    for (int i = 0; i < 10; i++)
        printf("%lu\n", primes[i]);

    // Print the program run time
    fprintf(stderr, "Time=%.3g\n", (double)(clock()-start_clock)/CLOCKS_PER_SEC);
}

/* End of bitset.c */