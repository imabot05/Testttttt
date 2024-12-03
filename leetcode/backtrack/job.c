#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

const int MAXN = 13;
const int INF = 1e9 + 7;

int job[MAXN]; // job[i] = j is job i is assigned to worker j
int n, load[MAXN], k, res;
int sum[MAXN]; // sum[i]: Sum of load work of worker i 

int min(int u, int v){
	return u < v ? u : v;	
}

int max(int u, int v){
	return u > v ? u : v;
}

void inp(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &load[i]);
	}
	scanf("%d", &k);
	res = INF;
}

void solution(){
	int tmp = -INF;
	for (int i = 1; i <= k; i++){
		tmp = max(sum[i], tmp);
	}
	res = min(res, tmp);
}
void Try(int i){
	if (i == n){
		solution();
		return;
	}
	for (int j = 1; j <= k; j++){
		if (job[i] == 0){
			job[i] = j;
			sum[j] += load[i];
			Try(i + 1);
			job[i] = 0;
			sum[j] -= load[i];	
		}
	}
}

int main(){
	inp();
	Try(0);
	printf("%d", res);
	return 0;
}
/*
5
1 2 4 7 8
2
11
*/

