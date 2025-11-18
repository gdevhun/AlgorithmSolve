#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int dp[45];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	dp[0] = 0;
	dp[1] = 1;
	for (int i=2; i<=n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	if (n == 0) cout << "0";
	else if (n == 1) cout << "1";
	else cout << dp[n];
}
	