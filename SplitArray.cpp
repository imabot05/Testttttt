#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<climits>
#include<queue>

using namespace std;

const int MAXN = 21;
int t;
int n, k, sum;
int A[MAXN];
int ok = 0;

bool check[MAXN];

void Try(int s, int count){
//	cout << s << " " << count << endl;
	if (count == k + 1){
		ok = 1;
		return;
	}
	if (ok == 1){
		return;
	}
	for (int j = 1; j <= n; j++){
		if (check[j] == 0){
			check[j] = 1;
			if (s == sum / k) Try(0, count + 1);
			else if (s < sum / k) Try(s + A[j], count);
			else return;		
		}
		check[j] = 0;
	}
}

int main(){
	int t;
	cin >> t;
	while (t--){
		cin >> n >> k;
		sum = 0;
		for (int i = 1; i <= n; i++){
			cin >> A[i];
			sum += A[i];
		}
		if (sum % k) {
			cout << "0";
			continue;
		} else {
			Try(0, 1);
			if (ok == 0) cout<<"0"<<endl;
			else cout<<"1"<<endl;
		}
	}
}
/*
2
5 3
2 1 4 5 6
1
5 3
2 1 5 5 6
0
*/
