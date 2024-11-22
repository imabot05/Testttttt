#include<iostream>
#include<vector>
#include<cstring>
#include<stack>

using namespace std;

const int MOD = 1e9 + 7;

void solve(){
	string expression;
	cin >> expression;
	stack<int> operands;
	stack<char> operators;
	for (int i = 0; i < expression.length(); i++){
		char c = expression[i];
		if (isdigit(c)){
			int num = c - '0';
			while (i + 1 < expression.length() && isdigit(expression[i + 1])){
				num = num * 10 + (expression[++i] - '0');
			}
			operands.push(num % MOD);
		} else if (c == '+'){
			if (i + 1 < expression.length() && expression[i + 1] == '+'){
				cout<<"NOT_CORRECT"<<endl;
				return;
			}
			operators.push(c);
		} else {
			cout<<"NOT_CORRECT"<<endl;
			return;
		} 
	}
	
	int result = 0;
	while (!operands.empty() && !operators.empty()){
		result = (result + operands.top()) % MOD;
		operands.pop();
		operators.pop();
	}
	
	if (!operands.empty()){
		result = (result + operands.top()) % MOD;
		operands.pop();
	}
	
	if (!operators.empty() || (expression.back() == '+')){
		cout<<"NOT_CORRECT"<<endl;
		return;
	}
	
	cout<<result;
}

int main(){
	solve();
	return 0;
}
