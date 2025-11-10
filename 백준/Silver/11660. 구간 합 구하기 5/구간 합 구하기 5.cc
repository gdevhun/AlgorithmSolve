#include<iostream>
#include<queue>
#include<algorithm>
#include <string>
using namespace std;
int n, m;
int presum[1025][1025];
int map[1025][1025];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin >> n >> m;
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
		{
			cin >> map[i][j];

			presum[i][j] = presum[i - 1][j]      // 위쪽
				+ presum[i][j - 1]      // 왼쪽
				- presum[i - 1][j - 1]    // 중복 제거
				+ map[i][j];          // 현재 값
		}
	}
	for (int i=0; i<m; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		// 구간 합 계산
		int result = presum[x2][y2]
			- presum[x1 - 1][y2]
			- presum[x2][y1 - 1]
			+ presum[x1 - 1][y1 - 1];

		cout << result << "\n";
	}
    return 0;
}
	