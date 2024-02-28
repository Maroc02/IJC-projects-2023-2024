/* ****************************** no_comment.c ******************************* */
/*  Author: Marek Čupr (xcuprm01)                                              */
/*  Subject: IJC - Project                                                     */
/*  Date: 20. 02. 2024                                                         */
/*  Functionality: Delete all comments from .c file                            */
/* *************************************************************************** */

#include <sys/stat.h>
#include <stdio.h>
#include "no_comment.h"

/*
int main(int argc, char *argv[]){
    FILE *f_ptr = stdin;
    if (argc == 2){
        f_ptr = fopen(argv[1], "r");
        if (!f_ptr)
            error_exit("Error: can't open file ", argv[1]);
    }

    int c; // Read characters
    states_t state = S_0;  // Initial state

    while((c = fgetc(f_ptr)) != EOF){
        switch (state)
        {
        case S_0:
            if (c == '/') state = S_1;
            else if (c == '"'){ putchar(c); state = S_6; }
            else if (c == '\''){ putchar(c); state = S_8; }
            else putchar(c);
            break;
        case S_1:
            if (c == '/') state = S_4;
            else if (c == '*') state = S_2;
            else { state = S_0; putchar('/'); putchar(c); }
            break;
        case S_2:
            if (c == '*') state = S_3;
            break;
        case S_3:
            if(c == '/') { state = S_0; putchar(' '); }
            else if(c != '*') state = S_2;
            break;
        case S_4:
            if (c == '\n') { putchar('\n'); state = S_0; }
            if (c == '\\') { state = S_5; }
            break;
        case S_5:
            if (c !='\\') state = S_4;
            break;
        case S_6:
            if (c == '\\') { putchar(c); state = S_7; }
            else if (c =='"') { putchar(c); state = S_0; }
            else putchar(c);
            break;
        case S_7:
            putchar(c); state = S_6;
            break;
        case S_8:
            if (c == '\\') { putchar(c); state = S_9; }
            else if (c == '\'') { putchar(c); state = S_0; }
            else putchar(c);
            break;
        case S_9:
            putchar(c); state = S_8;
            break;
        default:
            break;
        }
    }

    if (state != 0)
        error_exit("Finished at state that is not final");

    return 0;
}*/