#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<algorithm>
#include <cmath>
using namespace std;
vector<int>blueteam;
vector<int>whiteteam;
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
char map[501][501];
int visited[501][501];
int n, m;
int white, blue;
int bfsWhite(int y,int x)
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
			if (ny < 0 || nx < 0 || ny >= m || nx >= n || visited[ny][nx]) continue;
			if (map[ny][nx] == 'B') continue;
			visited[ny][nx] = visited[cy][cx] + 1;
			areanum++;
			que.push({ ny,nx });
		}
	}
	return areanum;
}
int bfsBlue(int y, int x)
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
			if (ny < 0 || nx < 0 || ny >= m || nx >= n || visited[ny][nx]) continue;
			if (map[ny][nx] == 'W') continue;
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
	for (int i=0; i<m; i++)
	{
		string input;
		cin >> input;
		for (int j=0; j<n; j++)
		{
			map[i][j] = input[j];
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j]=='W'&&!visited[i][j])
			{
				whiteteam.push_back(bfsWhite(i, j));

			}
			else if (map[i][j]=='B'&&!visited[i][j])
			{
				blueteam.push_back(bfsBlue(i, j));
			}
		}
	}
	for (auto elem : whiteteam)
	{
		white += pow(elem,2);
	}
	for (auto elem : blueteam)
	{
		blue += pow(elem, 2);
	}
	cout << white << " " << blue << "\n";
	return 0;

}