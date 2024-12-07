#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<iostream>
#include<vector>

const int BASE = 1e9 + 7;
int m, n, a[40], cnt[40], f[40][40], res, sum = 0;
std::string s;

int min(int u, int v){
	return u < v ? u : v;
}

void solution(){
	for (int i = 1; i <= n; i++){
		if (cnt[i] != 2) return;
	}
	res = min(res, sum);
}

void Try(int id){
	if (id == m + 1){
		solution();
		return;
	}
	
	if (sum > res){
		return;
	}
	
	for (int x = 0; x <= 1; x++){
		bool kt = 1;
		if (x == 1){
			sum += a[id];
			for (int i = 1; i <= n; i++){
				cnt[i] += f[i][id];
				if (cnt[i] > 2) kt = 0;
			}
			if (kt == 1) Try(id + 1);
			sum -= a[id];
			for (int i = 1; i <= n; i++){
				cnt[i] -= f[i][id];
			}
		}
		else Try(id + 1);
	}
}

void solve(){
	sum = 0;
	res = BASE;
	for (int i = 1; i <= n; i++){
		cnt[i] = 0;
	}
	Try(1);
	if (res == BASE) printf("-1");
	else printf("%d", res);
}

int main(){
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= m; i++){
		scanf("%d", &a[i]);
	}
	getline(std::cin, s);
	for (int i = 1; i <= n; i++){
		getline(std::cin, s);
		int d = 0;
		for (int j = 0; j < s.size(); j++){
			if (s[j] != ' ') d = d * 10 + (s[j] - '0');
			else {
				f[i][d] = 1;
				d = 0;
			}
		}
		if (d != 0) f[i][d] = 1;
	}
	solve();
	return 0;
}
/*
5 3
100 150 300 425 200
1 2 4
1 3 4 5
1 4 5
450
*/
