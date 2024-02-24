//
// Created by Admin on 2/14/2024.
//

#ifndef P1_SCANNER_H
#define P1_SCANNER_H

#include "token.h"
// Forward declaration of tokenID
//char nextChar; // my global nextchar

//columns chars
const int LETTER = 0;
const int DIGIT = 1;
const int PERCENTAGE = 2;
const int DOT_OR_EXCLAMATION  = 3;
const int COMMA = 4;
const int SEMICOLON = 5;
const int QUESTION_MARK = 6;
const int DOLLAR_SIGN = 7;
const int STAR = 8;
const int QUOTATION = 9;
const int WHITESPACE = 10;
const int END_OF_FILE = 11;

int mapingchar(char ); //mapping switch statement
tokenID token(int , const char* );
tokenID FADriver(char *);
void token_description(struct Token);
//tokenID FADriver();

#endif
