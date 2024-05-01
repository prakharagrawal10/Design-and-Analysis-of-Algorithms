#include <iostream>
#include <vector>

using namespace std;

// Function to check if it's safe to place a queen at position (x, y)
bool isSafe(vector<vector<int>>& arr, int x, int y, int n) {
    // Check if there's a queen in the same column
    for (int row = 0; row < x; row++) {
        if (arr[row][y] == 1) {
            return false;
        }
    }

    // Check if there's a queen in the upper left diagonal
    int row = x;
    int col = y;
    while (row >= 0 && col >= 0) {
        if (arr[row][col] == 1) {
            return false;
        }
        row--;
        col--;   
    }

    // Check if there's a queen in the upper right diagonal
    row = x;
    col = y;
    while (row >= 0 && col < n) {
        if (arr[row][col] == 1) {
            return false;
        }
        row--;
        col++;
    }

    return true;    
}

// Function to solve the N-Queens problem recursively
bool nQueen(vector<vector<int>>& arr, int x, int n) {
    // Base case: all queens are placed
    //here y not needed becasue we 
    //loop rows to place queen and check column in isSafe() function

    if (x >= n) {
        return true;
    }

    // Try placing queen in each column of the current row
    for (int col = 0; col < n; col++) {
        if (isSafe(arr, x, col, n)) {
            // Place the queen
            arr[x][col] = 1;

            // Recur for next row
            if (nQueen(arr, x + 1, n)) {
                return true;    
            }

            // If placing queen at (x, col) doesn't lead to a solution,
            // backtrack and try placing it elsewhere
            arr[x][col] = 0;
        }
    }
    // No solution found for this row
    return false;
}

int main() {
    int N = 4; // Number of queens and size of the chessboard
    // Create an empty chessboard
    vector<vector<int>> arr(N, vector<int>(N, 0));

    // Call the nQueen function to solve the problem
    if (nQueen(arr, 0, N)) {
        cout << "Solution exists. Here's the arrangement:\n";
        // Print the arrangement
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "Solution does not exist for N = " << N << endl;
    }
    return 0;
}
