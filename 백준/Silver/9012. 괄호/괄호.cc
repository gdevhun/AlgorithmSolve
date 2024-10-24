#include <iostream>
#include <stack>
using namespace std;
int t;
string input;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> input;
		stack<char>st;
		bool flag = true;
		for (int i = 0; i<input.size(); i++) {
			if (input[i] == '(') {
				st.push('(');
			}
			else { // input[i]== ')'
				if (st.size() != 0 && st.top() == '(') {
					st.pop();
				}
				else {
					flag = false; break;
				}
			}
		}
		if (flag && st.empty()) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}

	return 0;
}