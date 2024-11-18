#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

const int MAXN = 1005;
const int INF = 1e9 + 7;

int n, tt, d;
int a[MAXN], t[MAXN];
int f[MAXN][MAXN];
int res = -INF;

int main(){
	cin >> n >> tt >> d;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++){
		cin >> t[i];
	}
	// f[i][j]: The largest amount of goods when considering station i and using total time j 
	for (int i = 1; i <= tt; i++){
		for (int j = 1; j <= n; j++){
			for (int k = 1; k <= d; k++){
				if (i - t[j] >= 0 && j >= k) {
					f[i][j] = max(f[i - t[j]][j - k] + a[j], f[i][j]);
					res = max(res, f[i][j]);	
				}
			} 
		}
	}
	cout<<res;
	return 0;
}
/*
6 6 2
6 8 5 10 11 6
1 2 2 3 3 2
24
*/
