#include<iostream>
#include<algorithm>
#include<cstring>
#include<climits>

using namespace std;

const int MAXN = 13;
int H, W, n, res = 0;
int h[MAXN], w[MAXN];
bool used[31][31];

bool check(int i, int j, int k){
	for (int i1 = i; i1 <= i + w[k] - 1; i1++){
		for (int j1 = j; j1 <= j + h[k] - 1; j1++){
			if (used[i1][j1]) return false;
		}
	}
	return true;
}

void doMark(int i, int j, int k, int s){
	for (int i1 = i; i1 < i + w[k]; i1++){
		for (int j1 = j; j1 < j + h[k]; j1++){
			used[i1][j1] = s;
		}
	}
}

void Try(int k){
	if (res == 1){
		return;
	}
	for (int i = 0; i <= W - w[k]; i++){
		for (int j = 0; j <= H - h[k]; j++){
			if (check(i, j, k)){
				doMark(i, j, k, 1);
				if (k == n){
					res = 1;
				} else {
					Try(k + 1);
				}
				doMark(i, j, k, 0);
			}
		}
	}
}

int main(){
	cin >> H >> W;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> h[i] >> w[i];
	}
	Try(1);
	cout << res;
	return 0;
}
