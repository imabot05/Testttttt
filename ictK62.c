#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

const int MAXN = 11;
int cnt = 0, N;
bool mark[MAXN];
int x[MAXN];

bool check(int v, int k){
	if (mark[v] == true) return false;
	if (k < 6) return true;
	if (x[0] * 100 + x[1] * 10 + x[2] - x[3] * 100 - 62 + x[4] * 1000 + x[5] * 100 + v * 10 + x[2] == N) {
		return true;
	} 
	return false;
}

void solution(){
	cnt += 1;	
}

void Try(int k){
	for (int v = 1; v <= 9; v++){
		if (check(v, k)){
			x[k] = v;
			mark[v] = true;
			if (k == 6) solution();
			else Try(k + 1);
			mark[v] = false;
		}
	}
}

int main(int argc, const char **argv){
	scanf("%d", &N);
	Try(0);
	printf("%d\n", cnt);
	return 0;
}
/*
10200
12
*/
