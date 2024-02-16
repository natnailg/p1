//
// Created by Admin on 2/14/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include "testScanner.h"

//

void hellotestscanner(struct Token mytokens, const char* okenNames[]){
    printf("Token EOF: %c-----%c\n",mytokens.tokenId, okenNames[mytokens.tokenId]);
}
