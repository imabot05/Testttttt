#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
#include<cstring>

int X[7];
bool visited[11];
int T, n, ans;

// H U S T O I C (H, S != 0)
void solution(){
    int HUST = X[0] * 1000 + X[1] * 100 + X[2] * 10 + X[3];
    int SOICT = X[2] * 10000 + X[4] * 1000 + X[5] * 100 + X[6] * 10 + X[3];
    if (HUST + SOICT == n){
        ans += 1;
        for (int i = 0; i < 7; i++){
            printf("%d ", X[i]);
        }
        printf("\n");
    }
}

bool check(int v, int k){
    if ((k == 0 || k == 2) && v == 0)
        return false;
    return true;
}

void Try(int k){
    for (int v = 0; v <= 9; v++){
        if (!visited[v]){
            if (check(v, k)){
                X[k] = v;
                visited[v] = true;
                if (k == 6){
                    solution();
                } else {
                    Try(k + 1);
                }
                visited[v] = false;
            }
        }
    }
}

int main(int argc, const char **argv){
    scanf("%d", &T);
    while (T--){
        scanf("%d", &n);
        ans = 0;
        memset(visited, false, sizeof(visited));
        Try(0);
        printf("%d\n", ans);
    }
    return 0;
}

2
43286
2 5 4 8 0 7 3
2 7 4 8 0 5 3
6 0 3 8 7 2 4
6 2 3 8 7 0 4
7 0 3 8 6 2 4
7 2 3 8 6 0 4
6
19566
2 0 1 8 7 5 4
2 5 1 8 7 0 4
2 7 1 3 6 8 5
2 8 1 3 6 7 5
3 0 1 8 6 5 4
3 5 1 8 6 0 4
3 6 1 8 5 9 4
3 9 1 8 5 6 4
5 6 1 8 3 9 4
5 9 1 8 3 6 4
6 0 1 8 3 5 4
6 5 1 8 3 0 4
6 7 1 3 2 8 5
6 8 1 3 2 7 5
7 0 1 8 2 5 4
7 5 1 8 2 0 4
8 6 1 3 0 9 5
8 9 1 3 0 6 5
9 2 1 8 0 3 4
9 3 1 8 0 2 4
20
