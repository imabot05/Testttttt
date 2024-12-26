#include<bits/stdc++.h>
using namespace std;

const int MAXN = 15;
int H, W, n;
int h[MAXN], w[MAXN];
int mark[MAXN][MAXN];

bool check(int x, int y, int k, int type){
    int ah = h[k];
    int aw = w[k];
    if (type == 1) {
        ah = w[k];
        aw = h[k];
    }
    if (x + ah > H || y + aw > W)
        return false;
    for (int x1 = x; x1 <= x + ah - 1; x1++){
        for (int y1 = y; y1 <= y + aw - 1; y1++){
            if (mark[x1][y1] == 1) return false;
        }
    }
    return true;
}

void doMark(int x, int y, int k, int type, int markValue){
    int ah = h[k];
    int aw = w[k];
    if (type == 1) swap(ah, aw);
    for (int i = x; i <= x + ah - 1; i++){
        for (int j = y; j <= y + aw - 1; j++){
            mark[i][j] = markValue;
        }
    }
}

void Try(int k){
    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++){
            for (int type = 0; type <= 1; type++){
                if (check(i, j, k, type)){
                    doMark(i, j, k, type, 1);

                    if (k == n){
                        cout << "1" << endl;
                        exit(0);
                    }
                    else {
                        Try(k + 1);
                    }

                    doMark(i, j, k, type, 0);
                }
            }
        }
    }
}

int main(int argc, const char **argv){
    cin >> H >> W >> n;
    for (int i = 1; i <= n; i++){
        cin >> h[i] >> w[i];
    }

    memset(mark, 0, sizeof(mark));
    Try(1);
    cout << "0" << endl;
    return 0;
}
7 5
4
1 5
6 2
2 2
4 3
1
