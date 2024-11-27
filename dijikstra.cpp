#include<iostream>
#include<queue>
#include<stack>
#include<climits>
#include<cstring>

#define pii pair<int, int>

using namespace std;

const int MAXN = 101;
const int INF = 1e9 + 7;

int n, m, s;
vector<pii> adj[MAXN];
int d[MAXN];

bool visited[MAXN];

void dijikstra(){
	memset(d, INF, sizeof(d));
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({0, s});
	d[s] = 0;
	
	while (!pq.empty()){
		pii e = pq.top();
		pq.pop();
		int u = e.second;
		if (!visited[u]) cout << "Found shortest length from " << s << " to " << u << " = " << d[u] << "\n";
		visited[u] = true;
		for (auto x: adj[u]){
			int v = x.first;
			int w = x.second;
			if (!visited[v] && d[v] > d[u] + w){
				d[v] = d[u] + w;
				pq.push({d[v], v});
			}
		}
	}
}

int main(){
	cin >> m >> n >> s;
	for (int i = 0; i < n; i++){
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({b, c});
	}
	dijikstra();
	return 0;
}
/*
7 12 2
1 3 2
2 1 20
2 3 30
2 5 4
2 7 2
4 1 2
4 5 2
5 1 8
6 4 1
7 4 5
7 5 6
7 6 1
Found shortest length from 2 to 2 = 0
Found shortest length from 2 to 7 = 2
Found shortest length from 2 to 6 = 3
Found shortest length from 2 to 4 = 4
Found shortest length from 2 to 5 = 4
Found shortest length from 2 to 1 = 6
Found shortest length from 2 to 3 = 8
*/
