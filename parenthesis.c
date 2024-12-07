#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int n, res, X[22];

void solution(){
	res += 1;
	for (int i = 1; i <= n; i++){
		if (X[i] == 0) printf("(");
		else printf(")");
	}
	printf("\n");
}

void Try(int i, int open, int close, int diff){
	if (i == n + 1 && diff == 0){
		solution();
		return;
	}
	if (open > n / 2 || close > n / 2){
		return;
	}
	if (diff < 0) return;
	for (int j = 0; j <= 1; j++){
		X[i] = j;
		if (j == 0) Try(i + 1, open + 1, close, diff + 1);
		else Try(i + 1, open, close + 1, diff - 1);
	}
}

int main(){
	scanf("%d", &n);
	res = 0;
	Try(1, 0, 0 ,0);
	printf("%d", res);
	return 0;
}
/*
4
(())
()()
2
*/
