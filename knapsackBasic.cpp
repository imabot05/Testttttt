#include<iostream>
#include<vector>
#include<cstring>
#include<climits>

using namespace std;

int n, W;
int w[101], v[101];
int dp[101][100001];

int main(){
	cin >> n >> W;
	for (int i = 1; i <= n; i++){
		cin >> w[i] >> v[i];
	}
	
	for (int i = 1; i <= n; i++) dp[i][0] = 0;
	for (int i = 0; i <= W; i++)
		dp[0][i] = 0;
		
	for (int i = 1; i <= n; i++){
		for (int j = 0; j <= W; j++){
			if (j < w[i]){
				dp[i][j] = dp[i - 1][j];
			}
			else if (j - w[i] >= 0) {
				dp[i][j] = max(dp[i - 1][j - w[i]] + v[i], dp[i - 1][j]);
			}
		}
	}
	
	cout << dp[n][W];
	return 0;
}
/*
3 4
1 2
3 4
5 6
*/
