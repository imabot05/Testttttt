#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

const int INF = 1e9 + 7;

int n, b;
pair<int, int> a[31];
int dp[31][1000001];

int main(){
	cin >> n >> b;
	for (int i = 1; i <= n; i++){
		cin >> a[i].first >> a[i].second;
	}
	for (int i = 0; i <= b; i++){
		dp[0][i] = 0;
	}
	for (int i = 1; i <= n; i++){
		for (int j = 0; j <= b; j++){
			dp[i][j] = dp[i - 1][j];
			if (j >= a[i].first){
				dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i].first] + a[i].second);
			} 
		}
	}
	cout<<dp[n][b];
	return 0;
}
/*
2 6
4 2
3 2
2
*/
