#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

const int MAXN = 21;
int n, k, sum;
int X[MAXN];

void solution(){
	if (sum == k){
		for (int i = 1; i <= n; i++){
			printf("%d ", X[i]);
		}
		printf("\n");
	}
}

void Try(int i){
	if (sum > k) return;
	if (sum + (n - i + 1) < k) return;
	for (int j = 0; j <= 1; j++){
		X[i] = j;
		sum += X[i];
		if (i == n) solution();
		else Try(i + 1);
		sum -= X[i];
	}
}

int main(){
	scanf("%d %d", &n, &k);
	Try(1);
	return 0;
}
/*
6 3
0 0 0 1 1 1
0 0 1 0 1 1
0 0 1 1 0 1
0 0 1 1 1 0
0 1 0 0 1 1
0 1 0 1 0 1
0 1 0 1 1 0
0 1 1 0 0 1
0 1 1 0 1 0
0 1 1 1 0 0
1 0 0 0 1 1
1 0 0 1 0 1
1 0 0 1 1 0
1 0 1 0 0 1
1 0 1 0 1 0
1 0 1 1 0 0
1 1 0 0 0 1
1 1 0 0 1 0
1 1 0 1 0 0
1 1 1 0 0 0
*/
