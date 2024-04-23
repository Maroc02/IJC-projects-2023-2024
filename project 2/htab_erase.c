/* ********************** htab_erase.c ********************* */
/*  Author: Marek Čupr (xcuprm01)                            */
/*  College: VUT FIT                                         */
/*  Subject: IJC - Project 2                                 */
/*  Date: 09. 04. 2024                                       */
/*  Functionality: Clear the item from the hash table        */
/* ********************************************************* */

#include <assert.h>
#include <stdbool.h>

#include "htab.h"
#include "htab_private.h"

/**
 * @brief Clear the item from the hash table.
 * @param t Pointer to the hash table.
 * @param key Key of the item.
 * @return True if the item was cleared, otherwise false.
 */
bool htab_erase(htab_t * t, htab_key_t key) {
    // Validate the arguments
    assert((t != NULL) && (key != NULL));

    // Get the table index using hash function
    size_t tableIndex = htab_hash_function(key) % t->arrSize_m;

    // Get the searched item
    struct htab_item *prevItem = NULL;

    // Search for the item
     for (struct htab_item *currItem = t->items_m[tableIndex]; currItem != NULL; currItem = currItem->nextItem_m) {
        // The item was found
        if ((currItem->data_m != NULL) && (strcmp(currItem->data_m->key, key) == 0)) {
            // Connect the linked list items 
            prevItem->nextItem_m = currItem->nextItem_m;

            // Free the data key
            free(currItem->data_m->key);
            currItem->data_m->key = NULL;
            // Free the data
            free(currItem->data_m);
            currItem->data_m = NULL;
            // Free the item
            free(currItem);
            currItem = NULL;
            // Decrease the size of the hash table
            t->size_m--;
            return true;
        }
        
        // Move to the next item in the list
        prevItem = currItem;
    }

    // The item was not found
    return NULL;
}

/* End of htab_erase.c */