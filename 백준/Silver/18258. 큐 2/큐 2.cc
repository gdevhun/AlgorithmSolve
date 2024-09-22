#include<iostream>
#include<queue>
#include<string>
using namespace std;
queue<int>que;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr); //rapid IO
	int n; //명령의 수
	string str;
	int val;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		if (str == "push") {
			cin >> val;
			que.push(val);
		}
		else if (str == "pop") {
			if (!que.empty()) {
				cout << que.front() << '\n';
				que.pop();
			}
			else cout << "-1" << '\n';
		}
		else if (str == "size") {
			cout << que.size() << '\n';
		}
		else if (str == "empty") {
			cout << (int)que.empty() << '\n';
		}
		else if (str == "front") {
			if (que.empty()) cout << "-1" << '\n';
			else cout << que.front() << '\n';
		}
		else if (str == "back") {
			if (que.empty()) cout << "-1" << '\n';
			else cout << que.back() << '\n';
		}
	}
	return 0;
}
