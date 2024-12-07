#include <stdio.h>
#include <stdbool.h>

const int MAXN = 21;
const int INF = 1e9 + 7;

int n, m;
int cost[MAXN][MAXN];     
int X[MAXN];               
int currSum[MAXN];         
int res;                   
bool visited[MAXN];       
void Try(int i) {
    for (int j = 2; j <= n; j++) { 
        if (!visited[j]) {
            X[i] = j;
            currSum[i] = currSum[i - 1] + cost[X[i - 1]][j];
            if (currSum[i] < res) { 
                if (i < n) {        
                    visited[j] = true;
                    Try(i + 1);
                    visited[j] = false; 
                } else { 
                    int total_cost = currSum[i] + cost[X[i]][1]; 
                    if (total_cost < res) {
                        res = total_cost;
                    }
                }
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);

    // Initialize the adjacency matrix with INF
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) cost[i][j] = 0;
            else cost[i][j] = INF;
        }
    }
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        cost[u][v] = w;
        cost[v][u] = w;
    }
    visited[1] = true;
    X[1] = 1;
    currSum[1] = 0;
    res = INF;
    Try(2);
    if (res < INF) {
        printf("%d\n", res);
    } else {
        printf("-1");
    }

    return 0;
}
/*
4 6
1 2 3
1 3 2
1 4 1
2 3 1
2 4 2
3 4 4
6
*/
