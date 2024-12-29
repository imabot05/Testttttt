#include<bits/stdc++.h>
using namespace std;

const int MAXN = 101;

int block[MAXN][MAXN][MAXN];
int T, N;
int L, W, H;

void init(){
	for (int i = 1; i <= L; i++){
		for (int j = 1; j <= W; j++){
			for (int k = 1; k <= H; k++){
				block[i][j][k] = i * j * k;
			}
		}
	}
}
// length, width, height
int main(){
	cin >> T;
	while (T--){
		cin >> L >> W >> H;
		cin >> N;
		init();
		int u, v, w;
		for (int i = 1; i <= N; i++){
			cin >> u >> v >> w;
			block[u][v][w] = 0;
			block[v][u][w] = 0;
			block[u][w][v] = 0;
			block[v][w][u] = 0;
			block[w][u][v] = 0;
			block[w][v][u] = 0;
		}
		for (int i = 1; i <= L; i++){
			for (int j = 1; j <= W; j++){
				for (int k = 1; k <= H; k++){
					int minWaste = block[i][j][k];
					for (int m = 1; m <= i; m++){
						minWaste = min(minWaste, block[i - m][j][k] + block[m][j][k]);
					}
					for (int m = 1; m <= j; m++){
						minWaste = min(minWaste, block[i][j - m][k] + block[i][m][k]);
					}
					for (int m = 1; m <= k; m++){
						minWaste = min(minWaste, block[i][j][k - m] + block[i][j][m]);
					}
					block[i][j][k] = minWaste;
				}
			}
		}
		cout << block[L][W][H] << endl;
	}
	return 0;
}


