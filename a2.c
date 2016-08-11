/*
 Katie Pan
 Assignment 2
 The goal of this assignment is to demonstrate basic C programming skills.
 */


#include <stdio.h>

int mainMenu();
void exit(int status);

/*prints stars*/
int starPrinter(int number){
    /*variables declaration*/
    int i;
    
    /*print stars*/
    for(i = 0; i < number; i++){
        printf("%c", '*');
        
    }
    return 0;
}

/*prints spaces for parallelogram in shapePrinter*/
int spacePrinter(int number){
    /*variables declaration*/
    int i;
    
    /*print spaces*/
    for(i = 0; i < number; i++){
        printf("%c", ' ');
    }
    return 0;
}

/*This option will allow the user to print a shape in asterisks*/
int shapePrinter(){
    /*variables declaration*/
    char firstChar;
    int firstNum, secondNum, i1, i2, i3, i4;
    
    /*scan*/
    scanf("%s %d", &firstChar, &firstNum);
    
    /*square*/
    if(firstChar == 's'){
        if(firstNum > 0){
            for(i1 = 0; i1 < firstNum; i1++){
                starPrinter(firstNum);
                printf("\n");
            }
        }
        else{
            fprintf(stderr, "Invalid input");
        }
        
    }
    
    /*triangle*/
    else if(firstChar == 't'){
        if(firstNum > 0){
            for(i2 = 1; i2 <= firstNum; i2++){
                starPrinter(i2);
                printf("\n");
            }
        }
        else{
            fprintf(stderr, "Invalid input");
            printf("\n");
        }
    }
    
    /*rectangle*/
    else if(firstChar == 'r'){
        scanf("%d", &secondNum);
        if(firstNum > 0 && secondNum > 0){
            for(i3 = 0; i3 < firstNum; i3++){
                starPrinter(secondNum);
                printf("\n");
            }
        }
        else{
            fprintf(stderr, "Invalid input");
            printf("\n");
        }
    }
    
    /*parallelogram*/
    else if(firstChar == 'p' && firstNum > 0){
        scanf("%d", &secondNum);
        if(secondNum > 0){
            for(i4 = 0; i4 < firstNum; i4++){
                spacePrinter(i4);
                starPrinter(secondNum);
                printf("\n");
            }
        }
        
        else{
            fprintf(stderr, "Invalid input");
            mainMenu();
        }
    }
    
    /*error message*/
    else{
        
        fprintf(stderr, "Invalid input");
        printf("\n");
    }
    
    mainMenu();
    return 0;
}

/*For this option, the user will enter a char and the program will print the entire alphabet or number set, in continuous order until you would return to the specified char. */
int circularChars(){
    /*variables declaration*/
    char input;
    int i1, i2, i3, i4, i5, i6;
    
    /*first letter is scanner and printed*/
    scanf("%c",&input);
    scanf("%c", &input);
    
    /*input 0-9 numbers*/
    if(input >= '0' && input <= '9'){
        for(i1 = input; i1 <= '9'; ++i1){
            printf("%c", i1);
        }
        for(i2 = '0'; i2 < input; ++i2){
            printf("%c", i2);
        }
    }
    
    /*input is A-Z*/
    else if(input >= 'A' && input <= 'Z'){
        for(i3 = input; i3 <= 'Z'; ++i3){
            printf("%c", i3);
        }
        for(i4 = 'A'; i4 < input; ++i4){
            printf("%c", i4);
        }
    }
    
    /*input is a-z*/
    else if(input >= 'a' && input <= 'z'){
        for(i5 = input; i5 <= 'z'; ++i5){
            printf("%c", i5);
        }
        for(i6 = 'a'; i6 < input; ++i6){
            printf("%c", i6);
        }
    }
    
    /*error message*/
    else{
        fprintf(stderr, "Invalid input\n");
        mainMenu();
    }
    
    printf("\n");
    mainMenu();
    return 0;
}

/*factors helper method*/
int findFactors(int number){
    /*variables declaration*/
    int i1;
    
    /*count how many factors in number*/
    int count = 0;
    
    for(i1 = 1; i1 <= number; i1++){
        if (number % i1 == 0){
            count++;
        }
    }
    
    return count;
}

/*For this option, the user will enter two numbers and your program should print all numbers between the two numbers that have exactly two distinct factors.*/
int factors(){
    /*variables declaration*/
    int input1, input2, i1;
    
    /*scan*/
    scanf("%d %d", &input1, &input2);
    
    /*input1 and input 2 MUST be positive and input2 > input1*/
    if(input1 > 0 && input2 > 0 && input2 > input1){
        for(i1 = input1; i1 <= input2; i1++){
            if(findFactors(i1) == 4){
                printf("%d\n", i1);
            }
        }
    }
    
    /*error message*/
    else{
        fprintf(stderr, "Invalid input\n");
    }
    
    mainMenu();
    return 0;
}


/*When the program starts, it should display the following menu to the user:*/
int mainMenu(){
    /*variables declaration*/
    int intInput;
    
    /*When the program starts, this menu displays*/
    printf("1. Shape Printer\n");
    printf("2. Circular Chars\n");
    printf("3. Factors\n");
    printf("4. Exit\n");
    printf("What would you like to do? \n");
    
    scanf("%d", &intInput);
    fflush(stdin);
    
    /*if/else statement to see which program to run*/
    if(intInput == 1){
        shapePrinter();
    }
    
    /*no input exception*/
    else if(intInput == 0){
        exit(0);
    }
    
    else if(intInput == 2){
        circularChars();
    }
    else if(intInput == 3){
        factors();
    }
    else if(intInput == 4){
        exit(0);
    }
    
    /*error message*/
    else{
        mainMenu();
        fprintf(stderr, "Invalid input");
    }
    
    
    return 0;
}

/*main function*/
int main(){
    
    mainMenu();
    return 0;
}