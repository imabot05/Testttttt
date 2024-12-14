#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAXN = 10;
int X[MAXN], cnt = 0, n;
bool visited[MAXN];
// C, T, D, L, G, U: == n

bool check(){
    if (X[0] == 0 || X[1] == 0) return false;
    if (X[0] * 100000 + X[1] * 10000 + X[2] * 1000 + X[3] * 100 + X[4] * 10 + X[1] + X[1] * 1000 + X[1] * 100 + X[5] * 10 + X[2] == n){
        return true;
    }
    return false;
}

void solution(){
    cnt += 1;
    for (int i = 0; i < 6; i++){
        cout << X[i] << " ";
    }
    cout << endl;
}


void Try(int k){
    for (int v = 0; v <= 9; v++){
        if (v == 0 && (k == 0 || k == 1)) continue;
        if (!visited[v]){
            X[k] = v;
            visited[v] = true;
            if (k == 5){
                if (check()) solution();
            } else {
                Try(k + 1);
            }
            visited[v] = false;
        }
    }
}

void solve(){
    cin >> n;
    Try(0);
    cout << cnt;
}

int main(){
    solve();
    return 0;
}

/*
300079
2 9 0 1 3 4
2 9 0 1 4 3
2
*/
