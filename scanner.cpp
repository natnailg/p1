//
// Created by Admin on 2/14/2024.
//
#include <stdio.h>
#include "scanner.h"

const char* tokenNames[] = {"EOF token","T1 token","T2 token", "T2 token"};

void token_description(struct Token tokens){
    printf("Token description: %s\n", tokenNames[tokens.tokenId]);
}
