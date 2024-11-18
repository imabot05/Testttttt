#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, X[10], res;
bool used[10];
int cnt = 0;

bool check(){
	int t = X[1] * 100 + X[2] * 10 + X[3] - X[7] * 100 - 62 + X[4] * 1000 + X[5] * 100 + X[6] * 10 + X[3];
	return t == n;
}

void init(){
	memset(X, 0, sizeof(X));
	memset(used, false, sizeof(used));
}

void Try(int i){
	if (i == 8){
		if (check()) cnt++;
		return; 
	}
	for (int j = 1; j <= 9; j++){
		if (!used[j]){
			X[i] = j;
			used[j] = true;
			Try(i + 1);
			used[j] = false;
		}
	}
}

int main(){
	cin >> n;
	Try(1);
	cout << cnt;
	return 0;
}
/*
2000
28
*/
