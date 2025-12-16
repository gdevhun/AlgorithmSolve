#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<algorithm>
#include <cmath>
#include <set>
using namespace std;
int n, m, year;
int map[301][301];
int visited[301][301];
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
queue<pair<int, int>>que;
void meltIceMt()
{
	while (!que.empty())
	{
		int cy = que.front().first;
		int cx = que.front().second;
		que.pop();

		int cnt = 0;

		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;
			if (map[ny][nx] == 0)
			{
				cnt++;
			}

		}
		map[cy][cx] = map[cy][cx] - cnt;
		map[cy][cx] = max(map[cy][cx], 0);
	}
	
}
bool checkAllMelted()
{
	bool allMelted = true;
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
		{
			if (map[i][j]!=0)
			{
				allMelted = false;
				break;
			}
		}
		if (!allMelted) break;
	}
	return allMelted;
}
void checkTwoMt(int y,int x)
{
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;
		if (map[ny][nx]==0) continue;
		checkTwoMt(ny, nx);
	}
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin >> n >> m;
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
		{
			cin >> map[i][j];
		}
	}

	bool foundTwoMt = false;
	bool allMelted = false;
	while (true)
	{
		fill(&visited[0][0], &visited[0][0] + 301 * 301, 0);

		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (map[i][j] != 0)
				{
					que.push({ i,j });
					visited[i][j] = 1;
				}
			}
		}

		meltIceMt();

		if (checkAllMelted())
		{
			allMelted = true;
			break;
		}

		year++;

		fill(&visited[0][0], &visited[0][0] + 301 * 301, 0);

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (map[i][j] != 0 && !visited[i][j])
				{
					checkTwoMt(i,j);
					cnt++;
				}
			}
		}

		if (cnt >= 2)
		{
			foundTwoMt = true;
			break;
		} 
	}
	if (foundTwoMt) cout << year;
	if (allMelted) cout << "0";
	
	return 0;
}