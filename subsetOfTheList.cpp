#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> result;
void backtrack(vector<int> nums, int start, vector<int>current){
	result.push_back(current);
	for (int i = start; i < nums.size(); i++){
		current.push_back(nums[i]);
		backtrack(nums, i + 1, current);
		current.pop_back();
	}
}

void solve(){
	int n;
	vector<int> nums;
	cin >> n;
	for (int i = 0; i < n; i++){
		int u;
		cin >> u;
		nums.push_back(u);
	}
	vector<int> current;
	backtrack(nums, 0, current);
	cout << result.size() << endl;
}

int main(){
	solve();
	return 0;
}
