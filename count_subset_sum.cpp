#include<bits/stdc++.h>
using namespace std;

bool flag = 0;
void printSubsetSum(int i, int n, int set[], int targetSum, vector<int> &subset){
	if (targetSum == 0){
		flag = 1;
		cout << "[ ";
		for (int i = 0; i < subset.size(); i++){
			cout << subset[i] << " ";
		}
		cout << "]";
		return;
	}
	if (targetSum < 0 || i == n){
		return;
	} 
	
	printSubsetSum(i + 1, n, set, targetSum, subset);
	if (set[i] <= targetSum){
		subset.push_back(set[i]);
		printSubsetSum(i + 1, n, set, targetSum - set[i], subset);
		subset.pop_back();
	}
}

int main()
{
    // Test case 1
    int set[] = { 1, 2, 1 };
    int sum = 3;
    int n = sizeof(set) / sizeof(set[0]);
    vector<int> subset;
    cout << "Output 1:" << endl;
    printSubsetSum(0, n, set, sum, subset);
    cout << endl;
    flag = 0;
    // Test case 2
    int set2[] = { 3, 34, 4, 12, 5, 2 };
    int sum2 = 30;
    int n2 = sizeof(set) / sizeof(set[0]);
    vector<int> subset2;
    cout << "Output 2:" << endl;
    printSubsetSum(0, n2, set2, sum2, subset2);
    if (!flag) {
        cout << "There is no such subset";
    }
 
    return 0;
}
/*
Given a set[] of non-negative integers and a value sum, the task is to print the subset of the given set whose sum is equal to the given sum.

Examples: 


Input: set[] = {1,2,1}, sum = 3
Output: [1,2],[2,1]
Explanation: There are subsets [1,2],[2,1] with sum 3.


Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 30
Output: []
Explanation: There is no subset that add up to 30.
Output 1:
[ 2 1 ][ 1 2 ]
Output 2:
There is no such subset
*/
