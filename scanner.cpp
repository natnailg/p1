//
// Created by Admin on 2/14/2024.
//
#include <stdio.h>
#include "scanner.h"

const char* tokenNames[] = {"EOF token","T1 token","T2 token", "T2 token"};

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

//function for converting large int to tokenType
tokenID token(int num){
        switch (num){
            case 1002:
                return T1_tk;
            case 1003:
                return T2_tk;
            case 1004:
                return T3_tk;
            case 1001:
                return EOFtk;
            case -1:
                return Error;
            default:
                return unknown;
    }

}

// nextchar corresponds to the column of the table
// state coressponds to the row
tokenID FADriver(){ //assume nextChar set, and used as column index

    int state = 0; //initial state
    int nextState;
    char S[256]=" "; // to append the full string until the token is found
    int index = 0;
    while(1){ //not negative and not large value
        printf("before the nextstate: %d ---> %c ---> %s",state, nextChar, S );
        nextState = Table[state][nextChar];
//        S[index]='\0';
        if (nextState < 0) { //negative
            printf("Error negative number from table, there is something invalid, check again!!\n");
            return token(nextState);
        }
        if (nextState > 1000){ //LARGE VALUE
             //final state return the type of statnment
//                return (token(nextState), S);
                  return token(nextState);

    }else{ /*not final state */
            state = nextState;
            S[index++] = nextChar;
            nextChar = getchar();
        }

    }//end oof while loop

}// end of drive func




















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
