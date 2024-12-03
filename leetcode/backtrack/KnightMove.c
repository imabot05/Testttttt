#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

const int N = 8;
int matrix[N][N];

int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

bool isSafe(int x, int y, int matrix[N][N]){
    return x >= 0 && x < N && y >= 0 && y < N && matrix[x][y] == -1;
}

void printSolution(int matrix[N][N]){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void inp(){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            matrix[i][j] = -1;
        }
    }

    matrix[0][0] = 0;
}

int Try(int x, int y, int moves, int matrix[N][N]){
    if (moves == N * N){
        printSolution(matrix);
        return 1;
    }
    for (int k = 0; k < 8; k++){
        int nextX = x + dx[k];
        int nextY = y + dy[k];
        if (isSafe(nextX, nextY, matrix)){
            matrix[nextX][nextY] = moves;
            if (Try(nextX, nextY, moves + 1, matrix) == 1){
                return 1;
            }
            matrix[nextX][nextY] = -1;
        }
    }
    return 0;
}

int main(){
    inp();
    Try(0, 0, 1, matrix);
    return 0;
}
/*
0 11 8 5 2 13 16 19
9 6 1 12 17 20 3 14
30 27 10 7 4 15 18 21
63 24 31 28 35 22 47 44
32 29 26 23 48 45 36 57
25 62 51 34 39 56 43 46
52 33 60 49 54 41 58 37
61 50 53 40 59 38 55 42
*/
