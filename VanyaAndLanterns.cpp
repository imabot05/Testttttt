#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

const int MAXN = 1005;

int n, l, A[MAXN];

bool check(double x){
	double last = 0;
	for (int i = 1; i <= n; i++){
		if (A[i] - x > last) return 0;
		last = A[i] + x;
	}
	return last >= l;
}

double solve(){
	double l =0, r = 1e10;
	while (r - l > 1e-10){
		double mid = (l + r) / 2;
		if (check(mid)) r = mid;
		else l = mid;
	}
	return r;
}

int main(){
	cin >> n >> l;
	for (int i = 1; i <= n; i++){
		cin >> A[i];
	}
	sort(A + 1, A + n + 1);
	cout<<setprecision(9)<<fixed<<solve();
	return 0;
}
/*
7 15
15 5 3 7 9 14 0
2.500000000
*/
