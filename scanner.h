//
// Created by Admin on 2/14/2024.
//

#ifndef P1_SCANNER_H
#define P1_SCANNER_H

void printtable();
//states
#define LETTER          0
#define DIGIT           1
#define PERCENTAGE      2
#define DOT_OR_EXCLAMATION  3
#define COMMA           4
#define SEMICOLON       5
#define QUESTION_MARK   6
#define DOLLAR_SIGN     7
#define STAR            8
#define QUOTATION       9
#define WHITESPACE      10
#define END_OF_FILE     11

void scanners();
int mapingchar(char );
void readFromFile(char* file);
#endif //P1_SCANNER_H
