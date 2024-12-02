#include<stdio.h>
#include<stdbool.h>
#include<cstring>
#include<stdlib.h>

const int MAXN = 1005;

int X[MAXN], Y[MAXN], mem[MAXN][MAXN];
int n, m;

void inp(){
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++){
		scanf("%d", &X[i]);
	}
	for (int i = 0; i < m; i++){
		scanf("%d", &Y[i]);
	}
}

int max(int u, int v){
	return u > v ? u : v;
}

int LCS(int i, int j){
	printf("%d %d\n", i, j);
	if (i == -1 || j == -1) return 0;
	if (mem[i][j] != -1) return mem[i][j];
	if (X[i] == Y[j]){
		mem[i][j] = LCS(i - 1, j - 1) + 1;
	} else {
		mem[i][j] = max(LCS(i - 1, j), LCS(i, j - 1));
	}
	return mem[i][j];
}

void Trace(int i, int j) {
    if (i < 0 || j < 0) return;  
    if (X[i] == Y[j]) {
        Trace(i - 1, j - 1);  
        printf("%d ", X[i]);  
    } else if (j > 0 && mem[i][j] == mem[i][j - 1]) {
        Trace(i, j - 1);  
    } else if (i > 0 && mem[i][j] == mem[i - 1][j]) {
        Trace(i - 1, j);  
    }
}

int main(){
	inp();
	memset(mem, -1, sizeof(mem));
	int result = LCS(n - 1, m - 1);
	printf("%d\n", result);
	Trace(n - 1, m - 1);
	return 0;
}

