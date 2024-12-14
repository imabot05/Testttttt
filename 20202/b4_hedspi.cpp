#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<long long> dp;
vector<int> a;
vector<int> choose;

void inp() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

void solve() {
    if (n == 1) {
        if (a[0] < 0) {
            cout << 0 << endl << 0 << endl << endl;
        } else {
            cout << a[0] << endl << 1 << endl << 1 << endl;
        }
        return;
    }

    dp.resize(n);
    dp[0] = max(0, a[0]);
    dp[1] = max(dp[0], (long long)a[1]);
    choose.resize(n, 0);
    if (dp[0] < dp[1]) {
        choose[0] = 0;
        choose[1] = 1;
    } else {
        if (dp[0] > 0){
            choose[0] = 1;
            choose[1] = 0;
        } else {
            choose[0] = 0;
            choose[1] = 0;
        }
    }

    for (int i = 2; i < n; i++) {
        if (dp[i - 1] > dp[i - 2] + a[i]) {
            dp[i] = dp[i - 1];
            choose[i] = 0;
        } else {
            dp[i] = dp[i - 2] + a[i];
            choose[i] = 1;
        }
    }
    vector<int> indices;
    int i = n - 1;
    while (i >= 0) {
        if (choose[i] == 1) {
            indices.push_back(i + 1);
            i -= 2;
        } else {
            i--;
        }
    }

    reverse(indices.begin(), indices.end());

    cout << dp[n - 1] << endl;
    cout << indices.size() << endl;
    for (int idx : indices) {
        cout << idx << " ";
    }
    cout << endl;
}

int main() {
    inp();
    solve();
    return 0;
}
