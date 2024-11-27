#include<bits/stdc++.h>
using namespace std;


const int MAXN = 21;
vector<vector<int>> subsets;

int n, a[MAXN];
int s;
int res = 0;

void solution(vector<int> &v){
	for (int i = 0; i < v.size(); i++){
		cout << v[i] << " ";
	}
	cout<<endl;
}

void Try(int i, vector<int> tmp, int curSum){
	if (i == n + 1){
		if (curSum >= s){
			res += 1;
			solution(tmp);
		}
		return;
	}
	tmp.push_back(a[i]);
	Try(i + 1, tmp, curSum + a[i]);
	tmp.pop_back();
	Try(i + 1, tmp, curSum);
}

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	cin >> s;
	vector<int> temp;
	Try(1, temp, 0);
	cout<<res;
	return 0;
}
/*
4
3 5 8 6
10
3 5 8 6
3 5 8
3 5 6
3 8 6
3 8
5 8 6
5 8
5 6
8 6
9
*/
