/* ********************** htab_clear.c ********************* */
/*  Author: Marek Čupr (xcuprm01)                            */
/*  College: VUT FIT                                         */
/*  Subject: IJC - Project 2                                 */
/*  Date: 09. 04. 2024                                       */
/*  Functionality: Clear the hash table                      */
/* ********************************************************* */

#include <assert.h>

#include "htab.h"
#include "htab_private.h"

/**
 * @brief Clear the hash table.
 * @param t Pointer to the hash table.
 */
void htab_clear(htab_t *t) {
    // Validate the arguments
    assert(t != NULL);

    struct htab_item *currItem;
    struct htab_item *nextItem;

    // Iterate through the hash table
    for (size_t i = 0; i < t->arrSize_m; i++) {
        currItem = t->items_m[i];
        // Clear the linked list items
        while ((currItem) != NULL) {
            nextItem = currItem->nextItem_m;
            // Free the data key
            free(currItem->data_m->key);
            currItem->data_m->key = NULL;
            // Free the data
            free(currItem->data_m);
            currItem->data_m = NULL;
            //Free the item
            free(currItem);
            currItem = nextItem;
        }
        // Set the array items to NULL
        t->items_m[i] = NULL;
    }

    // Set the pointers to NULL
    currItem = NULL;
    nextItem = NULL;
}

/* End of htab_clear.c */
