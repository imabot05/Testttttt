#include<bits/stdc++.h>
using namespace std;

int n, a[21] = {};

void solution(int n){
	cout<<"(";
	for (int i = 1; i <= n; i++) cout<<a[i]<<" ";
	cout<<")";
}

void solve(int x, int sum, int k){
	for (int i = k; i >= 1; i--){
		if (sum + i <= n){
			a[x] = i;
			if (sum + i == n) {
				solution(x);
				cout << endl;	
			}
			solve(x + 1, sum + i, i);
		}
	}
}
int main(){
	cin >> n;
	solve(1, 0, n);
	return 0;
}
