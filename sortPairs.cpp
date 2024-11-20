/* 
Bai 2.12 - Tuan 11
Nguyen Duy Khanh - 20225019 - 744469 - 20241 
*/ 
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int main(){
	vector<pair<int, int>> pairs;
	int key, value;
	/********************
    Nguyen Duy Khanh - 20225019 
    Ma lop TH: 744469
    ********************/
	
    // Read the input (key, value)
    while (cin >> key >> value) {
        pairs.push_back({key, value});
    }
	
	sort(pairs.begin(), pairs.end(), [](pair<int, int> a, pair<int, int> b){
		if (a.second != b.second){
			return a.second > b.second;
		}
		return a.first > b.first;
	});
	
	for (auto p : pairs) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}
