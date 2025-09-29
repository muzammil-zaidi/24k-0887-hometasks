#include<iostream>
using namespace std;

const int n=5;

bool isSafe(int maze[n][n],int x,int y,int sol[n][n]){
    return(x>=0 && x<n && y>=0 && y<n && maze[x][y]==1 && sol[x][y]==0);
}

bool solveMazeUtil(int maze[n][n],int x,int y,int sol[n][n]){
    if(x==n-1 && y==n-1){
        sol[x][y]=1;
        return true;
    }

    if(isSafe(maze,x,y,sol)){
        sol[x][y]=1;


        if(solveMazeUtil(maze,x+1,y,sol)){
            return true;
        }

        if(solveMazeUtil(maze,x,y+1,sol)){
            return true;
        }

        if(solveMazeUtil(maze,x-1,y,sol)){
            return true;
        }

        if(solveMazeUtil(maze,x,y-1,sol)){
            return true;
        }

        sol[x][y]=0;
        return false;
    }
    return false;
}

void printSolution(int sol[n][n]){
    cout<<"Solution Path:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<sol[i][j]<<" ";
        cout<<"\n";
    }
}

int main(){
    int maze[n][n]={
        {1,1,0,1,1},
        {0,1,1,1,1},
        {1,0,0,0,1},
        {1,1,1,0,1},
        {1,0,1,1,1}
    };

    int sol[n][n]={0};

    if(solveMazeUtil(maze,0,0,sol)){
        printSolution(sol);
    }
    else{
        cout<<"No path found!\n";
    }

    return 0;
}
