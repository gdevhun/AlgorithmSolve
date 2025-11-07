#include<iostream>
#include<queue>
#include <algorithm>
using namespace std;
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
int dist[1001][1001];
bool visited[1001][1001];
int map[1001][1001];
int n, m;
void bfs(int y,int x)
{
	queue<pair<int, int>>que;
	dist[y][x] = 0;
	visited[y][x] = true;
	que.push({ y,x });
	while (!que.empty())
	{
		int cy = que.front().first;
		int cx = que.front().second;
		que.pop();

		for (int i=0; i<4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;
			if (map[ny][nx] == 0) continue;
			visited[ny][nx] = true;
			dist[ny][nx] = dist[cy][cx] + 1;
			que.push({ ny,nx });
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

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
			if (map[i][j] == 2) bfs(i, j);
		}
	}
	

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 0) cout << "0 ";
			else if (visited[i][j] == false) cout << "-1 ";
			else cout << dist[i][j]<<" ";
		}
		cout << "\n";
	}

    return 0;
}