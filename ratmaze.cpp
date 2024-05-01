#include <iostream>
#include <vector>

using namespace std;

// Function to check if the current cell is a valid move
bool isValidMove(vector<vector<int>>& maze, int row, int col, int n) {
    // Check if the current cell is within the maze boundaries
    if (row >= 0 && row < n && col >= 0 && col < n && maze[row][col] == 1) {
        return true;
    }
    return false;
}

// Function to solve the rat maze problem using backtracking
bool solveMaze(vector<vector<int>>& maze, int row, int col, int n, vector<vector<int>>& path) {
    // Check if the rat has reached the destination
    if (row == n - 1 && col == n - 1) {
        path[row][col] = 1;
        return true;
    }

    // Check if the current cell is a valid move
    if (isValidMove(maze, row, col, n)) {
        // Mark the current cell as part of the path
        path[row][col] = 1;

        // Move to the right
        if (solveMaze(maze, row, col + 1, n, path)) {
            return true;
        }

        // Move to the bottom
        if (solveMaze(maze, row + 1, col, n, path)) {
            return true;
        }

        // If no valid move is possible, backtrack
        path[row][col] = 0;
        return false;
    }

    return false;
}

int main() {
    int n;
    cout << "Enter the size of the maze: ";
    cin >> n;

    vector<vector<int>> maze(n, vector<int>(n));
    cout << "Enter the maze (0 for blocked cell, 1 for open cell):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maze[i][j];
        }
    }

    vector<vector<int>> path(n, vector<int>(n, 0));
    if (solveMaze(maze, 0, 0, n, path)) {
        cout << "Path found!" << endl;
        cout << "The path in the maze is:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << path[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No path found!" << endl;
    }

    return 0;
}