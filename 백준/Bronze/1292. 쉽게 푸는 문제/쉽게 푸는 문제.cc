#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
int num[500501];
int presum[500501];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// 1 2 3 4  5  6  7  8  9 ...
	// 1 2 2 3  3  3  4  4  4  4  5  5  5  5  5 ...
	// 1 3 5 8 11 14 18 22 26 30 35 40 45 50 55 ...  3~7 sum[7]=sum[2]
	int a, b;
	cin >> a >> b;
	int curIdx = 1;
	for (int i=1; i<=b; i++)
	{
		for (int j=i; j!=0; j--)
		{
			num[curIdx] = i;
			presum[curIdx] = presum[curIdx - 1] + num[curIdx];
			curIdx++;
		}
	}
	cout << presum[b] - presum[a - 1];

	return 0;
}