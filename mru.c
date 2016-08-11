/*
 Name: Katie Pan
 CSC 352 -- Assignment 4
 Singly Linked List-- MRU (Most Recently Used)
 */

#include "llist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void exit(int status);

//mru method that takes in a pointer LList
int mru(struct LList *list){
    int input, s;

    //scans in int input values
    while((s = scanf("\n%d", &input)) != EOF){
        
        //error: if input is not valid (ex: letters, symbols)
        if(s == 0){
            fprintf(stderr, "Input is not valid\n");
            exit(0);
        }
        
        //declare new struct w. error checks for memory
        struct LList_data *newLList_finddata = NULL;
        newLList_finddata = (struct LList_data *)malloc(sizeof(struct LList_data));
        if (!newLList_finddata){
            fprintf(stderr,"Not enough memory\n");
            exit(1);
        }
        
        //used to find specific element. if found, output is 1; if not found, output is 0
        int r = LList_find(list, input, newLList_finddata);
        
        struct LList_data newLList_addData;
        newLList_addData.x = input;
        
        //if x does exist
        //declare new struct and push it in front (void LList_push_front(struct LList * list, struct LList_data data))
        //remove old node (int LList_remove(struct LList * list, int x, struct LList_data * data))
        if(r == 1){
            
            newLList_addData.y = newLList_finddata->y;
            
            struct LList_data *removeData = NULL;
            removeData = (struct LList_data *)malloc(sizeof(struct LList_data));
            if (!removeData){
                fprintf(stderr,"Not enough memory\n");
                exit(1);
            }
            
            LList_remove(list, input, removeData);
            free(removeData);
        }
        
        //if x value doesn't exist
        //int LList_find(struct LList * list, int x, struct LList_data * data)
        //void LList_push_front(struct LList * list, struct LList_data data)
        else{

            newLList_addData.y = 1;
            
        }
        
        //push new node in front while freeing to prevent memory leaks
        LList_push_front(list, newLList_addData);
        free(newLList_finddata);
        
    }
    
    //When the user finishes entering integers (scanf returns EOF),
    //you should print out all the integers you have seen along with
    //the number of times it appeared, starting with the most recent
    //and going to the oldest
    //void LList_print(struct LList * list)
    if(s == EOF){
        LList_print(list);
        LList_destroy(list);
        exit(0);
    }
    
    return 0;
    
}

//main method
int main(){
    
    //create the stack w. memory error checks
    struct LList *llist;
    llist = LList_create();
    if(!llist){
        fprintf(stderr, "Out of memory\n");
        return EXIT_FAILURE;
    }
    
    //calls mru method
    mru(llist);
    
    return 0;
}



