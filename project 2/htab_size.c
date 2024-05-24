/* *********************** htab_size.c ********************** */
/*  Author: Marek Čupr (xcuprm01)                             */
/*  College: VUT FIT                                          */
/*  Subject: IJC - Project 2                                  */
/*  Date: 09. 04. 2024                                        */
/*  Functionality: Get the number of items in the hash table  */
/* ********************************************************** */

#include "htab_private.h"

/**
 * @brief Get the number of items in the hash table.
 * @param t Pointer to the hash table.
 * @return The number of items in the hash table.
 */
size_t htab_size(const htab_t * t) {
    return t->size_m;
}

/* End of htab_size.c */