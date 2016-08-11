
/*
 Katie Pan
 CSC 352 -- Lee Savoie
 Assignment 3b: Text Editor
 */

#include <stdio.h>
#include <string.h>

void exit(int status);
int mainMenu(char *sentence, int len);


/*If the user enters '-', your program should go into delete mode. The user
 will enter another character, and your program will delete the first instance 
 of that character in the provided string.*/
int delete(char *sentence, int len){
    int index = -1;
    
    char deleteChar;
    
    /*character to delete*/
    scanf("\n%c", &deleteChar);
    fflush(stdin);
    
    /*find index of first instance*/
    int i = 0;
    while(*(sentence+i) != '\0' && index == -1){
        if(*(sentence+i) == deleteChar){
            index = i;
            break;
        }
        else{
            i++;
        }
    }
    
    /*found in array/string */
    if(index != -1){
        char modSentence[len-1];
        /*update new array/string*/
        int j = 0;
        for(j = 0; j < index; j++){
            modSentence[j] = *(sentence+j);
            printf("%c", modSentence[j]);
        }
        
        int k;
        for(k = index; k < len-2; k++){
            modSentence[k] = *(sentence+k+1);
            printf("%c", modSentence[k]);
        }
        
        modSentence[len-2] = '\n';
        modSentence[len-1] = '\0';
        len--;
        
        printf("\n");
        mainMenu(modSentence, len);
    }
    
    /*not found in array/string */
    else{
        printf("%s", sentence);
        mainMenu(sentence, len);
    }
    
    
    return 0;
}

/*If the user enters '~', your program should go into replace mode.
 The user will enter two more characters, and your program will replace
 the first instance of the first character in the string with the second
 character.*/
char replace(char *sentence, int len){
    char replacedChar, newChar, modSentence[len];
    
    /*will replace THIS character...*/
    scanf("\n%c", &replacedChar);
    
    /*with this NEW character*/
    scanf("\n%c", &newChar);
    
    /*find index of first instance*/
    int index = -1;
    int i = 0;
    while(*(sentence+i) != '\0' && index == -1){
        if(*(sentence+i) == replacedChar){
            index = i;
        }
        else{
            i++;
        }
    }
    
    /*update new array/string*/
    int j = 0;
    for(j = 0; j < len-1; j++){
        if(j == index){
            modSentence[j] = newChar;
        }
        else{
            modSentence[j] = *(sentence+j);
        }
        printf("%c", modSentence[j]);
    }
    
    
    printf("\n");
    mainMenu(modSentence, len);
    return 0;
}

/*If the user enters '^', your program will reverse the string. It is
 acceptable to look online for a string reversal algorithm, but if you
 do so, you should note clearly in your code where the algorithm comes from.
 
 algorithm was taken from in-class coding example
 (example 2: string reversal using pointers)*/
int reverse(char *sentence, int len){
    
    char modSentence[len];

    int i, j;
    
    j = len-2;
    
    /*flips string and prints it out*/
    for(i = 0; i < len-1; i++){
        modSentence[i] = *(sentence+j);
        printf("%c", modSentence[i]);
        j--;
    }
    
    /*last element is new line, so added in*/
    modSentence[len-1] = '\n';
    
    printf("\n");
    mainMenu(modSentence, len);
    return 0;
}


/* mainMenu that takes in the sentence array/pointer and the current len (length)*/
int mainMenu(char *sentence, int len){
    
    /*input char that the user wants*/
    char inputChar;
    
    scanf("\n%c", &inputChar);
    
    fflush(stdin);
    
    
    /*delete*/
    if(inputChar == '-'){
        delete(sentence, len);
    }
    
    /*replace*/
    else if(inputChar == '~'){
        replace(sentence, len);
        
    }
    
    /*reverse*/
    else if(inputChar == '^'){
        reverse(sentence, len);
        
    }
    
    else if(inputChar == 'q'){
        exit(0);
    }
    
    /*errors*/
    else{
        fprintf(stderr, "Invalid input\n");
        exit(0);
    }
    
    return 0;
}


int main(){
    
    char sentence[100], inputChar;
    
    /*
     scan new string followed by new line
     It is guaranteed that the input string will 100 characters or less
     note: fgets will read a string until it reaches a new line
     */
    fgets(sentence, 101, stdin);
    
    /*input char that the user wants*/
    scanf("\n%c", &inputChar);
    
    int len = strlen(sentence);
    
    fflush(stdin);
    fflush(stdout);
    
    /*delete*/
    if(inputChar == '-'){
        delete(sentence, len);
    }
    
    /*replace*/
    else if(inputChar == '~'){
        
        replace(sentence, len);
        
    }
    
    /*reverse*/
    else if(inputChar == '^'){
        reverse(sentence, len);
        
    }
    
    /*If the user enters 'q', your program will exit.*/
    else if(inputChar == 'q'){
        exit(0);
    }
    
    /*errors*/
    else{
        fprintf(stderr, "Invalid input\n");
        exit(0);
    }
    
    return 0;
    
}