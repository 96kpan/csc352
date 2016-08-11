/*
 Name: Katie Pan
 CSC 352 -- Assignment 6
 Hashtable.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//each data contains the word and the number of times it has appeared in the text
struct hashtable_data {
    char *word;
    int count;
};

/*LList struct that resets head*/
struct LList {
    // You must fill in this struct with any data you need to maintain a linked
    // list.  You may need to create additional structs as well.
    struct NODE *head;
};

/*NODE struct that contains data (struct LList_data) and a next (struct NODE)*/
struct NODE {
    struct hashtable_data data;
    struct NODE *next;
};

//creates hashtable
struct LList * LList_create(){
    
    struct LList *newList = (struct LList*)malloc(sizeof(struct LList));
    
    if(!newList)
        return NULL;
    
    newList->head = NULL;
    
    return newList;
};

//hash function
int hash(char * data, int size) {
    unsigned long hash = 5381;
    char * p;
    for (p = data; *p != '\0'; ++p) {
        hash = (hash * 33) + *p;
    }
    return (int)(hash % size);
}

//creates a new individual node
struct NODE *createNode(char *inputWord){
    //Create a new leaf node and return the pointer
    struct NODE *tempNode = malloc(sizeof(struct NODE));
    if(!tempNode){
        fprintf(stderr, "Out of memory\n");
        exit(1);
    }
    
    //mallocs space for name
    int wordLen = strlen(inputWord);
    tempNode->data.word = malloc(wordLen+1);
    if(!tempNode->data.word){
        fprintf(stderr, "Out of memory\n");
        exit(1);
    }
    
    strcpy(tempNode->data.word, inputWord);
    
    tempNode->data.count = 1;
    
    return tempNode;
};

//insert in front
void insert(struct LList *list, char *inputWord){
    struct NODE *newNode = createNode(inputWord);
    
    newNode->next = list->head;
    list->head = newNode;
};

//find
//if return 0, not found
//if return 1, found
int LList_find(struct LList *list, char *inputWord){
    
    if(!list)
        return 0;
    
    if(!list->head)
        return 0;
    
    struct NODE *ref = list->head;
    
    while(ref != NULL){
        
        if(strcmp(ref->data.word, inputWord) == 0){
            
            ref->data.count++;
            return 1;
        }
        
        ref = ref->next;
    }
    
    return 0;
    
};

//print
void LList_print(struct LList * list){
    
    if(!list)
        return;
    
    if(!list->head)
        return;
    
    struct NODE *ref = list->head;

    while(ref != NULL){
        printf("%s, %d\n", ref->data.word, ref->data.count);
        ref = ref->next;
    }
    
    
    return;
};

//destroy
void LList_destroy(struct LList * list){
    
    if(!list)
        return;
    
    /*traverse the list and freeing each element*/
    while(list->head != NULL){
        
        struct NODE *ref = list->head;
        list->head = list->head->next;
        free(ref->data.word);
        free(ref);
    }
    
    free(list);
    return;
};


