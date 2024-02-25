//
// Created by Admin on 2/14/2024.
//
#include <stdio.h>
#include "scanner.h"
char nextChar;

const char* tokenNames[] = {"EOF token",  "T1 token", "T2 token", "T3 token", "Error token","Unknown token",};

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


tokenID FADriver(char* tokeninstances, int line_num) {
    int state = 0;
     Token token;
    int nextState;
    char S[256] = ""; // Assuming maximum token length of 255 characters
    int index = 0; // Index for tokeninstances
    int S_index = 0; // Index for S array

    nextChar = tokeninstances[index++]; // Initialize nextChar with the first character in tokeninstances
//
    while (1) { // Loop until the end of the string ('\0') is reached
        int column = mapingchar(nextChar); // Get column index using mappingchar function
        nextState = Table[state][column];

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
                    printf("must be followed by a digit %s %d\n",  S, line_num);
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
            // Final state reached, return the token
//            S[S_index] = '\0'; // Null-terminate the string
        switch (nextState) {
                case 1001:
                    token.tokenId = EOFtk;
                    printf("%s \n\n", tokenNames[token.tokenId]);
                    return EOFtk;
//                case 1002:
//                    token.tokenId = T1_tk;
//                    printf("%s - Full String: %s  %d\n\n",  tokenNames[1] ,S, line_num );
//                    break;
//                case 1003:
//                    token.tokenId = T2_tk;
//                    printf("%s - Full String: %s %d\n\n",token, S, line_num);
//                    break;
//                case 1004:
//                    token.tokenId = T3_tk;
//                    printf("%s - Full String: %s  %d\n\n",token, S, line_num);
//                    break;
//                default:
//                    token.tokenId = unknown;
//                    printf("%s - Full String: %s %d\n\n", token, S,line_num);
//                    return unknown;
//            }
            case 1002:
                token.tokenId = T1_tk;
                printf("Token ID: %d -> %s --->\n", token.tokenId, token); // Debugging print
                printf("%s - Full String: %s    %d\n\n", tokenNames[token.tokenId], S, line_num);
                printf("%s %s %s- Full String: %s    %d\n\n", tokenNames[token.tokenId],token, token.tokenId,S, line_num);

                break;
            case 1003:
                token.tokenId = T2_tk;
                printf("Token ID: %d\n", token.tokenId); // Debugging print
                printf("%s - Full String: %s    %d\n\n", tokenNames[token.tokenId], S, line_num);
                printf("%s %s %s- Full String: %s    %d\n\n", tokenNames[token.tokenId],token, token.tokenId,S, line_num);

                break;
            case 1004:
                printf("Token ID: %d\n", token.tokenId); // Debugging print
                token.tokenId = T3_tk;
                printf("%s - Full String: %s    %d\n\n", tokenNames[token.tokenId], S, line_num);
                printf("%s %s %s- Full String: %s    %d\n\n", tokenNames[token.tokenId],token, token.tokenId,S, line_num);

                break;
            default:
                token.tokenId = unknown;
                printf("%s %s %s- Full String: %s    %d\n\n", tokenNames[token.tokenId],token, token.tokenId,S, line_num);
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
//        return   printf("End of the string!! %s \n\n", tokenNames[1]);
}


