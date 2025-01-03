#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>

using namespace std;

const int MAXN = 1010;
const int INF = 1e9 + 7;

int n, D;
int x[MAXN], y[MAXN];
vector<vector<int>> adj;
int trace[MAXN];

int dis(int i, int j){
	int distance = (int)sqrt(pow((x[i] - x[j]), 2) + pow((y[i] - y[j]), 2));
	return distance;	
}

void inp(){
	cin >> n >> D;
	adj.resize(n + 1);
	for (int i = 1; i <= n; i++){
		cin >> x[i] >> y[i];
	}
}

void buildGraph(){
	for (int i = 1; i < n; i++){
		for (int j = i + 1; j <= n; j++){
			if (dis(i, j) <= D){
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}
}

int bfs(){
	queue<int> q;
	q.push(1);
	memset(trace, 0, sizeof(trace));
	trace[1] = -1;
	while (!q.empty()){
		int u = q.front();
		q.pop();
		for (int v: adj[u]){
			if (trace[v] == 0){
				trace[v] = u;
				if (v == n) return 1;
				q.push(v);
			}
		}
	}
	return 0;
}

int main(int argc, const char **argv){
	inp();
	buildGraph();
	if (bfs()){
		int length = 0;
		int u = n;
		do {
			length += 1;
			u = trace[u];
		} while (trace[u] != -1);
		cout << length;
	} else cout << "-1";
	return 0;
}
/*
8 4
6 0
3 1
10 2
7 3
9 4
10 7
2 6
7 9
4
*/
