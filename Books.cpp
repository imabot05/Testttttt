#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int n, t;
int timeRead[10001], sum[10001];

void inp(){
	std::cin>>n>>t;
	for (int i = 1; i <= n; i++){
		std::cin>>timeRead[i];
		if (i == 1) sum[i] = timeRead[i];
		else sum[i] = sum[i - 1] + timeRead[i];
	}
}

int binary_search(int sum[], int low, int high, int target){
	if (low > high){
		return -1;
	}
	int mid = (low + high) / 2;
	if (sum[mid] <= target && (mid == high || sum[mid + 1] > target)){
		return mid;
	}
	if (sum[mid] > target){
		return binary_search(sum, low, mid - 1, target);
	}
	if (sum[mid] <= target){
		return binary_search(sum, mid + 1, high, target);
	}
}

int main(){
	int result = INT_MIN;
	inp();
	for (int i = 1; i <= n; i++){
		// sum[j] - sum[i] + timeRead[i] <= t => sum[j] <= t + sum[i] - timeRead[i]
		int j = binary_search(sum, i, n, t + sum[i] - timeRead[i]);
		result = std::max(result, j - i + 1);
	}
	std::cout<<result;
	return 0;
}
