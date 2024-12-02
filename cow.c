
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


int canPlaceCows(int positions[], int N, int C, int minDistance){
	int cowPlaced = 1;
	int lastPos = positions[0];
	
	for (int i = 1; i < N; i++){
		if (positions[i] - lastPos >= minDistance){
			lastPos = positions[i];
			cowPlaced += 1;
		}
		
		if (cowPlaced == C) return 1;
	}
	return 0;
}

int maxDistance(int positions[], int N, int C){
	int low = 0;
	int high = positions[N - 1];
	
	int maxDist = -1;
	while (low <= high){
		int mid = low + (high - low) / 2;
		if (canPlaceCows(positions, N, C, mid)){
			if (mid > maxDist){
				maxDist = mid;
			}
			low = mid + 1;
		} else {
			high = mid - 1;
		} 
	}
	
	return maxDist;
}

int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		int N, C;
		scanf("%d %d", &N, &C);
		
		int positions[N + 1];
		for (int i = 0; i < N; i++){
			scanf("%d", &positions[i]);
		}
		
		for (int i = 0; i < N - 1; i++){
			for (int j = i + 1; j < N; j++){
				if (positions[i] > positions[j]){
					int tmp = positions[i];
					positions[i] = positions[j];
					positions[j] = tmp;
				}
			}
		}
		
		printf("%d\n", maxDistance(positions, N, C));
	}
	return 0;
}
/*
1
5 3
1 2 8 4 9
3
*/
