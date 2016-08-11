/*
 Katie Pan
 Assignment 3c: Ship Simulaton
 
 DEBUGGER: fprintf(stderr, "3\n");
 */

#include <stdio.h>
#include <string.h>

void exit(int status);

/*
 checks if coordinates are in range of the board
 if it is, returns 1
 if it isn't, returns 0
 */
int inRange(int xPos, int yPos){
    if(xPos < 20 && xPos > -1 && yPos < 20 && yPos > -1)
        return 1;
    else{
        return 0;
    }
}

/*main method*/
int main(){
    
    /*initializes variables*/
    int simBoard[20][20];
    int i, j, xpos, ypos;
    int shipXPos, shipYPos;
    
    /*set entire board to '0' = EMPTY*/
    for(i = 0; i < 20; i++){
        for (j = 0; j < 20; j++){
            simBoard[i][j] = 0;
        }
    }
    int r;
    /*reads in obstacles inputs*/
    while((r=scanf("%d", &xpos)) != EOF){
        
        
        /*if user ever inputs -1, we first check if there is any errors*/
        if(xpos == -1){
            
            /*error: EOF before starting position & exits*/
            if(scanf("%d %d", &shipXPos, &shipYPos) == EOF){
                fprintf(stderr, "No starting position!\n");
                exit(0);
            }
            
            /*error: starting position is not in range & exits*/
            else if(inRange(shipXPos-1, shipYPos-1) == 0){
                fprintf(stderr, "Incorrect starting position!\n");
                exit(0);
            }
            
            break;
        }
        
        scanf("%d", &ypos);

        
        /*if in range, simBoard will change from empty (0) to obstacle (1)*/
        if(inRange(xpos-1, ypos-1) == 1){
            /*1 = OBSTACLE*/
            simBoard[xpos-1][ypos-1] = 1;
        }
        
        /*errpr: obstacle position is not in range & exits*/
        else{
            fprintf(stderr, "Incorrect obstacle position!\n");
            exit(0);
        }
        
    }
    
    
    if(r== EOF){
        fprintf(stderr, "Error!\n");
        exit(0);
    }
  

    /*number of times ship has hit an obstacle*/
    int obstacleHit = 0;
    char direction;
    
    int x = shipXPos-1;
    int y = shipYPos-1;
    
    int alive = 0;
    
    /*scans in chars for directions, also checks if it is in range and if the ship is alive*/
    while(inRange(x, y) == 1 && scanf("\n%c", &direction) != EOF && alive == 0){
       
        /*error: can't start on an obstacle*/
        if(simBoard[x][y] == 1){
            fprintf(stderr, "ERROR!\n");
            exit(0);
        }
        
        /*PSEUDOCODE:
         north, south, east, west if statements all work in the same way:
         1. Checks if input char is n/N, s/S, e/E, w/W
         2. Checks if the new coodinates are in range
            - modifies the x, y variables accordingly
         3. Checks if there is an obstacle or not
            - if there is, checks how many times we have hit the obstacle
                - 3 times -> SHIP HAS SUNK & prints statement & sets alive = 1
                - < 3 times -> obstacleHit increases by 1 and simBoard[x][y]=0 (obstacle is wiped out)
         */
        
        /*north*/
        else if(direction == 'n' || direction == 'N'){
        
            if(inRange(x, y-1) == 1){
                
                y = y-1;
                
                if(simBoard[x][y] == 1){
                    
                    if(obstacleHit == 3){
                        printf("SUNK! at %d, %d\n", x+1, y+1);
                        alive = 1;
                    }
                    else{
                        obstacleHit++;
                        simBoard[x][y] = 0;
                    }
                }
            }
        }
        
        /*south*/
        else if(direction == 's' || direction == 'S'){
            
            if(inRange(x, y+1) == 1){
                
                y = y+1;
                
                if(simBoard[x][y] == 1){
                    
                    if(obstacleHit == 3){
                        printf("SUNK! at %d, %d\n", x+1, y+1);
                        alive = 1;
                    }
                    else{
                        obstacleHit++;
                        simBoard[x][y] = 0;
                    }
                }
            }
        }
        
        /*east*/
        else if(direction == 'e' || direction == 'E'){
           
            if(inRange(x + 1, y) == 1){
                x = x+1;
                
                if(simBoard[x][y] == 1){
            
                    if(obstacleHit == 3){
                        printf("SUNK! at %d, %d\n", x+1, y+1);
                        alive = 1;
                    }
                    else{
                        obstacleHit++;
                        simBoard[x][y] = 0;
                    }
                }
            }
        }
        
        /*west*/
        else if(direction == 'w' || direction == 'W'){
           
            if(inRange(x-1, y) == 1){
                x = x-1;
                
                if(simBoard[x][y] == 1){
                   
                    if(obstacleHit == 3){
                        printf("SUNK! at %d, %d\n", x+1, y+1);
                        alive = 1;
                    }
                    else{
                        obstacleHit++;
                        simBoard[x][y] = 0;
                    }
                }
            }
        }
        
        /*error: when user does not input a correct char (so anything that ISN'T n/N, s/S, e/E, w/W & continues program*/
        else{
            fprintf(stderr, "ERROR!\n");
            continue;
        }
    }
    
    /*if ship has sunk, user can still input values*/
    while(alive == 1 && scanf("\n%c", &direction) != EOF){
        continue;
    }

    /*if EOF before the ship sunk, prints this statement & exits*/
    if(alive == 0){
        printf("Survived! Ending location: %d, %d\n", x+1, y+1);
        exit(0);
    }
    
    /*if EOF and the ship already sunk, prints this statement & exits*/
    if(alive == 1){
        exit(0);
    }
    
    return 0;
}