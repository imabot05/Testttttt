#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

const int MAXN = 16;
const int INF = 1e9 + 7;

int n;
int cost[MAXN][MAXN];
int costMin =  INF;
int x[MAXN];
bool visited[MAXN];
int f, fopt;

void inp(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cin >> cost[i][j];
			if (cost[i][j] > 0 && cost[i][j] < costMin){
				costMin = cost[i][j];
			}
		}
	}
}

void Try(int k){
	for (int v = 1; v <= n; v++){
		if (!visited[v]){
			x[k] = v;
			visited[v] = true;
			f += cost[x[k -1]][v];
			if (k == n){
				if (f + cost[x[n]][1] < fopt){
					fopt = f + cost[x[n]][1];
				}
			} else {
				if (f + (n + 1 - k) * costMin < fopt){
					Try(k + 1);
				}
			}
			f -= cost[x[k - 1]][v];
			visited[v] = false;
		}
	}
}

int main(){
	inp();
	f = 0;
	fopt = INF;
	x[1] = 1;
	visited[1] = true;
	Try(2);
	cout << fopt << endl;
	return 0;
}
/*
4
0 1 2 9
1 0 4 5
2 4 0 3
9 5 3 0
11
*/
