/* ******************** no-comment.c ******************** */
/*  Author: Marek Čupr (xcuprm01)                         */
/*  College: VUT FIT                                      */
/*  Subject: IJC - Project 1                              */
/*  Date: 20. 02. 2024                                    */
/*  Functionality: Delete all comments from .c file       */
/* ****************************************************** */

#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <sys/stat.h>

#include "no-comment.h"

int main(int argc, char *argv[]){
    FILE *f_ptr = stdin; // Default input

    // Handle command line arguments
    if (argc > 1) {
        if (argc == 2){
            f_ptr = fopen(argv[1], "r"); // File input
            if (f_ptr == NULL)
                error_exit("can't open file %s\n", argv[1]);
        } else {
            error_exit("wrong argument count\n");
        }
    }

    // Default FSM state
    states_t state = S_0;
    int c; // Read input by characters

    // The following code is based on a finite-state machine
    while((c = fgetc(f_ptr)) != EOF){
        switch (state) {
            case S_0:
                if (c == '/') state = S_1;
                else if (c == '"') { putchar(c); state = S_6; }
                else if (c == '\'') { putchar(c); state = S_8; }
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

    // Check the final state 
    if (state != S_0)
        error_exit("finished at a non-final state\n");

    // Get the file descriptors for input and output
    int program_input_fd = fileno(f_ptr); 
    int program_output_fd = fileno(stdout); 

    // Get status information about the input
    struct stat input_stat;
    fstat(program_input_fd, &input_stat);

    // Get status information about the output
    struct stat output_stat;
    fstat(program_output_fd, &output_stat);

    // Check if the program output is redirected to the input file
    if (input_stat.st_dev == output_stat.st_dev && input_stat.st_ino == output_stat.st_ino)
        error_exit("output redirected to the same input file\n");

    return 0;
}

/* End of no-comment.c */