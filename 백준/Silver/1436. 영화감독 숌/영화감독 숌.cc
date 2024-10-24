#include<iostream>
int num, cnt, temp, ans;
using namespace std;
int main() {
	cin >> num;
	while (cnt != num) {
		ans++;
		temp = ans;
		while (temp != 0) {
			if (temp % 1000 == 666) {
				cnt++; break;
			}
			else temp /= 10;
		}
	}
	cout << ans;
}