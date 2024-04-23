/* ************************* tail.c ************************ */
/*  Author: Marek Čupr (xcuprm01)                            */
/*  College: VUT FIT                                         */
/*  Subject: IJC - Project 2                                 */
/*  Date: 31. 03. 2024                                       */
/*  Functionality: Print the last n lines of the input file  */
/* ********************************************************* */

#include "htab.h"
#include "io.h"

#define MAX_WORD_LENGTH 255 // Maximum word length

// Print the saved word
void print_line(htab_pair_t *data) {
    printf("%s\t%d\n", data->key, data->value);
}

int main(void) {
    // Initialize the hash table
    htab_t *t = htab_init(10000);

    // Buffer for the word
    char wordBuffer[MAX_WORD_LENGTH + 1];
    
    int wordLen, errPrinted = 0;
    // Read the words
    while ((wordLen = read_word(wordBuffer, MAX_WORD_LENGTH + 1, stdin)) != EOF) {
        // Check if the word is too long
        if ((wordLen > MAX_WORD_LENGTH) && (!errPrinted)) {
            errPrinted = 1;
            fprintf(stderr, "Warning: Word too long\n");
        }

        // Add the word to the hash table
        htab_lookup_add(t, wordBuffer);
    }

    // Print the words
    htab_for_each(t, print_line);

    #ifdef STATISTICS
        htab_statistics(t);
    #endif

    // Free the hash table
    htab_free(t);

    return 0;
}

/* End of wordcount.c */