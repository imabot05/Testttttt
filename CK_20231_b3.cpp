#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

const int INF = 1e9 + 7;
const int MAXN = 25;
int n;
int X[MAXN];
int load[2];
int diff = INF;

int min(int u, int v){
	return (u < v) ? u : v;
}

void solution(){
	diff = min(diff, abs(load[1] - load[0]));
}

void Try(int k){
	for (int i = 0; i <= 1; i++){
		load[i] += X[k];
		if (k == n - 1) solution();
		else Try(k + 1);
		load[i] -= X[k];
	}
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &X[i]);
	}
	Try(0);
	printf("%d", diff);
	return 0;
}

