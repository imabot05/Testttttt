#include<iostream>
#include<vector>
#include<cstring>
#include<climits>

using namespace std;

const int MAXN = 15;

int m, n, cur = 0, result = 0;
vector<bool> visited(MAXN, false);
vector<int> X(MAXN);

void printSolution(){
	result += 1;
	for (int i = 1; i <= n; i++){
		cout << X[i] << " ";
	}
	cout << endl;
}

void Try(int k){
	int start = ( k == n ? m - cur : 1);
	for (int i = start; i <= m - cur - (n - k); i++){
		X[k] = i;
		cur += i;
		if (k == n){
			printSolution();
		}
		else Try(k + 1);
		cur -= i;
	}
}

int main(){
	cin >> m >> n;
	Try(1);
	cout << result;
	return 0;
}
/*
10 3
1 1 8
1 2 7
1 3 6
1 4 5
1 5 4
1 6 3
1 7 2
1 8 1
2 1 7
2 2 6
2 3 5
2 4 4
2 5 3
2 6 2
2 7 1
3 1 6
3 2 5
3 3 4
3 4 3
3 5 2
3 6 1
4 1 5
4 2 4
4 3 3
4 4 2
4 5 1
5 1 4
5 2 3
5 3 2
5 4 1
6 1 3
6 2 2
6 3 1
7 1 2
7 2 1
8 1 1
36
*/
