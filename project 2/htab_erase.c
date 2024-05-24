/* ******************** htab_erase.c ****************** */
/*  Author: Marek Čupr (xcuprm01)                       */
/*  College: VUT FIT                                    */
/*  Subject: IJC - Project 2                            */
/*  Date: 09. 04. 2024                                  */
/*  Functionality: Delete the item from the hash table  */
/* **************************************************** */

#include <assert.h>

#include "htab_private.h"

/**
 * @brief Delete the item from the hash table.
 * @param t Pointer to the hash table.
 * @param key Key of the item.
 * @return True if the item was deleted, otherwise false.
 */
bool htab_erase(htab_t * t, htab_key_t key) {
    // Validate the arguments
    assert((t != NULL) && (key != NULL));

    // Get the hash table index using the hash function
    size_t tableIndex = htab_hash_function(key) % t->arrSize_m;

    // Initialize the item pointer
    struct htab_item *prevItem = NULL;

    // Iterate through the linked list of items
     for (struct htab_item *currItem = t->items_m[tableIndex]; currItem != NULL; currItem = currItem->nextItem_m) {
        // Check if the item was found
        if ((currItem->data_m != NULL) && (strcmp(currItem->data_m->key, key) == 0)) {
            // Check if the item is the first in the list
            if (prevItem == NULL) {
                // Connect the linked list items
                t->items_m[tableIndex] = currItem->nextItem_m;;
                // Free the data key
                free((char *) currItem->data_m->key);
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
            // Connect the linked list items 
            prevItem->nextItem_m = currItem->nextItem_m;
            // Free the data key
            free((char *) currItem->data_m->key);
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
    return false;
}

/* End of htab_erase.c */