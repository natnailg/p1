//
// Created by Admin on 2/14/2024.
//

#ifndef P1_TOKEN_H
#define P1_TOKEN_H

#include "Scanner.h"
#include "testScanner.h"

const int MAX_INSTANCE_TOKEN = 250;


//defining token id's using enum
typedef enum{
    EOFtk,  // end of file
    T1_tk,  // beings (a-z, A-Z) followed by one or more digits
    T2_tk,  // beings with % and must have one or more digits
    T3_tk  // . ! , ,; ? ?$ * 8'
}tokenID;
//string tokenNames[] = {"T1 token", "T1 token", "T1 token"};
extern const char* tokenNames[];

// for each token we are going to need the TokenID, TokenInstance, line#
struct Token{
    tokenID tokenId;
    char tokeninstance[MAX_INSTANCE_TOKEN];  // store them in an array
    int line_num;
};

#endif
