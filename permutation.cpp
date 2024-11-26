#include<iostream>
#include<vector>
#include<cstring>
#include<climits>

using namespace std;

const int MAXN = 21;

int X[MAXN];
int n;
bool visited[MAXN];

void solution(){
	for (int i = 1; i <= n; i++){
		cout<<X[i]<<" ";
	}
	cout<<endl;
}

void Try(int i){
	for (int j = 1; j <= n; j++){
		if (!visited[j]){
			X[i] = j;
			visited[j] = true;
			if (i == n){
				solution();
			}
			else {
				Try(i + 1);
			}
			visited[j] = false;
		}
	}
}

int main(){
	cin >> n;
	Try(1);
	return 0;
}
