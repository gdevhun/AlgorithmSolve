#include<iostream>
#include<stack>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr); //rapid IO
	stack<int>st;
	int k;  //명령수
	int tmp;
	cin >> k;
	while (k--) {
		cin >> tmp;
		if (tmp == 0) st.pop();
		else st.push(tmp);
	}
	int sum = 0; //합
	while (!st.empty()) {
		sum += st.top();
		st.pop();
	}
	cout << sum << "\n";
	return 0;
}
