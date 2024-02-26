//
// Created by Admin on 2/14/2024.
//

#include <stdio.h>
#include "scanner.h"
#include "token.h"


// we need a map function here that is going to read in the char, and it's going to be based on what that char is,
// it's going map it to a number that I decide. > = 0

// Function to read from file and print strings
void readFromFile(char* filename) {
    FILE *file = fopen(filename, "r"); // Open the file in read mode
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char input_char;
    struct Token token;
    int lineCount = 1; // Initialize line count to 1
    token.line_num = 1;
    int index = 0; // to keep track of the current position in tokeninstance

    // Keep reading characters until EOF is encountered
  // while ((input_char = fgetc(file))) {
    input_char = fgetc(file);
    do{
           if (input_char == '\n') {
               token.tokeninstance[index] = '\0'; // Null-terminate the token **************
               nextChar = token.tokeninstance[0];
               FADriver(token.tokeninstance, token.line_num);

               // Reset the token for the next line
               index = 0; // Reset index
               lineCount++; // Increment line count
               token.line_num++;
           } else {
               // Add characters to the token instance array
               token.tokeninstance[index++] = input_char;
               // Check for tokeninstance overflow
               if (index >= MAX_INSTANCE_TOKEN) {
                   printf("Error: Maximum token size exceeded.\n");
                   return;
               }
           }
       }while(input_char != EOF);

fclose(file);
}

//let us get rid of all the comments in, they will start with # and end with one.
void removcomments(char *inputfile, char *outputfile) {

    FILE *input_file = fopen(inputfile, "r");
    if (input_file == NULL) {printf("Error opening input file.\n"); return;}

    FILE *output_file = fopen(outputfile, "w");
    if (output_file == NULL) { printf("Error opening output file.\n");  return;}

    int input_char;
    bool comments = false;

    while ((input_char = fgetc(input_file)) != EOF) {
        if (!comments) {
            if (input_char != '#') {
                if(input_char != ' ' && input_char != '\t') {
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
