/*
 Name: Katie Pan
 CSC 352 -- Assignment 4
 Singly Linked List-- Driver Program
 */

#include "llist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//program will accept one character commands from the user and perform operations
int pickChoice(struct LList *list){
    char input;
    int xInput, findInt, removeInt, s, r, t;
    
    
    while(scanf("\n%c", &input) != EOF){
        //switch statement to pick choice
        switch(input) {
                
            case 'C' :
            case 'c' :
                //destroy the current linked list
                //create newlist
                //runs pickChoice again aka DOESNOTEXIT
                LList_destroy(list);
                struct LList *newlist;
                newlist = LList_create();
                
                pickChoice(newlist);
                break;
                
            case 'A' :
            case 'a' :
                //add an integer to the beginning of the list
                //check if EOF error, if so, stderr a message
                if((s = scanf("%d", &xInput)) == EOF){
                    fprintf(stderr, "No integer input\n");
                    exit(1);
                }
                
                //checks if the next number is an integer
                if(s == 0){
                    fprintf(stderr, "Wrong input, needs to be an integer\n");
                    exit(1);
                }
                    
                
                struct LList_data newLList_addData;
                newLList_addData.x = xInput;
                newLList_addData.y = 0;
                
                LList_push_front(list, newLList_addData);
                break;
                
            case 'F' :
            case 'f' :
                //find the first instance of an integer
                //check if EOF error, if so, stderr a message
                if((r = scanf("%d", &findInt)) == EOF){
                    fprintf(stderr, "No integer input\n");
                    exit(1);
                }
                
                //checks if the next number is an integer
                if(r == 0){
                    fprintf(stderr, "Wrong input, needs to be an integer\n");
                    exit(1);
                }
                
                //declare new struct w. memory error checks
                struct LList_data *newLList_finddata = NULL;
                
                newLList_finddata = (struct LList_data *)malloc(sizeof(struct LList_data));
                if (!newLList_finddata){
                    fprintf(stderr,"Not enough memory\n");
                    exit(1);
                }
                
                newLList_finddata->y = -1;
                
                LList_find(list, findInt, newLList_finddata);
                
                //if found, print
                if(newLList_finddata->y != -1){
                    fprintf(stdout, "%d, %d\n", newLList_finddata->x, newLList_finddata->y);
                }
                
                free(newLList_finddata);
                
                break;
                
            case 'R' :
            case 'r' :
                //remove the first instance of an integer
                //check if EOF error, if so, stderr a message
                if((t = scanf("%d", &removeInt)) == EOF){
                    fprintf(stderr, "No integer input\n");
                    exit(1);
                }
                
                //checks if the next number is an integer
                if(t == 0){
                    fprintf(stderr, "Wrong input, needs to be an integer\n");
                    exit(1);
                }
                
                //declare new struct w. memory error checks
                struct LList_data *LList_removeData = NULL;
                LList_removeData = (struct LList_data*)malloc(sizeof(struct LList_data));
                if(!LList_removeData){
                    fprintf(stderr,"Not enough memory\n");
                    exit(1);
                }
                
                LList_removeData->y = -1;
                
                LList_remove(list, removeInt, LList_removeData);
               
                //if found, print
                if(LList_removeData->y != -1){
                    fprintf(stdout, "%d, %d\n", LList_removeData->x, LList_removeData->y);
                }
                
                free(LList_removeData);
                
                break;
                
            case 'P' :
            case 'p' :
                //print list
                LList_print(list);
                break;
                
            default:
                //error
                fprintf(stderr, "Wrong input\n");
                LList_destroy(list);
                exit(0);
        }
    }

    
    return 0;
    
}

//main method
int main(){
    
    //create the stack and check for memory errors
    struct LList *llist;
    llist = LList_create();
    if(!llist){
        fprintf(stderr, "Out of memory\n");
        return EXIT_FAILURE;
    }
    
    pickChoice(llist);
    LList_destroy(llist);
    return 0;
}



