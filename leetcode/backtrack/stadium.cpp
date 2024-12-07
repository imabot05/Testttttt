#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, res;
struct club{
	int a, b, c;
};

club x[5001];
int f[5001];

bool cmp(club g, club h){
	if (g.b < h.b) return g.b < h.b;
	return g.a < h.a;
}

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> x[i].a >> x[i].b >> x[i].c;
	}
	sort(x + 1, x + n + 1, cmp);
	res = 0;
	for (int i = 1; i <= n; i++){
		f[i] = x[i].c;
		for (int j = 1; j < i; j++){
			if (x[j].b < x[i].a){
				f[i] = max(f[j] + x[i].c, f[i]);
			}
		}
	}
	for (int i = 1; i <= n; i++){
		res = max(res, f[i]);
	}	
	cout << res;
	return 0;
}
/*
5
1 3 4
1 5 5
3 6 2
4 7 9
5 7 6
13
*/
