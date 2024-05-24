/* ************************ htab_for_each.c *********************** */
/*  Author: Marek Čupr (xcuprm01)                                   */
/*  College: VUT FIT                                                */
/*  Subject: IJC - Project 2                                        */
/*  Date: 09. 04. 2024                                              */
/*  Functionality: Call a function for each item in the hash table  */
/* **************************************************************** */

#include <assert.h>

#include "htab_private.h"

/**
 * @brief Call a function for each item in the hash table.
 * @param t Pointer to the hash table.
 * @param f Pointer to the function.
 */
void htab_for_each(const htab_t * t, void (*f)(htab_pair_t *data)) {
    // Validate the arguments
    assert(t != NULL);

    // Iterate through the hash table
    for (size_t i = 0; i < t->arrSize_m; i++) {
        // Iterate through the linked list of items
        for (struct htab_item *currItem = t->items_m[i]; currItem != NULL; currItem = currItem->nextItem_m) {
            // Call the function for each item in the hash table
            f(currItem->data_m);
        }   
    }
}

/* End of htab_for_each.c */