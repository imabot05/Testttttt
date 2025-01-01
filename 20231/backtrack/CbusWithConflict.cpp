#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 25;
const int INF  = 1000000007;

int n, m, k;
int X[MAXN], sumDist[MAXN];
int result = INF, costMin = INF;
int numPass = 0;
int costMatrix[MAXN][MAXN];
// Mảng visited[v]: đánh dấu "đã ghé điểm v" (v ∈ [1..2n])
bool visited[MAXN];
// conflictMatrix[u][v] = true nếu khách u và v xung đột (u,v ∈ [1..n])
bool conflictMatrix[MAXN][MAXN];
// onBus[i] = true => khách i đang trên xe
bool onBus[MAXN];

void inp(){
    cin >> n >> m;
    for(int i = 0; i <= 2*n; i++){
        for(int j = 0; j <= 2*n; j++){
            cin >> costMatrix[i][j];
            if(costMatrix[i][j] > 0 && costMatrix[i][j] < costMin){
                costMin = costMatrix[i][j];
            }
        }
    }
    cin >> k;
    memset(conflictMatrix, false, sizeof(conflictMatrix));
    for(int i = 0; i < k; i++){
        int u, v;
        cin >> u >> v;  
        conflictMatrix[u][v] = true;
        conflictMatrix[v][u] = true;
    }
}

bool canPickup(int passenger){
    for(int i = 1; i <= n; i++){
        if(onBus[i] && conflictMatrix[i][passenger]){
            return false;
        }
    }
    return true;
}

void Try(int step){
    int currPos = X[step - 1];
    for(int v = 1; v <= 2*n; v++){
        if(!visited[v]){ 
            int costMove = costMatrix[currPos][v];
            if(costMove == 0) continue; 
            int nextCost = sumDist[step - 1] + costMove;
            if(nextCost + costMin*(2*n - (step - 1)) >= result) continue;

            if(v <= n){
                if(numPass < m && canPickup(v)){
                    X[step] = v;
                    visited[v] = true;
                    onBus[v] = true;
                    numPass++;
                    sumDist[step] = nextCost;
                    Try(step + 1);
                    visited[v] = false;
                    onBus[v] = false;
                    numPass--;
                }
            }
            else {
                int passenger = v - n;
                if(passenger >= 1 && passenger <= n){
                    if(visited[passenger] && onBus[passenger]){
                        X[step] = v;
                        visited[v] = true;    
                        onBus[passenger] = false;
                        numPass--;
                        sumDist[step] = nextCost;
                        if(step == 2*n){
                            int totalCost = sumDist[step] + costMatrix[v][0];
                            if(totalCost < result) result = totalCost;
                        } else {
                            Try(step + 1);
                        }
                        visited[v] = false;
                        onBus[passenger] = true;
                        numPass++;
                    }
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    inp();
    memset(visited, false, sizeof(visited));
    memset(onBus,   false, sizeof(onBus));

    X[0] = 0;
    sumDist[0] = 0;
    result = INF;
    numPass = 0;
    Try(1);
    if(result == INF) cout << -1 << "\n";
    else cout << result << "\n";
    return 0;
}
/*
5 3
0 2 3 4 2 3 4 5 3 8 7
5 0 1 4 6 1 4 2 9 8 2
1 2 0 4 2 3 4 5 3 6 2
2 2 3 0 2 3 4 5 3 8 4
5 2 3 4 0 3 4 5 3 9 7
1 2 3 1 2 0 4 2 2 8 2
2 2 3 4 2 3 0 5 3 2 7
3 2 3 6 2 3 4 0 3 1 1
5 2 3 4 2 3 4 5 0 8 7
1 2 3 5 2 3 4 5 3 0 9
8 2 3 4 2 3 4 5 3 2 0
2
1 4
1 3
25
*/
