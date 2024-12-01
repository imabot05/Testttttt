#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

const int SIZE = 9;

bool isValidSudoku(int grid[SIZE][SIZE]){
	bool rowCheck[SIZE][SIZE] = {0};
	bool colCheck[SIZE][SIZE] = {0};
	bool boxCheck[SIZE][SIZE] = {0};
	for (int i = 0; i < SIZE; i++){
		for (int j = 0; j < SIZE; j++){
			int number = grid[i][j];
			
			if (number < 1 || number > SIZE){
				return false;
			}
			number -= 1;
			if (rowCheck[i][number] || colCheck[j][number]){
				return false;
			}
			int boxIndex = (i / 3) * 3 + (j / 3);
			if (boxCheck[boxIndex][number]){
				return false;
			}
			boxCheck[boxIndex][number] = true;
		}
	}
	return true;
}

int main(){
	int grid[SIZE][SIZE];
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                scanf("%d", &grid[i][j]);
            }
        }

        printf("%d\n", isValidSudoku(grid) ? 1 : 0);
    }
	return 0;
}
/*
2
1 2 3 4 5 6 7 8 9
4 5 6 7 8 9 1 2 3
7 8 9 1 2 3 4 5 6
2 1 4 3 6 5 8 9 7
3 6 5 8 9 7 2 1 4
8 9 7 2 1 4 3 6 5
5 3 1 6 7 8 9 4 2
9 7 2 5 4 1 6 3 8
6 4 8 9 3 2 5 7 1
1
1 2 3 4 5 6 7 8 9
4 5 6 7 8 9 1 2 3
7 8 9 1 2 3 4 5 6
2 1 4 3 6 5 8 9 7
3 6 5 8 9 7 2 1 4
8 9 7 2 1 4 3 6 5
5 3 1 6 7 8 9 4 2
9 7 8 5 4 2 6 3 1
4 4 2 9 3 1 5 7 8
0
*/
