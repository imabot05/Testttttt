
#include<iostream> 
#include<vector>
#include<algorithm>
using namespace std;

const int MOD = 1e9 + 7;

int main(){
	int n, Q, cnt = 0;
	cin >> n >> Q;
	vector<int>a(n);
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	long long P = 0;
	for (int i = 0; i < n - 2; i++){
		for (int j = i + 1; j < n - 1; j++){
			int target = Q - a[i] - a[j];
			auto it = lower_bound(a.begin() + j + 1, a.end(), target);
			if (it != a.end() && *it == target){
				cnt = (cnt + 1) % MOD;
			}
		}
	}
	cout << cnt << endl;
	return 0;
} 

/* CODE TU LAM, TLE 1 TEST :<
#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int n, Q;
vector<int> v;
int cnt = 0;


int binarySearch(vector<int>v, int x, int y, int l, int r){
	while (l <= r){
		int midIndex = l + (r - l) / 2;
		if (v[midIndex] + v[x] + v[y] == Q){
			return 1; 
		} else {
			if (v[x] + v[midIndex] + v[y] < Q){
				l = midIndex + 1;
			} else {
				r = midIndex - 1;
			}
		}	
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> Q;
	v.resize(n + 1);
	for (int i = 1; i <= n; i++){
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int r = n;
	for (int i = 1; i <= n - 2; i++){
		for (int j = i + 1; j <= n - 1; j++){
			int l = j + 1;
//			cout << i << " " << j << " " << l << " " << r << endl;
			if (binarySearch(v, i, j, l, r)){
				cnt += 1;
			} 
		}
	}
	cnt = cnt % MOD;
	cout << cnt;
	return 0;
}

*/
