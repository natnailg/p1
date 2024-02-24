//
// Created by Admin on 2/14/2024.
//
#include <stdio.h>
#include "scanner.h"


const char* tokenNames[] = {"Unknown token", "EOF token", "T1 token", "T2 token", "T3 token"};
void token_description(struct Token tokens){
    printf("Token description: %s\n", tokenNames[tokens.tokenId]);
}

//FSA Table have row and column ordering as specified in class
int Table [12][12]= { //had to do 12 for the columns
        {1,-1,3,5,10,-1,8,-1,6,-1,0,1001},
        {-1,2,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {1002,2,1002,1002,1002,1002,1002,1002,1002,1002,1002,1002},
        {-1,4,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {1003,4,1003,1003,1003,1003,1003,1003,1003,1003,1003,1003},
        {1004,1004,1004,1004,1004,1004,1004,1004,1004,1004,1004,1004},
        {1004,1004,1004,1004,1004,1004,1004,1004,1004,7,1004,1004},
        {1004,1004,1004,1004,1004,1004,1004,1004,1004,1004,1004,1004},
        {1004,1004,1004,1004,1004,1004,1004,9,1004,1004,1004,1004},
        {1004,1004,1004,1004,1004,1004,1004,1004,1004,1004,1004,1004},
        {1004,1004,1004,1004,1004,11,1004,1004,1004,1004,1004,1004},
        {1004,1004,1004,1004,1004,1004,1004,1004,1004,1004,1004,1004}
};
//

int mapingchar(char c) {
    switch ((int)c) {
        case 'a' ... 'z': // lowercase letters 'a-z'
        case 'A' ... 'Z': // uppercase letters 'A-Z'
            return LETTER; // LETTER
        case '0' ... '9': // digits '0' to '9'
            return DIGIT; // DIGIT
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
        case '*': // Asterisk '*'
            return STAR; // STAR
        case '"': // Double quote '"'
            return QUOTATION; // QUOTATION
        case ' ': // White space (space)
        case '\n': // Newline character
            return WHITESPACE; // WHITESPACE
        case '\0': // EOF encountered
            return END_OF_FILE; // END_OF_FILE
        default:
            return -1; // Unknown character
    }
}

tokenID token(int num, const char* fullString) {
    printf("token function called\n");
    switch (num) {
        case 1001:
            printf("is ever char coming here !!= %c", fullString)
            printf("Token: %s - Full String: %s\n", tokenNames[1], fullString);
            return EOFtk;
        case 1002:
            printf("Token: %s - Full String: %s\n", tokenNames[2], fullString);
            return T1_tk;
        case 1003:
            printf("Token: %s - Full String: %s\n", tokenNames[3], fullString);
            return T2_tk;
        case 1004:
            printf("i am in token 3\n");
            printf("Token: %s - Full String: %s\n", tokenNames[4], fullString);
            return T3_tk;
        case -1:
            printf("Token: %s - Full String: %s\n", tokenNames[0], fullString);
            return Error;
        default:
            printf("Token: %s - Full String: %s\n", tokenNames[0], fullString);
            return unknown;
    }
}


tokenID FADriver(char ch) {
    printf("Received token string in FADriver: %c\n", ch);
    int state = 0;
    int nextState;
    char S[256] = ""; // Assuming maximum token length of 255 characters
    int index = 0;
//    char nextChar = getchar(); // Ensure nextChar is properly initialized
    while (1) { // Check for end of input
        int column = mapingchar(nextChar); // Get column index using mappingchar function
        if (column == -1) {
            printf("Error: Unknown character.\n");
            return Error; // Return an error token
        }

        nextState = Table[state][column];
        if (nextState < 0) {
            printf("Error: Negative number from table, something is invalid.\n");
            return Error; // Return an error token
        }
        if (nextState > 1000) {
            printf("large int found!!\n");
            // Final state reached, return the token
            S[index] = '\0'; // Null-terminate the string


            printf("before the nextstate: %d ---> %d ---char->%c ---> %s\n", state, column, nextChar, S);
            return token(nextState, S); // Return the token obtained from the token function along with the full string


        } else {
            // Not in final state yet
            state = nextState;
            S[index++] = nextChar; // Append the character to the string
            nextChar = getchar();
        }
    }
}



