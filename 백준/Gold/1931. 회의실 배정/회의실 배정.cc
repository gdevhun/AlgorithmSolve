#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<algorithm>
#include <cmath>
#include <set>
#include <stack>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<pair<int, int>>vec(n);
	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;
		vec[i].first = end;
		vec[i].second = start;
	}
	sort(vec.begin(),vec.end());
	int cnt = 1;
	int r = vec[0].first;

	for (int i = 1; i < n; i++) {
		if (r <= vec[i].second) {
			cnt++;
			r = vec[i].first;
		}
	}
	cout << cnt;
	return 0;
}