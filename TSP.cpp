#include<iostream>
#include<vector>
#include<cstring>
#include<climits>

using namespace std;

const int MAXN = 1005;

int n, cost[MAXN][MAXN];

int cmin = INT_MAX, best = INT_MAX;
int curr;
int mark[MAXN];
int X[MAXN];

void inp(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cin >> cost[i][j];
			if (cost[i][j]) cmin = min(cmin, cost[i][j]);
		}
	}
}

void Try(int k){
	if (curr + cmin * (n - k + 1) >= best){
		return;
	}
	
	for (int i = 2; i <= n; i++){
		if (!mark[i]){
			mark[i] = 1;
			X[k] = i;
			curr += cost[X[k - 1]][i];
			if (k == n){
				if (curr + cost[X[n]][1] < best){
					best = curr + cost[X[n]][1];
				}
			} else {
				Try(k + 1);
			}
			mark[i] = 0;
			curr -= cost[X[k - 1]][i];
		}
	}
}

int main(){
	inp();
	X[1] = 1;
	Try(2);
	cout << best;
	return 0;
}
/*
4
0 2 1 3
4 0 1 2
2 1 0 3
3 4 2 0
7
*/
