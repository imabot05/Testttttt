#include<bits/stdc++.h>
using namespace std;

const int MAXN = 101;

int n, steps, m;
int a[MAXN][MAXN];
int X[MAXN];
int cnt;

bool check(int v, int k){
	if (k == 1) return true;
	for (int i = 1; i < k; i++){
		if (X[i] == v) return false;
	}
	if (a[v][X[k - 1]] == 1) return true;
	return false;
}

void inp(){
	cin >> n >> steps;
	cin >> m;
	for (int i = 1; i <= m; i++){
		int x, y;
		cin >> x >> y;
		a[x][y] = 1;
		a[y][x] = 1;
	}
}

void printSolution(){
	cnt += 1;
	for(int i=1; i<=n; i++) {
		cout<<X[i]<<" ";
	}
	cout << endl;
}

void Try(int k){
	for (int v = 1; v <= n; v++){
		if (check(v, k)){
			X[k] = v;
			if (k == steps){
				printSolution();
			} else {
				Try(k + 1);
			}
		}
	}
}

int main(){
	inp();
	cnt = 0;
	steps += 1;
	Try(1);
	cout << cnt / 2;
	return 0;
}
