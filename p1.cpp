//
// Created by Admin on 2/14/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include "token.h"

int main(int argc, char* argv[]){

    printf("hello from main\n");

    void function1call = scanners();
    void function2call = hellotestscanner();

    printf("function 1 call: ", function1call);
    printf("function 2 call: ", function2call);


}
