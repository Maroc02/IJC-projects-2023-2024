/* *************** htab_init.c ************** */
/*  Author: Marek Čupr (xcuprm01)             */
/*  College: VUT FIT                          */
/*  Subject: IJC - Project 2                  */
/*  Date: 09. 04. 2024                        */
/*  Functionality: Initialize the hash table  */
/* ****************************************** */

#include <assert.h>

#include "htab_private.h"

/**
 * @brief Initialize the hash table.
 * @param n Number of items in the hash table.
 * @return Pointer to the initialized hash table.
 */
htab_t *htab_init(const size_t n) {
     // Validate the arguments
     assert(n > 0);

     // Allocate memory for the hashtable
     htab_t *t = (htab_t *) malloc(sizeof(htab_t));
     if (t == NULL)
          return NULL;

     // Initialize the default values
     t->arrSize_m = n;
     t->size_m = 0;

     // Allocate memory for all the items
     t->items_m = (htab_item_t **) calloc(n, sizeof(htab_item_t *));
     if (t->items_m == NULL) {
          free(t);
          return NULL;
     }

     return t;
}

/* End of htab_init.c */