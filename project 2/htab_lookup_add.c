/* ************** htab_lookup_add.c ************** */
/*  Author: Marek Čupr (xcuprm01)                  */
/*  College: VUT FIT                               */
/*  Subject: IJC - Project 2                       */
/*  Date: 09. 04. 2024                             */
/*  Functionality: Add the item to the hash table  */
/* *********************************************** */

#include <stdio.h>
#include <assert.h>

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
 * @return Pointer to the item if the item was found or added, otherwise NULL.
 */
htab_pair_t *htab_lookup_add(htab_t *t, htab_key_t key) {
    // Validate the arguments
    assert((t != NULL) && (key != NULL));

    // Get the hash table index using the hash function
    size_t tableIndex = htab_hash_function(key) % t->arrSize_m;

    // Get the current item
    struct htab_item *currItem = t->items_m[tableIndex];

    // The current item index is not empty
    if (currItem != NULL){
      // Iterate through the linked list of items
        while (currItem != NULL) {
            // Check if the item was found
            if ((currItem->data_m != NULL) && (strcmp(currItem->data_m->key, key) == 0)) {
                currItem->data_m->value++;
                return currItem->data_m;
            }

            // Break if the last item was reached
            if (currItem->nextItem_m == NULL)
                break;  

            // Move to the next item in the list
            currItem = currItem->nextItem_m;
        }

        // The item was not found, create a new item
        struct htab_item *newItem = (struct htab_item *) malloc(sizeof(struct htab_item));
        if (newItem == NULL)
            return NULL;

        // Allocate memory for the data
        newItem->data_m = (htab_pair_t *) malloc(sizeof(htab_pair_t));
        if (newItem->data_m == NULL) {
            free(newItem);
            return NULL;
        }
        
        // Initialize the default values
        newItem->data_m->key = my_strdup(key);
        newItem->data_m->value = 1;
        newItem->nextItem_m = NULL;

        // Increase the hashtable size
        t->size_m++;

        // Connect the linked list items
        currItem->nextItem_m = newItem;

        return newItem->data_m;
    } else { // The current item index is empty
        // The item was not found, create a new item
        struct htab_item *newItem = (struct htab_item *) malloc(sizeof(struct htab_item));
        if (newItem == NULL)
            return NULL;

        // Allocate memory for the data
        newItem->data_m = (htab_pair_t *) malloc(sizeof(htab_pair_t));
        if (newItem->data_m == NULL) {
            free(newItem);
            return NULL;
        }

        // Initialize the default values
        newItem->data_m->key = my_strdup(key);
        newItem->data_m->value = 1;
        newItem->nextItem_m = NULL;

        // Increase the hashtable size
        t->size_m++;

        // Connect the linked list items
        t->items_m[tableIndex] = newItem;

        return newItem->data_m;
    }
}

/* End of htab_lookup_add.c */