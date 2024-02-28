#include <math.h>
#include "eratosthenes.h"

void Eratosthenes(bitset_t arr) {
    bitset_fill(arr, 1);

    bitset_setbit(arr, 0, 0);
    bitset_setbit(arr, 1, 0);

    for (bitset_index_t i = 2; i < sqrt((double) bitset_size(arr)); i++){
        if (bitset_getbit(arr, i) == 1){
            for (bitset_index_t j = i * i; j < bitset_size(arr); j += i) {
                bitset_setbit(arr, j, 0);
            }
        }
    }
}