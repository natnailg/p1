//
// Created by Admin on 2/14/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include "token.h"
#include "scanner.h"

int main(int argc, char* argv[]){

    //reading from keyboard
    FILE *fp; //write to a file, whatever typed from the keyboard.
    char ch;  //reads the characters from the file
    char* Readin; // the file we are gone Readin to

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
        Readin = "out"; // for the Readin name/filestream
        fp = fopen(Readin, "w");
        ch = getchar();
        //check to see if everything is okay with writing to a file
        if(fp == NULL){
            printf("Error opening the file\n");
            return EXIT_FAILURE;
        }
        // put them in a file
        while(ch != EOF){
            fputc(ch, fp);
            ch = getchar();
        }
       fclose(fp); //closed the fp (file pointer for writing)

    }else{
        // read from the files
        Readin = argv[1];  //file we got from the command line
        filepointer = fopen(Readin, "r");
        if(filepointer == NULL){
            printf("Error opening the file\n");
            return EXIT_FAILURE;
        }

        printf("\ncharacters in the file \n");
        //loop through and print the characters from file
        while((filechar = fgetc(filepointer)) != EOF){
                printf("%c", filechar);
            }
        fclose(filepointer);
    }//end of else reading from file.


    struct Token tokens;
    tokens.tokenId = EOFtk;
    //call testScanner()
    token_description(tokens);

//    readFromFile(Readin); // working

    // call on the removecomments function and give it a newly created file
    char* outputfile = "output";
    removcomments(Readin, outputfile);

//    printf("toke description: %s\n", tokenNames[tokens.tokenId]);
    return 0;

}// end of main
