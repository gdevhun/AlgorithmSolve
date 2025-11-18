#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> vec(7);
	priority_queue<int, vector<int>, greater<int>> pq;
	int sum = 0;
	for (int i=0; i<7; i++)
	{
		cin >> vec[i];
		if (vec[i]%2!=0)
		{
			sum += vec[i];
			pq.push(vec[i]);
		}
	}
	if (!pq.empty())
	{
		cout << sum << "\n" << pq.top();
	}
	else
	{
		cout << "-1";
	}

	return 0;
}