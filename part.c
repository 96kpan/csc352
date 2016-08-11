/*
 Katie Pan
 CSC 352 -- Lee Savoie
 Assignment 3a: String Partitions
 */

#include <stdio.h>
#include <string.h>

int stringPartitions(int index, char* sentence);
void exit(int status);

/*main method*/
int main(){
    
    char sentence[101], inputChar;
    int i;
    
    /*
     scan new string followed by new line
     It is guaranteed that the input string will 100 characters or less
     note: fgets will read a string until it reaches a new line
     */
    
    /*error: no input string*/
    fgets(sentence, 101, stdin);
    int len =strlen(sentence);
    
    if(len == EOF){
        fprintf(stderr, "No input\n");
        exit(0);
    }
    
    
    /*character that the user wants to partition the string*/
    /*error: no input char*/
    if(scanf("\n%c", &inputChar) == EOF){
        fprintf(stderr, "No input\n");
        exit(0);
    }
    
    
    
    /*finds desired char in string and runs stringPartitions method*/
    for(i = 0; i < len; i++){
        
        /*hits specified char/index*/
        if(sentence[i] == inputChar){
            stringPartitions(i, sentence);
        }
    }

    return 0;
    
}

/*stringPartitions method that prints out the string*/
int stringPartitions(int index, char* sentence){
    int i1;
    
    /*prints first opening bracket*/
    printf("[");
    
    /*prints chars from the beginning to certain index*/
    for(i1 = 0; i1 < index; i1++){
        printf("%c", *(sentence+i1));
    }
    
    /*prints first closing bracket*/
    printf("],");
    
    /*prints first opening bracket*/
    printf("[");
    
    /*prints chars from index to the end*/
    int i2 = index;
    while(*(sentence+i2) != '\n' && *(sentence+i2) != '\0'){
        printf("%c", *(sentence+i2));
        i2++;
    }
    
    /*prints second closing bracket with new line*/
    printf("]\n");
    
    return 0;
}