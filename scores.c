/*
 Name: Katie Pan
 CSC 352 -- Assignment 5
 Binary Search Tree -- Tournament Scores
 */

#include "player.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 struct Player {
 char * name;
 int wins;
 int losses;
 };
 */




//main method
int main(){
    
    //create the BST w. memory error checks
    struct TreeNode *root = NULL;
    
    char user1[21], user2[21];
    int score1, s1, score2, s2, w;
    
    //user input
    while((w = scanf("%s", user1)) != EOF){
        
        //check if EOF error, if so, stderr a message
        if((s1 = scanf("%d", &score1)) == EOF){
            fprintf(stderr, "No score input\n");
            LList_destroy(root);
            exit(1);
        }
        
        //checks if the next number is an integer
        if(s1 == 0){
            fprintf(stderr, "Wrong score, needs to be an integer\n");
            LList_destroy(root);
            exit(1);
        }
        
        //USER 2
        if(scanf("%s", user2) != EOF){
            //error: no second user input score
            if((s2 = scanf("%d", &score2)) == EOF){
                fprintf(stderr, "No score input\n");
                LList_destroy(root);
                exit(1);
            }
            
            //error: check if score is an integer
            if(s2 == 0){
                fprintf(stderr, "Wrong score, needs to be an integer\n");
                LList_destroy(root);
                exit(1);
            }
            
            //score1 is bigger than score2
            //TreeNode *createNode(char *inputName)
            //TreeNode *insertElement(TreeNode *tempNode, char *inputName, int won, int lost)
            
            if(strcmp(user1, user2) == 0){
                fprintf(stderr, "No same players\n");
                exit(1);
            }
            
            //special case: if there is no BST yet, make a node
            if (root == NULL){
                root = createNode(user1);
                
                if(score1 > score2){
                    root->player.wins++;
                    insertElement(root, user2, 0, 1);
                    
                }
                
                else if (score2 > score1){
                    root->player.losses++;
                    insertElement(root, user2, 1, 0);
                }
                
                else{
                    fprintf(stderr, "Ties are not allowed\n");
                    LList_destroy(root);
                    exit(1);
                }
                
                continue;
            }
            
            //else traverse the tree and insert node
            struct TreeNode *tempNode1 = root;
            struct TreeNode *tempNode2 = root;
            
            if(score1 > score2){
                
                insertElement(tempNode1, user1, 1, 0);
                insertElement(tempNode2, user2, 0, 1);
                
            }
            
            else if (score2 > score1){
                insertElement(tempNode2, user2, 1, 0);
                insertElement(tempNode1, user1, 0, 1);
            }
            
            else{
                fprintf(stderr, "Ties are not allowed\n");
                LList_destroy(root);
                exit(1);
            }
        }
        
        //no second user error
        else{
            fprintf(stderr, "No second user\n");
            LList_destroy(root);
            exit(1);
        }
        
    }
    
    //if user pressed EOF, print tree and destroy
    if(w == EOF){
        
        printTree(root);
        LList_destroy(root);
        exit(0);
    }
    
    
    
    return 0;
}




