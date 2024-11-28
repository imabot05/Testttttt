#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<climits>
#include<utility>
#include<queue>

using namespace std;
const int MAXN = 1001;

int n, m, u, v, s, t;
queue<pair<int, int>> q;
pair<int, int> parent[MAXN][MAXN];
int dx[] = {-1,1,2,2,1,-1,-2,-2};
int dy[] = {-2,-2,-1,1,2,2,1,-1};
vector<pair<int, int>> path;
bool visited[MAXN][MAXN];

int check(int x, int y){
	return (x >= 1 && x <= n) && (y >= 1 && y <= m) && visited[x][y] == false;
} 

void bfs(){
	cin >> n >> m >> u >> v >> s >> t;
	pair<int, int> start = make_pair(u, v);
	q.push(start);
	
	parent[start.first][start.second] = make_pair(0, 0);
	while (!q.empty()){
		pair<int, int> top = q.front();
		q.pop();
		int x = top.first;
		int y = top.second;
		visited[x][y] = true;
		if (x == s && y == t){
			do {
//				cout << x << " " << y << endl;
				path.push_back({x, y});
				int x_tmp = x, y_tmp = y;
				x = parent[x_tmp][y_tmp].first;
				y = parent[x_tmp][y_tmp].second;	
			} while (!(x == 0 && y == 0));
			break;
		} 
		
		for (int i = 0; i < 8; i++){
			if (check(x + dx[i], y + dy[i])){
				q.push({x + dx[i], y + dy[i]});
				parent[x + dx[i]][y + dy[i]] = {x, y};
			}
		}
	}
	
	for (int i = path.size() - 1; i >= 0; i--){
		cout << path[i].first << " " << path[i].second<< endl;
	}
}

int main(){
	bfs();
	return 0;
}
/*
5 8
4 3 2 6
4 3
2 2
1 4
2 6
*/
