#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAXN = 1005;
int n, ans = 0;
int X[MAXN];

void inp(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> X[i];
    }
}

bool check(vector<int> v){
    if (v.size() == 0) return false;
    if (v.size() == 1) return true;
    for (int i = 0; i < v.size() - 1; i++){
        if ((v[i] * v[i + 1] >= 0 )|| (abs(v[i + 1]) <= abs(v[i]))){
            return false;
        }
    }
    return true;
}

void Try(int i, vector<int> &choose){
    if (i == n){
        if (check(choose)){
            cout << choose.size() << endl;
            if (ans < choose.size()){
                ans = choose.size();
            }
        }
        return;
    }

    choose.push_back(X[i]);
    Try(i + 1, choose);
    choose.pop_back();

    Try(i + 1, choose);
}

int main(){
    inp();
    vector<int> choose;
    Try(0, choose);
    cout << ans;
    return 0;
}
/*
14
2 34 4 -3 4 5 42 -6 45 7 9 10 11 12
*/
