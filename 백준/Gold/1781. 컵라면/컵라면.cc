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
	int ret = 0;
	int n;
	cin >> n;
	vector <pair<int, int>> vec(n);

	for (int i=0; i<n; i++)
	{
		cin >> vec[i].first;  //데드라인
		cin >> vec[i].second; //컵라면 수
	}
	sort(vec.begin(), vec.end());

	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i=0; i<n; i++)
	{
		pq.push(vec[i].second);

		if (pq.size()>vec[i].first)
		{
			pq.pop();
		}
	}
	while (!pq.empty())
	{
		ret += pq.top();
		pq.pop();
	}
	cout << ret;
	return 0;
}