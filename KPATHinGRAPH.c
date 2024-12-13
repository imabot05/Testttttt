#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

const int MAXN = 101;

int n, steps, m, cnt = 0;
int a[MAXN][MAXN];
int X[MAXN];

void inp(){
	scanf("%d %d", &n, &steps);
	scanf("%d", &m);
	for (int i = 0; i < m ; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		a[u][v] = 1;
		a[v][u] = 1;
	}
}

bool check(int v, int k){
	if (k == 1) return true;
	for (int i = 1; i <= k - 1; i++){
		if (X[i] == v) return false;
	}
	if (a[X[k - 1]][v] == 1) return true;
	return false;
}

void printSolution(){
	cnt += 1;
	for (int k = 1; k <= steps; k++)
		printf("%d ", X[k]);
	printf("\n");
}

void Try(int k){
	for (int v = 1; v <= n; v++){
		if (check(v, k)){
			X[k] = v;
			if (k == steps) printSolution();
			else Try(k + 1);
		}
	}
}

int main(){
	inp();
	Try(1);
	printf("%d ", cnt);
	return 0;
}
