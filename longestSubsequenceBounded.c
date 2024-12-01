#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

int longestSubsequence(int arr[], int n, int Q){
	int start = 0, end = 0, sum = 0, maxLength = -1;
	
	while (end < n){
		sum += arr[end];
		
		while (sum > Q && start <= end){
			sum -= arr[start];
			start++;
		}
		
		if (sum <= Q){
			if (end - start + 1 > maxLength){
				maxLength = end - start + 1;
			}
		}
		
		end += 1;
	}
	
	return maxLength;
}

int main(){
	int n, Q;
	scanf("%d %d", &n, &Q);
	int arr[n + 1];
	for (int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	
	int result = longestSubsequence(arr, n, Q);
	printf("%d\n", result);
	return 0;
}
/*
10 40
19 2 7 6 9 1 17 19 8 4
5
*/
