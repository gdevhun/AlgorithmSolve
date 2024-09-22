#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr); //rapid IO
	int T; //테스트 
	string str;
	cin >> T;
	bool flag = false;
	while (T--) {
		stack<char>st;
		cin >> str;
		for (int i = 0; i<str.length(); i++) {
			if (str[i] == '(') st.push('(');
			else if (str[i] == ')') {
				if (st.empty()) {
					flag = false; 
					break;
				}
				else if ((st.top() == '(') && (!st.empty())) {
					st.pop();  
					flag = true;
				}
				else { flag = false; break;  }
			}
		}
		if (flag&&st.empty()) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
	return 0;
}