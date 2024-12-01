#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

const int MAXN = 100;

bool check(int matrix[MAXN][MAXN], int n){
	for (int col = 0; col < n; col++){
		int queenCount = 0;
		for (int row = 0; row < n; row++){
			if (matrix[row][col] == 1) queenCount += matrix[row][col];
			if (queenCount > 1) return false;
		}
	}
	for (int row = 0; row < n; row++){
		for (int col = 0; col < n; col++){
			if (matrix[row][col] == 1){
				for (int i = 1; i < n; i++){
					if ((row + i < n && col + i < n && matrix[row + i][col + i] == 1) ||
						(row - i >= 0 && col - i >= 0 && matrix[row - i][col - i] == 1) ||
						(row - i >= 0 && col + i < n && matrix[row - i][col + i] == 1) ||
						(row + i < n && col - i >= 0 && matrix[row + i][col - i] == 1)
					){
						return false;
					}
				}
			}
		}
	}
	return true;
}

int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		int n;
		scanf("%d", &n);
		int matrix[MAXN][MAXN];
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				scanf("%d", &matrix[i][j]);
			}
		}
		
		if (check(matrix, n)){
			printf("1\n");
		} else {
			printf("0\n");
		}
	}
	return 0;
}
/*
2
4
0 1 0 0
0 0 0 1
1 0 0 0
0 0 1 0
1
4
0 1 0 0
0 0 0 0
1 0 0 1
0 0 1 0
0
*/

