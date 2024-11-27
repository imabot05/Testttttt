#include<bits/stdc++.h>
using namespace std;

int n, k, s;
int sum, res, X[11], check[21];

void Try(int i, int sum){
	for (int j = X[i - 1] + 1; j <= n - k + i; j++){
		if (!check[j]){
			check[j] = 1;
			X[i] = j;
			if (i == k){
				if (sum + j == s) res++;
			}
			else Try(i + 1, sum + j);
			check[j] = 0;
		}
	}
}

int main(){
	while(true){
		res = 0;
		cin >> n >> k >> s;
		if (n == 0 && k == 0 && s == 0){
			break;
		}
		Try(1, 0);
		cout << res << endl;
	}
	return 0;
}
/*
9 3 23
1
9 3 22
2
10 3 28
0
16 10 107
20
20 8 102
1542
20 10 105
5448
20 10 155
1
3 4 3
0
*/
