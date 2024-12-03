#include<bits/stdc++.h>
using namespace std;

int res = 0;

bool isPalindrome(string s){
	int j = s.length() - 1;
	for (int i = 0; i < j; i++){
		if (s[i] != s[j]){
			return false;
		}
		j--;
	}
	return true;
}

void dfs(string s, int i, string s1, string s2){
	if (i == s.length()){
		if (isPalindrome(s1) && isPalindrome(s2)){
			res = max(res, (int)s1.length() * (int)s2.length());
		}
		return;
	}
	dfs(s, i + 1, s1 + s[i], s2);
	dfs(s, i + 1, s1, s2 + s[i]);
	dfs(s, i + 1, s1, s2);
}

int main(){
	string s;
	cin >> s;
	dfs(s, 0, "", "");
	cout << res;
	return 0;
}
/*

Given a string s, find two disjoint palindromic subsequences of s such that the product of their lengths is maximized. The two subsequences are disjoint if they do not both pick a character at the same index.

Return the maximum possible product of the lengths of the two palindromic subsequences.

A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters. A string is palindromic if it reads the same forward and backward.

Input: s = "leetcodecom"
Output: 9
Explanation: An optimal solution is to choose "ete" for the 1st subsequence and "cdc" for the 2nd subsequence.
The product of their lengths is: 3 * 3 = 9.

accbcaxxcxx
25
*/
