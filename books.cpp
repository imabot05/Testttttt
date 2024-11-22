#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

int n, k;

bool canChooseBook(vector<int> A, int k, int d){
	int count = 1;
	int last_pos = A[0];
	int length = A.size();
	for (int i = 1; i < length; i++){
		if (A[i] - last_pos >= d){
			count += 1;
			last_pos = A[i];
		}
		if (count >= k){
			return true;
		}
	}
	return false;
}

int main(){
	cin >> n >> k;
	int result = 1e9 + 7;
	vector<int> A(n);
	for (int i = 0; i < n; i++){
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	int low = A[0];
	int high = A.back();
	
	while (low <= high) {
		int mid = (low + high) / 2;
		if (canChooseBook(A, k, mid)){
			result = mid;
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	cout<<result;
	return 0;
}
/*
5 3
10 4 2 3 1
3
*/
