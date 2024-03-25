/* ********************** error.h ********************** */
/*  Author: Marek Čupr (xcuprm01)                        */
/*  College: VUT FIT                                     */
/*  Subject: IJC - Project 1                             */
/*  Date: 20. 02. 2024                                   */
/*  Functionality: Header file for error.c               */
/* ***************************************************** */

#ifndef ERROR_H
#define ERROR_H

/**
 * @brief Prints an error message to stderr and exits the program.
 *
 * @param fmt Format string to be printed out.
 * @param ... Format specifiers.
 */
void warning(const char* fmt, ...);

/**
 * @brief Prints a warning message to stderr.
 *
 * @param fmt Format string to be printed out.
 * @param ... Format specifiers.
 */
void error_exit(const char* fmt, ...);

#endif

/* End of error.h */