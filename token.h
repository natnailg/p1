//
// Created by Admin on 2/14/2024.
//

#ifndef P1_TOKEN_H
#define P1_TOKEN_H

#include "scanner.h"
#include "testScanner.h"

const int MAX_INSTANCE_TOKEN = 250;


//defining token id's using enum
typedef enum{
    EOFtk,  // end of file
    T1_tk,  // beings (a-z, A-Z) followed by one or more digits
    T2_tk,  // beings with % and must have one or more digits
    T3_tk, // . ! , ,; ? ?$ * 8'
    Error, // for any state that is less than 0
//    Error_digit, //can't start with digit -1
//    Error_semicolon, //semicolon error -2
//    Error_dollar_sign, //can't have dollar sign at the start -3
//    Error_star, //can't start with * -4
//    Error_must_be_digit, // must be digit -5
//    Error_must_be_digits,  // another must be digit error -6
    unknown
}tokenID;
extern const char* tokenNames[];
//const char* tokenNames[] = {"EOF token","T1 token","T2 token", "T2 token"};

// for each token we are going to need the TokenID, TokenInstance, line#
struct Token{
    tokenID tokenId;   // to say what type of id
    char tokeninstance[MAX_INSTANCE_TOKEN];  // store them in an array
    int line_num; // for the line number
};


#endif
//string tokenNames[] = {"T1 token", "T1 token", "T1 token"};
