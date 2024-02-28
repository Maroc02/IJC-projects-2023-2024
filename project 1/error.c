/* ********************************* error.c ******************************** */
/*  Author: Marek Čupr (xcuprm01)                                             */
/*  Subject: IJC - Project                                                    */
/*  Date: 23. 02. 2024                                                        */
/*  Functionality: Print warnings and errors to stderr                        */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#include "error.h"

void warning(const char *fmt, ...){
    va_list warning_args;
    va_start(warning_args, fmt);
    fprintf(stderr, "Warning: ");
    vfprintf(stderr, fmt, warning_args);
    va_end(warning_args);
}

void error_exit(const char *fmt, ...){
    va_list warning_args;
    va_start(warning_args, fmt);
    fprintf(stderr, "Error: ");
    vfprintf(stderr, fmt, warning_args);
    va_end(warning_args);
    exit(1);
}