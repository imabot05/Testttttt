#include<iostream>
#include<vector>
#include<cstring>
#include<climits>

using namespace std;

const int MAXN = 1005;

string a = "banana";
string b = "kanama";

int mem[MAXN][MAXN];

int LCS(int i, int j){
	if (i == -1 || j == -1) return 0;
	if (mem[i][j] != -1) return mem[i][j];
	if (a[i] == b[j]){
		mem[i][j] = LCS(i - 1, j - 1) + 1;
	} else {
		mem[i][j] = max(LCS(i - 1, j), LCS(i, j - 1));
	}
	return mem[i][j];
}

void Trace(int i, int j){
	if (i == -1 || j == -1){
		return;
	}
	if (a[i] == b[j] && mem[i][j] == mem[i - 1][j - 1] + 1){
		Trace(i - 1, j - 1);
		cout<<a[i];
		return;
	}
	if (mem[i][j] == mem[i][j - 1]){
		Trace(i, j - 1);
		return;
	}
	if (mem[i][j] == mem[i - 1][j]){
		Trace(i - 1, j);
		return;
	}
}

int main(){
	memset(mem, -1, sizeof(mem));
	int m = a.length();
	int n = b.length();
	int result = LCS(m - 1, n - 1);
	cout<<result<<endl;
	Trace(m - 1, n - 1);
	return 0;
}
