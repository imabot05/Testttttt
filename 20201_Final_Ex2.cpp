#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;
int t, n;
int a[MAX];

int solve() {
    map<int, int> length_map;
    int longest = 0;  

    for (int i = 0; i < n; i++) {
        int current_length = length_map[a[i] - 1] + 1;
        length_map[a[i]] = max(length_map[a[i]], current_length);
        longest = max(longest, length_map[a[i]]);
    }

    return longest;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << solve() << "\n";
    }

    return 0;
}
