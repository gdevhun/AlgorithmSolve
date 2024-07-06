#include<iostream>
using namespace std;
long long p[101];
int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test;
	cin >> test;
	p[0] = 0; //not use
	p[1] = 1;
	p[2] = 1;
	p[3] = 1;
	for (int i = 4; i <= 100; i++) {
		p[i] = p[i - 2] + p[i - 3];
	}
	while (test--) {
		int cmd;
		cin >> cmd;
		cout << p[cmd] << "\n";
	}
}
