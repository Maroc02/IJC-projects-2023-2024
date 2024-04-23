/* *********************** htab_find.c ********************* */
/*  Author: Marek Čupr (xcuprm01)                            */
/*  College: VUT FIT                                         */
/*  Subject: IJC - Project 2                                 */
/*  Date: 09. 04. 2024                                       */
/*  Functionality: Find the item in the hash table           */
/* ********************************************************* */

#include <assert.h>

#include "htab.h"
#include "htab_private.h"

/**
 * @brief Find the item in the hash table.
 * @param t Pointer to the hash table.
 * @param key Key of the item.
 * @return Pointer to the item if the item was found, otherwise NULL.
 */
htab_pair_t * htab_find(const htab_t * t, htab_key_t key) {
    // Validate the arguments
    assert((t != NULL) && (key != NULL));

    // Get the table index using the hash function
    size_t table_index = htab_hash_function(key) % t->arrSize_m;

    // Iterate through the list of items
    for  (struct htab_item *currItem = t->items_m[table_index]; currItem != NULL; currItem = currItem->nextItem_m) {
        // Validate the data
        if ((currItem->data_m != NULL) && (strcmp(currItem->data_m->key, key) == 0)) // The item was found
            return currItem->data_m;
    }

    // The item was not found
    return NULL;
}

/* End of htab_find.c */