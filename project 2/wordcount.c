/* ************************* wordcount.c ************************ */
/*  Author: Marek Čupr (xcuprm01)                                 */
/*  College: VUT FIT                                              */
/*  Subject: IJC - Project 2                                      */
/*  Date: 09. 04. 2024                                            */
/*  Functionality: Count the occurrences of words from the input  */
/* ************************************************************** */

#include "htab.h"
#include "io.h"

#include <stdlib.h>

#define EXIT_FAILURE 1 // Exit failure code
#define MAX_WORD_LENGTH 255 // Maximum word length
#define HASH_TABLE_SIZE 6666 // Hash table size (The program takes approx. 10s to finish the seq test with this size)

// Print the word and its occurrence count
void print_word(htab_pair_t *data) {
    printf("%s\t%d\n", data->key, data->value);
}

int main(void) {
    // Initialize the hash table
    htab_t *t = htab_init(HASH_TABLE_SIZE);
    if (t == NULL) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Create a buffer to store the words
    char wordBuffer[MAX_WORD_LENGTH + 1];
    
    int wordLen, errPrinted = 0;
    // Read the words
    while ((wordLen = read_word(wordBuffer, MAX_WORD_LENGTH + 1, stdin)) != EOF) {
        // Check if the word is too long
        if ((wordLen > MAX_WORD_LENGTH) && (!errPrinted)) {
            // Print the error message
            errPrinted = 1; // Set the error flag
            fprintf(stderr, "Warning: Word too long\n");
        }

        // Add the word to the hash table
        if (htab_lookup_add(t, wordBuffer) == NULL) {
            // Free the hash table
            htab_free(t);
            
            fprintf(stderr, "Error: Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
    }

    // Print the words
    htab_for_each(t, print_word);

    // Print the statistics
    #ifdef STATISTICS
        htab_statistics(t);
    #endif

    // Free the hash table
    htab_free(t);

    return 0;
}

/* End of wordcount.c */