#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
	int n, k, m;
	cin >> n >> k >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	queue<int> q;
	int sum = 0, cnt = 0;
	for (int i = 0; i < k; i++){
		int x = a[i];
		sum += x;
		q.push(x);
	}
	if (sum == m) cnt += 1;
	for (int i = k; i < n; i++){
		sum -= q.front();
		q.pop();
		sum += a[i];
		q.push(a[i]);
		if (sum == m) cnt += 1;
	}
	cout << cnt << endl;
	return 0;
}
/*
6 3 20
7 6 7 4 11 5
2
*/
