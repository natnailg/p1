//
// Created by Admin on 2/14/2024.
//

#ifndef P1_TOKEN_H
#define P1_TOKEN_H

#include "testScanner.h"
#include "scanner.h"


//defining token id's using enum
typedef enum{
    EOFtk = 1001,  // end of file
    T1_tk = 1002,  // beings (a-z, A-Z) followed by one or more digits
    T2_tk = 1003,  // beings with % and must have one or more digits
    T3_tk = 1004  // . ! , ,; ? ?$ * 8'
}tokenID;

const int MAX_INSTANCE_TOKEN = 250;
// for each token we are going to need the TokenID, TokenInstance, line#
struct Token{
    tokenID tokenId;
    char tokeninstance[MAX_INSTANCE_TOKEN];  // store them in an array
    int line_num;
}Token;
#endif
