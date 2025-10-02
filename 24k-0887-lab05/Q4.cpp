#include<iostream>
#include<vector>
using namespace std;

bool isSafe(vector<string> &board,int row,int col,int n){
    for(int i=0;i<row;i++)
        if(board[i][col]=='Q'){
            return false;
        }

    for(int i=row-1,j=col-1;i>=0 &&j>=0;i--,j--){
        if(board[i][j]=='Q'){
            return false;
        }
    }

    for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
        if(board[i][j]=='Q'){
            return false;
        }
    }

    return true;
}

bool solveOne(vector<string> &board,int row,int n){
    if(row==n){
        return true;
    }

    for(int col=0;col<n;col++){
        if(isSafe(board,row,col,n)){
            board[row][col]='Q';
            if(solveOne(board,row+1,n)){
                return true;
            }
            board[row][col]='.';
        }
    }
    return false;
}

void countAll(vector<string> &board,int row,int n,long long &count) {
    if(row==n){
        count++;
        return;
    }
    for(int col=0;col<n;col++){
        if(isSafe(board,row,col,n)){
            board[row][col]='Q';
            countAll(board,row+1,n,count);
            board[row][col]='.';
        }
    }
}

int main(){
    int n;
    cout<<"Enter value of N: ";
    cin>>n;

    vector<string> board(n,string(n,'.'));

    if(solveOne(board,0,n)){
        cout<<"\nOne valid configuration:\n";
        for(int i=0;i<n;i++){
            cout<<board[i]<<"\n";
        }
    }
    else{
        cout<<"No solution exists for N = "<<n<<"\n";
    }

    long long total=0;
    vector<string> tempBoard(n,string(n,'.'));
    countAll(tempBoard,0,n,total);
    cout<<"\nTotal number of distinct solutions: "<<total<<"\n";

    return 0;
}
