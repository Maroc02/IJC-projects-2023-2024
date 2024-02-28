/* ******************************** error.h ******************************** */
/*  Author: Marek Čupr (xcuprm01)                                            */
/*  Subject: IJC - Project                                                   */
/*  Date: 23. 02. 2024                                                       */
/*  Functionality: Header file for error.c                                   */
/* ************************************************************************* */

#ifndef ERROR_H
#define ERROR_H

void error_exit(const char *fmt, ...);
void warning(const char *fmt, ...);

#endif