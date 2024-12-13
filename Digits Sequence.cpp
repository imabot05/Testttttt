#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

string digits;
int lenNum = 10000;

string convert(int n){
	string s;
	while (n) {
		int tmp = n % 10;
		s += tmp + '0';
		n /= 10;
	}
	reverse(s.begin(), s.end());
	return s;
}

int main() {     
    int k;
    cin >> k;
    string digits;
    int num = 1;
    while (digits.size() < k){
    	digits += convert(num);
    	num += 1;
	}
	cout << digits[k - 1] << endl;
	return 0;
}

/*
Let's write all the positive integer numbers one after another from 1
 without any delimiters (i.e. as a single string). It will be the infinite sequence starting with 123456789101112131415161718192021222324252627282930313233343536...

Your task is to print the k
-th digit of this sequence.

Input
The first and only line contains integer k
 (1≤k≤10000
) — the position to process (1
-based index).

Output
Print the k
-th digit of the resulting infinite sequence.
21
5
*/
