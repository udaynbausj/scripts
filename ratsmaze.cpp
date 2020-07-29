//
// Created by Uday B K on 16/05/20.
//


#include <iostream>
#include <vector>
#include <climits>
#define N 4
using namespace std;

bool isSafe(int maze[N][N] , int x , int y) {
    return x >=0 && x < N && y >= 0 && y < N && maze[x][y] == 1;
}

bool solveMazeUtil(int maze[N][N] , int x, int y, int sol[N][N]) {
    //if rat reaches final position
    if (x == N-1 && y == N-1 && maze[x][y] == 1)
        return true;
    if (isSafe(maze,x,y)) {
        sol[x][y] = 1;
        if (solveMazeUtil(maze,x + 1 , y  , sol))
            return true;
        if (solveMazeUtil(maze,x,y+1,sol))
            return true;
        sol[x][y]=0;
        return false;
    }
}

bool solveMaze(int maze[N][N]) {
    int sol[N][N] = { { 0, 0, 0, 0 },
                      { 0, 0, 0, 0 },
                      { 0, 0, 0, 0 },
                      { 0, 0, 0, 0 } };

}

int main() {
    int maze[N][N] = { { 1, 0, 0, 0 },
                       { 1, 1, 0, 1 },
                       { 0, 1, 0, 0 },
                       { 1, 1, 1, 1 } };
    solveMaze(maze);
}