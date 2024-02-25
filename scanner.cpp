//
// Created by Admin on 2/14/2024.
//
#include <stdio.h>
#include "scanner.h"


const char* tokenNames[] = {"Unknown token", "EOF token", "T1 token", "T2 token", "T3 token"};

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


tokenID FADriver(char* tokeninstances) {
    int state = 0;
    int nextState;
    char S[256] = ""; // Assuming maximum token length of 255 characters
    int index = 0; // Index for tokeninstances
    int S_index = 0; // Index for S array

    char nextChar = tokeninstances[index++]; // Initialize nextChar with the first character in tokeninstances

    while (1) { // Loop until the end of the string ('\0') is reached
        int column = mapingchar(nextChar); // Get column index using mappingchar function
        nextState = Table[state][column];

        if (nextState < 0) {
            switch (nextState) {
                case -1:
                    printf("can't start with a digit! %s\n", S);
                    return Error ;
                case -2:
                    printf("semicolone Error!!\n %s", S);
                    return Error;
                case -3:
                    printf("can't have dollar sign start %s \n", S);
                    return Error;
                case -4 :
                    printf("CAN'T START WITH STAR!! %s\n", S);
                    return Error;
                case -5 :
                    printf("must be followed by a digit %s\n", S);
                    return Error;
                case -6 :
                    printf("must be followed by a digit %s\n", S);
                    return Error;
                default:
                    printf("unknown Error %s\n",S);
                    return unknown;
            }
        }

        if (nextState > 1000) {
            // Final state reached, return the token
            S[S_index] = '\0'; // Null-terminate the string
            switch (nextState) {
                case 1001:
                    printf("%s \n\n", tokenNames[1]);
                    return EOFtk;
                case 1002:
                    printf("Token: %s - Full String: %s\n\n", tokenNames[2], S);
                    break;
                case 1003:
                    printf("Token: %s - Full String: %s\n\n", tokenNames[3], S);
                    break;
                case 1004:
                    printf("Token: %s - Full String: %s\n\n", tokenNames[4], S);
                    break;
                default:
                    printf("Token: %s - Full String: %s\n\n", tokenNames[0], S);
                    return unknown;
            }
            state = 0; // Reset the state to zero
            S_index = 0; // Reset the index for S array

            //reset the array
            for (int i = 0; i < 256; i++) {
                S[i] = '\0';
            }
            S[0] = nextChar; // Append the character to the string
            // nextChar = tokeninstances[index++]; // Read the next character from tokeninstances

            column = mapingchar(nextChar); // Get column index using mappingchar function
            nextState = Table[state][column];
            // printf("%sinside the switch------------------next state %d----------------%c, column %d\n", S, nextState, nextChar, column);


        } else {
            // Not in final state yet
            state = nextState;
            S[S_index++] = nextChar; // Append the character to the string
            nextChar = tokeninstances[index++]; // Read the next character from tokeninstances
        }
    }
}




//
//tokenID FADriver(char* tokeninstances) {
//    printf("%c", nextChar);
//   printf("Received token string in FADriver: %s\n", tokeninstances);
//    int state = 0;
//    int nextState;
//    char S[256] = ""; // Assuming maximum token length of 255 characters
//    int index = 0;
//
//    while (1) { // Check for end of input
//        int column = mapingchar(nextChar); // Get column index using mappingchar function
//        if (column == -1) {
//            printf("Error: Unknown character.\n");
//            return Error; // Return an error token
//        }
//
//        nextState = Table[state][column];
//        if (nextState < 0) {
//            printf("Error: Negative number from table, something is invalid.\n");
//            return Error; // Return an error token
//        }
//        if (nextState > 1000) {
//            printf("large int found!!\n");
//            // Final state reached, return the token
//            S[index] = '\0'; // Null-terminate the string
//
//
//            printf("before the nextstate: %d ---> %d ---char->%c ---> %s\n", state, column, nextChar, S);
//            return token(nextState, S); // Return the token obtained from the token function along with the full string
//
//
//        } else {
//            // Not in final state yet
//            state = nextState;
//            S[index++] = nextChar; // Append the character to the string
//            nextChar = getchar();
//        }
//    }
//}
//


//tokenID token(int num, char* fullString) {
//    printf("token function called --> %c\n", fullString);
//    switch (num) {
//        case 1001:
//            printf("is ever char coming here !!= %c", fullString);
//            printf("Token: %s - Full String: %s\n", tokenNames[1], fullString);
//            break;
//        case 1002:
//            printf("Token: %s - Full String: %s\n", tokenNames[2], fullString);
//            break;
//        case 1003:
//            printf("Token: %s - Full String: %s\n", tokenNames[3], fullString);
//            break;
//        case 1004:
//            printf("i am in token 3\n");
//            printf("Token: %s - Full String: %s\n", tokenNames[4], fullString);
//            break;
//        case -1:
//            printf("Token: %s - Full String: %s\n", tokenNames[0], fullString);
//            return Error;
//        default:
//            printf("Token: %s - Full String: %s\n", tokenNames[0], fullString);
//            return unknown;
//    }
//    return unknown;
//}
