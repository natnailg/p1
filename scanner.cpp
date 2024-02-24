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


tokenID FADriver(char *token_string) {
    printf("Received token string in FADriver: %s\n", token_string);
    int state = 0;
    int nextState;
    char S[256] = ""; // Assuming maximum token length of 255 characters
    int index = 0;
//    char nextChar = getchar(); // Ensure nextChar is properly initialized

    while (1) { // Check for end of input
        printf("inside of the finction!!!\n");
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
        printf("inside of the while!!!\n");

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

////function for converting large int to tokenType
//tokenID token(int num){
//        switch (num){
//            case 1002:
//                return T1_tk;
//            case 1003:
//                return T2_tk;
//            case 1004:
//                return T3_tk;
//            case 1001:
//                return EOFtk;
//            case -1:
//                return Error;
//            default:
//                return unknown;
//    }
//
//}
//
//// nextchar corresponds to the column of the table
//// state coressponds to the row
//tokenID FADriver(){ //assume nextChar set, and used as column index
//
//    int state = 0; //initial state
//    int nextState;
//    char S[256]=" "; // to append the full string until the token is found
//    int index = 0;
//    while(1){ //not negative and not large value
//        printf("before the nextstate: %d ---> %c ---> %s",state, nextChar, S );
//        nextState = Table[state][nextChar];
////        S[index]='\0';
//        if (nextState < 0) { //negative
//            printf("Error negative number from table, there is something invalid, check again!!\n");
//            return token(nextState);
//        }
//        if (nextState > 1000){ //LARGE VALUE
//             //final state return the type of statnment
////                return (token(nextState), S);
//                  return token(nextState);
//
//    }else{ /*not final state */
//            state = nextState;
//            S[index++] = nextChar;
//            nextChar = getchar();
//        }
//
//    }//end oof while loop
//
//}// end of drive func
//
//
//
//
















//function for converting large int to tokenType
//tokenID token(int num){
//    switch (num){
//        case 1002:
//            return T1_tk;
//        case 1003:
//            return T2_tk;
//        case 1004:
//            return T3_tk;
//        case 1001:
//            return EOFtk;
//        case -1:
//            return Error_digit;
//        case -2:
//            return Error_semicolon;
//        case -3:
//            return Error_dollar_sign;
//        case -4:
//            return Error_star;
//        case -5:
//            return Error_must_be_digit;
//        case -6:
//            return Error_must_be_digits;
//        default:
//            return unknown;
//    }
//
//}
