/* ********************** error.c ********************** */
/*  Author: Marek Čupr (xcuprm01)                        */
/*  College: VUT FIT                                     */
/*  Subject: IJC - Project 1                             */
/*  Date: 20. 02. 2024                                   */
/*  Functionality: Print warnings and errors to stderr   */
/* ***************************************************** */

#include <stdio.h>  // fprintf, vprintf
#include <stdarg.h> // va_list, va_start, va_end
#include <stdlib.h> // exit

#include "error.h"

void warning(const char* fmt, ...){
    va_list warning_args;
    va_start(warning_args, fmt);
    fprintf(stderr, "Warning: ");
    vfprintf(stderr, fmt, warning_args);
    va_end(warning_args);
}

void error_exit(const char* fmt, ...){
    va_list exit_args;
    va_start(exit_args, fmt);
    fprintf(stderr, "Error: ");
    vfprintf(stderr, fmt, exit_args);
    va_end(exit_args);
    exit(1); // End the program
}

/* End of error.c */