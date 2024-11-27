//NTCGROUP - Đoàn xe qua cầu
//
//Cho một đoàn xe gồm n chiếc đi trên một đường một chiều và đoàn xe đã được bố trí theo thứ tự từ 1 đến n. Mỗi một xe trong đoàn có vận tốc là vi và trọng lượng wi.
//
//Khi đi qua một chiếc cầu có trọng tải giới hạn là P thì đoàn xe phải chia thành các nhóm sao cho tổng trọng lượng của mỗi nhóm không quá P (Lưu ý rằng không được đảo thứ tự đoàn xe). Các nhóm phải đi tuần tự có nghĩa là nhóm thứ i chỉ được khởi hành khi mà toàn bộ xe của nhóm thứ i - 1 đã qua cầu. Giả thiết rằng P > wi với moiji=1,2,...,n.
//
//Rõ ràng khi đó thời gian để một nhóm xe qua cầu phụ thuộc vào xe chậm nhất trong nhóm đó nếu coi như chiều dài cũng như khoảng cách của các xe là không đáng kể.
//
//Hãy tìm cách chia đoàn xe thành các nhóm sao cho thời gian mà đoàn xe sang được cầu là nhỏ nhất có thể được.
//
//Dữ liệu:
//
//Dòng đầu là 3 số nguyên dương n, P và L (n, P, L <= 1000) thể hiện cho số xe, trọng lượng giới hạn của cầu và độ dài của cầu.
//Dòng thứ i trong n dòng kế tiếp gồm 2 số nguyên dương wi và vi (wi, vi <= 100)
//Kết quả: Một số thực là tổng thời gian nhỏ nhất để xe qua cầu, cho phép làm tròn lấy 2 chữ số sau dấu chấm thập phân.
//
//Ví dụ:
//
// 
//
//Input
//
// Output
//
//Giải thích
//
//10 100 100
//
//40 25
//
//50 20
//
//50 20
//
//70 10
//
//12 50
//
//09 70
//
//49 30
//
//38 25
//
//27 50
//
//19 70
//
//25.00
//
// 
//
//Chia thành các nhóm:
//
//{1}, {2,3}, {4,5,6}, {7,8}, {9,10}
//
//Tổng thời gian đi qua là:
//
//4+5+10+4+2=25


#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
const int INF = 1e9 + 7;

int n, p, l;

int t[MAXN], w[MAXN], v[MAXN];
int dp[MAXN];
int endOfPrevGroup[MAXN];

void init(){
	cin >> n >> p >> l;
	for (int i = 1; i <= n; i++){
		cin >> w[i] >> v[i];
		t[i] = l / v[i];
	} 
}

void solve(){
	dp[0] = 0;
	for (int i = 1; i <= n; i++){
		dp[i] = INF;
		int totalWeight = 0;
		int maxTime = 0;
		for (int j = i; j >= 1; j--){
			totalWeight = totalWeight + w[j];
			if (totalWeight > p){
				break;
			}
			if (maxTime < t[j]) maxTime = t[j];
			if (dp[i] > dp[j - 1] + maxTime){
				dp[i] = dp[j - 1] + maxTime;
				endOfPrevGroup[i] = j - 1;
			}
		}
	}
}

void traceback() {
    vector<int> groups;
    int current = n;

    while (current > 0) {
        groups.push_back(current); 
        current = endOfPrevGroup[current]; 
    }

    reverse(groups.begin(), groups.end());

    for (int i = 0; i < groups.size(); i++) {
        if (i == 0) {
            cout << groups[i] << " ";
        } else {
            cout << groups[i] << " ";
        }
    }
    cout << endl;
}

int main(){
	init();
	solve();
	cout << dp[n] << endl;
	traceback();
	return 0;
}
