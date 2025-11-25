#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int min_x, max_x;
	int min_y, max_y;
	int n;
	cin >> n;
	bool first = true;
	for (int i=0; i<n; i++)
	{
		int x, y;
		cin >> x >> y;
		if (first)
		{
			min_x = x; max_x = x;
			min_y = y; max_y = y;
			first = false;
		}
		min_x = min(min_x, x);
		max_x = max(max_x, x);
		min_y = min(min_y, y);
		max_y = max(max_y, y);
	}
	cout << abs(max_y - min_y) * abs(max_x - min_x);
	return 0;
}
	