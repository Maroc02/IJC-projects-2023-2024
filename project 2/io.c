/* ****************************************** io.c ***************************************** */
/*  Author: Marek Čupr (xcuprm01)                                                            */
/*  College: VUT FIT                                                                         */
/*  Subject: IJC - Project 2                                                                 */
/*  Date: 09. 04. 2024                                                                       */
/*  Functionality: Read a word from the input file and return the number of characters read  */       
/* ***************************************************************************************** */

#include <ctype.h>
#include <assert.h>

#include "io.h"

// Clear the white spaces from the input
int clear_space(FILE *f) {
    int read_char;
    // Clear the white space
    while (isspace( (char) (read_char = fgetc(f))) && (read_char != EOF)) {}
    return read_char;
}

// Read a word from the input and return the number of characters read
int read_word(char *s, int max, FILE *f) {
    // Validate the input
    assert((s != NULL) && (max > 0) && (f != NULL));

    // Clear the initial white spaces
    int read_char, read_cnt = 0;

    // Check for EOF
    if ((read_char = clear_space(f)) == EOF)
        return EOF;

    // Save the first character
    s[read_cnt++] = read_char;

    // Read the word
    while (read_cnt < (max - 1)) {
        // Check for white space
        if (isspace( (char) (read_char = fgetc(f))))
            break;

        // Check for EOF
        if (read_char == EOF)
            break;

        // Save the character
        s[read_cnt++] = read_char;
    }

    // Terminate the string
    s[read_cnt] = '\0';

    // Check if the word is too long
    if (read_cnt == (max - 1))
        while (!isspace( (char) (read_char = fgetc(f))) && (read_char != EOF)) {read_cnt++;}

    return read_cnt;
}

/* End of io.c */