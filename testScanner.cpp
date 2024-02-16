//
// Created by Admin on 2/14/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include "testScanner.h"
//#include "token.h"
//
void hellotestscanner(struct Token mytokens, const char* tokenNames[]){
    printf("Token EOF: %s-----%s\n",mytokens.tokenId, tokenNames[mytokens.tokenId]);
}
