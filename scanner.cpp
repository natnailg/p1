//
// Created by Admin on 2/14/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include "scanner.h"
#include "token.h"

// we need a map function here that is going to read in the char, and it's going to be based on what that char is,
// it's going map it to a number that I decide. > = 0

//FSA table have row and column ordering as specified in class
int table [12][12]= { //had to do 12 for the columns
        {1,-1,3,5,10,-2,8,-3,6,-4,0,1001},
        {-5,2,-5,-5,-5,-5,-5,-5,-5,-5,-5,5},
        {1002,2,1002,1002,1002,1002,1002,1002,1002,1002,1002,1002},
        {-5,4,-6,-6,-6,-6,-6,-6,-6,-6,-6,-6},
        {1003,4,1003,1003,1003,1003,1003,1003,1003,1003,1003,1003},
        {1004,1004,1004,1004,1004,1004,1004,1004,1004,1004,1004,1004},
        {1004,1004,1004,1004,1004,1004,1004,1004,1004,7,1004,1004},
        {1004,1004,1004,1004,1004,1004,1004,1004,1004,1004,1004,1004},
        {1004,1004,1004,1004,1004,1004,1004,9,1004,1004,1004,1004},
        {1004,1004,1004,1004,1004,1004,1004,1004,1004,1004,1004,1004},
        {1004,1004,1004,1004,1004,11,1004,1004,1004,1004,1004,1004},
        {1004,1004,1004,1004,1004,1004,1004,1004,1004,1004,1004,1004}

};
/*-1 => cant start with digit
 * -2 => semicolon error
 * -3 => can't have dollar sign start
 * -4 => can't start with quotation
 * -5 => must be digit
 * -6 => must be digit
 * t1_final = 1002
 * t2_final = 1003
 * t3_final = 1004
 * EOF_tk = 1001
 * */
void printtable() {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            printf("%d  ", table[i][j]);
        }
        printf("\n");
    }
}