/* ***************************** tail.c *************************** */
/*  Author: Marek Čupr (xcuprm01)                                   */
/*  College: VUT FIT                                                */
/*  Subject: IJC - Project 2                                        */
/*  Date: 31. 03. 2024                                              */
/*  Functionality: Print the last n number of lines from the input  */
/* **************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define EXIT_FAILURE 1 // Error exit value
#define LINE_END_RESERVED 2 // Line terminating symbols ('\n', '\0')
#define MAX_LINE_LEN 2047 // Maximum line length

/**
 * @brief Struct for circular buffer.
 */
typedef struct circularBuffer {
    int circleStart_m; // Start of the circle
    int circleEnd_m;   // End of the circle
    int circleIndex_m; // Current circle index
    int circleSize_m;  // Size of the circle
    char** buffer_m;   // Buffer for the lines
} circularBuffer_t;

/**
 * @brief Create a circular buffer.
 * @param n Size of the circular buffer.
 * @return Pointer to the circular buffer.
 */
circularBuffer_t* cbuf_create(unsigned int n) {
    // Allocate memory for the circular buffer
    circularBuffer_t* circBuffer = (circularBuffer_t *) malloc(sizeof(circularBuffer_t));
    if (circBuffer == NULL) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Allocate memory for the circular buffer items
    circBuffer->buffer_m = (char **) malloc(n * sizeof(char *));
    if (circBuffer->buffer_m == NULL) {
        free(circBuffer);
        fprintf(stderr, "Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Initialize the default values
    circBuffer->circleStart_m = 0;
    circBuffer->circleEnd_m = -1;
    circBuffer->circleIndex_m = 0;
    circBuffer->circleSize_m = n;

    return circBuffer;
}

/**
 * @brief Put a line into the circular buffer.
 * @param cb Pointer to the circular buffer.
 * @param line Pointer to the line. 
 */
void cbuf_put(circularBuffer_t* cb, char* line) {
    // Check if the buffer empty
    if (cb->circleEnd_m == -1) {
       cb->buffer_m[cb->circleStart_m] = line;
       cb->circleEnd_m += 2;
       (cb->circleIndex_m)++;
       return; 
    }

    // Update the indexes
    cb->circleStart_m = cb->circleStart_m % cb->circleSize_m;
    cb->circleEnd_m = cb->circleIndex_m % cb->circleSize_m;

    // Check if the buffer is full
    if (cb->circleStart_m == cb->circleEnd_m) {
        free(cb->buffer_m[cb->circleStart_m]);
        cb->circleStart_m++;
    }

    // Add the line into the buffer
    cb->buffer_m[cb->circleEnd_m] = line;
    (cb->circleIndex_m)++;
}

/**
 * @brief Get a line from the circular buffer.
 * @param cb Pointer to the circular buffer.
 * @return Pointer to the line.
 */
char* cbuf_get(circularBuffer_t* cb) {
    // Get the line index
    int index = (cb->circleStart_m) % cb->circleSize_m;
    (cb->circleStart_m)++;

    // Return the line
    return cb->buffer_m[index];
}

/**
 * @brief Free the circular buffer.
 * @param cb Pointer to the circular buffer.
 */
void cbuf_free(circularBuffer_t* cb) {
    // Free the lines
    for (int i = 0; i < cb->circleSize_m; i++)
        free(cb->buffer_m[i]);

    // Free the circular buffer
    free(cb->buffer_m);
    free(cb);
}

/**
 * @brief Get the minimum value.
 * @param val1 First value.
 * @param val2 Second value.
 * @return Minimum value.
 */
int min_value(int val1, int val2) {
    return val1 < val2 ? val1 : val2;
}

/**
 * @brief Create a line copy.
 * @param src Pointer to the line.
 * @return Pointer to the copied line.
 */
char *my_strdup(const char *src) {
    char *dst = (char *) malloc(strlen(src) + 1);
    if (dst == NULL) return NULL;
    strcpy(dst, src);
    return dst;
}

/**
 * @brief Handle the input arguments.
 * @param argc Number of arguments.
 * @param argv Array of arguments.
 * @param f_ptr Pointer to the file.
 * @param linesNum Pointer to the number of lines.
 */
void handle_arguments(int argc, char* argv[], FILE **f_ptr, int *linesNum) {
    if (argc == 2) { // Only a file specified
        // Open the file
        *f_ptr = fopen(argv[1], "r");
        if (*f_ptr == NULL) {
            fprintf(stderr, "Error: Invalid input arguments\n");
            exit(EXIT_FAILURE);
        }
    } else if (argc == 3) { // Only a number of lines specified
        if (strcmp(argv[1], "-n") != 0) {
            fprintf(stderr, "Error: Invalid input arguments\n");
            exit(EXIT_FAILURE);
        }

        // Covert the string to a number
        char stringTerminated[1];
        int convertionResult = sscanf(argv[2], "%d%s", linesNum, stringTerminated);
        if (convertionResult != 1) { // Check if the conversion was successful
            fprintf(stderr, "Error: Invalid input arguments\n");
            exit(EXIT_FAILURE);
        }
    } else if (argc == 4) { // Both a file and a number of lines specified
        if (strcmp(argv[1], "-n") == 0) { // Number of lines scecified first
            // Covert the string to a number
            char stringTerminated[1];
            int convertionResult = sscanf(argv[2], "%d%s", linesNum, stringTerminated);
            if (convertionResult != 1) { // Check if the conversion was successful
                fprintf(stderr, "Error: Invalid input arguments\n");
                exit(EXIT_FAILURE);
            }

            // Open the file
            *f_ptr = fopen(argv[3], "r");
            if (*f_ptr == NULL) {
                fprintf(stderr, "Error: Invalid input arguments\n");
                exit(EXIT_FAILURE);
            }
        } else if ((*f_ptr = fopen(argv[1], "r")) != NULL) { // A file specified first
            if (strcmp(argv[2], "-n") != 0) {
                fprintf(stderr, "Error: Invalid input arguments\n");
                exit(EXIT_FAILURE);
            }

            // Covert the string to a number
            char stringTerminated[1];
            int convertionResult = sscanf(argv[3], "%d%s", linesNum, stringTerminated);
            if (convertionResult != 1) { // Check if the conversion was successful
                fclose(*f_ptr);
                fprintf(stderr, "Error: Invalid input arguments\n");
                exit(EXIT_FAILURE);
            }
        } else { // Invalid input
            fprintf(stderr, "Error: Invalid input arguments\n");
            exit(EXIT_FAILURE);
        }
    } else { // Invalid input
        fprintf(stderr, "Error: Invalid input arguments\n");
        exit(EXIT_FAILURE);
    }

    // Validate the number of lines
    if (*linesNum < 0) {
        fprintf(stderr, "Error: Invalid input arguments\n");
        exit(EXIT_FAILURE);
    }

    // Zero lines
    if (*linesNum == 0)
        exit(0);
}

int main(int argc, char* argv[]) {
    // Initialize the default values
    FILE *f_ptr = stdin; // Default input
    int linesNum = 10; // Default number of lines

    // Handle the arguments
    if (argc != 1)
        handle_arguments(argc, argv, &f_ptr, &linesNum);

    // Create a circular buffer
    circularBuffer_t* circBuffer = cbuf_create(linesNum);

    // Create a buffer to store the lines
    char currentLine[MAX_LINE_LEN + LINE_END_RESERVED]; // Maximum line length + '\n' + '\0'

    int c; // Temporary variable for getc
    int errPrinted = 0; // Check if the error was printed
    char *lineCopy; // Copy of the line

    // Read the lines
    while (fgets(currentLine, MAX_LINE_LEN + 2, f_ptr)) {
        // Check if the line is too long
        if (strlen(currentLine) > MAX_LINE_LEN) {
            // Print the error message
            if (!errPrinted) {
                errPrinted = 1; // Set the error flag
                fprintf(stderr, "Warning: Line too long\n");
            }

            // Terminate the line
            currentLine[MAX_LINE_LEN] = '\n';
            currentLine[MAX_LINE_LEN + 1] = '\0';
            // Delete the rest of the line
            while (((c = getc(f_ptr)) != '\n') && c != EOF);
        }

        // Copy the line using a custom strdup function
        lineCopy = my_strdup(currentLine);
        if (lineCopy == NULL) { // Strdup memory allocation failed
            // Free the circular buffer
            cbuf_free(circBuffer);

            // Close the file
            if (f_ptr != stdin)
                fclose(f_ptr);

            fprintf(stderr, "Error: Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }

        // Add the line into the circular buffer
        cbuf_put(circBuffer, lineCopy);
    }

    // Print the last n number of lines
    for (int i = 0; i < min_value(circBuffer->circleSize_m, circBuffer->circleIndex_m); i++)
        printf("%s", cbuf_get(circBuffer));

    // Free the circular buffer
    cbuf_free(circBuffer);

    // Close the file
    if (f_ptr != stdin)
        fclose(f_ptr);

    return 0;
}

/* End of tail.c */