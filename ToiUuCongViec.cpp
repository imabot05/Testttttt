//Đề bài: Phân công công việc tối ưu
//Bài toán:
//Bạn được giao nhiệm vụ phân công N công việc cho M máy sao cho:
//
//Mỗi công việc được thực hiện bởi đúng một máy.
//Một số công việc có ràng buộc, ví dụ: công việc i phải được hoàn thành trước công việc j.
//Mỗi công việc i có một khối lượng công việc c[i].
//Một máy có thể thực hiện nhiều công việc.
//Mục tiêu:
//Phân công công việc sao cho khối lượng công việc lớn nhất mà một máy phải thực hiện là nhỏ nhất.
//
//Input:
//Dòng đầu tiên chứa hai số nguyên N (số lượng công việc) và M (số lượng máy).
//Dòng thứ hai chứa N số nguyên c[1], c[2], ..., c[N], là khối lượng công việc của từng công việc.
//N dòng tiếp theo, mỗi dòng chứa N số nguyên A[i][j]:
//A[i][j] = 1 nghĩa là công việc i phải hoàn thành trước công việc j.
//A[i][j] = 0 nếu không có ràng buộc nào giữa i và j.
//Output:
//In ra khối lượng công việc lớn nhất nhỏ nhất mà một máy phải thực hiện khi phân công công việc hợp lệ.

#include<iostream>
#include<vector>
#include<cstring>
#include<climits>

using namespace std;

const int MAXN = 101;
const int INF = 1e9 + 7;

int n, m, A[MAXN][MAXN];
int cost[MAXN];

int load[MAXN];
bool marked[MAXN];

int X[MAXN];
int res = INF;

void inp(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> cost[i];
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cin >> A[i][j];
		}
	}
}

bool check(int v, int k){
	for (int i = 1; i <= n; i++){
		if (A[i][v] == 1 && X[i] > v){
			return false;
		}
	}
	return true;
}

void solution(){
	int maxLoad = -1;
	for (int i = 1; i <= m; i++){
		maxLoad = max(maxLoad, load[i]);
	}
	if (maxLoad < res) res = maxLoad;
}

void Try(int k){
	for (int v = 1; v <= m; v++){
		if (check(v, k)){
			X[k] = v;
			load[v] += cost[k];
			if (k == n) solution();
			else Try(k + 1);			
			load[v] = load[v] - cost[k];
		}
	}
}

int main(){
	inp();
	for (int i = 1; i <= m; i++){
		load[i] = 0;
	}
	Try(1);
	cout<<res;
	return 0;
}
//4 2
//10 5 7 8
//0 1 0 0
//0 0 1 0
//0 0 0 1
//0 0 0 0
//15
