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
    EOFtk= 1001,  // end of file
    T1_tk = 1002,  // beings (a-z, A-Z) followed by one or more digits
    T2_tk = 1003,  // beings with % and must have one or more digits
    T3_tk = 1004, // . ! , ,; ? ?$ * 8'
    Error = -1, // for any state that is less than 0
    unknown = 0
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
