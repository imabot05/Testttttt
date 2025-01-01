#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAXN = 31;

int n, k, S, cnt = 0;
int arr[MAXN];

void inp(){
	cin >> n >> k >> S;
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
}

void Try(int i, int currSum, int numChoose){
	if (i == n){
		if (currSum == S && numChoose == k){
			cnt += 1;
		}
		return;
	}
	if (currSum + arr[i] <= S){
		Try(i + 1, currSum + arr[i], numChoose + 1);
	}
	Try(i + 1, currSum, numChoose);
}

int main(){
	inp();
	Try(0, 0, 0);
	cout << cnt;
	return 0;
}
