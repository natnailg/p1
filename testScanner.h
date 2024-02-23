//
// Created by Admin on 2/14/2024.
//

#ifndef P1_TESTSCANNER_H
#define P1_TESTSCANNER_H

void printtable();
//states
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

//#define LETTER          0
//#define DIGIT           1
//#define PERCENTAGE      2
//#define DOT_OR_EXCLAMATION  3
//#define COMMA           4
//#define SEMICOLON       5
//#define QUESTION_MARK   6
//#define DOLLAR_SIGN     7
//#define STAR            8
//#define QUOTATION       9
//#define WHITESPACE      10
//#define END_OF_FILE     11

void scanners();
int mapingchar(char );
void readFromFile(char* file);
#endif //P1_TESTSCANNER_H
