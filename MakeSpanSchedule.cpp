#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cstring>
#include<algorithm>

using namespace std;

const int MAXN = 100005;

bool visited[MAXN];
vector<int> adj[MAXN];
int d[MAXN];
int n, m;
void inp(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> d[i];
	}
	for (int i = 1; i <= m; i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
}
stack<int> st;
void dfs(int u){
	visited[u] = true;
	for (int v: adj[u]){
		if (!visited[v]) dfs(v);
	}
	st.push(u);
}

void solve(){
	inp();
	for (int i = 1; i <= n; i++){
		if (!visited[i]) dfs(i);
	}
	vector<int> topo;
	while (!st.empty()){
//		cout << st.top() << " ";
		topo.push_back(st.top());
		st.pop();
	}
	int dp[MAXN];
	memset(dp, 0, sizeof(dp));
	int makespan = 0;
	for (int i = 0; i < topo.size(); i++){
		for (int v: adj[topo[i]]){
			dp[v] = max(dp[v], dp[topo[i]] + d[topo[i]]);
		}
		makespan = max(makespan, dp[topo[i]] + d[topo[i]]);	
	}
	cout << makespan;
}

int main(){
    solve();
    return 0;
}
