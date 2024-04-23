/* ************************ htab_for_each.c *********************** */
/*  Author: Marek Čupr (xcuprm01)                                   */
/*  College: VUT FIT                                                */
/*  Subject: IJC - Project 2                                        */
/*  Date: 09. 04. 2024                                              */
/*  Functionality: Call a function for each item in the hash table  */
/* *********************** **************************************** */

#include <assert.h>

#include "htab.h"
#include "htab_private.h"

/**
 * @brief Call a function for each item in the hash table.
 * @param t Pointer to the hash table.
 * @param f Pointer to the function.
 */
void htab_for_each(const htab_t * t, void (*f)(htab_pair_t *data)) {
    // Validate the arguments
    assert(t != NULL);

    // Iterate through the list of items
    for (size_t i = 0; i < t->arrSize_m; i++) {
        for (struct htab_item *currItem = t->items_m[i]; currItem != NULL; currItem = currItem->nextItem_m) {
            f(currItem->data_m);
        }   
    }
}

/* End of htab_for_each.c */