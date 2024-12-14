#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int n, m;
vector<string> ans;
vector<vector<int>> vis;
vector<vector<char>> board;
vector<string> words;

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

bool check(string word, vector<string> words){
	for (string x: words){
		if (word == x) return true;
	}
	return false;
}

void backtrack(int i, int j, string tmp){
	if (check(tmp, words)){
		ans.push_back(tmp);
	}
	if (i < 0 || i > n || j < 0 || j > m) return;
	vis[i][j] = 1;
	for (int k = 0; k < 4; k++){
		int newI = i + dy[k];
		int newJ = j + dx[k];
		if (newI >= 0 && newI < n && newJ >= 0 && newJ < m && !vis[newI][newJ]){
			tmp.push_back(board[newI][newJ]);
			backtrack(newI, newJ, tmp);
			tmp.pop_back();
		}
	}
	vis[i][j] = 0;
}

int main(){
	cin >> n >> m;
	board.resize(n, vector<char>(m));
	vis.resize(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> board[i][j];
		}
	}
	int k;
	cin >> k;
	words.resize(k);
	for (int i = 0; i < k; i++){
		cin >> words[i];
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			string s;
			s.push_back(board[i][j]);
			backtrack(i, j, s);
		}
	}
	for (string word: ans){
		cout << word << " ";
	}
	return 0;
}
/*
Given an m x n board of characters and a list of strings words, return all words on the board.

Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

Input: board = [["a","b"],["c","d"]], words = ["abcb"]
Output: []

4 4
o a a n
e t a e
i h k r
i f l v
4
oath pea eat rain
oath eat
*/
