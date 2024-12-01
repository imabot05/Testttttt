#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
string s, final;
priority_queue<string> pq;
int n, checked[100001];

void Try(int i, string curr, int prevIndex){
	if (i == n){
		pq.push(curr);
		return;
	}
	for (int j = prevIndex; j < s.size(); j++){
		if (!checked[j]){
			checked[j] = 1;
			Try(i + 1, curr + s[j], j + 1);
			checked[j] = 0;
		}
	}
}

int main(){
	cin >> s >> n;
	Try(0, "", 0);
	cout << pq.top();
	return 0;
}
