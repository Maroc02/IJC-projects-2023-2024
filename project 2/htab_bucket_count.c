/* ********** htab_bucket_count.c ********* */
/*  Author: Marek Čupr (xcuprm01)           */
/*  College: VUT FIT                        */
/*  Subject: IJC - Project 2                */
/*  Date: 09. 04. 2024                      */
/*  Functionality: Get the hash table size  */
/* **************************************** */

#include "htab_private.h"

/**
 * @brief Get the hash table size.
 * @param t Pointer to the hash table.
 * @return Number of items in the hash table.
 */
size_t htab_bucket_count(const htab_t * t) {
    return t->arrSize_m;
}

/* End of htab_bucket_count.c */
