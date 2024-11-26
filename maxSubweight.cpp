#include<iostream>
#include<vector>
#include<cstring>
#include<climits>

using namespace std;

const int MAXN = 1e6 + 5;
const int INF = 1e9 + 7;

int n;
int A[MAXN], memory[MAXN];
int comp[MAXN];

int maxSum(int i){
	if (i == 1) return A[i];
	if (comp[i]) return memory[i];
	int res = max(A[i], maxSum(i - 1) + A[i]);
	memory[i] = res;
	comp[i] = 1;
	return res;
}

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> A[i];
	}
	
	int maximum = -INF;
	for (int i = 1; i <= n; i++){
		if (maximum < maxSum(i)) maximum = maxSum(i);
//		cout<<maxSum(i)<<" ";
	}
	cout << maximum;
	return 0;
}
