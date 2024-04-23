/* ******************** htab_lookup_add.c******************* */
/*  Author: Marek Čupr (xcuprm01)                            */
/*  College: VUT FIT                                         */
/*  Subject: IJC - Project 2                                 */
/*  Date: 09. 04. 2024                                       */
/*  Functionality: Add the item to the hash table            */
/* ********************************************************* */

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "htab.h"
#include "htab_private.h"

/**
 * @brief Create a word copy.
 * @param src Pointer to the word.
 * @return Pointer to the copied word.
 */
char *my_strdup(const char *src) {
    char *dst = (char *) malloc(strlen(src) + 1);
    if (dst == NULL) return NULL;
    strcpy(dst, src);
    return dst;
}

/**
 * @brief Add the item to the hash table.
 * @param t Pointer to the hash table.
 * @param key Key of the item.
 * @return Pointer to the new created or already existing item.
 */
htab_pair_t *htab_lookup_add(htab_t *t, htab_key_t key) {
    // Validate the arguments
    assert((t != NULL) && (key != NULL));

    // Get the table index using hash function
    size_t tableIndex = htab_hash_function(key) % t->arrSize_m;

    // Get the searched item
    struct htab_item *currItem = t->items_m[tableIndex];
    // The index already contains some items
    if (currItem != NULL){
        // Search for the correct item
        while (currItem != NULL) {
            if ((currItem->data_m != NULL) && (strcmp(currItem->data_m->key, key) == 0)) {
                // The item was found
                currItem->data_m->value++;
                return currItem->data_m;
            }

            if (currItem->nextItem_m == NULL)
                break;  

            currItem = currItem->nextItem_m;
        }

        // Item was not found, allocate memory for new item
        struct htab_item *newItem = (struct htab_item *) malloc(sizeof(struct htab_item));
        if (newItem == NULL) // Check memory allocation
            return NULL;

        // Allocate memory for the data
        newItem->data_m = (htab_pair_t *) malloc(sizeof(htab_pair_t));
        if (newItem->data_m == NULL) { // Check memory allocation
            free(newItem);
            return NULL;
        }
        
        // Initialize the new item
        newItem->data_m->key = my_strdup(key);
        newItem->data_m->value = 1;
        newItem->nextItem_m = NULL;

        // Increase the hashtable size
        t->size_m++;

        // Connect the list items 
        currItem->nextItem_m = newItem;

        // Return the new item
        return newItem->data_m;
    } else { // The index is empty
        // Allocate memory for the new item 
        struct htab_item *newItem = (struct htab_item *) malloc(sizeof(struct htab_item));
        if (newItem == NULL) // Check memory allocation
            return NULL;

        // Allocate memory for the data
        newItem->data_m = (htab_pair_t *) malloc(sizeof(htab_pair_t));
        if (newItem->data_m == NULL) { // Check memory allocation  
            free(newItem);
            return NULL;
        }

        // Initialize the new item
        newItem->data_m->key = my_strdup(key);
        newItem->data_m->value = 1;
        newItem->nextItem_m = NULL;

        // Increase the hashtable size
        t->size_m++;

        // Connect the list items
        t->items_m[tableIndex] = newItem;

        // Return the new item
        return newItem->data_m;
    }
}

/* End of htab_lookup_add.c */