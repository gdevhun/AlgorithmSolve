#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	set<int> myset;

	for (int i=1; i<=n; i++)
	{
		if (n%i==0)
		{
			myset.insert(i);
		}
	}
	if (k > myset.size())
	{
		cout << "0";
	}
	else
	{
		int idx = 0;
		for (auto it=myset.begin(); it!=myset.end(); ++it)
		{
			idx++;
			if (idx==k)
			{
				cout << *it;
				break;
			}
		}
	}
	return 0;
}