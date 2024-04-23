/* ******************** htab_statistics.c ******************* */
/*  Author: Marek Čupr (xcuprm01)                             */
/*  College: VUT FIT                                          */
/*  Subject: IJC - Project 2                                  */
/*  Date: 09. 04. 2024                                        */
/*  Functionality: Print the hash table statistics            */
/* ********************************************************** */

#include <stdio.h>
#include <stdint.h>
#include <assert.h>

#include "htab.h"
#include "htab_private.h"

/**
 * @brief Print the hash table statistics.
 * @param t Pointer to the hash table.
 */
void htab_statistics(const htab_t * t) {
    // Validate the arguments
    assert(t != NULL);

    // Find the minimum and maximum length of each linked list
    size_t minLen = SIZE_MAX, maxLen = 0;
    for (size_t i = 0; i < t->arrSize_m; i++) {
        // Coun the linked list length
        size_t currLen = 0;

        // Go through the list
        for (struct htab_item *item = t->items_m[i]; item != NULL; item = item->nextItem_m) { currLen++; }

        // Update the min and max length
        minLen = (currLen < minLen) ? currLen : minLen;
        maxLen = (currLen > maxLen) ? currLen : maxLen;
    }

    // Print the statistics
    fprintf(stderr, "--Hashtable statistics--\n");
    fprintf(stderr, "Items total: %zu\n", t->size_m);
    fprintf(stderr, "Non-empty items total: %zu\n", t->arrSize_m);

    // Check division by zero
    if (t->size_m != 0)
        fprintf(stderr, "Hashtable average: %f\n", (float) (t->arrSize_m / t->size_m));
    else
        fprintf(stderr, "Hashtable average: 0\n");

    fprintf(stderr, "Maximum length: %zu\n", maxLen);
    fprintf(stderr, "Minimum length: %zu\n", minLen);
}

/* End of htab_statistics.c */