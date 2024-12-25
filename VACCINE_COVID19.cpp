#include<bits/stdc++.h>
using namespace std;

int X[8];
int N;
int res = 0;
int choose[11];
// VACCINE COVID19
// V, A, C, I, N, E, O, D
bool check(){
    if (X[0] == 0) return false;
    int sum = X[0] * 1000000 + X[1] * 100000 + X[2] * 10000 + X[3] * 100 + X[4] * 10 + X[5]
                - X[2] * 1000000 - X[6] * 100000 - X[0] * 10000 - X[3] * 1000 - X[7] * 100 - 19;
    if (sum == N) return true;
    return false;
}

void Try(int i){
    if (i == 8){
        if (check()) res += 1;
        return;
    }
    for (int j = 0; j <= 9; j++){
        if (i == 0 && j == 0) continue;
        if (!choose[j]){
            X[i] = j;
            choose[j] = true;
            Try(i + 1);
            choose[j] = false;
        }
    }
}

int main(int argc, const char ** argv){
    memset(choose, false, sizeof(choose));
    cin >> N;
    Try(0);
    cout << res;
    return 0;
}
