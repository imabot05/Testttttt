// Problem: Feasible Cycles
// Given n points on a plane, each point i has coordinates x[i] and y[i], count the number of cycles that start from a point, visit all the (n-1) other points exactly once, and return to the starting point, such that the total distance of the cycle is less than or equal to a given number L. 
// Note that, the distance from point i to point j is the Manhattan distance |x[i] - x[j]| + |y[i] - y[j]|.

// Input:
// Line 1: Integer n (1 ≤ n ≤ 10)
// Line i+1: Contains two integers, separated by a space, for the coordinates (x[i] and y[i]) of point i (0 ≤ x[i], y[i] ≤ 100)
// Line n+1: Integer L (1 ≤ L ≤ 100000)

// Output: One integer for the number of feasible cycles

// Example:
// Input:
// 5
// 41 67
// 34 0
// 69 24
// 78 58
// 62 64
// 222

// Output: 2
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAXN = 21;

int n, L;
vector<pair<int, int>> cityList;
bool visited[MAXN];
int dist[MAXN][MAXN];

void inp(){
	cin >> n;
	int x, y;
	for (int i = 1; i <= n; i++){
		cin >> x >> y;
		cityList.push_back({x, y});
	}
	cin >> L;
	
	for (int i = 0; i < cityList.size() - 1; i++){
		for (int j = i + 1; j < cityList.size(); j++){
			int distance = abs(cityList[i].first - cityList[j].first) + abs(cityList[i].second - cityList[j].second);
			dist[i][j] = dist[j][i] = distance;
		}
	}
}

int cnt = 0;
void dfs(int startCity, int currCity, int currLength, int numVisited){
	if (numVisited == n){
		if (currLength + dist[currCity][startCity] <= L){
			cnt += 1;
		}
		return;
	}
	if (currLength > L){
		return;
	}
	for (int i = 0; i < n; i++){
		if (!visited[i]){
			visited[i] = true;
			dfs(startCity, i, currLength + dist[currCity][i], numVisited + 1);
			visited[i] = false;
		}
	}
}

int main(){
	inp();
	for (int i = 0; i < n; i++){
		memset(visited, false, sizeof(visited));
		visited[i] = true;
		dfs(i, i, 0, 1);
	}
	cout << cnt / n;
	return 0;
}
/*
6
41 67
34 0
69 24
78 58
62 64
15 28
268
4
*/
