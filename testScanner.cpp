//
// Created by Admin on 2/14/2024.
//
#include <string.h>
#include <stdio.h>

#include "scanner.h"
#include "token.h"

// Function to read from file and print and stores the string of characters.
void readFromFile(char* filename) {

    FILE *file = fopen(filename, "r"); // Open the file in read mode
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char input_char;
    struct Token token;
    token.line_num = 1;
    int index = 0; // to keep track of the current position in tokeninstance

    memset(token.tokeninstance, 0, MAX_INSTANCE_TOKEN);

    do {
        // Read a character from the file
        input_char = fgetc(file);

        // Check for newline
        if (input_char == '\n') {
            // Increment line number
            token.line_num++;

        } else if (input_char == EOF) {
            // End of file reached, store the last token instance and break the loop
            token.tokeninstance[index] = '\0'; // Null-terminate the token instance
            break;

        } else {
            // Check for buffer overflow
            if (index < MAX_INSTANCE_TOKEN - 1) {
                // Read characters into array
                token.tokeninstance[index++] = input_char;

            } else {
                printf("Error: Maximum token size exceeded.\n");
                break;
            }
        }
    } while (1);

    Scanner(token.tokeninstance, token.line_num);


    fclose(file);
}



//let us get rid of all the comments in, they will start with # and end with one.
void testScanner(char *inputfile, char *outputfile) {

    FILE *input_file = fopen(inputfile, "r");
    if (input_file == NULL) {printf("Error opening input file.\n"); return;}

    FILE *output_file = fopen(outputfile, "w");
    if (output_file == NULL) { printf("Error opening output file.\n");  return;}

    int input_char;
    bool comments = false;

    while ((input_char = fgetc(input_file)) != EOF) {
        if (!comments) {
            if (input_char != '#') {
                if(input_char != '\t') {
                    fputc(input_char, output_file); // Write character to output file if not in a comment
                }
            } else {
                comments = true; // Start of comment
            }
        } else {
            if (input_char == '\n') {
                comments = false; // End of comment when encountering a newline
            }
        }
    }

    fclose(input_file);
    fclose(output_file);

    readFromFile(outputfile); //passing the char array not the file pointer

}