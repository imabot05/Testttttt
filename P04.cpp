#include<bits/stdc++.h>
using namespace std;

const int MAXN = 101;

int n, M;
int cost[MAXN][MAXN];
bool visited[MAXN];
int X[MAXN];
int f, ans = 0;

bool check(int v, int k){
	if (visited[v] == true) return false;
	if (f + cost[X[k - 1]][v] > M) return false;
	return true;
}

void Try(int k){
	for (int v = 1; v <= n; v++){
		if (check(v, k)){
			X[k] = v;
			f += cost[X[k-1]][v];
			visited[v] = true;
			if (k == n){
				if (f + cost[X[n]][1] <= M){
					ans++;
					cout << f + cost[X[n]][1];	
				}
			}
			else Try(k + 1);
			visited[v] = false;
			f = f - cost[X[k - 1]][v];
		}
	}
}

int main(){
	f = 0;
	cin >> n >> M;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cin >> cost[i][j];
		}
	}
	
	for (int v = 1; v <= n; v++){
		visited[v] = false;
	}
	X[1] = 1;
	visited[1] = true;
	Try(2);
	
	cout<<ans;
	return 0;
}
//4 20
//0 2 3 6
//1 0 4 8
//5 6 0 7
//4 9 2 0
//4
