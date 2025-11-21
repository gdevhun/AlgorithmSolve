#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int n, m;
int map[1001][1001];
int dist[1001][1001];
int dayCnt;
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };

queue<pair<int, int>>que;
void bfs()
{
	while (!que.empty())
	{
		int cy = que.front().first;
		int cx = que.front().second;

		que.pop();

		for (int i=0; i<4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m || dist[ny][nx]) continue;
			if (map[ny][nx] == -1) continue;
			dist[ny][nx] = dist[cy][cx] + 1;
			que.push({ ny,nx });
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> m >> n;
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
		{
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 1)
			{
				que.push({ i,j });
				dist[i][j] = 1;
			} 
		}
	}
	
	bfs();

	bool impossible = false;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (dist[i][j]==0 && map[i][j]==0)
			{
				impossible = true;
				break;
			}
			dayCnt = max(dayCnt, dist[i][j]);
		}
		if (impossible) break;
	}
	if (impossible) cout << -1;
	else cout << dayCnt - 1;
	return 0;
}