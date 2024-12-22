#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

int n, sum, cnt = 0, X[6];
bool used[10];
// C, T, D, L, G, U
bool check(){
	if (X[0] == 0 || X[1] == 0) return false;
	if (X[0] * 100000 + X[1] * 10000 + X[2] * 1000 + X[3] * 100 + X[4] * 10 + X[1]
		+ X[1] * 1000 + X[1] * 100 + X[5] * 10 + X[2] == sum)
		return true;
	return false;
}

void Try(int i){
	for (int j = 0; j <= 9; j++){
		if (i == 0 || i == 1){
			if (j == 0) continue;
		}
		if (!used[j]){
			X[i] = j;
			used[j] = 1;
			if (i == 5){
				if (check()) {
					cnt += 1;
					for (int k = 0; k <= 5; k++) cout << X[k] << " ";
					cout << endl;	
				}
			} else {
				Try(i + 1);
			}
			used[j] = 0;
		}
	}
}

int main(){
	cin >> sum;
	Try(0);
	cout << cnt;
	return 0;
}
/*
300079
2 9 0 1 3 4
2 9 0 1 4 3
2
*/
