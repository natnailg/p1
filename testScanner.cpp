//
// Created by Admin on 2/14/2024.
//

#include <stdio.h>
#include <ctype.h>
#include "testScanner.h"
#include "token.h"

// we need a map function here that is going to read in the char, and it's going to be based on what that char is,
// it's going map it to a number that I decide. > = 0

//FSA Table have row and column ordering as specified in class
int Table [12][12]= { //had to do 12 for the columns
        {1,-1,3,5,10,-2,8,-3,6,-4,0,1001},
        {-5,2,-5,-5,-5,-5,-5,-5,-5,-5,-5,5},
        {1002,2,1002,1002,1002,1002,1002,1002,1002,1002,1002,1002},
        {-5,4,-6,-6,-6,-6,-6,-6,-6,-6,-6,-6},
        {1003,4,1003,1003,1003,1003,1003,1003,1003,1003,1003,1003},
        {1004,1004,1004,1004,1004,1004,1004,1004,1004,1004,1004,1004},
        {1004,1004,1004,1004,1004,1004,1004,1004,1004,7,1004,1004},
        {1004,1004,1004,1004,1004,1004,1004,1004,1004,1004,1004,1004},
        {1004,1004,1004,1004,1004,1004,1004,9,1004,1004,1004,1004},
        {1004,1004,1004,1004,1004,1004,1004,1004,1004,1004,1004,1004},
        {1004,1004,1004,1004,1004,11,1004,1004,1004,1004,1004,1004},
        {1004,1004,1004,1004,1004,1004,1004,1004,1004,1004,1004,1004}

};
/*-1 => cant start with digit
 * -2 => semicolon error
 * -3 => can't have dollar sign start
 * -4 => can't start with quotation
 * -5 => must be digit
 * -6 => must be digit
 * t1_final = 1002
 * t2_final = 1003
 * t3_final = 1004
 * EOF_tk = 1001
 * */


void printtable() {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            printf("%d  ", Table[i][j]);
        }
        printf("\n");
    }
}


////////////////////////////////////////////////////////////////////////////////////////////
int mapingchar(char c) {
    switch ((int)c) {
        case 'a' ... 'z': // lowercase letters 'a-z'
        case 'A' ... 'Z': // uppercase letters 'A-Z'
            return LETTER;
        case '0' ... '9': // digits '0' to '9'
            return DIGIT;
        case '%': // Percent sign '%'
            return PERCENTAGE;
        case '.': // Period '.'
        case '!': // Exclamation mark '!'
            return DOT_OR_EXCLAMATION;
        case ',': // Comma ','
            return COMMA;
        case ';': // Semicolon ';'
            return SEMICOLON;
        case '?': // Question mark '?'
            return QUESTION_MARK;
        case '$': // Dollar sign '$'
            return DOLLAR_SIGN;
        case '*': // Asterisk '*'
            return STAR;
        case '"': // Double quote '"'
            return QUOTATION;
        case ' ': // White space (space)
        case '\n': // Newline character
            return WHITESPACE;
        case '\0': // EOF encountered
            return END_OF_FILE;
        default:
            return -1; // Unknown character
    }
}

void printCharacterType(char c, int result, int line) {
    switch (result) {
        case LETTER:
            printf("Character %c is a letter -> line %d.\n", c, line);
            break;
        case DIGIT:
            printf("Character %c is a digit -> line %d.\n", c, line);
            break;
        case PERCENTAGE:
            printf("Character %c is a percentage sign -> line %d.\n", c, line);
            break;
        case DOT_OR_EXCLAMATION:
            printf("Character %c is a period or exclamation mark -> line %d.\n", c, line);
            break;
        case COMMA:
            printf("Character %c is a comma -> line %d.\n", c, line);
            break;
        case SEMICOLON:
            printf("Character %c is a semicolon -> line %d.\n", c, line);
            break;
        case QUESTION_MARK:
            printf("Character %c is a question mark -> line %d.\n", c, line);
            break;
        case DOLLAR_SIGN:
            printf("Character %c is a dollar sign -> line %d.\n", c, line);
            break;
        case STAR:
            printf("Character %c is an asterisk -> line %d.\n", c, line);
            break;
        case QUOTATION:
            printf("Character %c is a double quote -> line %d.\n", c, line);
            break;
        case WHITESPACE:
            printf("Character  is a whitespace -> line %d.\n",  line);
            break;
        case END_OF_FILE:
            printf("EOF encountered -> line %d.\n", line);
            break;
        default:
            printf("Character %c is an unknown character -> line %d.\n", c, line);
    }
}



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
    token.line_num =1;
    int index = 0; // to keep track of the current position in tokeninstance

    // Keep reading characters until EOF is encountered
    while ((input_char = fgetc(file)) != EOF) {
        if (input_char == '\n') {
            token.tokeninstance[index] = '\0'; // Null-terminate the token
            printf("Line %d: %s\n", lineCount, token.tokeninstance); // Print the string
            printf("Line %d: %s\n", token.line_num, token.tokeninstance); // Print the string

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
    }
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
            if (input_char != '#' && !isspace(input_char) && input_char != '\n') {
                fputc(input_char, output_file); // Write character to output file if not in a comment
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