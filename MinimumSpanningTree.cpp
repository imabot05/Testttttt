#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAXN = 1e5 + 5;
int n, m;
int weight = 0;

int parent[MAXN];
int sz[MAXN];

struct edge{
	int u, v, w;
};

vector<edge> edges;

void init(){
	for (int i = 1; i <= n; i++){
		parent[i] = i;
		sz[i] = 1;
	}
}

int find(int u){
	if (u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}

bool Union(int u, int v){
	u = find(u);
	v = find(v);
	if ( u == v ) return 0;
	if (sz[u] < sz[v]) swap(u, v);
	parent[v] = u;
	sz[u] += sz[v];
	return 1;
}

void inp(){
	std::cin>>n>>m;
	for (int i = 1; i <= m; i++){
		int x, y, z;
		cin>>x>>y>>z;
		edge e;
		e.u = x;
		e.v = y;
		e.w = z;
		edges.push_back(e);
	}			
}

bool cmp(edge a, edge b){
	return a.w < b.w;
}

void Kruskal(){
	vector<edge> mst;
	int res = 0;
	sort(edges.begin(), edges.end(), cmp);
	for (int i = 0; i < edges.size(); i++){
		if (mst.size() == n - 1) break;
		edge e = edges[i];
		if (Union(e.u, e.v)){
			mst.push_back(e);
			res += e.w;
		}
	}
	if (mst.size() != n - 1) cout<<"-1";
	else cout<<res;	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	inp();
	init();
	Kruskal();
	return 0;
}

