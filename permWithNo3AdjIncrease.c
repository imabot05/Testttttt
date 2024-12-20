#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
const int MAXN = 101;
bool marked[MAXN];
int X[MAXN], n;
bool check(int v, int k){
	if (k <= 2) return true;
	if (X[k - 2] > X[k - 1]) return true;
	return v < X[k - 1];
}

void printSol(){
	for (int i = 1; i <= n; i++){
		printf("%d ", X[i]);
	}
	printf("\n");
}

void Try(int k){
	for (int v = 1; v <= n; v++){
		if (!marked[v] && check(v, k)){
			X[k] = v;
			marked[v] = true;
			if (k == n) printSol();
			else Try(k + 1);
			marked[v] = false;
		}
	}
}

int main(){
	scanf("%d", &n);
	Try(1);
	return 0;
}
/*
6
1 3 2 5 4 6
1 3 2 6 4 5
1 3 2 6 5 4
1 4 2 5 3 6
1 4 2 6 3 5
1 4 2 6 5 3
1 4 3 2 6 5
1 4 3 5 2 6
1 4 3 6 2 5
1 4 3 6 5 2
1 5 2 4 3 6
1 5 2 6 3 4
1 5 2 6 4 3
1 5 3 2 6 4
1 5 3 4 2 6
1 5 3 6 2 4
1 5 3 6 4 2
1 5 4 2 6 3
1 5 4 3 2 6
1 5 4 3 6 2
1 5 4 6 2 3
1 5 4 6 3 2
1 6 2 4 3 5
1 6 2 5 3 4
1 6 2 5 4 3
1 6 3 2 5 4
1 6 3 4 2 5
1 6 3 5 2 4
1 6 3 5 4 2
1 6 4 2 5 3
1 6 4 3 2 5
1 6 4 3 5 2
1 6 4 5 2 3
1 6 4 5 3 2
1 6 5 2 4 3
1 6 5 3 2 4
1 6 5 3 4 2
1 6 5 4 2 3
1 6 5 4 3 2
2 1 4 3 6 5
2 1 5 3 6 4
2 1 5 4 3 6
2 1 5 4 6 3
2 1 6 3 5 4
2 1 6 4 3 5
2 1 6 4 5 3
2 1 6 5 3 4
2 1 6 5 4 3
2 3 1 5 4 6
2 3 1 6 4 5
2 3 1 6 5 4
2 4 1 5 3 6
2 4 1 6 3 5
2 4 1 6 5 3
2 4 3 1 6 5
2 4 3 5 1 6
2 4 3 6 1 5
2 4 3 6 5 1
2 5 1 4 3 6
2 5 1 6 3 4
2 5 1 6 4 3
2 5 3 1 6 4
2 5 3 4 1 6
2 5 3 6 1 4
2 5 3 6 4 1
2 5 4 1 6 3
2 5 4 3 1 6
2 5 4 3 6 1
2 5 4 6 1 3
2 5 4 6 3 1
2 6 1 4 3 5
2 6 1 5 3 4
2 6 1 5 4 3
2 6 3 1 5 4
2 6 3 4 1 5
2 6 3 5 1 4
2 6 3 5 4 1
2 6 4 1 5 3
2 6 4 3 1 5
2 6 4 3 5 1
2 6 4 5 1 3
2 6 4 5 3 1
2 6 5 1 4 3
2 6 5 3 1 4
2 6 5 3 4 1
2 6 5 4 1 3
2 6 5 4 3 1
3 1 4 2 6 5
3 1 5 2 6 4
3 1 5 4 2 6
3 1 5 4 6 2
3 1 6 2 5 4
3 1 6 4 2 5
3 1 6 4 5 2
3 1 6 5 2 4
3 1 6 5 4 2
3 2 1 5 4 6
3 2 1 6 4 5
3 2 1 6 5 4
3 2 4 1 6 5
3 2 5 1 6 4
3 2 5 4 1 6
3 2 5 4 6 1
3 2 6 1 5 4
3 2 6 4 1 5
3 2 6 4 5 1
3 2 6 5 1 4
3 2 6 5 4 1
3 4 1 5 2 6
3 4 1 6 2 5
3 4 1 6 5 2
3 4 2 1 6 5
3 4 2 5 1 6
3 4 2 6 1 5
3 4 2 6 5 1
3 5 1 4 2 6
3 5 1 6 2 4
3 5 1 6 4 2
3 5 2 1 6 4
3 5 2 4 1 6
3 5 2 6 1 4
3 5 2 6 4 1
3 5 4 1 6 2
3 5 4 2 1 6
3 5 4 2 6 1
3 5 4 6 1 2
3 5 4 6 2 1
3 6 1 4 2 5
3 6 1 5 2 4
3 6 1 5 4 2
3 6 2 1 5 4
3 6 2 4 1 5
3 6 2 5 1 4
3 6 2 5 4 1
3 6 4 1 5 2
3 6 4 2 1 5
3 6 4 2 5 1
3 6 4 5 1 2
3 6 4 5 2 1
3 6 5 1 4 2
3 6 5 2 1 4
3 6 5 2 4 1
3 6 5 4 1 2
3 6 5 4 2 1
4 1 3 2 6 5
4 1 5 2 6 3
4 1 5 3 2 6
4 1 5 3 6 2
4 1 6 2 5 3
4 1 6 3 2 5
4 1 6 3 5 2
4 1 6 5 2 3
4 1 6 5 3 2
4 2 1 5 3 6
4 2 1 6 3 5
4 2 1 6 5 3
4 2 3 1 6 5
4 2 5 1 6 3
4 2 5 3 1 6
4 2 5 3 6 1
4 2 6 1 5 3
4 2 6 3 1 5
4 2 6 3 5 1
4 2 6 5 1 3
4 2 6 5 3 1
4 3 1 5 2 6
4 3 1 6 2 5
4 3 1 6 5 2
4 3 2 1 6 5
4 3 2 5 1 6
4 3 2 6 1 5
4 3 2 6 5 1
4 3 5 1 6 2
4 3 5 2 1 6
4 3 5 2 6 1
4 3 6 1 5 2
4 3 6 2 1 5
4 3 6 2 5 1
4 3 6 5 1 2
4 3 6 5 2 1
4 5 1 3 2 6
4 5 1 6 2 3
4 5 1 6 3 2
4 5 2 1 6 3
4 5 2 3 1 6
4 5 2 6 1 3
4 5 2 6 3 1
4 5 3 1 6 2
4 5 3 2 1 6
4 5 3 2 6 1
4 5 3 6 1 2
4 5 3 6 2 1
4 6 1 3 2 5
4 6 1 5 2 3
4 6 1 5 3 2
4 6 2 1 5 3
4 6 2 3 1 5
4 6 2 5 1 3
4 6 2 5 3 1
4 6 3 1 5 2
4 6 3 2 1 5
4 6 3 2 5 1
4 6 3 5 1 2
4 6 3 5 2 1
4 6 5 1 3 2
4 6 5 2 1 3
4 6 5 2 3 1
4 6 5 3 1 2
4 6 5 3 2 1
5 1 3 2 6 4
5 1 4 2 6 3
5 1 4 3 2 6
5 1 4 3 6 2
5 1 6 2 4 3
5 1 6 3 2 4
5 1 6 3 4 2
5 1 6 4 2 3
5 1 6 4 3 2
5 2 1 4 3 6
5 2 1 6 3 4
5 2 1 6 4 3
5 2 3 1 6 4
5 2 4 1 6 3
5 2 4 3 1 6
5 2 4 3 6 1
5 2 6 1 4 3
5 2 6 3 1 4
5 2 6 3 4 1
5 2 6 4 1 3
5 2 6 4 3 1
5 3 1 4 2 6
5 3 1 6 2 4
5 3 1 6 4 2
5 3 2 1 6 4
5 3 2 4 1 6
5 3 2 6 1 4
5 3 2 6 4 1
5 3 4 1 6 2
5 3 4 2 1 6
5 3 4 2 6 1
5 3 6 1 4 2
5 3 6 2 1 4
5 3 6 2 4 1
5 3 6 4 1 2
5 3 6 4 2 1
5 4 1 3 2 6
5 4 1 6 2 3
5 4 1 6 3 2
5 4 2 1 6 3
5 4 2 3 1 6
5 4 2 6 1 3
5 4 2 6 3 1
5 4 3 1 6 2
5 4 3 2 1 6
5 4 3 2 6 1
5 4 3 6 1 2
5 4 3 6 2 1
5 4 6 1 3 2
5 4 6 2 1 3
5 4 6 2 3 1
5 4 6 3 1 2
5 4 6 3 2 1
5 6 1 3 2 4
5 6 1 4 2 3
5 6 1 4 3 2
5 6 2 1 4 3
5 6 2 3 1 4
5 6 2 4 1 3
5 6 2 4 3 1
5 6 3 1 4 2
5 6 3 2 1 4
5 6 3 2 4 1
5 6 3 4 1 2
5 6 3 4 2 1
5 6 4 1 3 2
5 6 4 2 1 3
5 6 4 2 3 1
5 6 4 3 1 2
5 6 4 3 2 1
6 1 3 2 5 4
6 1 4 2 5 3
6 1 4 3 2 5
6 1 4 3 5 2
6 1 5 2 4 3
6 1 5 3 2 4
6 1 5 3 4 2
6 1 5 4 2 3
6 1 5 4 3 2
6 2 1 4 3 5
6 2 1 5 3 4
6 2 1 5 4 3
6 2 3 1 5 4
6 2 4 1 5 3
6 2 4 3 1 5
6 2 4 3 5 1
6 2 5 1 4 3
6 2 5 3 1 4
6 2 5 3 4 1
6 2 5 4 1 3
6 2 5 4 3 1
6 3 1 4 2 5
6 3 1 5 2 4
6 3 1 5 4 2
6 3 2 1 5 4
6 3 2 4 1 5
6 3 2 5 1 4
6 3 2 5 4 1
6 3 4 1 5 2
6 3 4 2 1 5
6 3 4 2 5 1
6 3 5 1 4 2
6 3 5 2 1 4
6 3 5 2 4 1
6 3 5 4 1 2
6 3 5 4 2 1
6 4 1 3 2 5
6 4 1 5 2 3
6 4 1 5 3 2
6 4 2 1 5 3
6 4 2 3 1 5
6 4 2 5 1 3
6 4 2 5 3 1
6 4 3 1 5 2
6 4 3 2 1 5
6 4 3 2 5 1
6 4 3 5 1 2
6 4 3 5 2 1
6 4 5 1 3 2
6 4 5 2 1 3
6 4 5 2 3 1
6 4 5 3 1 2
6 4 5 3 2 1
6 5 1 3 2 4
6 5 1 4 2 3
6 5 1 4 3 2
6 5 2 1 4 3
6 5 2 3 1 4
6 5 2 4 1 3
6 5 2 4 3 1
6 5 3 1 4 2
6 5 3 2 1 4
6 5 3 2 4 1
6 5 3 4 1 2
6 5 3 4 2 1
6 5 4 1 3 2
6 5 4 2 1 3
6 5 4 2 3 1
6 5 4 3 1 2
6 5 4 3 2 1
*/
