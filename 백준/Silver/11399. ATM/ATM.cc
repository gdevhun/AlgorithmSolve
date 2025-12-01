#include <iostream>
#include<algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int time[1005];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> time[i];
	}
	int total = 0;
	int temp = 0;
	sort(time, time+n);
	for (int i = 0; i < n; i++) {
		temp += time[i];
		total += temp;
	}
	cout << total << endl;
}