/* (a) Using Backtracking to Trace the Path
We will assume the robot can move:
Right (R)
Down (D)

If it gets stuck, it backtracks (goes back to the previous step) and tries a different route.

Step-by-Step Path Tracing
Start: (0,0) 
(0,0) → move Down → (1,0) 
(1,0) → move Right → (1,1) 
(1,1) → move Down → (2,1) 
(2,1) → move Right → (2,2) 
(2,2) → move Right → (2,3) 
(2,3) → move Down → (3,3)  (Reached destination)  

(b) If Multiple Paths Exist How Backtracking Chooses

If the robot encounters multiple possible moves (for example, both Right and Down are free),
the backtracking algorithm typically follows this order:
Priority: Move Right → then Down → then Left → then Up */


#include <iostream>
#include <vector>
using namespace std;

#define N 4

bool isSafe(int x, int y, vector<vector<int>>& maze, vector<vector<int>>& path){
    return (x >= 0 && y >= 0 && x < N && y < N && maze[x][y] == 1 && path[x][y] == 0);
}

bool solveMaze(vector<vector<int>>& maze, int x, int y, vector<vector<int>>& path){
    if(x == N - 1 && y == N - 1){
        path[x][y] = 1;
        return true;
    }

    if(isSafe(x, y, maze, path)){
        path[x][y] = 1;

        if (solveMaze(maze, x, y + 1, path)){
            return true;
        }
        if (solveMaze(maze, x + 1, y, path)){
            return true;
        }

        path[x][y] = 0;
    }
    return false;
}

int main(){
    vector<vector<int>> maze={
        {1,0,1,1},
        {1,1,0,1},
        {0,1,1,1},
        {1,0,1,1}
    };

    vector<vector<int>> path(N, vector<int>(N, 0));

    if(solveMaze(maze, 0, 0, path)){
        cout << "Path found:\n";
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++)
                cout << path[i][j] << " ";
            cout << endl;
        }
    }
    else{
        cout << "No path exists.\n";
    }
    return 0;
}
