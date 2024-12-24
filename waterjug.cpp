#include<iostream>
#include<queue>
using namespace std;

struct combination{
    int first;
    int second;
    int step;
};

const int MAXN = 901;
queue<combination> combinationQueue;
int visited[MAXN][MAXN];

int findCombination(int a, int b, int c){
    combinationQueue.push(combination{a, 0, 1});
    combinationQueue.push(combination{0, b, 1});
    while (!combinationQueue.empty()){
        combination x = combinationQueue.front();
        cout << x.first << " " << x.second << " " << x.step << endl;
        if (x.first == c || x.second == c){
            return x.step;
        } else {
            if (visited[x.first][x.second] == 1){
                combinationQueue.pop();
                continue;
            } else {
                visited[x.first][x.second] = 1;
            }
        }
        combinationQueue.pop();
        combinationQueue.push({a, x.second, x.step + 1});
        combinationQueue.push({x.first, b, x.step + 1});
        combinationQueue.push(combination{0, x.second, x.step + 1});
        combinationQueue.push(combination{x.first, 0, x.step + 1});
        if (x.first > b- x.second)
            combinationQueue.push(combination{x.first - b + x.second, b, x.step+1});
        else
            combinationQueue.push(combination{0, x.second+x.first, x.step+1});

        if (x.second > a - x.first){
            combinationQueue.push(combination{a, x.second - a + x.first, x.step + 1});
        } else {
            combinationQueue.push(combination{x.first + x.second, 0, x.step + 1});
        }
    }
    return -1;
}

int main(int argc, const char **argv){
    int a, b, c;
    cin >> a >> b >> c;
    cout << findCombination(a, b, c);
    return 0;
}

10 7 4
10 0 1
0 7 1
10 0 2
10 7 2
0 0 2
10 0 2
3 7 2
10 0 2
10 7 2
0 7 2
0 7 2
0 0 2
0 7 2
7 0 2
10 7 3
10 7 3
0 7 3
10 0 3
10 7 3
10 7 3
10 0 3
0 7 3
0 0 3
0 0 3
0 0 3
0 0 3
10 7 3
3 7 3
0 7 3
3 0 3
3 7 3
10 0 3
10 0 3
7 7 3
0 0 3
7 0 3
0 7 3
7 0 3
10 0 4
3 7 4
0 0 4
3 0 4
0 3 4
3 0 4
10 7 4
7 7 4
0 7 4
7 0 4
7 7 4
10 4 4
4
