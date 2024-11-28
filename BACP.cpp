#include<iostream>
#include<vector>
#include<cstring>
#include<climits>
#include<algorithm>

using namespace std;

const int MAXN = 21;
const int INF = 1e9 + 7;

int N, M, c[MAXN];
int load[MAXN], A[MAXN][MAXN];
int X[MAXN], res = INF;

bool check(int k, int i){
	if (X[k] != 0) return false;
	for (int j = 1; j <= N; j++){
		if (A[k][j] == 1 && i <= X[j]) return false;
	}
	return true;
}

void solution(){
	int value = *max_element(load + 1, load + N + 1);
	res = min(res, value);
}

void Try(int k){
	for (int i = 1; i <= M; i++){
		if (check(k, i)){
			X[k] = i;
			load[i] += c[k];
			if (k == N) solution();
			else Try(k + 1);
			X[k] = 0;
			load[i] -= c[k];
		}
	}
}

int main(){
	cin >> N >> M;
	for (int i = 1; i <= N; i++){
		cin >> c[i];
		X[i] = 0;
	}
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			cin >> A[i][j];
		}
	}
	Try(1);
	cout<<res<<"\n";
	return 0;
}
/*
6 2
4 4 4 4 2 4
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 1 0 0 0
0 0 1 0 0 0
1 0 0 0 0 0
12
*/
