#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int apt[15][15];
int getsum(int floor, int roomnum)
{
	int ret = 0;
	for (int i=1; i<=roomnum; i++)
	{
		ret += apt[floor - 1][i];
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T, k, n;
	cin >> T;

	for (int i=0 ;i<15; i++)
	{
		apt[0][i] = i;
	}

	for (int i=1; i<15; i++)
	{
		for (int j=1; j<15; j++)
		{
			apt[i][j] = getsum(i, j);
		}
	}
	while (T--)
	{
		cin >> k >> n;
		cout << apt[k][n] << "\n";
	}
	
}