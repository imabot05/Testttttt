

#include<iostream>
#include<climits>
#include<vector>
#include<string.h>
#include<algorithm>

using namespace std;

const int MAXN = 101;

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int k, m, n;
string dict[MAXN];
char M[MAXN][MAXN];
vector<string> S;
bool check[MAXN][MAXN];

void Try(int x, int y, string s){
	for (int i = 0; i < k; i++){
		if (dict[i] == s) S.push_back(s);
	}
	for (int i = 0; i < 8; i++){
		int x1 = x + dx[i];
		int y1 = y + dy[i];
		if (x1 >= 0 && x1 < m && y1 >= 0 && y1 < n && check[x1][y1] == false){
			check[x1][y1] = true;
			Try(x1, y1, s + M[x1][y1]);
			check[x1][y1] = false;
		}
	}
}


int main(){
	int t;
	cin >> t;
	while (t--){
		S.clear();
		cin >> k >> m >> n;
		for (int i = 0; i < k; i++){
			cin >> dict[i];
		}
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				cin >> M[i][j];
			}
		}
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				memset(check, false, sizeof(check));
				check[i][j] = true;
				string s = "";
				Try(i, j, s + M[i][j]);
			}
		}
		if (S.size() == 0)cout << -1;
		else
			for (auto s:S) {
				cout << s << " ";
			}
		cout << endl;
	}
	return 0;
}
/*
1
4 3 3
GEEKS FOR QUIZ GO
G I Z
U E K
Q S E
GEEKS QUIZ
*/
