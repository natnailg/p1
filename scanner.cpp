//
//
// Created by Admin on 2/14/2024.
//
#include <stdio.h>
#include <string.h>
#include "scanner.h"
char nextChar;

const char* tokenNames[] = {"EOF token",  "T1 token", "T2 token", "T3 token", "Error token","Unknown token"};

//FSA Table have row and column ordering as specified in class
int Table [12][12]= { //had to do 12 for the columns
        {1,-1,3,5,10,-2,8,-3,6,-4,0,1001},
        {-5,2,-5,-5,-5,-5,-5,-5,-5,-5,-5,-5},
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
///

int mapingchar(char c) {
    switch ((int)c) {
        case 'a': case 'b': case 'c': case 'd': case 'e': case 'f': case 'g':
        case 'h': case 'i': case 'j': case 'k': case 'l': case 'm': case 'n':
        case 'o': case 'p': case 'q': case 'r': case 's': case 't': case 'u':
        case 'v': case 'w': case 'x': case 'y': case 'z':
        case 'A': case 'B': case 'C': case 'D': case 'E': case 'F': case 'G':
        case 'H': case 'I': case 'J': case 'K': case 'L': case 'M': case 'N':
        case 'O': case 'P': case 'Q': case 'R': case 'S': case 'T': case 'U':
        case 'V': case 'W': case 'X': case 'Y': case 'Z':
            return LETTER;
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
            return DIGIT;
        case '%': // Percent sign '%'
            return PERCENTAGE; // PERCENTAGE
        case '.': // Period '.'
        case '!': // Exclamation mark '!'
            return DOT_OR_EXCLAMATION; // DOT_OR_EXCLAMATION
        case ',': // Comma ','
            return COMMA; // COMMA
        case ';': // Semicolon ';'
            return SEMICOLON; // SEMICOLON
        case '?': // Question mark '?'
            return QUESTION_MARK; // QUESTION_MARK
        case '$': // Dollar sign '$'
            return DOLLAR_SIGN; // DOLLAR_SIGN
        case '*': // Asterisk '*' //
            return STAR; // STAR
        case '"': // Double quote '"'
            return QUOTATION; // QUOTATION
        case ' ': // White space (space)
            return WHITESPACE; // WHITESPACE
        case '\n': // Newline character
            return WHITESPACE;
        case '\0': // EOF encountered
            return END_OF_FILE; // END_OF_FILE
        default:
            printf("invalid character detected!! %c \n", c );
            return -1;// Unknown character
    }
}


tokenID FADriver(char* tokeninstances, int line_num) {
    int state = 0;
    struct Token token;
    int nextState;
    char S[256] = ""; // Assuming maximum token length of 255 characters
    int index = 0; // Index for tokeninstances
    int S_index = 0; // Index for S array
    int column;
    nextChar = tokeninstances[index++]; // Initialize nextChar with the first character in tokeninstances
//
    while (1) { // Loop until the end of the string ('\0') is reached or invalid character

        column = mapingchar(nextChar); // Get column index using mappingchar function
        nextState = Table[state][column];

        // a assurance to break out of the loop if invalid character is used
        if (column == -1){
            break;
        }
        if (nextState < 0) {
            switch (nextState) {
                case -1:
                    printf("can't start with a digit! %s %d\n", S, line_num);
                    return Error ;
                case -2:
                    printf("semicolone Error!!\n %s %d",  S, line_num);
                    return Error;
                case -3:
                    printf("can't have dollar sign start %s %d\n",  S, line_num);
                    return Error;
                case -4 :
                    printf("CAN'T START WITH STAR!! %s %d\n",  S, line_num);
                    return Error;
                case -5 :
                    printf("must be a digit %s %d\n",  S, line_num);
                    return Error;
                case -6 :
                    printf("must be followed by a digit %s %d\n",  S, line_num);
                    return Error;
                default:
                    printf("unknown Error %s %d\n", S, line_num);
                    return unknown;
            }
        }

        if (nextState > 1000) {
            //  Final state reached, return the token
            S[S_index] = '\0'; // Null-terminate the string
            switch (nextState) {
                case 1001:
                    token.tokenId = EOFtk;
                    printf("%s\n", tokenNames[0]);
                    return EOFtk;
                case 1002:
                    token.tokenId = T1_tk;
                    printf("%s - Full String: %s    %d\n\n", tokenNames[1], S, line_num);
                    break;
                case 1003:
                    token.tokenId = T2_tk;
                    printf("%s - Full String: %s    %d\n\n", tokenNames[2], S, line_num);
                    break;
                case 1004:
                    token.tokenId = T3_tk;
                    printf("%s - Full String: %s    %d\n\n", tokenNames[3], S, line_num);
                    break;
                default:
                    token.tokenId = unknown;
                    printf("%s - Full String: %s    %d\n\n", tokenNames[4], S, line_num);
                    return unknown;
            }
            // resetting the states for the nextchar in the string of chars.
            state = 0;
            S_index = 0;
            nextState=0;
            column=0;
            memset(S, '\0', strlen(S)); // Reset the array to null characters

        } else {
            // Not in final state yet
            state = nextState;
            S[S_index++] = nextChar; // Append the character to the string
            nextChar = tokeninstances[index++]; // Read the next character from tokeninstances
        }

    }
    return EOFtk;
}