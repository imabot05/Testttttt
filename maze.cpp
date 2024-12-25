#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

struct Point{
    int x, y;
    int step;
};

const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int dfs(vector<vector<int>> maze, int startRow, int startCol){
    int n = maze.size();
    int m = maze[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<Point> q;
    q.push({startRow, startCol, 0});
    visited[startRow][startCol] = true;
    while (!q.empty()){
        Point p = q.front();
        q.pop();
        if (maze[p.x][p.y] == true){
            continue;
        }
        if (p.x == n - 1 || p.y == m - 1 || p.x == 0 || p.y == 0){
            return p.step + 1;
        }
        for (int i = 0; i < 4; i++){
            int x1 = p.x + dirs[i][0];
            int y1 = p.y + dirs[i][1];
            if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && !visited[x1][y1]){
                q.push({x1, y1, p.step + 1});
                visited[x1][y1] = true;
            }
        }
    }
    return -1;
}

int main(int argc, const char **argv){
    int n, m, row, col;
    cin >> n >> m >> row >> col;
    vector<vector<int>> maze(n, vector<int>(m));
    for(int i=0;i<n;i++){
         for(int j=0;j<m;j++){
             cin>>maze[i][j];
         }
     }
     int result = dfs(maze, row - 1, col - 1);
     cout << result;
     return 0;
}
8 12 5 6
1 1 0 0 0 0 1 0 0 0 0 1
1 0 0 0 1 1 0 1 0 0 1 1
0 0 1 0 0 0 0 0 0 0 0 0
1 0 0 0 0 0 1 0 0 1 0 1
1 0 0 1 0 0 0 0 0 1 0 0
1 0 1 0 1 0 0 0 1 0 1 0
0 0 0 0 1 0 1 0 0 0 0 0
1 0 1 1 0 1 1 1 0 1 0 1
7

