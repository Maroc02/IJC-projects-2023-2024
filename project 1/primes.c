#include "bitset.h"
#include "eratosthenes.h"
#include <stdio.h>

int main() {
    bitset_alloc(p, 666000000LU);
    Eratosthenes(p);
    int primes = 0;
    unsigned long primes_num[10];
    for (int i = 665999999; i >= 2; i--){
        if (bitset_getbit(p, i) == 1){
            if (primes < 10){
                primes_num[primes] = i;
                primes++;
            }
        }
    }

    for (int i = 9; i >= 0; i--){
        printf("%lu\n", primes_num[i]);
    }
}