// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid
#define UNASSIGNED 0

// N is used for the size of Sudoku grid.
// Size will be NxN
#define N 9

// } Driver Code Ends

class Solution {
  public:
    // Function to find a solved Sudoku.
    bool canPlace(int grid[N][N], int i, int j, int numToPlace) {

        // check row and column
        for (int x = 0; x < N; x++) {
            if (grid[x][j] == numToPlace || grid[i][x] == numToPlace)
                return false;
        }

        // check smallGrid
        int smallGridSize = sqrt(N); // 3
        int smallI = (i / smallGridSize) * smallGridSize;
        int smallJ = (j / smallGridSize) * smallGridSize;

        for (int r = smallI; r < smallI + smallGridSize; r++) {
            for (int c = smallJ; c < smallJ + smallGridSize; c++) {
                if (grid[r][c] == numToPlace)
                    return false;
            }
        }
        return true;
    }

    bool solveHelper(int grid[N][N], int i, int j) {
        if (i == N) {
            // printGrid(grid);
            return true;
        }
        if (j == N) {
            return solveHelper(grid, i + 1, 0);
        }
        if (grid[i][j] != 0) {
            return solveHelper(grid, i, j + 1);
        }
        // Empty cell, try to place all numbers

        for (int num = 1; num <= 9; num++) {
            if (canPlace(grid, i, j, num)) {
                grid[i][j] = num;
                bool isThisValid = solveHelper(grid, i, j + 1);
                if (isThisValid)
                    return true;
            }
        }
        grid[i][j] = 0;
        return false;
    }
    bool SolveSudoku(int grid[N][N]) {
        // Your code here
        return solveHelper(grid, 0, 0);
    }

    // Function to print grids of the Sudoku.
    void printGrid(int grid[N][N]) {
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                cout << grid[r][c] << " ";
            }
        }
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int grid[N][N];

        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                cin >> grid[i][j];

        Solution ob;

        if (ob.SolveSudoku(grid) == true)
            ob.printGrid(grid);
        else
            cout << "No solution exists";

        cout << endl;
    }

    return 0;
} // } Driver Code Ends