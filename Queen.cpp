#include<iostream>
#include<vector>
#include<cstring>
#include<climits>

using namespace std;

int X[101];
int n, cnt = 0;

void solution(){
	cnt++;
	for (int i = 1; i <= n; i++){
		cout<<"Xep quan thu "<<i<<" o vi tri "<<X[i]<<endl;
	}
}

bool check(int j, int k){
	for (int i = 1; i <= k - 1; i++){
		if (j == X[i] || abs(j - X[i]) == k - i) return false;
	}
	return true;
}

void Try(int k){
	for (int j = 1; j <= n; j++){
		if (check(j, k)){
			X[k] = j;
			if (k == n) solution();
			else Try(k + 1);
		}
	}
}

int main(){
	cout << "Nhap n: ";
	cin>>n;
	Try(1);
	cout << cnt;
	return 0;
}
