#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;
int t, n;
int a[MAX];

int solve() {
    vector<int> lis;  // Vector to store the potential LIS elements with consecutive increasing by 1

    for (int i = 0; i < n; i++) {
        if (lis.empty() || (a[i] == lis.back() + 1)) {
            // If lis is empty or a[i] is exactly 1 more than the last element in lis
            lis.push_back(a[i]);
        } else {
            // Otherwise, find the position to replace in lis array using lower_bound
            auto it = lower_bound(lis.begin(), lis.end(), a[i]);
            
            if (it == lis.end()) {
                // If a[i] is greater than all elements, add it to the end
                lis.push_back(a[i]);
            } else {
                // Replace the found position with a[i]
                *it = a[i];
            }
        }
    }
    
    return lis.size();  // The length of the vector lis is the length of the required LIS
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
