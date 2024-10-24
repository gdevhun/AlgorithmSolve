#include <iostream>
#include <stack>
#include <string>
using namespace std;
int t;
string input;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (1) {

		bool flag = true;
		stack<char>st;
		getline(cin, input);
		if (input == ".") break;

		for (int i = 0; i < input.size(); i++) {
			if (input[i] == '(' || input[i] == '[') st.push(input[i]);
			else if (input[i] == ')') {
				if (st.size() && st.top() == '(') st.pop();
				else {
					flag = false; break;
				}
			}
			else if (input[i] == ']') {
				if (st.size() && st.top() == '[') st.pop();
				else {
					flag = false; break;
				}
			}
		}

		if (st.empty() && flag) cout << "yes" << "\n";
		else cout << "no" << "\n";
	}
	
	return 0;
}
