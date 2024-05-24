/* ******************* htab_private.h ****************** */
/*  Author: Marek Čupr (xcuprm01)                        */
/*  College: VUT FIT                                     */
/*  Subject: IJC - Project 2                             */
/*  Date: 09. 04. 2024                                   */
/*  Functionality: Private header file for htab.h        */
/* ***************************************************** */

#include <string.h>
#include <stdlib.h>

#include "htab.h"

/**
 * @brief Struct for the hash table item.
 */
typedef struct htab_item {
    htab_pair_t *data_m;          // Item data
    struct htab_item *nextItem_m; // Pointer to the next item
} htab_item_t;

/**
 * @brief Struct for the hash table.
 */
struct htab {
    size_t size_m;         // Size of the hash table
    size_t arrSize_m;      // Number of items in the hash table
    htab_item_t **items_m; // Array of items
};

/* End of htab_private.h */