#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <vector>
#include <queue>
#include <bitset>
#include <tuple>
#include <algorithm>

using namespace std;

const vector<int> DIRECTIONS = {0, 1, 0, -1, 0};

int bfsBacktrack(vector<vector<int>> &grid, int rows, int cols, int row, int col) {
    queue<tuple<int, int, int, bitset<1024>>> queue;
    bitset<1024> visited;
    int maxGold = 0;
    visited[row * cols + col] = 1;
    queue.push({row, col, grid[row][col], visited});
    
    while (!queue.empty()) {
        auto [currRow, currCol, currGold, currVis] = queue.front();
        queue.pop();
        maxGold = max(maxGold, currGold);
        
        for (int direction = 0; direction < 4; direction++) {
            int nextRow = currRow + DIRECTIONS[direction];
            int nextCol = currCol + DIRECTIONS[direction + 1];
            
            if (nextRow >= 0 && nextRow < rows && nextCol >= 0 && nextCol < cols && grid[nextRow][nextCol] != 0
                && !currVis[nextRow * cols + nextCol]) {
                currVis[nextRow * cols + nextCol] = 1;
                queue.push({nextRow, nextCol, currGold + grid[nextRow][nextCol], currVis});
                currVis[nextRow * cols + nextCol] = 0;
            }
        }
    }
    
    return maxGold;
}

int getMaximumGold(vector<vector<int>> &grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    
    int maxGold = 0;
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            if (grid[row][col] != 0) {
                maxGold = max(maxGold, bfsBacktrack(grid, rows, cols, row, col));
            }
        }
    }
    return maxGold;
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    cout << getMaximumGold(grid) << endl;
    return 0;
}
/*

In a gold mine grid of size m x n, each cell in this mine has an integer representing the amount of gold in that cell, 0 if it is empty.

Return the maximum amount of gold you can collect under the conditions:

Every time you are located in a cell you will collect all the gold in that cell.
From your position, you can walk one step to the left, right, up, or down.
You can't visit the same cell more than once.
Never visit a cell with 0 gold.
You can start and stop collecting gold from any position in the grid that has some gold.

5 3
1 0 7
2 0 6
3 4 5
0 3 0
9 0 20
28
*/
