#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T, currentMoney;
	cin >> T;
	while (T--)
	{
		cin >> currentMoney;
		pair<int, int> currency[4] = { {25,0},{10,0},{5,0},{1,0} };
		while (currentMoney!=0)
		{
			if (currentMoney>=currency[0].first)
			{
				currentMoney -= currency[0].first;
				currency[0].second++;
			}
			else if (currentMoney>=currency[1].first)
			{
				currentMoney -= currency[1].first;
				currency[1].second++;
			}
			else if (currentMoney >= currency[2].first)
			{
				currentMoney -= currency[2].first;
				currency[2].second++;
			}
			else if (currentMoney >= currency[3].first)
			{
				currentMoney -= currency[3].first;
				currency[3].second++;
			}
		}
		for (auto cur : currency)
		{
			cout << cur.second << " ";
		}
		cout << "\n";
	}
}