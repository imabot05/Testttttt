#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAXN = 1e6 + 5;
int n, k;
int s[MAXN], t[MAXN];
int maxProduct = 0;
vector<pair<int, int>> v;

bool cmp(pair<int, int> p1, pair<int, int> p2){
    return p1.second < p2.second;
}

void inp(){
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        int s, t;
        cin >> s >> t;
        v.push_back({s, t});
    }
}

void solve(){
    int lastPeriod = -1;
    sort(v.begin(), v.end(), cmp);
    int currSum = 0;
    int choose = 0;
    for (int i = 0; i < v.size(); i++){
        if (v[i].first > lastPeriod && choose < k){
            currSum += (v[i].second - v[i].first);
            lastPeriod = v[i].second;
            choose += 1;
        }
    }
    if (choose < k) {
        cout << -1 << endl;
    } else {
        cout << currSum << endl;
    }
}

int main(int argc, const char ** argv){
    inp();
    solve();
    return 0;
}
/*
5 2
8 12
6 11
3 9
2 5
1 4
8
*/
