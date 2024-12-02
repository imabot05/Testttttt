#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

const int MOD = 1e9 + 7;
const int MAXN = 101;
int result = 0;
int n, M, A[MAXN];

void Try(int k, int sum){
	if (k == n){
		if (sum == M){
			result = (result + 1) % MOD;
		}
		return;
	}	
	for (int v = 0; v <= (M - sum) / A[k]; v++){
		Try(k + 1, sum + A[k] * v);
	}
}

int main(){
	scanf("%d %d", &n, &M);
	for (int i = 0; i < n; i++){
		scanf("%d", &A[i]);
	}
	
	Try(0, 0);
	printf("%d", result);
	return 0;
}
