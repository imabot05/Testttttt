#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int n, a[18], check[18], ans = 99999;

void inp(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	memset(check, 0, sizeof(check));
}

void Try(int i, int load, int day){
	if (i == n + 1){
		ans = std::min(ans, day);
		return;
	}
	int ok = 0;
	for (int j = 1; j <= n; j++){
		if (!check[j] && load + a[j] <= 6){
			check[j] = 1;
			ok = 1;
			Try(i + 1, load + a[j], day);
			check[j] = 0;
		}
	}
	if (ok == 0) Try(i, 0, day + 1);
}

void solve(){
	inp();
	Try(1, 0, 1);
	cout << ans;
}

int main(){
	solve();
	return 0;
}
/*
Có n môn học 1; : : : ; n ph£i đưæc di„n ra trong mºt chuØi ngày, mØi ngày đưæc chia thành 6 đơn vị thời
gian. Môn học i di„n ra di đơn vị thời gian. Hai môn học trong cùng mºt ngày không đưæc ph†p giao
nhau. H¢y l“p lịch cho c¡c môn học sao cho sŁ lưæng ngày Q cƒn dùng là ‰t nh§t.
Dœ li»u vào
• DÆng thø nh§t chøa sŁ nguy¶n dương n (1 ≤ n ≤ 15);
• DÆng thø hai chøa n sŁ nguy¶n di c¡ch nhau bởi d§u c¡ch (1 ≤ di ≤ 6).
K‚t qu£
Ghi ra duy nh§t mºt sŁ Q t…m đưæc.
*/
