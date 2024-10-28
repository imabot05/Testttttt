#include<iostream>
#include<queue>

#define ll long long 
#define FOR(i,l,r) for (int i = l; i <= r; i++)
#define FOD(i,l,r) for (int i = l; i >= r; i--)

const int MAXN = 100001;
int n, m, s, t;
std::vector<std::pair<int, int>> adj[MAXN];
void inp(){
	std::cin>>n>>m;
	for (int i = 0; i < m; i++){
		int x, y, z;
		std::cin>>x>>y>>z;
		adj[x].push_back({y, z});
	}
	std::cin>>s>>t;
}

const int INF = 1e9 + 7;
int pre[MAXN];

void dijikstra(int s){
	std::vector<ll> dist(n + 1, INF);
	dist[s] = 0;
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int, int>>> Q;
	Q.push({0, s});
	while (!Q.empty()){
		std::pair<int, int> top = Q.top();
		Q.pop();
		int u = top.second;
		int distance = top.first;
		if (distance > dist[u])
			continue;
		
		for (auto it: adj[u]){
			int v = it.first;
			int weight = it.second;
			if (dist[v] > dist[u] + weight){
				dist[v] = dist[u] + weight;
				Q.push({dist[v], v});
			}
		}
	}
	std::cout<<dist[t];
}

int main(int argc, const char **argv){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	inp();
	dijikstra(s);
	return 0;
}
