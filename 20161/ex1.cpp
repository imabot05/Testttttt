#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAXN = 1000005;
const int INF = 1e9 + 7;

int n, k;
int A[MAXN];
int res = -INF;

int main(){
	cin >> n >> k;
	int prefix[MAXN];
	prefix[0] = 0;
	for (int i = 1; i <= n; i++){
		cin >> A[i];
		prefix[i] = prefix[i - 1] + A[i];
	}	
	
	for (int i = k; i <= n; i++){
		if (prefix[i] - prefix[i - k] > res){
			res = prefix[i] - prefix[i - k];
		}
	}
	cout << res;
	return 0; 
}
/*
6 3
2 3 20 4 6 5
30
*/
