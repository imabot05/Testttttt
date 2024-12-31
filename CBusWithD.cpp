#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

const int MAXN = 25;
const int INF = 1e9 + 7;

int n, m, D;
int x[MAXN], sumDist[MAXN];
int result = INF, costMin = INF;
int numPass = 0;
int costMatrix[MAXN][MAXN];
bool visited[MAXN];
int distPassenger[MAXN];

void inp(){
	cin >> n >> m >> D;
	memset(visited, false, sizeof(visited));
	for (int i = 1; i <= n; i++){
		distPassenger[i] = -1;
	}
	
	for (int i = 0; i <= 2 * n; i++){
		for (int j = 0; j <= 2 * n; j++){
			cin >> costMatrix[i][j];
			if (costMatrix[i][j] > 0 && costMatrix[i][j] < costMin){
				costMin = costMatrix[i][j];
			}
		}
	}
	
	x[0] = 0;
	sumDist[0] = 0;
}

void Try(int k){
	if (k == 2 * n + 1){
		int total = sumDist[k - 1] + costMatrix[x[k - 1]][0];
		if (total < result) result = total;
		return;
	}
	
	int currPos = x[k - 1];
	for (int v = 1; v <= 2 * n; v++){
		if (costMatrix[currPos][v] == 0) continue;
		if (!visited[v]){
			int backupDist[MAXN];
			for (int i = 1; i <= n; i++){
				backupDist[i] = distPassenger[i];
			}
			
			int costMove = costMatrix[currPos][v];
			for (int i = 1; i <= n; i++){
				if (distPassenger[i] >= 0){
					distPassenger[i] += costMove;
				}
			}
			
			sumDist[k] = sumDist[k - 1] + costMove;
			if (sumDist[k] + costMin * (2 *n + 1 - k) >= result){
				for (int i = 1; i <= n; i++){
					distPassenger[i] = backupDist[i];
				}
				continue;
			}
			
			if (v <= n){
				if (numPass < m){
					x[k] = v;
					visited[v] = true;
					numPass += 1;
					distPassenger[v] = 0;
					Try(k + 1);
					visited[v] = false;
					numPass -= 1;
					distPassenger[v] = -1;
				}
			} else {
				int iPassenger = v - n;
				if (visited[iPassenger] && distPassenger[iPassenger] >= D){
					x[k] = v;
					visited[v] = true;
					numPass -= 1;
					
					Try(k + 1);
					
					visited[v] = false;
					numPass += 1;
				}
			}
			for (int i = 1; i <= n; i++){
				distPassenger[i] = backupDist[i];
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	inp();
	Try(1);
	if (result == INF){
		cout << "-1" << endl;
	} else cout << result << endl;
	return 0;
}




















