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

	int curTime = 0;
	for (int i=0; i<n; i++)
	{
		//도착시간, 검문시간
		cin >> vec[i].first;
		cin >> vec[i].second;
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < n; i++) {
		if (i == 0) 
		{
			curTime += vec[i].first;
			curTime += vec[i].second;
			continue;
		}
		if (curTime <= vec[i].first) {
			curTime = vec[i].first;
			curTime += vec[i].second;
		}
		else {
			curTime += vec[i].second;
		}
	}
	cout << curTime;
	return 0;
}