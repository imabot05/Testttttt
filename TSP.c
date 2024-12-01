#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

const int MAXN = 15;

int N, M;
int matrix[MAXN][MAXN];
bool visited[MAXN];
int permutation[MAXN];
int count = 0;

void calculateTours(int currentCity, int length){
	if (currentCity == N){
		if (length + matrix[permutation[N - 1]][0] <= M){
			count += 1;
		}
		return;
	}
	
	for (int nextCity = 1; nextCity < N; nextCity++){
		if (!visited[nextCity]){
			visited[nextCity] = 1;
			permutation[currentCity] = nextCity;
			int newLength = length + matrix[permutation[currentCity - 1]][nextCity];
			if (newLength <= M){
				calculateTours(currentCity + 1, newLength);
			}
			visited[nextCity] = 0;
		}
	}
}

int main(){
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			scanf("%d", &matrix[i][j]);
		}
	}
	
	visited[0] = true;
	permutation[0] = 0;
	calculateTours(1, 0);
	printf("%d\n", count);
	return 0;
}
/*
4 10
0 1 2 6
1 0 5 4
2 5 0 3
6 4 3 0
2
*/
