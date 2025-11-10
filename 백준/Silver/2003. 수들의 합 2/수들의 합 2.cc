#include<iostream>
#include<queue>
#include<algorithm>
#include <string>
using namespace std;
int n, m;
int arr[10001];
int presum[10001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin >> n >> m;

	
	for (int i=1; i<=n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		presum[i + 1] = arr[i + 1] + presum[i];
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			int sum = presum[j] - presum[i - 1];
			if (sum == m) cnt++;
		}
	}
	cout << cnt;
    return 0;
}