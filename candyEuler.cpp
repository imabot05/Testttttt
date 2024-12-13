#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAXN = 21;
int n, m;
int x[MAXN];
int currSum = 0;

void printSol(){
	for (int i = 1; i <= n; i++){
		cout << x[i] << " ";
	}
	cout << endl;
}

void Try(int k){
	int startVal;
	if (k < n){
		startVal = 1;
	}
	else startVal = m - currSum;
	for (int i = startVal; i <= m - currSum - (n - k); i++){
		x[k] = i;
		currSum += i;
		if (k == n) printSol();
		else Try(k + 1);
		currSum -= i;
	}
}

int main(){
	currSum = 0;
	cin >> n >> m;
	Try(1);
	return 0;
}
