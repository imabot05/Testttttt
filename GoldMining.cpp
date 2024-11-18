#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

const int MAXN = 1e5 + 5;
const int INF = 1e9 + 7;

int n, L1, L2;
int a[MAXN], dp[MAXN];
int res = -INF;

int main(){
	cin >> n >> L1 >> L2;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= L1; i++){
		dp[i] = a[i];
	}
	for (int i = L1 + 1; i <= n; i++){
		for (int j = L2; j >= L1; j--){
			if (i >= j) {
				dp[i] = max(dp[i], dp[i - j] + a[i]);	
			}
			else {
				dp[i] = a[i];
			}
			res = max(res, dp[i]);
		}
	}
	cout<<res;
	return 0;
}
/*
6 2 3
3 5 9 6 7 4
19
*/
