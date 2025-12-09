#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<algorithm>
#include <cmath>
using namespace std;
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
int canvas[501][501];
int visited[501][501];
int n, m, cnt;
int maxarea;
int bfs(int y,int x)
{
	int areanum = 1;
	queue<pair<int, int>> que;
	que.push({ y,x });
	visited[y][x] = 1;
	while (!que.empty())
	{
		int cy = que.front().first;
		int cx = que.front().second;
		que.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;
			if (canvas[ny][nx] == 0) continue;
			visited[ny][nx] = visited[cy][cx] + 1;
			areanum++;
			que.push({ ny,nx });
		}
	}
	return areanum;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin >> n >> m;
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
		{
			cin >> canvas[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (canvas[i][j]==1&&!visited[i][j])
			{
				maxarea=max(bfs(i, j),maxarea);
				cnt++;
			}
		}
	}
	
	cout << cnt << "\n" << maxarea << "\n";
	return 0;

}