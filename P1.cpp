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
    char* output; // the file we are gone output to

    //reading from file
    FILE* filepointer; //file pointer
    char filechar;	//get the characters

//if arg is greater than two, meaning more than one file exit
    if(argc > 2){
        printf("Error number of arguments!!\n");
        return EXIT_FAILURE;
    }

    //read from the keyboard
    if(argc == 1) {
        output = "out"; // for the output name/filestream
        fp = fopen(output, "w");

        //check to see if everything is okay with writing to a file
        if(fp == NULL){
            printf("Error opening the file\n");
            return EXIT_FAILURE;
        }
        // put them in a file
        while(ch != EOF){
            fputc(ch, fp);
        }
        fclose(fp); //closed the fp (file pointer for writing)

    }else{
        // read from the files
        output = argv[1];  //file we got from the command line defined uptop
        filepointer = fopen(output,"r");
        if(filepointer == NULL){
            printf("Error opening the file\n");
            return EXIT_FAILURE;
        }

        printf("\ncharacters in the file \n");
        //loop through and print the characters from file
        while((filechar = fgetc(filepointer)) != EOF){
            // ASCII check in the file if there is special character
                printf("%c", filechar);
            }
    }
//
    fclose(fp); //closed the fp (file pointer for writing)
    fclose(filepointer);
    return 0;

}// end of main
