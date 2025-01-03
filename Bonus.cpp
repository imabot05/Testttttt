//Tuấn là người chiến thắng trong một cuộc thi “tìm hiểu kiến thức vũ trụ” và được nhận các phần thưởng do công ty XYZ tài trợ. Các phần thưởng được bố trí trên một bảng hình vuông nxn có dạng một lưới ô vuông kích thước đơn vị. Các dòng của bảng được đánh số từ 1 đến n, từ trên xuống dưới và các cột của bảng được đánh số từ 1 đến n, từ trái qua phải. Ô nằm trên giao của dòng i và cột j được gọi là ô (i,j) và trên ô đó chứa một món quà có giá trị là a[i,j] (1 <= i, j <= n)
//
//Đề nhận phần thưởng, Tuấn được phép chọn một hình vuông kích thước k x k chiếm trọn trong một số ô của bảng và nhận tất cả các phần quà có trong các ô nằm trong hình vuông đó.
//
//Yêu cầu: Hãy xác định tổng giá trị lớn nhất của món quà mà Tuấn có thể nhận được.
//
//Dữ liệu:
//
//Dòng thứ nhất chứa hai sô nguyên dương n, k (n <= 1000, n/3 <= k <= n).
//Dòng thứ i trong số n dòng tiếp theo chứa n số nguyên dương, số thứ j là a[i,j] (a[i,j] <= 1000)
//Kết quả: Ghi ra một số nguyên duy nhất là tổng giá trị lớn nhất của các món quà mà Tuấn có thể nhận được.
//
//Ví dụ:
//
//Dữ liệu
//
//Kết quả
//
//4 3
//1 9 1 1
//9 9 9 9
//1 9 9 9
//1 9 9 14
//86


#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1005;
int n, k, dp[MAXN][MAXN], ans;

int main(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cin >> dp[i][j];
			dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
		}
	}
	
	for (int i = k; i <= n; i++){
		for (int j = k; j <= n; j++){
			int S = dp[i][j] - dp[i - k][j] - dp[i][j - k] + dp[i - k][j - k];
			ans = max(ans, S);
		}
	}
	
	cout << ans;
	return 0;
}
