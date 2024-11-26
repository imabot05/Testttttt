#include<iostream>
#include<vector>
#include<cstring>
#include<climits>

using namespace std;

const int MAXN = 21;
int n, m;
int s[MAXN];

void solution(){
	for (int i = 1; i <= m; i++){
		cout << s[i] <<" ";
	}
	cout<<endl;
}

bool check(int v, int k){
	return true;
}

void Try(int k){
	for (int v = s[k - 1] + 1; v <= n - m + k; v++){
		if (check(v, k)){
			s[k] = v;
			if (k == m){
				solution();
			} else {
				Try(k + 1);
			}
		}
	}
}

int main(){
	cin >> n >> m;
	s[0] = 0;
	Try(1);
	return 0;
}
/*
5 3
1 2 3
1 2 4
1 2 5
1 3 4
1 3 5
1 4 5
2 3 4
2 3 5
2 4 5
3 4 5
*/
