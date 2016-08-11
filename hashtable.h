/*
 Name: Katie Pan
 CSC 352 -- Assignment 6
 Hashtable.h
 */

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

//hash function
int hash(char * data, int size);

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

//create null hashtable
struct LList * LList_create();

//creates a new individual node
struct NODE *createNode(char *inputWord);

//insert in front
void insert(struct LList *list, char *inputWord);

//find
//if return 0, not found
//if return 1, found
int LList_find(struct LList *list, char *inputWord);

//print
void LList_print(struct LList * list);

//destroy
void LList_destroy(struct LList * list);

#endif
