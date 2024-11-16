#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAXN = 23;
const int INF = 1e9 + 7;

bool visited[MAXN];
int c[MAXN][MAXN], cmin = INF, cost = 0, d[12], D, K, N, m = 1e9 + 7;
vector<int> route;

bool check(int v, int k){
	if (visited[v]) return false;
	if (v <= N && K == 0) return false;
	if (v > N && !visited[v - N]) return false;
	if (cost + (2 * N + 1 - k) * cmin > m) 
		return false;
	for (int i = 1; i <= N; i++){
		if (d[i] != -1 && d[i] + c[route.back()][v] > D)
		return false;
	}
	return true;
}

void Try(int k){
	if (k == 2 * N + 1){
		m = min(m, cost + c[route.back()][0]);
        return;
	}
	for (int i = 1; i <= 2 * N; i++){
		if (check(i, k)){
			int tmp = c[route.back()][i];
			cost += tmp;
			
			if (i <= N){
				K--;
				d[i] = 0;
			} else {
				K++;
				d[i - N] = -1;
			}
			route.push_back(i);
			visited[i] = true;
			for (int i = 1; i <= N; i++){
				if (d[i] != -1) d[i] += tmp;
			}
			Try(k + 1);
			cost -= tmp;
			if (i <= N){
				K++;
				d[i] = -1;
			} else {
				K--;
				d[i - N] = tmp;
			}
			route.pop_back();
            visited[i] = false;
            for (int i = 1; i <= N; i++){
            	if (d[i] != -1) d[i] -= tmp;	
			}
		}
	}	
}

int main(){
	cin >> N >> K >> D;
	memset(d, -1, sizeof(d));
    for (int i = 0; i <= 2 * N; i++){
    	for (int j = 0; j <= 2 * N; j++){
            cin >> c[i][j];
            if (i != j) cmin = min(cmin, c[i][j]);
        }	
	}
    route.push_back(0);
    visited[0] = true;
    Try(1);
    cout<<m;
    return 0;
}
