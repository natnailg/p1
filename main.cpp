//
// Created by Admin on 2/14/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include "token.h"

int main(int argc, char* argv[]){

    //reading from keyboard
    FILE *fp; //write to a file, whatever typed from the keyboard.
    char ch;  //reads the characters from the file
    char* Readin; // the file we are gone Read in to

    //reading from file
    FILE* filepointer; //file pointer

    //if arg is greater than two, meaning more than one file exit
    if(argc > 2){
        printf("Error number of arguments!!\n");
        return EXIT_FAILURE;
    }

    //read from the keyboard and put it in to a file.
    if(argc == 1) {
        Readin = "out";
        fp = fopen(Readin, "w");
        ch = getchar();

        //check to see if everything is okay with writing to a file
        if(fp == NULL){
            printf("Error opening the file\n");
            return EXIT_FAILURE;
        }

        // put all the chars in to a file
        while(ch != EOF){
            fputc(ch, fp);
            ch = getchar();
        }
        fclose(fp); //closed the fp (file pointer for writing)

    }else{
        // read from the file
        Readin = argv[1];  //file we got from the command line
        filepointer = fopen(Readin, "r");

        if(filepointer == NULL){
            printf("Error opening the file\n");
            return EXIT_FAILURE;
        }

        fclose(filepointer);
    }//end of else reading from file.


    // call the filter function in testscanner and sending it a file to write the filtered version to.
    char* outputfile = "output";
    testScanner(Readin, outputfile);

    //remove(outputfile); // removing the file created that is filtered.
    return 0;

}// end of main