//
// Created by Admin on 2/14/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include "testScanner.h"



void token_description(struct Token tokens){
    printf("Token description: %s\n", tokenNames[tokens.tokenId]);
}
