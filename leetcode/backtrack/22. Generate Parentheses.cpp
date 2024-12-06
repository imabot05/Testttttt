#include<iostream>
#include<vector>
#include<string>

using namespace std;
int n;
vector<string> result;

void backtrack(vector<string> &result, string current, int open, int close){
	if (open == n && close == n){
		result.push_back(current);
		return;
	}
	
	if (open < n){
		backtrack(result, current + "(", open + 1, close);
	}
	if (close < open){
		backtrack(result, current + ")", open, close + 1);
	}
}

int main(){
	cin >> n;
	backtrack(result, "", 0, 0);
	for (string rs: result){
		cout << rs << endl;
	}
	return 0;
}
/*
22. Generate Parentheses
Medium
Topics
Companies
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:
Input: n = 1
Output: ["()"]
Constraints:
1 <= n <= 8
*/
