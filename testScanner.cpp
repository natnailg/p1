// Natanail Gebru
// Created by Admin on 2/14/2024.
//

#include <string.h>
#include <stdio.h>

#include "scanner.h"
#include "token.h"

const char* tokenNames[] = {"EOF token",  "T1 token", "T2 token", "T3 token", "Error token","Unknown token"};


//read from the file and print the necessary requirments of the token.
void readFromFile(char* filename){

    file = fopen(filename, "r"); // Open the file in read mode

    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    Token tokenInfo;
    int line_num = 1;

    memset(tokenInfo.tokeninstance, '\0', MAX_INSTANCE_TOKEN);

    nextChar = fgetc(file);

    do {
        // Start scanner function
        if (nextChar == '\n'){
            line_num++;
        }
        tokenInfo = Scanner(line_num);

        printf("%s\t%s\t%d\n", tokenNames[tokenInfo.tokenId], tokenInfo.tokeninstance, tokenInfo.line_num);

    } while (nextChar != EOF);
}

//gets rid of all the comments in it and newlines, and print it to a new file and pass it to a function
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

