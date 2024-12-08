#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int n, k, m, a[101], prevCheck;
int currSum = 0, cnt = 0;
bool used[101];

void inp(){
	cin >> n >> k >> m;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	memset(used, false, sizeof(used));
}

void Try(int i, int currSum){
	if (i == k){
		if (currSum == m) cnt += 1;
		return;
	}
	for (int j = prevCheck; j < n; j++){
		if (currSum < m){
			if (!used[j]){
				prevCheck = j;
				used[j] = 1;
				Try(i + 1, currSum + a[j]);
				used[j] = 0;
				prevCheck = 0;
			}
		}
	}
}

int main(){
	inp();
	Try(0, 0);
	cout << cnt;
	return 0;
}

/*
6 3 15
4 7 2 6 4 5
4
*/
