#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000;
map<int, int> history;
int orderTime[MAXN];
int totalOrders = 0;

int convertTimePoint(string timePoint) {
    int hh = stoi(timePoint.substr(0, 2));
    int mm = stoi(timePoint.substr(3, 2));
    int ss = stoi(timePoint.substr(6, 2));
    return hh * 3600 + mm * 60 + ss;
}

void inp() {
    memset(orderTime, 0, sizeof(orderTime));
    while (true) {
        string orderId, timePoint;
        cin >> orderId;
        if (orderId == "#") break;
        cin >> timePoint;
        int timePointNumber = convertTimePoint(timePoint);
        orderTime[timePointNumber]++;
        totalOrders++;
        if (history.find(timePointNumber) != history.end()) {
            history[timePointNumber]++;
        } else {
            history[timePointNumber] = 1;
        }
    }
    int curr = orderTime[0];
    for (int i = 1; i <= MAXN; i++) {
        curr += orderTime[i];
        orderTime[i] = curr;
    }
}


void queries() {
    string command;
    while (true) {
        cin >> command;
        if (command == "###") {
            break;
        } else if (command == "?number_orders") {
            cout << totalOrders << endl;
        } else if (command == "?number_orders_at_time") {
            string timePoint;
            cin >> timePoint;
            int timePointNumber = convertTimePoint(timePoint);
            cout << history[timePointNumber] << endl;
        } else if (command == "?number_orders_in_period") {
            string timePoint1, timePoint2;
            cin >> timePoint1 >> timePoint2;
            int t1 = convertTimePoint(timePoint1);
            int t2 = convertTimePoint(timePoint2);
            if (t1 == 0) {
                cout << orderTime[t2] << endl;
            } else {
                cout << orderTime[t2] - orderTime[t1 - 1] << endl;
            }
        }
    }
}

int main(int argc, const char **argv){
    inp();
    queries();
    return 0;
}
