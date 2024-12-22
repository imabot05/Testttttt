#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#include<stack>

using namespace std;

const int MAXN = 100005;
int n, m;
vector<int> adj[MAXN];
vector<int> t_adj[MAXN];
bool visited[MAXN];
stack<int> st;

void inp(){
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		t_adj[y].push_back(x);
	}
	memset(visited, false, sizeof(visited));
}

void dfs1(int u){
	visited[u] = true;
	for (int v: adj[u]){
		if (!visited[v]) dfs1(v);
	}
	st.push(u);
}

void dfs2(int u){
	visited[u] = true;
	for (int v: t_adj[u]){
		if (!visited[v]) dfs2(v);
	}
}

void solve(){
	for (int i = 1; i <= n; i++){
		if (!visited[i]) dfs1(i);
	}
	memset(visited, false, sizeof(visited));
	int scc = 0;
	while (!st.empty()){
		int u = st.top();
		st.pop();
		if (!visited[u]){
			++scc;
			dfs2(u);
		}
	}
	cout << scc;
}

int main(){
	inp();
	solve();
	return 0;
}
