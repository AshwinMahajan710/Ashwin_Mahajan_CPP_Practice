#include"Ashwin_Mahajan_task3_Maze.h"
#include<string>
#include<iostream>

// All imp global variables
const int MAX_LEFT = 0;
const int MAX_RIGHT = 11;
const int MAX_UP = 0;
const int MAX_DOWN = 11;
const int TARGET_X = 2;
const int TARGET_Y = 0;

// function to print the maze
void printMaze(char maze[12][12], int& val1, int& val2){

    std::cout<<"\n\n";
    for (int i = 0; i < 12; i++)
    {
        for(int j=0;j<12;j++){
            
            if(i==val1 && j == val2){
                std::cout<<"0 ";
            }
            else {
                std::cout<<maze[i][j]<<" ";
            }
        }
        std::cout<<std::endl;
    }    
    
}

void solveMaze(char maze[12][12] , int& currPos_x, int& currPos_y, std::string priorityDir){

    if(currPos_x == TARGET_X && currPos_y == TARGET_Y){ return ;}
    
    if(priorityDir == "right"){
        // 1. right of right = down
        if(currPos_x + 1 <= MAX_DOWN && maze[currPos_x + 1][currPos_y] != '#'){
            currPos_x++;
            priorityDir = "down";
        }
        // 2. straight = right
        else if(currPos_y + 1 <= MAX_RIGHT && maze[currPos_x][currPos_y + 1] != '#'){
            currPos_y++;
            priorityDir = "right";
        }
        // 3. left of right = up
        else if(currPos_x - 1 >= MAX_UP && maze[currPos_x - 1][currPos_y] != '#'){
            currPos_x--;
            priorityDir = "up";
        }
        // 4. back = left
        else{
            currPos_y--;
            priorityDir = "left";
        }
        printMaze(maze, currPos_x , currPos_y);
        solveMaze(maze, currPos_x, currPos_y , priorityDir);
    }


    else if(priorityDir == "down"){
        // 1. right of down = left
        if(currPos_y - 1 >= MAX_LEFT && maze[currPos_x][currPos_y - 1] != '#'){
            currPos_y--;
            priorityDir = "left";
        }
        // 2. straight = down
        else if(currPos_x + 1 <= MAX_DOWN && maze[currPos_x + 1][currPos_y] != '#'){
            currPos_x++;
            priorityDir = "down";
        }
        // 3. left of down = right
        else if(currPos_y + 1 <= MAX_RIGHT && maze[currPos_x][currPos_y + 1] != '#'){
            currPos_y++;
            priorityDir = "right";
        }
        // 4. back = up
        else{
            currPos_x--;
            priorityDir = "up";
        }
        printMaze(maze, currPos_x , currPos_y);
        solveMaze(maze, currPos_x, currPos_y , priorityDir);
    }

    else if(priorityDir == "left"){
        // 1. right of left = up
        if(currPos_x - 1 >= MAX_UP && maze[currPos_x - 1][currPos_y] != '#'){
            currPos_x--;
            priorityDir = "up";
        }
        // 2. straight = left
        else if(currPos_y - 1 >= MAX_LEFT && maze[currPos_x][currPos_y - 1] != '#'){
            currPos_y--;
            priorityDir = "left";
        }
        // 3. left of left = down
        else if(currPos_x + 1 <= MAX_DOWN && maze[currPos_x + 1][currPos_y] != '#'){
            currPos_x++;
            priorityDir = "down";
        }
        // 4. back = right
        else{
            currPos_y++;
            priorityDir = "right";
        }
        printMaze(maze, currPos_x , currPos_y);
        solveMaze(maze, currPos_x, currPos_y , priorityDir);
        
    }

    else if(priorityDir == "up"){
        // 1. right of up = right
        if(currPos_y + 1 <= MAX_RIGHT && maze[currPos_x][currPos_y + 1] != '#'){
            currPos_y++;
            priorityDir = "right";
        }
        // 2. straight = up
        else if(currPos_x - 1 >= MAX_UP && maze[currPos_x - 1][currPos_y] != '#'){
            currPos_x--;
            priorityDir = "up";
        }
        // 3. left of up = left
        else if(currPos_y - 1 >= MAX_LEFT && maze[currPos_x][currPos_y - 1] != '#'){
            currPos_y--;
            priorityDir = "left";
        }
        // 4. back = down
        else{
            currPos_x++;
            priorityDir = "down";
        }
        printMaze(maze, currPos_x , currPos_y);
        solveMaze(maze, currPos_x, currPos_y , priorityDir);
    }
}