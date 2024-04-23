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
 * @brief Free the hash table.
 * @param t Pointer to the hash table.
 */
void htab_free(htab_t *t) {
    // Validate the arguments
    assert(t != NULL);

    // Clear the hash table
    htab_clear(t);

    // Free the array of items
    free(t->items_m);
    t->items_m = NULL;
    // Free the hash table
    free(t);
    t = NULL;
}

/* End of htab_free.c */