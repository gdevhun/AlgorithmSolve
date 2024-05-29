#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr); 
	stack<int>st;
	int n;
	cin >> n;
	while (n--) {
		int cmd;
		cin >> cmd;
		if(cmd == 1) {
			int elem;
			cin >> elem;
			st.push(elem);
		}
		else if (cmd == 2) {
			if (!st.empty()) {
				cout << st.top() << '\n';
				st.pop();
			}
			else cout << "-1" << '\n';
		}
		else if (cmd == 3) {
			cout << st.size() << '\n';
		}
		else if (cmd == 4) {
			if (st.empty()) {
				cout << "1" << '\n';
			}
			else {
				cout << "0" << '\n';
			}
		}
		else if (cmd == 5) {
			if (!st.empty()) {
				cout << st.top() << '\n';
			}
			else {
				cout << "-1" << '\n';
			}
		}
		
	}
}