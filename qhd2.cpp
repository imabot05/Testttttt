//Có một đoàn khách gồm n người xếp hàng mua vé xem phim. Người thứ i có 2 lựa chọn: mua vé cho mình với giá tiền là ai, mua vé cho mình và người phía sau (mua cho mình và người thứ i+1) với giá bi. Hỏi chi phí nhỏ nhất để mua vé cho toàn bộ n người là bao nhiêu?
//
//Input:
//
//Dòng 1: số nguyên dương n thể hiện cho số người xếp hàng mua vé \small (2 \leq n \leq 10^5)
//Dòng 2…n+1: Mỗi dòng gồm 2 số nguyên dương ai và bi lần lượt thể hiện cho số tiền phải trả nếu mua vé cho bản thân mình và số tiền phải trả nếu mua vé cho mình và người phía sau.
//Output:
//
//Số nguyên duy nhất là số tiền phải trả ít nhất để mua vé cho tất cả mọi người
//


#include<iostream>
#include<vector>
#include<cstring>
#include<climits>

using namespace std;

const int MAXN = 1005;

int n, A[MAXN], B[MAXN], dp[MAXN];

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> A[i] >> B[i];
	}
	
	dp[n] = A[n];
	for (int i = n - 1; i >= 1; i--){
		dp[i] = min(dp[i + 1] + A[i], dp[i + 2] + B[i]);
	}
	cout << dp[1];
	return 0;
}
/*
4
3 2
4 1
3 6
2 1
6
*/
