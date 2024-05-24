/* ************ htab_clear.c *********** */
/*  Author: Marek Čupr (xcuprm01)        */
/*  College: VUT FIT                     */
/*  Subject: IJC - Project 2             */
/*  Date: 09. 04. 2024                   */
/*  Functionality: Clear the hash table  */
/* ************************************* */

#include <assert.h>

#include "htab_private.h"

/**
 * @brief Clear the hash table.
 * @param t Pointer to the hash table.
 */
void htab_clear(htab_t *t) {
    // Validate the arguments
    assert(t != NULL);

    // Initialize the item pointers
    struct htab_item *currItem = NULL;
    struct htab_item *nextItem = NULL;

    // Iterate through the hash table
    for (size_t i = 0; i < t->arrSize_m; i++) {
        // Get the current item
        currItem = t->items_m[i];
        // Iterate through the linked list of items
        while ((currItem) != NULL) {
            nextItem = currItem->nextItem_m;
            // Free the data key
            free((char *) currItem->data_m->key);
            currItem->data_m->key = NULL;
            // Free the data
            free(currItem->data_m);
            currItem->data_m = NULL;
            // Free the item
            free(currItem);
            currItem = nextItem;
        }
        // Set the array items to NULL
        t->items_m[i] = NULL;
    }

    // Set the item pointers to NULL
    currItem = NULL;
    nextItem = NULL;
}

/* End of htab_clear.c */
