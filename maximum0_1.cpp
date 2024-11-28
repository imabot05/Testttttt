#include<iostream>
#include<vector>
#include<queue>

using namespace std;
const int MAXN = 1001;

int main(){
	int t;
	cin >> t;
	while (t--){
		int m, n;
		cin >> m >> n;
		int M[MAXN][MAXN];
		for (int i = 0; i < m; i++){
			for (int j = 0; j < m; j++){
				cin >> M[i][j];
			}
		}
		
		for (int i = 1; i < m; i++){
			for (int j = 0; j < n; j++){
				if (M[i][j] == 1) M[i][j] += M[i - 1][j];
			}
		}
		
		int maxx = 0;
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				int minn = M[i][j];
				for (int l = j; l >= 0; l--){
					if (M[i][l] != 0){
						if (minn > M[i][l]) minn = M[i][l];
						maxx = max(maxx, minn * (j - l + 1));	
					} else break;
				}
			}
		}
		cout << maxx << endl;
	}
}
/*
1
4 4 
1 0 0 0
1 1 1 0
0 1 1 1
0 1 1 1
6
*/
