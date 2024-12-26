#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

const int INF = 1e9 + 7;

int n, m;
const int MAXN = 21;
int X[MAXN], cost[MAXN], A[MAXN][MAXN], sum[MAXN];
int res = INF;

int max(int a, int b){
    return (a > b) ? a : b;
}

void inp(){
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++){
        scanf("%d", &cost[i]);
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            scanf("%d", &A[i][j]);
        }
    }
}

bool check(int period, int course){
    for (int i = 1; i < course; i++){
        if (A[i][course] == 1 && X[i] >= period) return false;
        if (A[course][i] == 1 && X[i] <= period) return false;
    }
    return true;
}

void solution(){
    int tmp_max = -1;
    for (int i = 1; i <= m; i++){
        tmp_max = max(tmp_max, sum[i]);
    }
    if (res > tmp_max) res = tmp_max;
}

void Try(int course){
    for (int period = 1; period <= m; period++){
        if (check(period, course)){
            X[course] = period;
            sum[period] += cost[course];
            if (course == n){
                solution();
            } else {
                Try(course + 1);
            }
            sum[period] -= cost[course];
        }
    }
}

int main(int argc, const char **argv){
    inp();
    Try(1);
    printf("%d", res);
    return 0;
}
