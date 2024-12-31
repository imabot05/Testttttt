#include<iostream>
#include<vector>
#include<algorithm>

const int MAXN = 17;
const int INF = 1e9 + 7;
using namespace std;

int n, K;
int cost[MAXN];
int X[MAXN], sum[MAXN];
int A[MAXN][MAXN];
int res = INF;

void inp(){
	cin >> n >> K;
	for (int i = 1; i <= n; i++){
		cin >> cost[i];
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cin >> A[i][j];
		}
	}
}

bool check(int period, int course){
	for (int i = 1; i < course; i++){
		if (A[i][course] == 1 && X[i] >= period) return false;
		if (A[course][i] == 1 && X[i] <= period) return false;  
	}
	return true;
}

void solution(){
	int tmp_max = -1;
	for (int i = 1; i <= K; i++){
		tmp_max = max(sum[i], tmp_max);
	}
	res = min(tmp_max, res);
}

void Try(int course){
	for (int period = 1; period <= K; period++){
		if (check(period, course)){
			X[course] = period;
			sum[period] += cost[course];
			if (course == n){
				solution();
			} else {
				Try(course + 1);
			}
			sum[period] -= cost[course];
		}
	}
}

int main(){
	inp();
	Try(1);
	cout << res << endl;
	return 0;
}
