#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAXN = 1005;
int n, ans = 0;
int X[MAXN], dp[MAXN];

int max(int a, int b){
    return (a > b) ? a : b;
}

void inp(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> X[i];
    }
}

void solve(){
    for (int i = 0; i < n; i++){
        dp[i] = 1;
        for (int j = 0; j < i; j++){
            if ((abs(X[j]) < abs(X[i])) && (X[i] * X[j] < 0)){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
}

int main(int argc, const char **argv){
    inp();
    solve();
    cout << ans;
    return 0;
}
/*
14
2 34 4 -3 4 5 42 -6 45 7 9 10 11 12
5
*/
