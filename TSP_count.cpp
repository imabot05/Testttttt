#include<iostream>
#include<vector>
#include<algorithm>

const int MAXN = 15;
int n, m;
int matrix[MAXN][MAXN];
int X[MAXN];
bool visited[MAXN];
int sum = 0;
int count = 0;

void inp(){
	std::cin>>n>>m;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			std::cin>>matrix[i][j];
		}
	}
}

void Try(int i){
	for (int j = 2; j <= n; j++){
		if (matrix[X[i - 1]][j] != 0 && !visited[j]){
			X[i] = j;
			visited[j] = true;
			sum += matrix[X[i - 1]][j];
			if (sum <= m){
				if (i == n){
					if (sum + matrix[X[i]][1] <= m){
						count++;
					} 
				} else {
					Try(i + 1);
				}
			}
			visited[j] = false;
			sum -= matrix[X[i - 1]][j];
		}
	}
}

int main(){
	inp();
	X[1] = 1;
	visited[1] = true;
	Try(2);
	std::cout<<count;
	return 0;
}
