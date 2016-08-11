/*
 Name: Katie Pan
 CSC 352 -- Assignment 5
 Binary Search Tree 
 */

/*player.c file*/

#ifndef PLAYER_H
#define PLAYER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void free(void *ptr);

/* Defines the data that must be stored for each player. */
struct Player {
    char * name;
    int wins;
    int losses;
};

//struct TreeNode that stores struct Player and left & right nodes
struct TreeNode {
    struct Player player;
    struct TreeNode *left, *right;
};

//creates a new individual node
struct TreeNode *createNode(char *inputName){
    //Create a new leaf node and return the pointer
    struct TreeNode *tempNode = malloc(sizeof(struct TreeNode));
    if(!tempNode){
        fprintf(stderr, "Out of memory\n");
        exit(1);
    }
    
    //mallocs space for name
    int nameLen = strlen(inputName);
    tempNode->player.name = malloc(nameLen+1);
    if(!tempNode->player.name){
        fprintf(stderr, "Out of memory\n");
        exit(1);
    }
    
    strcpy(tempNode->player.name, inputName);
    
    tempNode->player.wins = 0;
    tempNode->player.losses = 0;
    
    tempNode->left = NULL;
    tempNode->right = NULL;
    
    return tempNode;
};

//inserts node into the BST
int insertElement(struct TreeNode *tempNode, char *inputName, int won, int lost){
    
    
    
    //traverse the left BST
    if(strcmp(inputName, tempNode->player.name) < 0){
        
        
        if(tempNode->left == NULL){
            struct TreeNode *insertNode = createNode(inputName);
            tempNode->left = insertNode;
            
            if(won == 1){
                tempNode->left->player.wins++;
            }
            else{
                tempNode->left->player.losses++;
            }
            
            return 0;
        }
        insertElement(tempNode->left, inputName, won,lost);
    }
    
    //traverse the right BST
    else if(strcmp(inputName, tempNode->player.name) > 0){
        
        if(tempNode->right == NULL){
            struct TreeNode *insertNode = createNode(inputName);
            tempNode->right = insertNode;
            
            if(won == 1){
                tempNode->right->player.wins++;
            }
            else{
                tempNode->right->player.losses++;
            }
            return 0;
        }
        insertElement(tempNode->right, inputName, won, lost);
    }
    
    //if inputName already exists
    else if(strcmp(inputName, tempNode->player.name) == 0){
        
        //if won
        if(won == 1){
            tempNode->player.wins++;
        }
        //if lost
        else{
            tempNode->player.losses++;
        }
    }
    
    return 0;
};

//print BST in order
//"if player a had 10 wins and 5 losses, you would print "a, 10, 5" followed
//by a newline, and you would repeat this pattern for each player."
void printTree(struct TreeNode *tempNode){
    //display the full tree
    if(tempNode==NULL){
        return;
    }
    printTree(tempNode->left);
    printf("%s, %d, %d\n", tempNode->player.name, tempNode->player.wins, tempNode->player.losses);
    printTree(tempNode->right);
    return;
};

//destroys the BST (helper method)
void LList_destroyHelper(struct TreeNode * tempNode){
    
    if(tempNode == NULL)
        return;
    
    LList_destroyHelper(tempNode->left);
    LList_destroyHelper(tempNode->right);
    //printf("Freeing %s\n",tempNode->player.name);
    
    free(tempNode->player.name);
    free(tempNode);
};

//destroys the BST
void LList_destroy(struct TreeNode * root){
    
    struct TreeNode *tempNode = root;
    
    if(root == NULL)
        return;
    
    LList_destroyHelper(tempNode);
};


#endif



