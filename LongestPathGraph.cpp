#include<iostream>
#include<set>
#include<vector>
#include<algorithm>

using namespace std;

const int MAXN = 15;
int N, M;
set<int> adj[MAXN];
int X[MAXN];
int best;
bool visited[MAXN];

void inp(){
	cin >> N >> M;
	
	for (int i = 0; i < M; i++){
		int u, v;
		cin >> u >> v;
		adj[u].insert(v);
		adj[v].insert(u);
	}
}

bool check(int v, int k){
	if (visited[v]) return false;
	return adj[X[k - 1]].find(v) != adj[X[k - 1]].end();
}

void Try(int k){
	for (int v: adj[X[k - 1]]){
		if (check(v, k)){
			visited[v] = true;
			X[k] = v;
			best = max(best, k); 
			Try(k + 1);
			visited[v] = false;
		}
	}
}

void solve(){
	best = 1;
	for (int v = 1; v <= N; v++){
		X[1] = v;
		visited[v] = true;
		Try(2);
		visited[v] = false;
	}
	cout << best;
}

int main(){
	inp();
	solve();
	return 0;
}
