#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<climits>

using namespace std;

const int MAXN = 31;

int n, s;
int a[MAXN], b[MAXN];
int ok, sum;
int res = 0;

//void solution(int x){
//	for (int i = 1; i < x; i++){
//		cout << b[i] << " ";
//	}
//	cout<<endl;
//}

void Try(int i, int sum, int cur){
	if (sum == s){
		res += 1;
		ok = 1;
		return;
	}
	if (sum > s) return;
	for (int j = cur; j <= n; j++){
//		b[i] = a[j];
		if (sum + a[j] <= s) Try(i + 1, sum + a[j], j);
	}
}

int main(){
	int t;
	cin >> t;
	while (t--) {
		res = 0;
		cin >> n >> s;
		for (int i = 1; i <= n; i++){
			cin >> a[i];
		}
		sort(a + 1, a + n + 1);
		Try(1, 0, 1);
		if (ok == 0) cout<<-1<<endl;
		else cout<<res<<endl;
	}
}
/*
1
4 8
2 4 6 8
5
*/
