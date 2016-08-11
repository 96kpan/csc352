//
//  player.h
//  
//
//  Created by Katie Pan on 7/11/16.
//
//

/*player.h file*/

#ifndef PLAYER_H
#define PLAYER_H

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
struct TreeNode *createNode(char *inputName);

//inserts node into the BST
int insertElement(struct TreeNode *tempNode, char *inputName, int won, int lost);

//print BST in order
//"if player a had 10 wins and 5 losses, you would print "a, 10, 5" followed
//by a newline, and you would repeat this pattern for each player."
void printTree(struct TreeNode *tempNode);

//destroys the BST (helper method)
void LList_destroyHelper(struct TreeNode * tempNode);

//destroys the BST
void LList_destroy(struct TreeNode * root);


#endif
