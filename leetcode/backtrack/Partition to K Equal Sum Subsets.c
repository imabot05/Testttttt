#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

const int MAXN = 17;
int a[MAXN], subset[MAXN], sumSubset[MAXN];
int n, k, sum, ok = 0;

void inp(){
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		sum += a[i];
	}
}

bool checkSolution(){
	for (int i = 0; i < k; i++){
		sumSubset[i] = 0;
	}
	for (int i = 0; i < n; i++){
		int j = subset[i];
		sumSubset[j] += a[i];
	}
	for (int i = 0; i < k; i++){
//		printf("%d ", sumSubset[i]);
		if (sumSubset[i] != sum / k) return false;
	}
	return true;
}

void Try(int i){
	if (i == n){
		if(checkSolution()) ok = 1;
		return;
	}
	if (ok) return;
	for (int j = 0; j < k; j++){
		subset[i] = j;
		Try(i + 1);
	}
}

int main(){
	inp();
	if (sum % k != 0){
		printf("FALSE");
	} else {
		Try(0);
		if (ok) {
			printf("TRUE");
		} else printf("FALSE");
	}
	return 0;
}
/*
698. Partition to K Equal Sum Subsets
Medium
Topics
Companies
Hint
Given an integer array nums and an integer k, return true if it is possible to divide this array into k non-empty subsets whose sums are all equal.

 

Example 1:

Input: nums = [4,3,2,3,5,2,1], k = 4
Output: true
Explanation: It is possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
Example 2:

Input: nums = [1,2,3,4], k = 3
Output: false
 

Constraints:

1 <= k <= nums.length <= 16
1 <= nums[i] <= 104
The frequency of each element is in the range [1, 4].
*/
