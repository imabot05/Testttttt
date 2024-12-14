#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<int> matchSticks;

bool dfs(vector<int> &matchSticks, vector<int> &kow, int index, int target){
	if (index == n){
		return true;
	}
	for (int i = 0; i < 4; i++){
		if (kow[i] + matchSticks[index] > target){
			continue;
		}
		kow[i] += matchSticks[index];
		if (dfs(matchSticks, kow, index + 1, target)){
			return true;
		}
		kow[i] -= matchSticks[index];
	}
	return false;
}

int main(){
	cin >> n;
	matchSticks.resize(n);
	for (int i = 0; i < n; i++){
		cin >> matchSticks[i];
	}
	int sum = 0;
	for (int i = 0; i < n; i++){
		sum += matchSticks[i];
	}
	if (sum % 4 != 0 && n < 4){
		cout << "-1";
		return 0;
	}
	vector<int> kow(4, 0);
	cout << dfs(matchSticks, kow, 0, sum / 4);
	return 0;
}
