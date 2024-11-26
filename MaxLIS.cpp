#include<iostream>
#include<vector>
#include<cstring>
#include<climits>

using namespace std;

int a[1001], n, mem[1001];

void init(){
	cin >> n;
	for (int i = 0; i < n; i++){
		cin>>a[i];
	}
	memset(mem, -1, sizeof(mem));
}

int lis(int i){
	if (mem[i] != -1) return mem[i];
	mem[i] = 1;
	for (int j = 0; j < i; j++){
		if (a[j] < a[i]){
			mem[i] = max(mem[i], lis(j) + 1);
		}
	}
	return mem[i];
}

void Trace(int i){
	for (int j = 0; j < i; j++){
		if ((a[j] < a[i]) && (mem[i] == mem[j] + 1)){
			Trace(j);
			break;
		}
	}
	cout<<a[i]<<" ";
}

int main(){
	init();
	int res = 1, pos = 0;
	for (int i = 1; i < n; i++){
		if (lis(i) > res){
			res = lis(i);
			pos = i;
		}
	}
	cout<<res<<endl;
	Trace(pos);
	return 0;
}
/*
10
2 1 5 4 3 6 3 -6 9 10
5
2 5 6 9 10
*/

