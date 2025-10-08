#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int N = 5;

int maze[N][N] = {
    {1, 1, 1, 0, 1},
    {0, 1, 0, 1, 1},
    {1, 1, 1, 1, 0},
    {0, 1, 0, 1, 1},
    {1, 1, 1, 0, 1}
};

struct Cell {
    int x;
    int y;
};

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool isSafe(int x, int y, bool visited[N][N]) {
    return (x >= 0 && x < N && y >= 0 && y < N &&
            maze[x][y] == 1 && !visited[x][y]);
}

void findPaths(int x, int y, int destX, int destY,
               Cell path[100], int pathLength,
               vector<vector<Cell>> &allPaths,
               bool visited[N][N]) {

    if (x == destX && y == destY) {
        path[pathLength].x = x;
        path[pathLength].y = y;

        int size = pathLength + 1;
        vector<Cell> temp(size);
        for (int i = 0; i < size; i++) {
            temp[i] = path[i];
        }
        allPaths.push_back(temp);
        return;
    }

    visited[x][y] = true;
    path[pathLength].x = x;
    path[pathLength].y = y;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (isSafe(nx, ny, visited)) {
            findPaths(nx, ny, destX, destY, path, pathLength + 1, allPaths, visited);
        }
    }

    visited[x][y] = false;
}

void printPaths(vector<vector<Cell>> &paths, string name) {
    cout << name << " Paths:\n";
    int pathCount = 1;

    for (int i = 0; i < paths.size(); i++) {
        cout << "Path " << pathCount++ << ": ";
        for (int j = 0; j < paths[i].size(); j++) {
            cout << "(" << paths[i][j].x << "," << paths[i][j].y << ") ";
        }
        cout << endl;
    }
    cout << endl;
}

void findIntersections(vector<vector<Cell>> &rabbitPaths,
                       vector<vector<Cell>> &catPaths) {
    cout << "Intersection Points:\n";
    bool found = false;

    for (int i = 0; i < rabbitPaths.size(); i++) {
        for (int j = 0; j < catPaths.size(); j++) {
            for (int r = 0; r < rabbitPaths[i].size(); r++) {
                for (int c = 0; c < catPaths[j].size(); c++) {
                    if (rabbitPaths[i][r].x == catPaths[j][c].x &&
                        rabbitPaths[i][r].y == catPaths[j][c].y) {
                        cout << "(" << rabbitPaths[i][r].x << "," << rabbitPaths[i][r].y << ") ";
                        found = true;
                    }
                }
            }
        }
    }

    if (!found)
        cout << "No intersections found.";
    cout << endl;
}

int main() {
    bool visited[N][N] = {false};

    Cell path[100];
    vector<vector<Cell>> rabbitPaths;
    vector<vector<Cell>> catPaths;

    findPaths(0, 0, 2, 2, path, 0, rabbitPaths, visited);

    findPaths(4, 4, 2, 2, path, 0, catPaths, visited);

    printPaths(rabbitPaths, "Rabbit");
    printPaths(catPaths, "Cat");

    findIntersections(rabbitPaths, catPaths);

    return 0;
}
