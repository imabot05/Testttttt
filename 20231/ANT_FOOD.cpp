#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int n, m;
vector<vector<int>> board;
vector<vector<int>> dp;
int res;

void inp(){
	cin >> m >> n;
	board.assign(m ,vector<int>(n));
	dp.assign(m, vector<int>(n));
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			cin >> board[i][j];
		}
	}
}

int main(){
	inp();
	for (int i = 0; i < m; i++){
		dp[i][0] = board[i][0];
	}
	for (int j = 1; j < n; j++){
		for (int i = 0; i < m; i++){
			int a1 = dp[(i - 1 + n) % n][j - 1] + board[i][j];
			int a2 = dp[i][j - 1] + board[i][j];
			int a3 = dp[(i + 1 + n) % n][j - 1] + board[i][j];
			dp[i][j] = max(a1, max(a2, a3));
		}
	}
	for (int i = 0; i < m; i++){
		res = max(res, dp[i][n - 1]);
	}
	
	cout << res;
	return 0;
}
/*
ANT_FOOD
4 4
1 3 1 5
2 2 4 1
5 0 2 3
0 6 1 2
17
*/
