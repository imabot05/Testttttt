#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<math.h>

using namespace std;

int n, ans = INT_MAX;
vector<int> tasks;
vector<int> load;

void inp(){
    cin >> n;
    tasks.resize(n);
    for (int i = 0; i < n; i++){
        cin >> tasks[i];
    }
}

void backtrack(int index, vector<int> &tasks, vector<int> &load){
    if (index == n){
        if (ans > load.size()){
            ans = load.size();
        }
        return;
    }

    for (int i = 0; i < load.size(); i++){
        if (load[i] + tasks[index] <= 6){
            load[i] += tasks[index];
            backtrack(index + 1, tasks, load);
            load[i] -= tasks[index];
        }
    }

    load.push_back(tasks[index]);
    backtrack(index + 1, tasks, load);
    load.pop_back();
}

int main(){
    inp();
    backtrack(0, tasks, load);
    cout << ans;
    return 0;
}
