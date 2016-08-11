/*
 Name: Katie Pan
 CSC 352 -- Assignment 6
 Hashtable -wf
 */

#include "hashtable.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//After reading each word, you should remove any punctuation
//and change all letters to lower case before doing any other
//processing.
void modify(char *word)
{
    char *input = word;
    char *retVal = word;
    
    while (*input){
        //punctuation
        if (ispunct(*input)){
            input++;
        }
        //uppercase to lowercase
        else if (isupper(*input)){
            *retVal++ = tolower(*input);
            input++;
        }
        else if (input == retVal){
            input++;
            retVal++;
        }
        else{
            *retVal++ = *input++;
        }
    }
    
    *retVal = 0;
}


//argc = how many arguments are passing in; counts a.out
//argv = element
//main function
int main(int argc, char * argv[]){
    
    //Error: if there is no arguments passed
    if(argc == 1){
        fprintf(stderr, "No file inputted\n");
        exit(1);
    }
    
    //create hashtables with values set to null
    struct LList *array[1000];
    int k = 0;
    for(k = 0; k < 1000; k++){
        array[k] = LList_create();
    }
    
    //output directed into file called "wordfrequency.txt"
    FILE *outputfp;
    outputfp = freopen("wordfrequency.txt", "w", stdout);
    
    if (outputfp == NULL) {
        fprintf(stderr, "Could not open file\n");
        int l = 0;
        for(l = 0; l < 1000; l++){
            LList_destroy(array[l]);
        }
        exit(1);
    }
    
    //opens each files using a for loop
    int i = 1;
    for(i = 1; i < argc; i++){
       
        int s;
        
        FILE *fp = fopen(argv[i], "r");
        
        //error: if could not open file
        if (fp == NULL) {
            fprintf(stderr, "Could not open file\n");
            int l = 0;
            for(l = 0; l < 1000; l++){
                LList_destroy(array[l]);
            }
            exit(1);
        }
        
        //spec: words will be 1024 characters or less
        char word[1025];
        while(fscanf(fp, "%s", word) != EOF){
            
            //modifies word before processing
            modify(word);
            
            //checks if len is 0
            int wordLen = strlen(word);
            if(wordLen == 0){
                continue;
            }
            
            int hashNumber = hash(word, 1000);
            
            //if element already exists
            if(LList_find(array[hashNumber], word) == 1){
                continue;
            }
        
            insert(array[hashNumber], word);
        }
        
        //close file
        s = fclose(fp);
        if (s == EOF) {
            fprintf(stderr, "Did not close properly\n");
            int l = 0;
            for(l = 0; l < 1000; l++){
                LList_destroy(array[l]);
            }
            exit(1);
        }
    }
    
    //print
    int j = 0;
    for(j = 0; j < 1000; j++){
        LList_print(array[j]);
        LList_destroy(array[j]);
    }

    int t;
    t = fclose(outputfp);
    
    if (t == EOF) {
        fprintf(stderr, "Did not close properly\n");
        int l = 0;
        for(l = 0; l < 1000; l++){
            LList_destroy(array[l]);
        }
        exit(1);
    }

    return 0;
}