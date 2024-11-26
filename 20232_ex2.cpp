#include<bits/stdc++.h>
using namespace std;

vector<int> v;
int k;
int cnt = 0;
void backtrack(int i, int curSum){
	if (i == v.size()){
		if (curSum > k && curSum % 5 == 0){
			cnt++;
		}
		return;
	}
	
	backtrack(i + 1, curSum + v[i]);
	backtrack(i + 1, curSum);
}

int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		v.push_back(x);
	}
	cin>>k;
	backtrack(0, 0);
	cout<<cnt<<endl;
	return 0;
}
/*
4
1000 1600 101 200
1901
2
*/
