#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	queue<int>queue;
	int n, k;
	cin >> n >> k;
	vector<int> vec;
	for (int i = 1; i <= n; i++) {
		queue.push(i);
	}
	while (n--) {
		for (int t = 1; t < k; t++) {
			queue.push(queue.front());
			queue.pop();
		}
		vec.push_back(queue.front());
		queue.pop();
	}
	cout << "<";
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i];
		if (i == vec.size() - 1) {
			cout << ">";
		}
		else {
			cout<< ", ";
		}
	}
}