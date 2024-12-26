#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAXN = 100005;

int n, D;
vector<int> a;
vector<int> dp;

int main(){
    cin >> n >> D;
    a.resize(n);
    dp.resize(n);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int res = 0;
    for (int i = 1; i <= n; i++){
        dp[i] = 1;
        for (int j = 1; j < i; j++){
            if (abs(a[i] - a[j]) <= D)
                dp[i] = max(dp[i], dp[j] + 1);
        }
        res = max(res, dp[i]);
    }
    cout << res;
    return 0;
}

10 3
4 1 5 2 8 4 7 5 14 6
7
