/* **************** io.h *************** */
/*  Author: Marek Čupr (xcuprm01)        */
/*  College: VUT FIT                     */
/*  Subject: IJC - Project 2             */
/*  Date: 09. 04. 2024                   */
/*  Functionality: Header file for io.c  */
/* ************************************* */

#ifndef IO_H
#define IO_H

#include <stdio.h>

/**
 * @brief Clear the white spaces from the input file.
 * @param f File to read from.
 * @return First non-white space character.
 */
int clear_space(FILE *f);

/**
 * @brief Read a word from the input file.
 * @param f File to read from.
 * @return Number of characters read.
 */
int read_word(char *s, int max, FILE *f);

#endif // IO_H

/* End of io.h */