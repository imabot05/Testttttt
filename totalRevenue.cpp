#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(int argc, const char ** argv){
    int n, K, D;
    cin >> n >> K >> D;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int Q = 0;
    int s = 0;
    for (int i = 0; i < K; i++){
        s += arr[i];
    }
    if (s >= D) Q += 1;
    for (int i = K; i < n; i++){
        s += arr[i];
        s -= arr[i - K];
        if (s >= D) Q += 1;
    }
    cout << Q;
    return 0;
}
