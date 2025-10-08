/*(a) Apply Backtracking to Find the Safe Escape Path

We’ll assume the person can move:
Right (R)
Down (D)

Step-by-Step Path Tracing
Start at (0,0)
(0,0) → Right → (0,1)
(0,1) → Down → (1,1)
(1,1) → Right → (1,2) 
(1,2) → Down → (2,2)  (Blocked) → Backtrack to (1,2)
(1,2) → Down → (2,3)
(2,3) → Down → (3,3)  (Goal reached)

(b) What if No Safe Route Exists?

If no path from start to end exists:
The backtracking algorithm tries every possible move recursively.
Each time a move fails (no further safe cells), it backtracks — i.e., returns to the previous cell and tries another direction.
When all possible routes are explored and none lead to the goal, the algorithm concludes that no path exists. */

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

        if(solveMaze(maze, x, y + 1, path)){
            return true;
        }
        if(solveMaze(maze, x + 1, y, path)){
            return true;
        }

        path[x][y] = 0;
    }

    return false;
}

int main(){
    vector<vector<int>> maze ={
        {1,1,0,1},
        {0,1,1,0},
        {1,1,0,1},
        {0,1,1,1}
    };

    vector<vector<int>> path(N, vector<int>(N, 0));

    if (solveMaze(maze, 0, 0, path)){
        cout << "Safe Escape Path Found:\n";
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++)
                cout << path[i][j] << " ";
            cout << endl;
        }
    }
    else{
        cout << "No safe escape path exists!\n";
    }

    return 0;
}
