#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int dp[45];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while (true)
	{
		int n;
		cin >> n;
		if (n == -1) break;
		set<int> myset;
		int sum = 0;
		for (int i=1; i<n; i++)
		{
			if (n%i==0)
			{
				myset.insert(i);
			}
		}
		//sort(myset.begin(),myset.end());
		for (auto elem : myset)
		{
			sum += elem;
		}
		if (sum==n)
		{
			cout << n << " = ";
			for (auto it=myset.begin(); it!=myset.end(); ++it)
			{
				cout << *it;
				if (next(it)!=myset.end())
				{
					cout << " + ";
				}
			}
			cout << "\n";
		}
		else
		{
			cout << n << " is NOT perfect." << "\n";
		}
	}
}