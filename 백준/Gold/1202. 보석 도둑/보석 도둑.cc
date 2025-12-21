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
	int n, k; //보석수, 가방 갯수
	cin >> n >> k;
	vector<pair<int, int>> jewel(n); 
	vector<int> bag(k);
	long long int ret = 0;
	for (int i=0; i<n; i++)
	{
		cin >> jewel[i].first >> jewel[i].second; //무게 가격
	}
	sort(jewel.begin(), jewel.end());
	for (int i=0; i<k; i++)
	{
		cin >> bag[i];
	}
	sort(bag.begin(),bag.end());

	priority_queue<int>pq;
	int jewelCurIdx = 0;

	for (int i=0; i<k; i++)
	{
		//해당 가방에 들어갈 수 있는 보석 다넣기
		while (jewelCurIdx < n &&  jewel[jewelCurIdx].first <= bag[i])
		{
			pq.push(jewel[jewelCurIdx].second);
			jewelCurIdx++;
		}
		if (!pq.empty())
		{
			ret += pq.top();
			pq.pop();
		}
	}
	cout << ret;
	return 0;
}
