/* *********************** htab_size.c ********************** */
/*  Author: Marek Čupr (xcuprm01)                             */
/*  College: VUT FIT                                          */
/*  Subject: IJC - Project 2                                  */
/*  Date: 09. 04. 2024                                        */
/*  Functionality: Get the the hash table size                */
/* ********************************************************** */

#include "htab.h"
#include "htab_private.h"

/**
 * @brief Get the hash table size.
 * @param t Pointer to the hash table.
 * @return The hash table size.
 */
size_t htab_size(const htab_t * t) {
    return t->size_m;
}

/* End of htab_size.c */